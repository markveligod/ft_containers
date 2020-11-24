#pragma once

#include "../main.hpp"

int gen_int() { return (rand() % 1448228);}

char gen_char() 
{
    int i = rand() % 100;
    return (static_cast<char>((i < 33) ? i + 30 : i));
}

double gen_dd() { return ((rand() % 1448228) / 100.0);}

float gen_ff() { return ((rand() % 1448228) / 100.0f);}

std::string gen_str()
{
    std::string str[10] = {"Возьми это!", "Убирайся с моей лужайки!", "- Кофе? Черный... как моя душа.", "Я - огонь, Я - Смерть!", "Молния! Кукачев!", "Ты пытался открыть меня?", "Одной обоймы будет недостаточно!", "Давайте начнем эту вечеринку!", "Ты называешь себя крутым парнем?", "Неужели кто-то что-то почувствовал?"};
    return (str[rand() % 10]);
}

template<typename T>
void print_list(std::stringstream &os, std::list<T> &orig, ft::list<T> &no)
{
    typename std::list<T>::iterator or_begin = orig.begin();
    typename std::list<T>::iterator or_end = orig.end();
    typename ft::list<T>::iterator no_begin = no.begin();
    typename ft::list<T>::iterator no_end = no.end();

    os << "[Orig]: \t";
    while (or_begin != or_end)
    {
        os << *or_begin << " ";
        ++or_begin;
    }
    os << std::endl;
    os << "[No orig]: \t";
    while (no_begin != no_end)
    {
        os << *no_begin << " ";
        ++no_begin;
    }
    os << std::endl;

    typename std::list<T>::reverse_iterator or_rbegin = orig.rbegin();
    typename std::list<T>::reverse_iterator or_rend = orig.rend();
    typename ft::list<T>::reverse_iterator no_rbegin = no.rbegin();
    typename ft::list<T>::reverse_iterator no_rend = no.rend();

    os << "[R_Orig]: \t";
    while (or_rbegin != or_rend)
    {
        os << *or_rbegin << " ";
        ++or_rbegin;
    }
    os << std::endl;
    os << "[R_No or]: \t";
    while (no_rbegin != no_rend)
    {
        os << *no_rbegin << " ";
        ++no_rbegin;
    }
    os << std::endl;

}

template<typename T>
void print_size(std::stringstream &os, std::list<T> &orig, ft::list<T> &no)
{
    os << "Size orig: " << orig.size() << std::endl;
    os << "Size noorig: " << no.size() << std::endl;
}

template<typename T, typename K>
bool check_iterators(T or_begin, T or_end, K no_begin, K no_end)
{
    while (no_begin != no_end && or_begin != or_end)
    {
        if (*or_begin != *no_begin)
            return (false);
        ++or_begin;
        ++no_begin;
    }
    if (no_begin != no_end || or_begin != or_end)
        return (false);
    return (true);
}

template<typename T>
bool check_list(std::list<T> &orig, ft::list<T> &no)
{
    typename std::list<T>::iterator or_begin = orig.begin();
    typename std::list<T>::iterator or_end = orig.end();
    typename ft::list<T>::iterator no_begin = no.begin();
    typename ft::list<T>::iterator no_end = no.end();

    while (or_begin != or_end)
    {
        if (*or_begin != *no_begin)
            return (false);
        ++or_begin;
        ++no_begin;
    }

    typename std::list<T>::reverse_iterator or_rbegin = orig.rbegin();
    typename std::list<T>::reverse_iterator or_rend = orig.rend();
    typename ft::list<T>::reverse_iterator no_rbegin = no.rbegin();
    typename ft::list<T>::reverse_iterator no_rend = no.rend();
    while (or_rbegin != or_rend)
    {
        if (*or_rbegin != *no_rbegin)
            return (false);
        ++or_rbegin;
        ++no_rbegin;
    }
    return (true);
}

template<typename T>
bool list_check_constructor(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_constructor \n";
    os << "\nCreaty constructor empty (orig_1 noorig_1)\n";

    std::list<T> orig_1;
    ft::list<T> noorig_1;

    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (size_type n, const value_type& val) (orig_2 noorig_2)\n";
    std::list<T> orig_2(4, data_1);
    ft::list<T> noorig_2(4, data_1);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (size_type n, const value_type& val) (orig_3 noorig_3)\n";
    std::list<T> orig_3(5, data_2);
    ft::list<T> noorig_3(5, data_2);
    print_list(os, orig_3, noorig_3);
    print_size(os, orig_3, noorig_3);
    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_3, noorig_3))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::iterator or_begin_1 = orig_3.begin();
    typename std::list<T>::iterator or_end_1 = orig_3.end();
    typename ft::list<T>::iterator no_begin_1 = noorig_3.begin();
    typename ft::list<T>::iterator no_end_1 = noorig_3.end();

    os << "\nCreaty constructor (iterator first, iterator last) (orig_4 noorig_4)\n";
    std::list<T> orig_4(or_begin_1, or_end_1);
    ft::list<T> noorig_4(no_begin_1, no_end_1);
    print_list(os, orig_4, noorig_4);
    print_size(os, orig_4, noorig_4);
    if (orig_4.size() != noorig_4.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_4, noorig_4))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::const_iterator or_begin_2 = orig_4.begin();
    typename std::list<T>::const_iterator or_end_2 = orig_4.end();
    typename ft::list<T>::const_iterator no_begin_2 = noorig_4.begin();
    typename ft::list<T>::const_iterator no_end_2 = noorig_4.end();

    os << "\nCreaty constructor (const_iterator first, const_iterator last) (orig_5 noorig_5)\n";
    std::list<T> orig_5(or_begin_2, or_end_2);
    ft::list<T> noorig_5(no_begin_2, no_end_2);
    print_list(os, orig_5, noorig_5);
    print_size(os, orig_5, noorig_5);
    if (orig_5.size() != noorig_5.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_5, noorig_5))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (const list &other) orig_6(orig_2) noorig_6(noorig_2)\n";
    std::list<T> orig_6(orig_2);
    ft::list<T> noorig_6(noorig_2);
    print_list(os, orig_6, noorig_6);
    print_size(os, orig_6, noorig_6);
    if (orig_6.size() != noorig_6.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_6, noorig_6))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_operator(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_operator \n";
    os << "\nCreaty operator=(const list &other)\n";
    std::list<T> orig_1(10, data_1);
    ft::list<T> noorig_1(10, data_1);
    std::list<T> orig_2(15, data_2);
    ft::list<T> noorig_2(15, data_2);

    os << "\nBefore orig_1 noorig_1\n";
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }
    os << "\nBefore orig_2 noorig_2\n";
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    orig_1 = orig_2;
    noorig_1 = noorig_2;

    os << "\nAfter orig_1 noorig_1\n";
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }
    os << "\nAfter orig_2 noorig_2\n";
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_begin(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_begin \n";

    os << "\nlist #1 orig_1 noorig_1 \n";
    std::list<T> orig_1(7, data_1);
    ft::list<T> noorig_1(7, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    std::list<T> orig_2(4, data_2);
    ft::list<T> noorig_2(4, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::iterator or_begin_1 = orig_1.begin();
    typename std::list<T>::iterator or_end_1 = orig_1.end();
    typename ft::list<T>::iterator no_begin_1 = noorig_1.begin();
    typename ft::list<T>::iterator no_end_1 = noorig_1.end();

    typename std::list<T>::const_iterator or_begin_2 = orig_1.begin();
    typename std::list<T>::const_iterator or_end_2 = orig_1.end();
    typename ft::list<T>::const_iterator no_begin_2 = noorig_1.begin();
    typename ft::list<T>::const_iterator no_end_2 = noorig_1.end();

    typename std::list<T>::iterator or_begin_5 = orig_2.begin();
    typename std::list<T>::iterator or_end_5 = orig_2.end();
    typename ft::list<T>::iterator no_begin_5 = noorig_2.begin();
    typename ft::list<T>::iterator no_end_5 = noorig_2.end();

    typename std::list<T>::const_iterator or_begin_6 = orig_2.begin();
    typename std::list<T>::const_iterator or_end_6 = orig_2.end();
    typename ft::list<T>::const_iterator no_begin_6 = noorig_2.begin();
    typename ft::list<T>::const_iterator no_end_6 = noorig_2.end();

    if (!check_iterators<typename std::list<T>::iterator, typename ft::list<T>::iterator>(or_begin_1, or_end_1, no_begin_1, no_end_1) ||
    !check_iterators<typename std::list<T>::const_iterator, typename ft::list<T>::const_iterator>(or_begin_2, or_end_2, no_begin_2, no_end_2) ||
    !check_iterators<typename std::list<T>::iterator, typename ft::list<T>::iterator>(or_begin_5, or_end_5, no_begin_5, no_end_5) ||
    !check_iterators<typename std::list<T>::const_iterator, typename ft::list<T>::const_iterator>(or_begin_6, or_end_6, no_begin_6, no_end_6))
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_rbegin(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_rbegin \n";

    os << "\nlist #1 orig_1 noorig_1 \n";
    std::list<T> orig_1(7, data_1);
    ft::list<T> noorig_1(7, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    std::list<T> orig_2(4, data_2);
    ft::list<T> noorig_2(4, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::reverse_iterator or_begin_3 = orig_1.rbegin();
    typename std::list<T>::reverse_iterator or_end_3 = orig_1.rend();
    typename ft::list<T>::reverse_iterator no_begin_3 = noorig_1.rbegin();
    typename ft::list<T>::reverse_iterator no_end_3 = noorig_1.rend();

    typename std::list<T>::const_reverse_iterator or_begin_4 = orig_1.rbegin();
    typename std::list<T>::const_reverse_iterator or_end_4 = orig_1.rend();
    typename ft::list<T>::const_reverse_iterator no_begin_4 = noorig_1.rbegin();
    typename ft::list<T>::const_reverse_iterator no_end_4 = noorig_1.rend();

    typename std::list<T>::reverse_iterator or_begin_7 = orig_2.rbegin();
    typename std::list<T>::reverse_iterator or_end_7 = orig_2.rend();
    typename ft::list<T>::reverse_iterator no_begin_7 = noorig_2.rbegin();
    typename ft::list<T>::reverse_iterator no_end_7 = noorig_2.rend();

    typename std::list<T>::const_reverse_iterator or_begin_8 = orig_2.rbegin();
    typename std::list<T>::const_reverse_iterator or_end_8 = orig_2.rend();
    typename ft::list<T>::const_reverse_iterator no_begin_8 = noorig_2.rbegin();
    typename ft::list<T>::const_reverse_iterator no_end_8 = noorig_2.rend();

    if (!check_iterators<typename std::list<T>::reverse_iterator, typename ft::list<T>::reverse_iterator>(or_begin_3, or_end_3, no_begin_3, no_end_3) ||
    !check_iterators<typename std::list<T>::const_reverse_iterator, typename ft::list<T>::const_reverse_iterator>(or_begin_4, or_end_4, no_begin_4, no_end_4) ||
    !check_iterators<typename std::list<T>::reverse_iterator, typename ft::list<T>::reverse_iterator>(or_begin_7, or_end_7, no_begin_7, no_end_7) ||
    !check_iterators<typename std::list<T>::const_reverse_iterator, typename ft::list<T>::const_reverse_iterator>(or_begin_8, or_end_8, no_begin_8, no_end_8))
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_empty(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_empty \n";

    os << "\nlist #1 orig_1 noorig_1 \n";
    std::list<T> orig_1;
    ft::list<T> noorig_1;
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nEmpty orig_1 => " << orig_1.empty() << std::endl;
    os << "Empty noorig_1 => " << noorig_1.empty() << std::endl;
    if ((orig_1.empty()) != (noorig_1.empty()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #1 orig_1 noorig_1 \n";
    orig_1.assign(5, data_1);
    noorig_1.assign(5, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nEmpty orig_1 => " << orig_1.empty() << std::endl;
    os << "Empty noorig_1 => " << noorig_1.empty() << std::endl;
    if ((orig_1.empty()) != (noorig_1.empty()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    std::list<T> orig_2;
    ft::list<T> noorig_2;
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nEmpty orig_2 => " << orig_2.empty() << std::endl;
    os << "Empty noorig_2 => " << noorig_2.empty() << std::endl;
    if ((orig_2.empty()) != (noorig_2.empty()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    orig_2.assign(5, data_2);
    noorig_2.assign(5, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nEmpty orig_2 => " << orig_2.empty() << std::endl;
    os << "Empty noorig_2 => " << noorig_2.empty() << std::endl;
    if ((orig_2.empty()) != (noorig_2.empty()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_size(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_size \n";

    os << "\nlist #1 orig_1 noorig_1 \n";
    std::list<T> orig_1;
    ft::list<T> noorig_1;
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nsize orig_1 => " << orig_1.size() << std::endl;
    os << "size noorig_1 => " << noorig_1.size() << std::endl;
    if ((orig_1.size()) != (noorig_1.size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #1 orig_1 noorig_1 \n";
    orig_1.assign(5, data_1);
    noorig_1.assign(5, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nsize orig_1 => " << orig_1.size() << std::endl;
    os << "size noorig_1 => " << noorig_1.size() << std::endl;
    if ((orig_1.size()) != (noorig_1.size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    std::list<T> orig_2;
    ft::list<T> noorig_2;
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nsize orig_2 => " << orig_2.size() << std::endl;
    os << "size noorig_2 => " << noorig_2.size() << std::endl;
    if ((orig_2.size()) != (noorig_2.size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    orig_2.assign(15, data_2);
    noorig_2.assign(15, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nsize orig_2 => " << orig_2.size() << std::endl;
    os << "size noorig_2 => " << noorig_2.size() << std::endl;
    if ((orig_2.size()) != (noorig_2.size()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_max_size(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_max_size \n";

    os << "\nlist #1 orig_1 noorig_1 \n";
    std::list<T> orig_1;
    ft::list<T> noorig_1;
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nmax_size orig_1 (on mac 768614336404564650 or in std::string 384307168202282325) => " << orig_1.max_size() << std::endl;
    os << "max_size noorig_1 => " << noorig_1.max_size() << std::endl;
    if (((typeid(T) == typeid(std::string)) ? 384307168202282325 : 768614336404564650) != (noorig_1.max_size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #1 orig_1 noorig_1 \n";
    orig_1.assign(5, data_1);
    noorig_1.assign(5, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nmax_size orig_1 (on mac 768614336404564650 or in std::string 384307168202282325) => " << orig_1.max_size() << std::endl;
    os << "max_size noorig_1 => " << noorig_1.max_size() << std::endl;
    if (((typeid(T) == typeid(std::string)) ? 384307168202282325 : 768614336404564650) != (noorig_1.max_size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    std::list<T> orig_2;
    ft::list<T> noorig_2;
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nmax_size orig_2 (on mac 768614336404564650 or in std::string 384307168202282325) => " << orig_2.max_size() << std::endl;
    os << "max_size noorig_2 => " << noorig_2.max_size() << std::endl;
    if (((typeid(T) == typeid(std::string)) ? 384307168202282325 : 768614336404564650) != (noorig_2.max_size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig_2 noorig_2 \n";
    orig_2.assign(15, data_2);
    noorig_2.assign(15, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nmax_size orig_2 (on mac 768614336404564650 or in std::string 384307168202282325) => " << orig_2.max_size() << std::endl;
    os << "max_size noorig_2 => " << noorig_2.max_size() << std::endl;
    if (((typeid(T) == typeid(std::string)) ? 384307168202282325 : 768614336404564650) != (noorig_2.max_size()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_front(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_front \n";

    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(15, data_1);
    ft::list<T> noorig(15, data_1);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nfront orig => " << orig.front() << std::endl;
    os << "front noorig => " << noorig.front() << std::endl;
    if ((orig.front()) != (noorig.front()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #1 orig noorig \n";
    orig.assign(5, data_1);
    noorig.assign(5, data_1);
    orig.push_back(data_2);
    noorig.push_back(data_2);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nfront orig => " << orig.front() << std::endl;
    os << "front noorig => " << noorig.front() << std::endl;
    if ((orig.front()) != (noorig.front()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_back(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_back \n";

    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(15, data_1);
    ft::list<T> noorig(15, data_1);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nback orig => " << orig.back() << std::endl;
    os << "back noorig => " << noorig.back() << std::endl;
    if ((orig.back()) != (noorig.back()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #1 orig noorig \n";
    orig.assign(5, data_1);
    noorig.assign(5, data_1);
    orig.push_back(data_2);
    noorig.push_back(data_2);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nback orig => " << orig.back() << std::endl;
    os << "back noorig => " << noorig.back() << std::endl;
    if ((orig.back()) != (noorig.back()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_assign(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_assign \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig;
    ft::list<T> noorig;
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);

    os << "\nAfter run assign with data_1 \n";
    orig.assign(15, data_1);
    noorig.assign(15, data_1);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run assign with data_2 \n";
    orig.assign(5, data_2);
    noorig.assign(5, data_2);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_push_back(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_push_back \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig;
    ft::list<T> noorig;
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);

    os << "\nAfter run push_back with data_1 \n";
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_1);
        noorig.push_back(data_1);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run push_back with data_2 \n";
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_2);
        noorig.push_back(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_pop_back(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_pop_back \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(11, data_1);
    ft::list<T> noorig(11, data_1);
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_2);
        noorig.push_back(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_back\n";
    orig.pop_back();
    noorig.pop_back();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_back\n";
    orig.pop_back();
    noorig.pop_back();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_back\n";
    orig.pop_back();
    noorig.pop_back();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_push_front(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_push_front \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig;
    ft::list<T> noorig;
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);

    os << "\nAfter run push_front with data_1 \n";
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_front(data_1);
        noorig.push_front(data_1);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run push_front with data_2 \n";
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_front(data_2);
        noorig.push_front(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_pop_front(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_pop_front \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(11, data_1);
    ft::list<T> noorig(11, data_1);
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_2);
        noorig.push_back(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_front\n";
    orig.pop_front();
    noorig.pop_front();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_front\n";
    orig.pop_front();
    noorig.pop_front();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run pop_front\n";
    orig.pop_front();
    noorig.pop_front();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_clear(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_clear \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(11, data_1);
    ft::list<T> noorig(11, data_1);
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_2);
        noorig.push_back(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run clear\n";
    orig.clear();
    noorig.clear();
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_insert(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_insert \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig(11, data_1);
    ft::list<T> noorig(11, data_1);
    for (size_t i = 0; i < 11; i++)
    {
        orig.push_back(data_2);
        noorig.push_back(data_2);
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::iterator or_begin = orig.begin();
    typename std::list<T>::iterator or_end = orig.end();
    typename ft::list<T>::iterator no_begin = noorig.begin();
    typename ft::list<T>::iterator no_end = noorig.end();

    os << "\nAfter run insert (iterator position, const value_type& val);\n";
    orig.insert(++or_begin, data_2);
    noorig.insert(++no_begin, data_2);
    orig.insert(--or_end, data_2);
    noorig.insert(--no_end, data_2);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    or_begin = orig.begin();
    or_end = orig.end();
    no_begin = noorig.begin();
    no_end = noorig.end();

    os << "\nAfter run insert (iterator position, size_type n, const value_type& val);\n";
    orig.insert(or_begin, 4, data_2);
    noorig.insert(no_begin, 4, data_2);
    orig.insert(or_end, 4, data_2);
    noorig.insert(no_end, 4, data_2);

    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run insert (iterator position, InputIterator first, InputIterator last)\n";
    orig.insert(orig.begin(), orig.begin(), orig.end());
    noorig.insert(noorig.begin(), noorig.begin(), noorig.end());

    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_erase(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_erase \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig;
    ft::list<T> noorig;
    for (size_t i = 0; i < 11; i++)
    {
        if (i % 2 == 0)
        {
            orig.push_back(data_2);
            noorig.push_back(data_2);
        }
        else
        {
            orig.push_back(data_1);
            noorig.push_back(data_1);
        }
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    typename std::list<T>::iterator or_begin = orig.begin();
    typename std::list<T>::iterator or_end = orig.end();
    typename ft::list<T>::iterator no_begin = noorig.begin();
    typename ft::list<T>::iterator no_end = noorig.end();

    os << "\nAfter run erase (iterator position)\n";
    orig.erase(++or_begin);
    noorig.erase(++no_begin);

    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter run erase (iterator position)\n";
    orig.erase(--or_end);
    noorig.erase(--no_end);

    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    or_begin = orig.begin();
    or_end = orig.end();
    no_begin = noorig.begin();
    no_end = noorig.end();

    os << "\nAfter run erase (iterator first, iterator last)\n";
    orig.erase(or_begin, --or_end);
    noorig.erase(no_begin, --no_end);

    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_swap(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_swap \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig_1(11, data_1);
    ft::list<T> noorig_1(11, data_1);
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig noorig \n";
    std::list<T> orig_2(6, data_2);
    ft::list<T> noorig_2(6, data_2);
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter swap(list& x)\n";
    orig_1.swap(orig_2);
    noorig_1.swap(noorig_2);

    os << "\nlist #1 orig noorig \n";
    print_list(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nlist #2 orig noorig \n";
    print_list(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool list_check_resize(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! list_check_resize \n";
    os << "\nlist #1 orig noorig \n";
    std::list<T> orig;
    ft::list<T> noorig;

    for (size_t i = 0; i < 11; i++)
    {
        if (i % 2 == 0)
        {
            orig.push_back(data_2);
            noorig.push_back(data_2);
        }
        else
        {
            orig.push_back(data_1);
            noorig.push_back(data_1);
        }
    }
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter resize(5) \n";
    orig.resize(5);
    noorig.resize(5);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter resize(20) \n";
    orig.resize(20);
    noorig.resize(20);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter resize(125, data_1) \n";
    orig.resize(125, data_1);
    noorig.resize(125, data_1);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nAfter resize(12, data_2) \n";
    orig.resize(12, data_2);
    noorig.resize(12, data_2);
    print_list(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
void list_start(std::ofstream *out)
{
    if (typeid(T) == typeid(int))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check assign]: " << ((list_check_assign<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_back]: " << ((list_check_push_back<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_back]: " << ((list_check_pop_back<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_front]: " << ((list_check_push_front<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_front]: " << ((list_check_pop_front<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check clear]: " << ((list_check_clear<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check insert]: " << ((list_check_insert<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check erase]: " << ((list_check_erase<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check swap]: " << ((list_check_swap<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check resize]: " << ((list_check_resize<int>(out, gen_int(), gen_int())) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(char))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check assign]: " << ((list_check_assign<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_back]: " << ((list_check_push_back<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_back]: " << ((list_check_pop_back<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_front]: " << ((list_check_push_front<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_front]: " << ((list_check_pop_front<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check clear]: " << ((list_check_clear<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check insert]: " << ((list_check_insert<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check erase]: " << ((list_check_erase<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check swap]: " << ((list_check_swap<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check resize]: " << ((list_check_resize<char>(out, gen_char(), gen_char())) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(double))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check assign]: " << ((list_check_assign<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_back]: " << ((list_check_push_back<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_back]: " << ((list_check_pop_back<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_front]: " << ((list_check_push_front<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_front]: " << ((list_check_pop_front<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check clear]: " << ((list_check_clear<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check insert]: " << ((list_check_insert<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check erase]: " << ((list_check_erase<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check swap]: " << ((list_check_swap<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check resize]: " << ((list_check_resize<double>(out, gen_dd(), gen_dd())) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(float))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check assign]: " << ((list_check_assign<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_back]: " << ((list_check_push_back<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_back]: " << ((list_check_pop_back<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_front]: " << ((list_check_push_front<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_front]: " << ((list_check_pop_front<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check clear]: " << ((list_check_clear<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check insert]: " << ((list_check_insert<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check erase]: " << ((list_check_erase<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check swap]: " << ((list_check_swap<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check resize]: " << ((list_check_resize<float>(out, gen_ff(), gen_ff())) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(std::string))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<std::string>(out,gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check assign]: " << ((list_check_assign<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_back]: " << ((list_check_push_back<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_back]: " << ((list_check_pop_back<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check push_front]: " << ((list_check_push_front<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check pop_front]: " << ((list_check_pop_front<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check clear]: " << ((list_check_clear<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check insert]: " << ((list_check_insert<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check erase]: " << ((list_check_erase<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check swap]: " << ((list_check_swap<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check resize]: " << ((list_check_resize<std::string>(out, gen_str(), gen_str())) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
}
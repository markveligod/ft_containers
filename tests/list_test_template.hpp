#pragma once

#include "../main.hpp"

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
    os << "\nlist_check_constructor \n";
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
    os << "\nlist_check_operator \n";
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
    os << "\nlist_check_begin \n";

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
    os << "\nlist_check_rbegin \n";

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
    os << "\nlist_check_empty \n";

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
    os << "\nlist_check_size \n";

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
    os << "\nlist_check_max_size \n";

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
    os << "\nlist_check_front \n";

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
    os << "\nlist_check_back \n";

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
void list_start(std::ofstream *out)
{
    if (typeid(T) == typeid(int))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<int>(out, 21, 42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<int>(out, 21, 42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<int>(out, 21, 42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<int>(out, 42, 21)) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(char))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<char>(out, '1', '2')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<char>(out, '2', '1')) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(double))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<double>(out, 21.42, 42.21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<double>(out, 21.42, 42.21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<double>(out, 21.42, 42.21)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<double>(out, 42.21, 21.42)) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(float))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<float>(out, 21.42f, 42.21f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<float>(out, 21.42f, 42.21f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<float>(out, 21.42f, 42.21f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<float>(out, 42.21f, 21.42f)) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
    else if (typeid(T) == typeid(std::string))
    {
        std::cout << YELLOW << "\n[check constructor]: " << ((list_check_constructor<std::string>(out, "21 42", "42 21")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check operator=]: " << ((list_check_operator<std::string>(out, "21 42", "42 21")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check begin(end)]: " << ((list_check_begin<std::string>(out,"21 42", "42 21")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check rbegin(rend)]: " << ((list_check_rbegin<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check empty]: " << ((list_check_empty<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check size]: " << ((list_check_size<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check max_size]: " << ((list_check_max_size<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check front]: " << ((list_check_front<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
        std::cout << YELLOW << "[check back]: " << ((list_check_back<std::string>(out, "42 21", "21 42")) ? GREEN"OK" : RED"FAIL") << std::endl;
    }
}
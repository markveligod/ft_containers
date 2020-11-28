#pragma once

#include "../main.hpp"

template<typename T>
void print_vector(std::stringstream &os, std::vector<T> &orig, ft::vector<T> &no)
{
    typename std::vector<T>::iterator or_begin = orig.begin();
    typename std::vector<T>::iterator or_end = orig.end();
    typename ft::vector<T>::iterator no_begin = no.begin();
    typename ft::vector<T>::iterator no_end = no.end();

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

    typename std::vector<T>::reverse_iterator or_rbegin = orig.rbegin();
    typename std::vector<T>::reverse_iterator or_rend = orig.rend();
    typename ft::vector<T>::reverse_iterator no_rbegin = no.rbegin();
    typename ft::vector<T>::reverse_iterator no_rend = no.rend();

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
void print_size(std::stringstream &os, std::vector<T> &orig, ft::vector<T> &no)
{
    os << "Size orig: " << orig.size() << std::endl;
    os << "Size noorig: " << no.size() << std::endl;
    os << "Capacity orig: " << orig.capacity() << std::endl;
    os << "Capacity noorig: " << no.capacity() << std::endl;
}

template<typename T>
bool check_vector(std::vector<T> &orig, ft::vector<T> &no)
{
    typename std::vector<T>::iterator or_begin = orig.begin();
    typename std::vector<T>::iterator or_end = orig.end();
    typename ft::vector<T>::iterator no_begin = no.begin();
    typename ft::vector<T>::iterator no_end = no.end();

    while (or_begin != or_end)
    {
        if (*or_begin != *no_begin)
            return (false);
        ++or_begin;
        ++no_begin;
    }

    typename std::vector<T>::reverse_iterator or_rbegin = orig.rbegin();
    typename std::vector<T>::reverse_iterator or_rend = orig.rend();
    typename ft::vector<T>::reverse_iterator no_rbegin = no.rbegin();
    typename ft::vector<T>::reverse_iterator no_rend = no.rend();
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
bool vector_check_constructor(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! vector_check_constructor \n";
    os << "\nCreaty constructor empty (orig_1 noorig_1)\n";

    std::vector<T> orig_1;
    ft::vector<T> noorig_1;

    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (size_type n, const value_type& val) (orig_2 noorig_2)\n";
    std::vector<T> orig_2(4, data_1);
    ft::vector<T> noorig_2(4, data_1);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (size_type n, const value_type& val) (orig_3 noorig_3)\n";
    std::vector<T> orig_3(5, data_2);
    ft::vector<T> noorig_3(5, data_2);
    print_vector(os, orig_3, noorig_3);
    print_size(os, orig_3, noorig_3);
    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_3, noorig_3))
    {
        *out << os.str();
        return (false);
    }

    typename std::vector<T>::iterator or_begin_1 = orig_3.begin();
    typename std::vector<T>::iterator or_end_1 = orig_3.end();
    typename ft::vector<T>::iterator no_begin_1 = noorig_3.begin();
    typename ft::vector<T>::iterator no_end_1 = noorig_3.end();

    os << "\nCreaty constructor (iterator first, iterator last) (orig_4 noorig_4)\n";
    std::vector<T> orig_4(or_begin_1, or_end_1);
    ft::vector<T> noorig_4(no_begin_1, no_end_1);
    print_vector(os, orig_4, noorig_4);
    print_size(os, orig_4, noorig_4);
    if (orig_4.size() != noorig_4.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_4, noorig_4))
    {
        *out << os.str();
        return (false);
    }

    typename std::vector<T>::const_iterator or_begin_2 = orig_4.begin();
    typename std::vector<T>::const_iterator or_end_2 = orig_4.end();
    typename ft::vector<T>::const_iterator no_begin_2 = noorig_4.begin();
    typename ft::vector<T>::const_iterator no_end_2 = noorig_4.end();

    os << "\nCreaty constructor (const_iterator first, const_iterator last) (orig_5 noorig_5)\n";
    std::vector<T> orig_5(or_begin_2, or_end_2);
    ft::vector<T> noorig_5(no_begin_2, no_end_2);
    print_vector(os, orig_5, noorig_5);
    print_size(os, orig_5, noorig_5);
    if (orig_5.size() != noorig_5.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_5, noorig_5))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (const vector &other) orig_6(orig_2) noorig_6(noorig_2)\n";
    std::vector<T> orig_6(orig_2);
    ft::vector<T> noorig_6(noorig_2);
    print_vector(os, orig_6, noorig_6);
    print_size(os, orig_6, noorig_6);
    if (orig_6.size() != noorig_6.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_6, noorig_6))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
bool vector_check_operator(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! vector_check_operator \n";
    os << "\nCreaty operator=(const vector &other)\n";
    std::vector<T> orig_1(10, data_1);
    ft::vector<T> noorig_1(10, data_1);
    std::vector<T> orig_2(15, data_2);
    ft::vector<T> noorig_2(15, data_2);

    os << "\nBefore orig_1 noorig_1\n";
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }
    os << "\nBefore orig_2 noorig_2\n";
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    orig_1 = orig_2;
    noorig_1 = noorig_2;

    os << "\nAfter orig_1 noorig_1\n";
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }
    os << "\nAfter orig_2 noorig_2\n";
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}
template<typename T>
bool vector_check_begin(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! vector_check_begin \n";

    os << "\nvector #1 orig_1 noorig_1 \n";
    std::vector<T> orig_1(7, data_1);
    ft::vector<T> noorig_1(7, data_1);
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nvector #2 orig_2 noorig_2 \n";
    std::vector<T> orig_2(4, data_2);
    ft::vector<T> noorig_2(4, data_2);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    typename std::vector<T>::iterator or_begin_1 = orig_1.begin();
    typename std::vector<T>::iterator or_end_1 = orig_1.end();
    typename ft::vector<T>::iterator no_begin_1 = noorig_1.begin();
    typename ft::vector<T>::iterator no_end_1 = noorig_1.end();

    typename std::vector<T>::const_iterator or_begin_2 = orig_1.begin();
    typename std::vector<T>::const_iterator or_end_2 = orig_1.end();
    typename ft::vector<T>::const_iterator no_begin_2 = noorig_1.begin();
    typename ft::vector<T>::const_iterator no_end_2 = noorig_1.end();

    typename std::vector<T>::iterator or_begin_5 = orig_2.begin();
    typename std::vector<T>::iterator or_end_5 = orig_2.end();
    typename ft::vector<T>::iterator no_begin_5 = noorig_2.begin();
    typename ft::vector<T>::iterator no_end_5 = noorig_2.end();

    typename std::vector<T>::const_iterator or_begin_6 = orig_2.begin();
    typename std::vector<T>::const_iterator or_end_6 = orig_2.end();
    typename ft::vector<T>::const_iterator no_begin_6 = noorig_2.begin();
    typename ft::vector<T>::const_iterator no_end_6 = noorig_2.end();

    if (!check_iterators<typename std::vector<T>::iterator, typename ft::vector<T>::iterator>(or_begin_1, or_end_1, no_begin_1, no_end_1) ||
    !check_iterators<typename std::vector<T>::const_iterator, typename ft::vector<T>::const_iterator>(or_begin_2, or_end_2, no_begin_2, no_end_2) ||
    !check_iterators<typename std::vector<T>::iterator, typename ft::vector<T>::iterator>(or_begin_5, or_end_5, no_begin_5, no_end_5) ||
    !check_iterators<typename std::vector<T>::const_iterator, typename ft::vector<T>::const_iterator>(or_begin_6, or_end_6, no_begin_6, no_end_6))
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool vector_check_rbegin(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! vector_check_rbegin \n";

    os << "\nvector #1 orig_1 noorig_1 \n";
    std::vector<T> orig_1(7, data_1);
    ft::vector<T> noorig_1(7, data_1);
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nvector #2 orig_2 noorig_2 \n";
    std::vector<T> orig_2(4, data_2);
    ft::vector<T> noorig_2(4, data_2);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    typename std::vector<T>::reverse_iterator or_begin_3 = orig_1.rbegin();
    typename std::vector<T>::reverse_iterator or_end_3 = orig_1.rend();
    typename ft::vector<T>::reverse_iterator no_begin_3 = noorig_1.rbegin();
    typename ft::vector<T>::reverse_iterator no_end_3 = noorig_1.rend();

    typename std::vector<T>::const_reverse_iterator or_begin_4 = orig_1.rbegin();
    typename std::vector<T>::const_reverse_iterator or_end_4 = orig_1.rend();
    typename ft::vector<T>::const_reverse_iterator no_begin_4 = noorig_1.rbegin();
    typename ft::vector<T>::const_reverse_iterator no_end_4 = noorig_1.rend();

    typename std::vector<T>::reverse_iterator or_begin_7 = orig_2.rbegin();
    typename std::vector<T>::reverse_iterator or_end_7 = orig_2.rend();
    typename ft::vector<T>::reverse_iterator no_begin_7 = noorig_2.rbegin();
    typename ft::vector<T>::reverse_iterator no_end_7 = noorig_2.rend();

    typename std::vector<T>::const_reverse_iterator or_begin_8 = orig_2.rbegin();
    typename std::vector<T>::const_reverse_iterator or_end_8 = orig_2.rend();
    typename ft::vector<T>::const_reverse_iterator no_begin_8 = noorig_2.rbegin();
    typename ft::vector<T>::const_reverse_iterator no_end_8 = noorig_2.rend();

    if (!check_iterators<typename std::vector<T>::reverse_iterator, typename ft::vector<T>::reverse_iterator>(or_begin_3, or_end_3, no_begin_3, no_end_3) ||
    !check_iterators<typename std::vector<T>::const_reverse_iterator, typename ft::vector<T>::const_reverse_iterator>(or_begin_4, or_end_4, no_begin_4, no_end_4) ||
    !check_iterators<typename std::vector<T>::reverse_iterator, typename ft::vector<T>::reverse_iterator>(or_begin_7, or_end_7, no_begin_7, no_end_7) ||
    !check_iterators<typename std::vector<T>::const_reverse_iterator, typename ft::vector<T>::const_reverse_iterator>(or_begin_8, or_end_8, no_begin_8, no_end_8))
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool vector_check_empty(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! vector_check_empty \n";

    os << "\nvector #1 orig_1 noorig_1 \n";
    std::vector<T> orig_1;
    ft::vector<T> noorig_1;
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
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

    os << "\nvector #1 orig_1 noorig_1 \n";
    orig_1.assign(5, data_1);
    noorig_1.assign(5, data_1);
    print_vector(os, orig_1, noorig_1);
    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_1, noorig_1))
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

    os << "\nvector #2 orig_2 noorig_2 \n";
    std::vector<T> orig_2;
    ft::vector<T> noorig_2;
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
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

    os << "\nvector #2 orig_2 noorig_2 \n";
    orig_2.assign(5, data_2);
    noorig_2.assign(5, data_2);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig_2, noorig_2))
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
void runner_cor_vec(std::ofstream *out, T (*f)())
{
    std::cout << YELLOW << "\n[check constructor]: \t" << ((vector_check_constructor<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check operator=]: \t" << ((vector_check_operator<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check begin(end)]: \t" << ((vector_check_begin<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check rbegin(rend)]: \t" << ((vector_check_rbegin<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check empty]: \t\t" << ((vector_check_empty<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << RESET;
}

template<typename T>
void vector_start(std::ofstream *out)
{
    if (typeid(T) == typeid(int))
    {
        runner_cor_vec<int>(out, gen_int);
    }
    else if (typeid(T) == typeid(char))
    {
        runner_cor_vec<char>(out, gen_char);
    }
    else if (typeid(T) == typeid(double))
    {
        runner_cor_vec<double>(out, gen_dd);
    }
    else if (typeid(T) == typeid(float))
    {
        runner_cor_vec<float>(out, gen_ff);
    }
    else if (typeid(T) == typeid(std::string))
    {
        runner_cor_vec<std::string>(out, gen_str);
    }
}
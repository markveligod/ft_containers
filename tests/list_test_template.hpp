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
bool list_check_constructor(std::ofstream *out)
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

    *out << os.str();
    return (true);
}

template<typename T>
void list_start(std::ofstream *out)
{
    std::cout << YELLOW << "\n\n[check constructor]: " << ((list_check_constructor<T>(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    
}
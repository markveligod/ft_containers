#include <iostream>
#include <cstdio>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>
#include "List/List.hpp"

/*
**==========================
**         Colors
**==========================
*/
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

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

bool list_check_main(std::ofstream *out)
{
    std::stringstream os;
    os << "\nCHECK MAIN!!!\n";
    os << "\nCreaty constructor empty\n";
    std::list<int> orig_1;
    ft::list<int> noorig_1;

    print_size(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    
    os << "\nCreaty constructor with orig_2(4, 21) and noorig_2(4, 21)\n";
    std::list<int> orig_2(4, 21);
    ft::list<int> noorig_2(4, 21);

    print_size(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    print_list(os, orig_2, noorig_2);
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }
    
    os << "\nCreaty constructor copy orig_3(orig_2) and noorig_3(noorig_2)\n";
    std::list<int> orig_3(orig_2);
    ft::list<int> noorig_3(noorig_2);
    print_size(os, orig_3, noorig_3);
    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    print_list(os, orig_3, noorig_3);
    if (!check_list(orig_3, noorig_3))
    {
        *out << os.str();
        return (false);
    }
    
    os << "\nCreaty constructor in iterator\n";
    std::list<int>::iterator or_begin = orig_3.begin();
    std::list<int>::iterator or_end = orig_3.end();
    ft::list<int>::iterator no_begin = noorig_3.begin();
    ft::list<int>::iterator no_end = noorig_3.end();
    std::list<int> orig_4(or_begin, or_end);
    ft::list<int> noorig_4(no_begin, no_end);
    print_size(os, orig_4, noorig_4);
    if (orig_4.size() != noorig_4.size())
    {
        *out << os.str();
        return (false);
    }
    print_list(os, orig_4, noorig_4);
    if (!check_list(orig_4, noorig_4))
    {
        *out << os.str();
        return (false);
    }
    *out << os.str();
    return (true);
}

bool list_check_iterator(std::ofstream *out)
{
    std::stringstream os;

    os << "\nCHECK ITERATOR!!!\n";
    os << "\nTest iterator\n";
    std::list<int> orig(40, 42);
    ft::list<int> noorig(40, 42);
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

bool list_check_capacity(std::ofstream *out)
{
    std::stringstream os;

    os << "\nCHECK capacity!!!\n";
    os << "\nTest empty\n";
    std::list<int> orig;
    ft::list<int> noorig;
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.empty() << std::endl;
    os << "[No Or]: \t" << noorig.empty() << std::endl;
    if (orig.empty() != noorig.empty())
    {
        *out << os.str();
        return (false);
    }

    for (size_t i = 0; i < 8; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.empty() << std::endl;
    os << "[No Or]: \t" << noorig.empty() << std::endl;
    if (orig.empty() != noorig.empty())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest max_size\n";
    os << "[Or]: \t" << orig.max_size() << std::endl;
    os << "[No Or]: \t" << noorig.max_size() << std::endl;
    if (orig.max_size() != noorig.max_size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest size\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    
    orig.clear();
    noorig.clear();
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool list_check_elaccess(std::ofstream *out)
{
    std::stringstream os;

    os << "\nCHECK Element access!!!\n";
    os << "\nTest front\n";
    std::list<int> orig;
    ft::list<int> noorig;
    for (size_t i = 0; i < 8; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.front() << std::endl;
    os << "[No Or]: \t" << noorig.front() << std::endl;
    if (orig.front() != noorig.front())
    {
        *out << os.str();
        return (false);
    }
    orig.clear();
    noorig.clear();
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.front() << std::endl;
    os << "[No Or]: \t" << noorig.front() << std::endl;
    if (orig.front() != noorig.front())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest back\n";
    for (size_t i = 0; i < 8; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.back() << std::endl;
    os << "[No Or]: \t" << noorig.back() << std::endl;
    if (orig.back() != noorig.back())
    {
        *out << os.str();
        return (false);
    }

    orig.clear();
    noorig.clear();
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.back() << std::endl;
    os << "[No Or]: \t" << noorig.back() << std::endl;
    if (orig.back() != noorig.back())
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

void list_start()
{
    std::ofstream out;
    std::cout <<  "\033c";
    out.open("log_list", std::ios::trunc);
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "\n\n[check main(Constructor, destructor, operator=)]: " << (list_check_main(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check iterator(begin end rbegin rend)]: " << (list_check_iterator(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check capacity(size empty max_size)]: " << (list_check_capacity(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Element access(front back)]: " << (list_check_elaccess(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    out.close();
    std::cout << CYAN << "\n\tCheck log_list\n\n" << RESET;
    getchar();
    getchar();
}

int main()
{
    int num;
    srand(time(NULL));
    while (true)
    {
        std::cout <<  "\033c";
        std::cout << YELLOW << "\n\nThis tests aim on testing the project of name \"ft_containers\" \n" << RESET;
        std::cout << RED << "Progress status will be displayed on the screen and the result will be recorded in a " << CYAN << "LOG" << RED << " file!!!\n" << RESET;
        std::cout << CYAN << "1. " << RESET << "List\n";
        std::cout << CYAN << "0. " << RESET << "Exit\n";
        std::cout << YELLOW << "Choice a number: " << RESET;
        std::cin >> num;
        switch (num)
        {
        case 1:
            list_start();
            break;
        case 0:
            return (0);
        }
    }
    return (0);
}
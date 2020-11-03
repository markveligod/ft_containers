#include <iostream>
#include <algorithm>
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
void print(T data)
{
    std::cout << data << " ";
}

void test_list_example_1()
{
    std::list<int> ex_original;
    ft::List<int> ex_nooriginal;
    
    //push_back()
    std::cout << YELLOW << "\nTesting" << GREEN << " push_back()" << RESET << std::endl;
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 100;
        ex_original.push_back(temp);
        ex_nooriginal.push_back(temp);
    }
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;
    
    //push_front()
    std::cout << YELLOW << "\nTesting" << GREEN << " push_front()" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
    {
        int temp = rand() % 100;
        ex_original.push_front(temp);
        ex_nooriginal.push_front(temp);
    }
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    //size()
    std::cout << YELLOW << "\nTesting" << GREEN << " size()" << RESET << std::endl;
    std::cout << YELLOW << "[Original]: \t" << CYAN << ex_original.size() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN << ex_nooriginal.size() << RESET << std::endl;

    //empty()
    std::cout << YELLOW << "\nTesting" << GREEN << " empty()" << RESET << std::endl;
    std::cout << YELLOW << "[Original]: \t" << ((ex_original.empty()) ? GREEN"TRUE" : RED"FALSE" ) << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << ((ex_nooriginal.empty()) ? GREEN"TRUE" : RED"FALSE" ) << RESET << std::endl;

    //pop_front()
    std::cout << YELLOW << "\nTesting" << GREEN << " pop_front()" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ex_original.pop_front();
        ex_nooriginal.pop_front();
    }
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    //pop_back()
    std::cout << YELLOW << "\nTesting" << GREEN << " pop_back()" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
    {
        ex_original.pop_back();
        ex_nooriginal.pop_back();
    }
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    //iterator
    std::cout << YELLOW << "\nTesting" << GREEN << " iterator" << RESET << std::endl;
    std::list<int>::iterator it_begin_1 = ex_original.begin();
    std::list<int>::iterator it_end_1 = ex_original.end();
    ft::List<int>::iterator it_begin_2 = ex_nooriginal.begin();
    ft::List<int>::iterator it_end_2 = ex_nooriginal.end();

    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(it_begin_1, it_end_1, print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(it_begin_2, it_end_2, print<int>);
    std::cout << RESET << std::endl;

    //const_iterator
    std::cout << YELLOW << "\nTesting" << GREEN << " const_iterator" << RESET << std::endl;
    std::list<int>::const_iterator it_begin_3 = ex_original.begin();
    std::list<int>::const_iterator it_end_3 = ex_original.end();
    ft::List<int>::const_iterator it_begin_4 = ex_nooriginal.begin();
    ft::List<int>::const_iterator it_end_4 = ex_nooriginal.end();

    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(it_begin_3, it_end_3, print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(it_begin_4, it_end_4, print<int>);
    std::cout << RESET << std::endl;

    //reverse_iterator
    std::cout << YELLOW << "\nTesting" << GREEN << " reverse_iterator" << RESET << std::endl;
    std::list<int>::reverse_iterator it_begin_5 = ex_original.rbegin();
    std::list<int>::reverse_iterator it_end_5 = ex_original.rend();
    ft::List<int>::reverse_iterator it_begin_6 = ex_nooriginal.rbegin();
    ft::List<int>::reverse_iterator it_end_6 = ex_nooriginal.rend();

    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(it_begin_5, it_end_5, print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(it_begin_6, it_end_6, print<int>);
    std::cout << RESET << std::endl;

    //const_reverse_iterator
    std::cout << YELLOW << "\nTesting" << GREEN << " const_reverse_iterator" << RESET << std::endl;
    std::list<int>::const_reverse_iterator it_begin_7 = ex_original.rbegin();
    std::list<int>::const_reverse_iterator it_end_7 = ex_original.rend();
    ft::List<int>::const_reverse_iterator it_begin_8 = ex_nooriginal.rbegin();
    ft::List<int>::const_reverse_iterator it_end_8 = ex_nooriginal.rend();

    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(it_begin_7, it_end_7, print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(it_begin_8, it_end_8, print<int>);
    std::cout << RESET << std::endl;

    //max_size()
    std::cout << YELLOW << "\nTesting" << GREEN << " max_size()" << RESET << std::endl;
    std::cout << YELLOW << "[Original]: \t" << CYAN << ex_original.max_size() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN << ex_nooriginal.max_size() << RESET << std::endl;

    //front()
    std::cout << YELLOW << "\nTesting" << GREEN << " front()" << RESET << std::endl;
    ex_original.front() -= ex_original.back();
    ex_nooriginal.front() -= ex_nooriginal.back();
    std::cout << YELLOW << "[Original]: \t" << CYAN << ex_original.front() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN << ex_nooriginal.front() << RESET << std::endl;

    //back()
    std::cout << YELLOW << "\nTesting" << GREEN << " back()" << RESET << std::endl;
    ex_original.back() += ex_original.front();
    ex_nooriginal.back() += ex_nooriginal.front();
    std::cout << YELLOW << "[Original]: \t" << CYAN << ex_original.back() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN << ex_nooriginal.back() << RESET << std::endl;

    //insert()
    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::list<int>::iterator it_1 = ex_original.begin();
    ++it_1;
    ft::List<int>::iterator it_2 = ex_nooriginal.begin();
    ++it_2;
    ex_original.insert(it_1, 1488228);
    ex_nooriginal.insert(it_2, 1488228);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::list<int>::iterator it_3 = ex_original.begin();
    ft::List<int>::iterator it_4 = ex_nooriginal.begin();
    ex_original.insert(it_3, 2281488);
    ex_nooriginal.insert(it_4, 2281488);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.rbegin(), ex_original.rend(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.rbegin(), ex_nooriginal.rend(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::list<int>::iterator it_5 = ex_original.begin();
    ft::List<int>::iterator it_6 = ex_nooriginal.begin();
    ex_original.insert(it_5, 4, 1488);
    ex_nooriginal.insert(it_6, 4, 1488);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.rbegin(), ex_original.rend(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.rbegin(), ex_nooriginal.rend(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::list<int>::iterator it_7 = ex_original.begin();
    ft::List<int>::iterator it_8 = ex_nooriginal.begin();
    ++it_7; ++it_7; ++it_7; ++it_7; ++it_7; ++it_7; ++it_7; ++it_7;
    ++it_8; ++it_8; ++it_8; ++it_8; ++it_8; ++it_8; ++it_8; ++it_8;
    ex_original.insert(it_7, 4, 1488);
    ex_nooriginal.insert(it_8, 4, 1488);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.rbegin(), ex_original.rend(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.rbegin(), ex_nooriginal.rend(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::list<int> temp_1; temp_1.push_back(20); temp_1.push_back(30); temp_1.push_back(40);
    ft::List<int> temp_2; temp_2.push_back(20); temp_2.push_back(30); temp_2.push_back(40);
    std::list<int>::iterator it_begin_temp_1 = temp_1.begin();
    std::list<int>::iterator it_end_temp_1 = temp_1.end();
    ft::List<int>::iterator it_begin_temp_2 = temp_2.begin();
    ft::List<int>::iterator it_end_temp_2 = temp_2.end();
    std::list<int>::iterator it_9 = ex_original.begin();
    ft::List<int>::iterator it_10 = ex_nooriginal.begin();
    ++it_9; ++it_9; ++it_9; ++it_9; ++it_9; ++it_9; ++it_9; ++it_9;
    ++it_10; ++it_10; ++it_10; ++it_10; ++it_10; ++it_10; ++it_10; ++it_10;
    ex_original.insert(it_9, it_begin_temp_1, it_end_temp_1);
    ex_nooriginal.insert(it_10, it_begin_temp_2, it_end_temp_2);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " insert()" << RESET << std::endl;
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.rbegin(), ex_original.rend(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.rbegin(), ex_nooriginal.rend(), print<int>);
    std::cout << RESET << std::endl;

}

void test_list_example_2()
{
    //constructor
    std::cout << YELLOW << "\nTesting" << GREEN << " constructor" << RESET << std::endl;
    std::list<int> ex_original(7, 228);
    ft::List<int> ex_nooriginal(7, 228);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(ex_original.begin(), ex_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(ex_nooriginal.begin(), ex_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[Original]: <size>\t" << CYAN << ex_original.size() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: <size>\t" << CYAN << ex_nooriginal.size() << RESET << std::endl;

    std::cout << YELLOW << "\nTesting" << GREEN << " constructor" << RESET << std::endl;
    std::list<int>::iterator it_begin_1 = ex_original.begin();
    std::list<int>::iterator it_end_1 = ex_original.end();
    ft::List<int>::iterator it_begin_2 = ex_nooriginal.begin();
    ft::List<int>::iterator it_end_2 = ex_nooriginal.end();
    std::list<int> test_original(it_begin_1, it_end_1);
    ft::List<int> test_nooriginal(it_begin_2, it_end_2);
    std::cout << YELLOW << "[Original]: \t" << CYAN;
    std::for_each(test_original.begin(), test_original.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: \t" << CYAN;
    std::for_each(test_nooriginal.begin(), test_nooriginal.end(), print<int>);
    std::cout << RESET << std::endl;
    std::cout << YELLOW << "[Original]: <size>\t" << CYAN << test_original.size() << RESET << std::endl;
    std::cout << YELLOW << "[NO Original]: <size>\t" << CYAN << test_nooriginal.size() << RESET << std::endl;

}

int main()
{
    srand(time(NULL));
    std::cout << RED << "|==========================|\n" << RESET;
    test_list_example_1();
    test_list_example_2();
    std::cout << RED << "|==========================|\n" << RESET;
    return (0);
}
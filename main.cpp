#include <iostream>

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


int main()
{
    srand(time(NULL));
    std::cout << RED << "|==========================|\n" << RESET;
    std::cout << YELLOW << "Testing " << GREEN << "list" << YELLOW << " with INT...\n" << RESET;
    ft::List<int> list_int;
    for (size_t i = 0; i < 10; i++)
        list_int.push_back(rand() % 100);
    std::cout << YELLOW << "[Size list]: " << CYAN << list_int.size() << std::endl;
    std::cout << YELLOW << "[Max Size list]: " << CYAN << list_int.max_size() << std::endl;
    std::cout << YELLOW << "[Empty]: " << ((list_int.empty()) ? GREEN"TRUE" : RED"FALSE" ) << std::endl;
    list_int.pop_front();
    std::cout << YELLOW << "[pop_front]: " << GREEN << "Done\n" << RESET;
    std::cout << YELLOW << "[Size list]: " << CYAN << list_int.size() << std::endl;
    list_int.pop_back();
    std::cout << YELLOW << "[pop_back]: " << GREEN << "Done\n" << RESET;
    std::cout << YELLOW << "[Size list]: " << CYAN << list_int.size() << std::endl;
    list_int.push_front(228);
    std::cout << YELLOW << "[push_front]: " << GREEN << "Done\n" << RESET;
    std::cout << YELLOW << "[Size list]: " << CYAN << list_int.size() << std::endl;
    
    ft::List<int>::iterator it_begin = list_int.begin();
    ft::List<int>::iterator it_end = list_int.end();
    std::cout << YELLOW << "[Array]: *simple* " << CYAN;
    while (it_begin != it_end)
    {
        std::cout << *it_begin << " ";
        ++it_begin;
    }
    std::cout << RESET << std::endl;

    ft::List<int>::iterator it_rbegin = list_int.rbegin();
    ft::List<int>::iterator it_rend = list_int.rend();
    std::cout << YELLOW << "[Array]: *reverse* " << CYAN;
    while (it_rbegin != it_rend)
    {
        std::cout << *it_rbegin << " ";
        --it_rbegin;
    }
    std::cout << RESET << std::endl;

    return (0);
}
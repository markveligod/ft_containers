#include <iostream>
#include "List.hpp"

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
    for (size_t i = 0; i < 30; i++)
        list_int.push_back(rand() % 100);
    std::cout << YELLOW << "[Size list]: " << CYAN << list_int.size() << std::endl;

    
    return (0);
}
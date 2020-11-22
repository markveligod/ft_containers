#include "./main.hpp"

void list_run()
{
    list_start<int>();
    
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
            list_run();
            break;
        case 0:
            return (0);
        }
    }
    return (0);
}
#include "./main.hpp"

void list_run()
{
    std::ofstream out;
    std::cout <<  "\033c";
    out.open("log_list", std::ios::trunc);
    out << "|========================================================================================================|\n";
    out << "|                                        Check list<int>                                                 |\n";
    out << "|========================================================================================================|\n";
    std::cout << std::endl << CYAN << "CHECK list" << YELLOW << "<int>" << RESET << std::endl;
    list_start<int>(&out);
    out << "|========================================================================================================|\n\n";

    out << "|========================================================================================================|\n";
    out << "|                                        Check list<char>                                                |\n";
    out << "|========================================================================================================|\n";
    std::cout << std::endl << CYAN << "CHECK list" << YELLOW << "<char>" << RESET << std::endl;
    list_start<char>(&out);
    out << "|========================================================================================================|\n\n";

    out << "|========================================================================================================|\n";
    out << "|                                        Check list<double>                                              |\n";
    out << "|========================================================================================================|\n";
    std::cout << std::endl << CYAN << "CHECK list" << YELLOW << "<double>" << RESET << std::endl;
    list_start<double>(&out);
    out << "|========================================================================================================|\n\n";

    out << "|========================================================================================================|\n";
    out << "|                                        Check list<float>                                               |\n";
    out << "|========================================================================================================|\n";
    std::cout << std::endl << CYAN << "CHECK list" << YELLOW << "<float>" << RESET << std::endl;
    list_start<float>(&out);
    out << "|========================================================================================================|\n\n";

    out << "|========================================================================================================|\n";
    out << "|                                        Check list<std::string>                                         |\n";
    out << "|========================================================================================================|\n";
    std::cout << std::endl << CYAN << "CHECK list" << YELLOW << "<std::string>" << RESET << std::endl;
    list_start<std::string>(&out);
    out << "|========================================================================================================|\n\n";

    out.close();
    std::cout << CYAN << "\n\tCheck log_list " << RESET;
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
            list_run();
            break;
        case 0:
            return (0);
        }
    }
    return (0);
}
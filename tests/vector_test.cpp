#include "../main.hpp"

template<typename T>
void print_vector(std::stringstream &os, std::vector<T> &orig, ft::vector<T> &no)
{
    os << "[Or]: \t";
    for (size_t i = 0; i < orig.size(); i++)
        os << orig[i] << " ";
    os << std::endl;
    os << "[No]: \t";
    for (size_t i = 0; i < no.size(); i++)
        os << no[i] << " ";
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
    for (size_t i = 0; i < no.size(); i++)
    {
        if (orig[i] != no[i])
            return (false);
    }
    return (true);
    
}

bool vector_check_main(std::ofstream *out)
{
    std::stringstream os;
    os << "\nCHECK MAIN!!!\n";
    os << "\nCreaty constructor empty\n";
    std::vector<int> orig;
    ft::vector<int> noorig;
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor (size_t count, T const &data)\n";
    std::vector<int> orig_2(14, 21);
    ft::vector<int> noorig_2(14, 21);
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

    os << "\nTest operator= (vector = vector)\n";
    orig = orig_2;
    noorig = noorig_2;
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_vector(orig, noorig))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true); 
}

void vector_start()
{
    std::ofstream out;
    std::cout <<  "\033c";
    out.open("log_vector", std::ios::trunc);
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "\n\n[check Main]: " << (vector_check_main(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    out.close();
    std::cout << CYAN << "\n\tCheck log_vector" << RESET;
    getchar();
    getchar();
}

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

    os << "\nTest constructor (iterator first, iterator last)\n";
    std::vector<int>::iterator or_begin = orig.begin();
    std::vector<int>::iterator or_end = orig.end();
    ft::vector<int>::iterator no_begin = noorig.begin();
    ft::vector<int>::iterator no_end = noorig.end();

    std::vector<int> orig_3(or_begin, or_end);
    ft::vector<int> noorig_3(no_begin, no_end);
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

    *out << os.str();
    return (true); 
}

bool vector_check_iterators(std::ofstream *out)
{
    std::stringstream os;
    os << "\nCHECK iterator!!!\n";
    std::vector<int> orig(7, 42);
    ft::vector<int> noorig(7, 42);
    for (size_t i = 0; i < 5; i++)
    {
        orig.push_back(21);
        noorig.push_back(21);
    }
    
    print_vector(os, orig, noorig);

    os << "\nCreaty iterator\n";
    std::vector<int>::iterator or_begin_1 = orig.begin();
    std::vector<int>::iterator or_end_1 = orig.end();
    ft::vector<int>::iterator no_begin_1 = noorig.begin();
    ft::vector<int>::iterator no_end_1 = noorig.end();

    os << "[Or]: ";
    for (; or_begin_1 != or_end_1; or_begin_1++)
        os << *or_begin_1 << " ";
    os << std::endl;

    os << "[No]: ";
    for (; no_begin_1 != no_end_1; no_begin_1++)
        os << *no_begin_1 << " ";
    os << std::endl;
    


    os << "\nCreaty const_iterator\n";

    std::vector<int>::const_iterator or_begin_2 = orig.begin();
    std::vector<int>::const_iterator or_end_2 = orig.end();
    ft::vector<int>::const_iterator no_begin_2 = noorig.begin();
    ft::vector<int>::const_iterator no_end_2 = noorig.end();

    os << "[Or]: ";
    for (; or_begin_2 != or_end_2; or_begin_2++)
        os << *or_begin_2 << " ";
    os << std::endl;

    os << "[No]: ";
    for (; no_begin_2 != no_end_2; no_begin_2++)
        os << *no_begin_2 << " ";
    os << std::endl;

    os << "\nCreaty reverse_iterator\n";

    std::vector<int>::reverse_iterator or_begin_3 = orig.rbegin();
    std::vector<int>::reverse_iterator or_end_3 = orig.rend();
    ft::vector<int>::reverse_iterator no_begin_3 = noorig.rbegin();
    ft::vector<int>::reverse_iterator no_end_3 = noorig.rend();

    os << "[Or]: ";
    for (; or_begin_3 != or_end_3; or_begin_3++)
        os << *or_begin_3 << " ";
    os << std::endl;

    os << "[No]: ";
    for (; no_begin_3 != no_end_3; no_begin_3++)
        os << *no_begin_3 << " ";
    os << std::endl;

    os << "\nCreaty const_reverse_iterator\n";

    std::vector<int>::const_reverse_iterator or_begin_4 = orig.rbegin();
    std::vector<int>::const_reverse_iterator or_end_4 = orig.rend();
    ft::vector<int>::const_reverse_iterator no_begin_4 = noorig.rbegin();
    ft::vector<int>::const_reverse_iterator no_end_4 = noorig.rend();

    os << "[Or]: ";
    for (; or_begin_4 != or_end_4; or_begin_4++)
        os << *or_begin_4 << " ";
    os << std::endl;

    os << "[No]: ";
    for (; no_begin_4 != no_end_4; no_begin_4++)
        os << *no_begin_4 << " ";
    os << std::endl;

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
    std::cout << YELLOW << "[check Iterators]: " << (vector_check_iterators(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    out.close();
    std::cout << CYAN << "\n\tCheck log_vector" << RESET;
    getchar();
    getchar();
}

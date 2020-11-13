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

bool vector_check_capacity(std::ofstream *out)
{
    std::stringstream os;
    std::vector<int> orig(7, 42);
    ft::vector<int> noorig(7, 42);

    os << "\nCHECK capacity!!!\n";
    for (size_t i = 0; i < 5; i++)
    {
        orig.push_back(21);
        noorig.push_back(21);
    }
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

    //empty
    os << "\nTest empty\n";
    os << "[Or] => " << orig.empty() << std::endl;
    os << "[No] => " << noorig.empty() << std::endl;
    if ((orig.empty()) != (noorig.empty()))
    {
        *out << os.str();
        return (false);
    }

    orig.clear();
    noorig.clear();
    os << "\nTest empty clear\n";
    os << "[Or] => " << orig.empty() << std::endl;
    os << "[No] => " << noorig.empty() << std::endl;
    if ((orig.empty()) != (noorig.empty()))
    {
        *out << os.str();
        return (false);
    }

    //size
    os << "\nTest size!!!\n";
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
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

    //max_size
    os << "\nTest max_size!!!\n";
    os << "[Or] => " << orig.max_size() << std::endl;
    os << "[No] => " << noorig.max_size() << std::endl;

    //resize
    os << "\nTest resize before!!!\n";
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);

    orig.resize(12);
    noorig.resize(12);
    os << "\nTest resize after (12)!!!\n";
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

    os << "\nTest resize after (5)!!!\n";
    orig.resize(5);
    noorig.resize(5);
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

    os << "\nTest resize after (50)!!!\n";
    orig.resize(50);
    noorig.resize(50);
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

    //capacity
    os << "\nTest capacity!!!\n";
    os << "[Or] => " << orig.capacity() << std::endl;
    os << "[No] => " << noorig.capacity() << std::endl;

    //reserve
    os << "\nTest reserve(10)!!!\n";
    orig.reserve(10);
    noorig.reserve(10);
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

    os << "\nTest reserve clear before!!!\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);

    orig.reserve(20);
    noorig.reserve(20);
    os << "\nTest reserve after(20)!!!\n";
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

    orig.reserve(120);
    noorig.reserve(120);
    os << "\nTest reserve after(120)!!!\n";
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

bool vector_check_access(std::ofstream *out)
{
    std::stringstream os;
    std::vector<int> orig;
    ft::vector<int> noorig;

    os << "\nCHECK Element access!!!\n";
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 1000;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);

    os << "\nTest front!!!\n";
    os << "[Or] => " << orig.front() << std::endl;
    os << "[No] => " << noorig.front() << std::endl;

    os << "\nTest back!!!\n";
    os << "[Or] => " << orig.back() << std::endl;
    os << "[No] => " << noorig.back() << std::endl;

    os << "\nTest operator[2]!!!\n";
    os << "[Or] => " << orig[2] << std::endl;
    os << "[No] => " << noorig[2] << std::endl;

    os << "\nTest operator[3]!!!\n";
    os << "[Or] => " << orig[3] << std::endl;
    os << "[No] => " << noorig[3] << std::endl;

    try
    {
        os << "\nTest [Or] at(100)!!!\n";
        os << "[Or] => " << orig.at(100) << std::endl;
    }
    catch(const std::exception& e)
    {
        os << "[Error]: " << e.what() << '\n';
    }

    try
    {
        os << "\nTest [No] at(100)!!!\n";
        os << "[No] => " << noorig.at(100) << std::endl;
    }
    catch(const std::exception& e)
    {
        os << "[Error]: " << e.what() << '\n';
    }

    *out << os.str();
    return (true); 
}

bool vector_check_modifiers(std::ofstream *out)
{
    std::stringstream os;
    std::vector<int> orig;
    ft::vector<int> noorig;

    os << "\nCHECK Modifiers!!!\n";

    //assign
    os << "\nTest assign(size_t count, const T &data)!!!\n";
    orig.assign(7, 100);
    noorig.assign(7, 100);
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

    std::vector<int> orig_2;
    ft::vector<int> noorig_2;
    std::vector<int>::iterator or_begin_1 = orig.begin();
    std::vector<int>::iterator or_end_1 = orig.end();
    ft::vector<int>::iterator no_begin_1 = noorig.begin();
    ft::vector<int>::iterator no_end_1 = noorig.end();

    os << "\nTest assign(iterator first, iterator last)!!!\n";
    orig_2.assign(++or_begin_1, --or_end_1);
    noorig_2.assign(++no_begin_1, --no_end_1);
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

    os << "\nTest assign(size_t count, const T &data)!!!\n";
    orig.assign(5, 21);
    noorig.assign(5, 21);
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

    os << "\nTest assign(iterator first, iterator last)!!!\n";
    orig_2.assign(++or_begin_1, --or_end_1);
    noorig_2.assign(++no_begin_1, --no_end_1);
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

    //clear
    os << "\nTest clear!!!\n";
    orig.clear();
    noorig.clear();
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

    //insert
    os << "\nTest insert(iterator position, const T &data)!!!\n";
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 1000;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    os << "\nTest insert before!!!\n";
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    std::vector<int>::iterator or_begin_2 = orig.begin();
    ft::vector<int>::iterator no_begin_2 = noorig.begin();

    orig.insert(++or_begin_2, 1488228);
    noorig.insert(++no_begin_2, 1488228);

    os << "\nTest insert after!!!\n";
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

    std::vector<int>::iterator or_end_2 = orig.end();
    ft::vector<int>::iterator no_end_2 = noorig.end();

    orig.insert(--or_end_2, 1488228);
    noorig.insert(--no_end_2, 1488228);

    os << "\nTest insert after!!!\n";
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

    os << "\nTest insert(iterator position, size_t count, const T &data)!!!\n";
    
    std::vector<int>::iterator or_end_3 = orig.end();
    ft::vector<int>::iterator no_end_3 = noorig.end();

    orig.insert(or_end_3, 22, 42);
    noorig.insert(no_end_3, 22, 42);

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

    os << "\nTest insert(iterator position, iterator first, iterator last)!!!\n";
    os << "\nTest before [Or][No]!!!\n";
    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    os << "\nTest before [Or_2][No_2]!!!\n";
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);

    std::vector<int>::iterator or_begin_4 = orig_2.begin();
    std::vector<int>::iterator or_end_4 = orig_2.end();
    ft::vector<int>::iterator no_begin_4 = noorig_2.begin();
    ft::vector<int>::iterator no_end_4 = noorig_2.end();

    orig.insert(++(orig.begin()), or_begin_4, or_end_4);
    noorig.insert(++(noorig.begin()), no_begin_4, no_end_4);

    os << "\nTest after!!!\n";
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

    //pop_back()
    os << "\nTest pop_back()!!!\n";
    os << "\nTest after!!!\n";
    orig.pop_back();
    noorig.pop_back();
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

    os << "\nTest after!!!\n";
    orig.pop_back();
    noorig.pop_back();
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

    os << "\nTest after!!!\n";
    orig.pop_back();
    noorig.pop_back();
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

    //push_back
    os << "\nTest push_back!!!\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 5; i++)
    {
        int temp = rand() % 10;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
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

    os << "\nTest push_back!!!\n";
    for (size_t i = 0; i < 45; i++)
    {
        int temp = rand() % 10;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
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

    os << "\nTest swap!!!\n";
    os << "\nTest before!!!\n";

    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();

    orig.assign(7, 42);
    noorig.assign(7, 42);
    orig_2.assign(7, 21);
    noorig_2.assign(7, 21);

    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);

    os << "\nTest after!!!\n";

    orig.swap(orig_2);
    noorig.swap(noorig_2);

    print_vector(os, orig, noorig);
    print_size(os, orig, noorig);
    print_vector(os, orig_2, noorig_2);
    print_size(os, orig_2, noorig_2);

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
    std::cout << YELLOW << "[check Capacity]: " << (vector_check_capacity(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Element access]: " << (vector_check_access(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Modifiers]: " << (vector_check_modifiers(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    out.close();
    std::cout << CYAN << "\n\tCheck log_vector" << RESET;
    getchar();
    getchar();
}

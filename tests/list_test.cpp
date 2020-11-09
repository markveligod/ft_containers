#include "../main.hpp"

bool compare(int i, int j) {return (i > j);}

bool predict(int i) {return (i == 1448228);}

bool binarypredicate(int i, int j) {return (i == j);}

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

bool list_check_modifiers(std::ofstream *out)
{
    std::stringstream os;
    os << "\nCHECK Modifiers!!!\n";
    os << "\nTest assign I\n";
    std::list<int> orig;
    ft::list<int> noorig;

    //assign

    orig.assign(7, 100);
    noorig.assign((size_t)7, 100);

    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    std::list<int> orig_2(14, 42);
    ft::list<int> noorig_2(14, 42);
    os << "\nTest assign II before\n";
    print_list(os, orig_2, noorig_2);
    orig_2.assign(orig.begin(), orig.end());
    noorig_2.assign(noorig.begin(), noorig.end());
    os << "\nTest assign II after\n";
    print_list(os, orig_2, noorig_2);
    if (!check_list(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    //push_back

    os << "\nTest push_back and pop_back\n";
    orig.clear();
    noorig.clear();
    os << "\nTest push_back before\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    for (size_t i = 0; i < 27; i++)
    {
        int temp = rand() % 100;
        orig.push_back(temp);
        noorig.push_back(temp);
    }
    os << "\nTest push_back after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //pop_back

    os << "\nTest pop_back \n";
    for (size_t i = 0; i < 17; i++)
    {
        orig.pop_back();
        noorig.pop_back();
    }
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //pop_front

    os << "\nTest push_front and pop_front\n";
    orig.clear();
    noorig.clear();
    os << "\nTest push_front before\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    for (size_t i = 0; i < 27; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest push_front after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest pop_front \n";
    for (size_t i = 0; i < 17; i++)
    {
        orig.pop_front();
        noorig.pop_front();
    }
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //resize

    os << "\nTest resize BIG with Number\n";
    orig.resize(20, 42);
    noorig.resize(20, 42);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest resize SMALL\n";
    orig.resize(5, 42);
    noorig.resize(5, 42);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest resize BIG without Number\n";
    orig.resize(20);
    noorig.resize(20);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //insert

    os << "\nTest insert (iterator position, const T& data)\n";
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    std::list<int>::iterator it_or_begin = orig.begin();
    std::list<int>::iterator it_or_end = orig.end();
    ft::list<int>::iterator it_no_begin = noorig.begin();
    ft::list<int>::iterator it_no_end = noorig.end();
    ++it_or_begin;
    ++it_no_begin;
    orig.insert(it_or_begin, 1448228);
    noorig.insert(it_no_begin, 1448228);
    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    --it_or_begin; --it_or_begin;
    --it_no_begin; --it_no_begin;
    orig.insert(it_or_begin, 1448228);
    noorig.insert(it_no_begin, 1448228);
    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    orig.insert(it_or_end, 1448228);
    noorig.insert(it_no_end, 1448228);
    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest insert (iterator position, size_t n, const T& data)\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 27; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    it_or_begin = orig.begin();
    it_or_end = orig.end();
    it_no_begin = noorig.begin();
    it_no_end = noorig.end();
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    orig.insert(it_or_begin, 4, 1448228);
    noorig.insert(it_no_begin, 4, 1448228);
    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest after\n";
    orig.insert(it_or_end, 4, 1448228);
    noorig.insert(it_no_end, 4, 1448228);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest after\n";
    ++it_or_begin; ++it_or_begin; ++it_or_begin; ++it_or_begin; ++it_or_begin;
    ++it_no_begin; ++it_no_begin; ++it_no_begin; ++it_no_begin; ++it_no_begin;

    orig.insert(it_or_begin, 4, 1448228);
    noorig.insert(it_no_begin, 4, 1448228);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest insert (iterator position, iterator first, iterator last)\n";
    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest insert before I\n";
    print_list(os, orig, noorig);
    for (size_t i = 0; i < 7; i++)
    {
        orig_2.push_front(42);
        noorig_2.push_front(42);
    }

    os << "\nTest insert before II\n";
    print_list(os, orig_2, noorig_2);
    std::list<int>::iterator or_begin = orig_2.begin();
    std::list<int>::iterator or_end = orig_2.end();
    ft::list<int>::iterator no_begin = noorig_2.begin();
    ft::list<int>::iterator no_end = noorig_2.end();
    it_or_begin = orig.begin();
    it_or_end = orig.end();
    it_no_begin = noorig.begin();
    it_no_end = noorig.end();

    os << "\nTest after with END\n";
    orig.insert(it_or_end, or_begin, or_end);
    noorig.insert(it_no_end, no_begin, no_end);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest after with BEGIN\n";
    orig.insert(it_or_begin, or_begin, or_end);
    noorig.insert(it_no_begin, no_begin, no_end);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    ++it_or_begin; ++it_or_begin; ++it_or_begin; ++it_or_begin; ++it_or_begin;
    ++it_no_begin; ++it_no_begin; ++it_no_begin; ++it_no_begin; ++it_no_begin;

    os << "\nTest after with MID\n";
    orig.insert(it_or_begin, or_begin, or_end);
    noorig.insert(it_no_begin, no_begin, no_end);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //erase

    os << "\nTest erase (iterator position)\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    it_or_begin = orig.begin();
    it_or_end = orig.end();
    it_no_begin = noorig.begin();
    it_no_end = noorig.end();

    os << "\nTest after with BEGIN\n";
    orig.erase(it_or_begin);
    noorig.erase(it_no_begin);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest after with END\n";
    orig.erase(--it_or_end);
    noorig.erase(--it_no_end);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest after with MID\n";
    it_or_begin = orig.begin();
    it_no_begin = noorig.begin();
    ++it_or_begin; ++it_or_begin;
    ++it_no_begin; ++it_no_begin;
    orig.erase(it_or_begin);
    noorig.erase(it_no_begin);
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest erase (iterator first, iterator last)\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    it_or_begin = orig.begin();
    it_or_end = orig.end();
    it_no_begin = noorig.begin();
    it_no_end = noorig.end();

    ++it_or_begin; ++it_or_begin;
    ++it_no_begin; ++it_no_begin;

    orig.erase(it_or_begin, --it_or_end);
    noorig.erase(it_no_begin, --it_no_end);

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    it_or_begin = orig.begin();
    it_or_end = orig.end();
    it_no_begin = noorig.begin();
    it_no_end = noorig.end();

    orig.erase(it_or_begin, it_or_end);
    noorig.erase(it_no_begin, it_no_end);

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //swap

    os << "\nTest swap(list &other)\n";
    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    print_list(os, orig_2, noorig_2);
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;

    orig_2.swap(orig);
    noorig_2.swap(noorig);

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool list_check_operations(std::ofstream *out)
{
    std::stringstream os;
    std::list<int> orig;
    ft::list<int> noorig;
    std::list<int> orig_2(4, 21);
    ft::list<int> noorig_2(4, 21);

    os << "\nCHECK Operations!!!\n";
    //splice
    os << "\nTest splice (iterator position, list<T> &other)\n";
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    print_list(os, orig_2, noorig_2);
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;

    orig.splice(orig.begin(), orig_2);
    noorig.splice(noorig.begin(), noorig_2);

    os << "\nTest after with BEGIN\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    orig_2.insert(orig_2.begin(), 4, 42);
    noorig_2.insert(noorig_2.begin(), 4, 42);

    orig.splice(--(orig.end()), orig_2);
    noorig.splice(--(noorig.end()), noorig_2);

    os << "\nTest after with MID\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    orig_2.insert(orig_2.begin(), 4, 1448228);
    noorig_2.insert(noorig_2.begin(), 4, 1448228);

    orig.splice(orig.end(), orig_2);
    noorig.splice(noorig.end(), noorig_2);

    os << "\nTest after with END\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest splice (iterator position, list<T> &other, iterator i)\n";
    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();

    orig.insert(orig.begin(), 4, 1448228);
    noorig.insert(noorig.begin(), 4, 1448228);
    orig_2.insert(orig_2.begin(), 4, 42);
    noorig_2.insert(noorig_2.begin(), 4, 42);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    print_list(os, orig_2, noorig_2);
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;

    orig.splice(orig.begin(), orig_2, orig_2.begin());
    noorig.splice(noorig.begin(), noorig_2, noorig_2.begin());

    os << "\nTest after with BEGIN\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    orig.splice(--(orig.end()), orig_2, --(orig_2.end()));
    noorig.splice(--(noorig.end()), noorig_2, --(noorig_2.end()));

    os << "\nTest after with MID\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    orig.splice(orig.end(), orig_2, orig_2.begin());
    noorig.splice(noorig.end(), noorig_2, noorig_2.begin());

    os << "\nTest after with END\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest splice (iterator position, size_t n, const T& data)\n";
    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();

    orig.insert(orig.begin(), 4, 1448228);
    noorig.insert(noorig.begin(), 4, 1448228);
    orig_2.insert(orig_2.begin(), 4, 42);
    noorig_2.insert(noorig_2.begin(), 4, 42);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    print_list(os, orig_2, noorig_2);
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;

    orig.splice(orig.begin(), orig_2, orig_2.begin(), orig_2.end());
    noorig.splice(noorig.begin(), noorig_2, noorig_2.begin(), noorig_2.end());

    os << "\nTest after with BEGIN\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    orig_2.insert(orig_2.begin(), 4, 21);
    noorig_2.insert(noorig_2.begin(), 4, 21);

    orig.splice(--(orig.end()), orig_2, orig_2.begin(), orig_2.end());
    noorig.splice(--(noorig.end()), noorig_2, noorig_2.begin(), noorig_2.end());

    os << "\nTest after with MID\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    orig_2.insert(orig_2.begin(), 4, 0);
    noorig_2.insert(noorig_2.begin(), 4, 0);

    orig.splice(orig.end(), orig_2, orig_2.begin(), orig_2.end());
    noorig.splice(noorig.end(), noorig_2, noorig_2.begin(), noorig_2.end());

    os << "\nTest after with END\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //remove
    os << "\nTest remove\n";
    orig.clear();
    noorig.clear();

    orig.insert(orig.begin(), 4, 1448228);
    noorig.insert(noorig.begin(), 4, 1448228);
    orig.insert(orig.begin(), 4, 42);
    noorig.insert(noorig.begin(), 4, 42);
    orig.insert(orig.begin(), 4, 21);
    noorig.insert(noorig.begin(), 4, 21);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.remove(1448228);
    noorig.remove(1448228);

    os << "\nTest after with 1448228\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    orig.remove(42);
    noorig.remove(42);

    os << "\nTest after with 42\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //remove_if
    os << "\nTest remove_if\n";
    orig.clear();
    noorig.clear();

    orig.insert(orig.begin(), 4, 1448228);
    noorig.insert(noorig.begin(), 4, 1448228);
    orig.insert(orig.begin(), 4, 42);
    noorig.insert(noorig.begin(), 4, 42);
    orig.insert(orig.begin(), 4, 21);
    noorig.insert(noorig.begin(), 4, 21);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.remove_if(predict);
    noorig.remove_if(predict);

    os << "\nTest after with predict function (1448228)\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    //unique
    os << "\nTest unique\n";
    orig.clear();
    noorig.clear();

    orig.insert(orig.begin(), 5, 1448228);
    noorig.insert(noorig.begin(), 5, 1448228);
    orig.insert(orig.begin(), 5, 42);
    noorig.insert(noorig.begin(), 5, 42);
    orig.insert(orig.begin(), 5, 21);
    noorig.insert(noorig.begin(), 5, 21);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.unique();
    noorig.unique();

    os << "\nTest after without binarypredict function\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    orig.insert(orig.begin(), 5, 1448228);
    noorig.insert(noorig.begin(), 5, 1448228);
    orig.insert(orig.begin(), 5, 42);
    noorig.insert(noorig.begin(), 5, 42);
    orig.insert(orig.begin(), 5, 21);
    noorig.insert(noorig.begin(), 5, 21);

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.unique(binarypredicate);
    noorig.unique(binarypredicate);

    os << "\nTest after with binarypredict function\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }


    //sort
    os << "\nTest sort\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.sort();
    noorig.sort();

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest sort with compare function\n";
    orig.clear();
    noorig.clear();
    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }
    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig.sort(compare);
    noorig.sort(compare);

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }



    //merge
    os << "\nTest merge\n";
    orig.clear();
    noorig.clear();
    orig_2.clear();
    noorig_2.clear();

    for (size_t i = 0; i < 7; i++)
    {
        int temp = rand() % 100;
        orig.push_front(temp);
        noorig.push_front(temp);
    }

    os << "\nTest before\n";
    print_list(os, orig, noorig);
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;

    orig_2.insert(orig_2.begin(), 5, 1448228);
    noorig_2.insert(noorig_2.begin(), 5, 1448228);
    orig_2.insert(orig_2.begin(), 5, 42);
    noorig_2.insert(noorig_2.begin(), 5, 42);
    orig_2.insert(orig_2.begin(), 5, 21);
    noorig_2.insert(noorig_2.begin(), 5, 21);

    print_list(os, orig_2, noorig_2);
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;

    orig.sort();
    noorig.sort();
    orig_2.sort();
    noorig_2.sort();

    orig.merge(orig_2);
    noorig.merge(noorig_2);

    os << "\nTest after\n";
    print_list(os, orig, noorig);
    if (!check_list(orig, noorig))
    {
        *out << os.str();
        return (false);
    }
    os << "[Or]: \t" << orig.size() << std::endl;
    os << "[No Or]: \t" << noorig.size() << std::endl;
    if (orig.size() != noorig.size())
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
    os << "[Or]: \t" << orig_2.size() << std::endl;
    os << "[No Or]: \t" << noorig_2.size() << std::endl;
    if (orig_2.size() != noorig_2.size())
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
    std::cout << YELLOW << "\n\n[check Main]: " << (list_check_main(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Iterator]: " << (list_check_iterator(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Capacity]: " << (list_check_capacity(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Element access]: " << (list_check_elaccess(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Modifiers]: " << (list_check_modifiers(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    std::cout << YELLOW << "[check Operations]: " << (list_check_operations(&out) ? GREEN"OK" : RED"FAIL") << std::endl;
    out << "|========================================================================================================|\n";
    out.close();
    std::cout << CYAN << "\n\tCheck log_list" << RESET;
    getchar();
    getchar();
}

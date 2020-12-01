#pragma once

#include "../main.hpp"

void print_map(std::stringstream &os, std::map<int, std::string> &orig, ft::map<int, std::string> &no)
{
    std::map<int, std::string>::iterator or_begin = orig.begin();
    std::map<int, std::string>::iterator or_end = orig.end();
    ft::map<int, std::string>::iterator no_begin = no.begin();
    ft::map<int, std::string>::iterator no_end = no.end();

    os << "[Orig]: \t\n";
    while (or_begin != or_end)
    {
        os << or_begin->first << " = " << or_begin->second << std::endl;
        ++or_begin;
    }

    os << "[No orig]: \t\n";
    while (no_begin != no_end)
    {
        os << no_begin->first << " = " << no_begin->second << std::endl;
        ++no_begin;
    }

    std::map<int, std::string>::reverse_iterator or_rbegin = orig.rbegin();
    std::map<int, std::string>::reverse_iterator or_rend = orig.rend();
    ft::map<int, std::string>::reverse_iterator no_rbegin = no.rbegin();
    ft::map<int, std::string>::reverse_iterator no_rend = no.rend();

    os << "[R_Orig]: \t\n";
    while (or_rbegin != or_rend)
    {
        os << or_rbegin->first << " = " << or_rbegin->second << std::endl;
        ++or_rbegin;
    }

    os << "[No R_orig]: \t\n";
    while (no_rbegin != no_rend)
    {
        os << no_rbegin->first << " = " << no_rbegin->second << std::endl;
        ++no_rbegin;
    }
}

void print_size_map(std::stringstream &os, std::map<int, std::string> &orig, ft::map<int, std::string> &no)
{
    os << "Size orig: " << orig.size() << std::endl;
    os << "Size noorig: " << no.size() << std::endl;
}

bool check_map(std::map<int, std::string> &orig, ft::map<int, std::string> &no)
{
    std::map<int, std::string>::iterator or_begin = orig.begin();
    std::map<int, std::string>::iterator or_end = orig.end();
    ft::map<int, std::string>::iterator no_begin = no.begin();
    ft::map<int, std::string>::iterator no_end = no.end();

    while (or_begin != or_end && no_begin != no_end)
    {
        if (or_begin->first != no_begin->first || or_begin->second != no_begin->second)
            return (false);
        ++or_begin;
        ++no_begin;
    }
    if (no_begin != no_end)
        return (false);

    std::map<int, std::string>::reverse_iterator or_rbegin = orig.rbegin();
    std::map<int, std::string>::reverse_iterator or_rend = orig.rend();
    ft::map<int, std::string>::reverse_iterator no_rbegin = no.rbegin();
    ft::map<int, std::string>::reverse_iterator no_rend = no.rend();
    while (or_rbegin != or_rend && no_rbegin != no_rend)
    {
        if (or_rbegin->first != no_rbegin->first || or_rbegin->second != no_rbegin->second)
            return (false);
        ++or_rbegin;
        ++no_rbegin;
    }
    return (true);
}

bool map_check_constructor(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_constructor \n";
    os << "\nTest#1 Creaty constructor empty (orig_1 noorig_1)\n";

    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;

    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    std::map<int,std::string> first;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    ft::map<int,std::string> second;

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    os << "\nTest#2 Creaty constructor (iterator first, iterator last)\n";

    std::map<int, std::string> orig_2(first.begin(), first.end());
    ft::map<int, std::string> noorig_2(second.begin(), second.end());
    print_map(os, orig_2, noorig_2);
    print_size_map(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    std::map<int, std::string>::const_iterator or_begin = first.begin();
    std::map<int, std::string>::const_iterator or_end = first.end();
    ft::map<int, std::string>::const_iterator no_begin = second.begin();
    ft::map<int, std::string>::const_iterator no_end = second.end();

    os << "\nTest#3 Creaty constructor (const_iterator first, const_iterator last)\n";

    std::map<int, std::string> orig_3(or_begin, or_end);
    ft::map<int, std::string> noorig_3(no_begin, no_end);
    print_map(os, orig_3, noorig_3);
    print_size_map(os, orig_3, noorig_3);
    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_3, noorig_3))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#4 constructor (const map& x)\n";

    std::map<int, std::string> orig_4(first);
    ft::map<int, std::string> noorig_4(second);
    print_map(os, orig_4, noorig_4);
    print_size_map(os, orig_4, noorig_4);
    if (orig_4.size() != noorig_4.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_4, noorig_4))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_operator_equal(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_operator= \n";
    os << "\nCreaty map(orig_1 noorig_1)\n";
    std::map<int,std::string> first;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    ft::map<int,std::string> second;

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    os << "\nTest#1 operator=\n";
    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;

    orig_1 = first;
    noorig_1 = second;
    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 operator=\n";
    std::map<int, std::string> orig_2;
    ft::map<int, std::string> noorig_2;

    orig_2 = orig_1;
    noorig_2 = noorig_1;
    print_map(os, orig_2, noorig_2);
    print_size_map(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_iterator(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_iterator \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    ft::map<int,std::string> second;

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 iterator\n";
    std::map<int, std::string>::iterator or_begin_1 = first.begin();
    std::map<int, std::string>::iterator or_end_1 = first.end();
    ft::map<int, std::string>::iterator no_begin_1 = second.begin();
    ft::map<int, std::string>::iterator no_end_1 = second.end();
    
    os << "[Orig]: \t\n";
    while (or_begin_1 != or_end_1)
    {
        os << or_begin_1->first << " = " << or_begin_1->second << std::endl;
        ++or_begin_1;
    }

    os << "[No orig]: \t\n";
    while (no_begin_1 != no_end_1)
    {
        os << no_begin_1->first << " = " << no_begin_1->second << std::endl;
        ++no_begin_1;
    }

    os << "\nTest#2 const_iterator\n";
    std::map<int, std::string>::const_iterator or_begin_2 = first.begin();
    std::map<int, std::string>::const_iterator or_end_2 = first.end();
    ft::map<int, std::string>::const_iterator no_begin_2 = second.begin();
    ft::map<int, std::string>::const_iterator no_end_2 = second.end();
    os << "[Orig]: \t\n";
    while (or_begin_2 != or_end_2)
    {
        os << or_begin_2->first << " = " << or_begin_2->second << std::endl;
        ++or_begin_2;
    }

    os << "[No orig]: \t\n";
    while (no_begin_2 != no_end_2)
    {
        os << no_begin_2->first << " = " << no_begin_2->second << std::endl;
        ++no_begin_2;
    }

    os << "\nTest#3 reverse_iterator\n";
    std::map<int, std::string>::reverse_iterator or_begin_3 = first.rbegin();
    std::map<int, std::string>::reverse_iterator or_end_3 = first.rend();
    ft::map<int, std::string>::reverse_iterator no_begin_3 = second.rbegin();
    ft::map<int, std::string>::reverse_iterator no_end_3 = second.rend();
    os << "[Orig]: \t\n";
    while (or_begin_3 != or_end_3)
    {
        os << or_begin_3->first << " = " << or_begin_3->second << std::endl;
        ++or_begin_3;
    }

    os << "[No orig]: \t\n";
    while (no_begin_3 != no_end_3)
    {
        os << no_begin_3->first << " = " << no_begin_3->second << std::endl;
        ++no_begin_3;
    }

    os << "\nTest#4 const_reverse_iterator\n";
    std::map<int, std::string>::const_reverse_iterator or_begin_4 = first.rbegin();
    std::map<int, std::string>::const_reverse_iterator or_end_4 = first.rend();
    ft::map<int, std::string>::const_reverse_iterator no_begin_4 = second.rbegin();
    ft::map<int, std::string>::const_reverse_iterator no_end_4 = second.rend();
    os << "[Orig]: \t\n";
    while (or_begin_4 != or_end_4)
    {
        os << or_begin_4->first << " = " << or_begin_4->second << std::endl;
        ++or_begin_4;
    }

    os << "[No orig]: \t\n";
    while (no_begin_4 != no_end_4)
    {
        os << no_begin_4->first << " = " << no_begin_4->second << std::endl;
        ++no_begin_4;
    }

    *out << os.str();
    return (true);
}

bool map_check_empty(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_empty \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 empty map\n";
    os << "Empty orig: " << first.empty() << std::endl;
    os << "Empty noorig: " << second.empty() << std::endl;

    if ((first.empty()) != (second.empty()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 fill map\n";
    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "Empty orig: " << first.empty() << std::endl;
    os << "Empty noorig: " << second.empty() << std::endl;

    if ((first.empty()) != (second.empty()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_size(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_size \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 empty map\n";
    os << "size orig: " << first.size() << std::endl;
    os << "size noorig: " << second.size() << std::endl;

    if ((first.size()) != (second.size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 fill map\n";
    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "size orig: " << first.size() << std::endl;
    os << "size noorig: " << second.size() << std::endl;

    if ((first.size()) != (second.size()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_max_size(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_max_size \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 empty map\n";
    os << "max_size orig: " << first.max_size() << std::endl;
    os << "max_size noorig: " << second.max_size() << std::endl;

    if ((first.max_size()) != (second.max_size()))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 fill map\n";
    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "max_size orig: " << first.max_size() << std::endl;
    os << "max_size noorig: " << second.max_size() << std::endl;

    if ((first.max_size()) != (second.max_size()))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_operator_skobki(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_operator_skobki \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 operator[1]\n";
    os << "[1] orig: " << first[1] << std::endl;
    os << "[1] noorig: " << second[1] << std::endl;

    if ((first[1]) != (second[1]))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 operator[2]\n";
    os << "[2] orig: " << first[2] << std::endl;
    os << "[2] noorig: " << second[2] << std::endl;

    if ((first[2]) != (second[2]))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 operator[3]\n";
    os << "[3] orig: " << first[3] << std::endl;
    os << "[3] noorig: " << second[3] << std::endl;

    if ((first[3]) != (second[3]))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#4 operator[4]\n";
    os << "[4] orig: " << first[4] << std::endl;
    os << "[4] noorig: " << second[4] << std::endl;

    if ((first[4]) != (second[4]))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#6 operator[6]\n";
    os << "[6] orig: " << first[6] << std::endl;
    os << "[6] noorig: " << second[6] << std::endl;

    if ((first[6]) != (second[6]))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_insert(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_insert \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 (const value_type& val);\n";
    first.insert(std::pair<int, std::string>(228, "1448228"));
    second.insert(std::pair<int, std::string>(228, "1448228"));

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 (const value_type& val);\n";
    first.insert(std::pair<int, std::string>(22, "PiuPiu"));
    second.insert(std::pair<int, std::string>(22, "PiuPiu"));

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 (iterator position, const value_type& val)\n";
    first.insert(first.begin(), std::pair<int, std::string>(12, "Oh dawn dude!"));
    second.insert(second.begin(), std::pair<int, std::string>(12, "Oh dawn dude!"));

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#4 (InputIterator first, InputIterator last);\n";
    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;
    orig_1.insert(first.begin(), first.end());
    noorig_1.insert(second.begin(), second.end());

    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#5 (InputIterator first, InputIterator last);\n";
    std::map<int, std::string> orig_2;
    ft::map<int, std::string> noorig_2;
    orig_2.insert(orig_1.begin(), orig_1.end());
    noorig_2.insert(noorig_1.begin(), noorig_1.end());

    print_map(os, orig_2, noorig_2);
    print_size_map(os, orig_2, noorig_2);
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_2, noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_erase(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_erase \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 .begin() (iterator position)\n";
    first.erase(first.begin());
    second.erase(second.begin());

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 .begin() (iterator position)\n";
    first.erase(first.begin());
    second.erase(second.begin());

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 [7] (const key_type& k);\n";
    first.erase(7);
    second.erase(7);

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#4 [5] (const key_type& k);\n";
    first.erase(5);
    second.erase(5);

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#5 ++.begin() --.end() (iterator first, iterator last)\n";
    first.erase(++(first.begin()), --(first.end()));
    second.erase(++(second.begin()), --(second.end()));

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_swap(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_swap \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 swap orig_1(first) noorig_1(second)\n";
    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;

    orig_1.swap(first);
    noorig_1.swap(second);

    os << "\nTest#1 after swap first second\n";
    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 after swap orig_1 noorig_1\n";
    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_clear(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_clear \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 clear first second\n";
    first.clear();
    second.clear();

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_key_comp(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_key_comp \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;
    std::map<int,std::string>::key_compare comp_first = first.key_comp();
    ft::map<int,std::string>::key_compare comp_second = second.key_comp();

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }


    os << "\nTest#1\n";
    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;

    std::map<int, std::string>::iterator or_begin = ++(first.begin());
    std::map<int, std::string>::iterator or_end = --(first.end());
    ft::map<int, std::string>::iterator no_begin = ++(second.begin());
    ft::map<int, std::string>::iterator no_end = --(second.end());

    while (comp_first(or_begin->first, or_end->first))
    {
        orig_1.insert(std::pair<int, std::string>(or_begin->first, or_begin->second));
        ++or_begin;
    }

    while (comp_second(no_begin->first, no_end->first))
    {
        noorig_1.insert(std::pair<int, std::string>(no_begin->first, no_begin->second));
        ++no_begin;
    }

    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_value_comp(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_value_comp \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;
    std::map<int,std::string>::value_compare comp_first = first.value_comp();
    ft::map<int,std::string>::value_compare comp_second = second.value_comp();

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }


    os << "\nTest#1\n";
    std::map<int, std::string> orig_1;
    ft::map<int, std::string> noorig_1;

    std::map<int, std::string>::iterator or_begin = ++(first.begin());
    std::map<int, std::string>::iterator or_end = --(first.end());
    ft::map<int, std::string>::iterator no_begin = ++(second.begin());
    ft::map<int, std::string>::iterator no_end = --(second.end());

    while (comp_first(*or_begin, *or_end))
    {
        orig_1.insert(std::pair<int, std::string>(or_begin->first, or_begin->second));
        ++or_begin;
    }

    while (comp_second(*no_begin, *no_end))
    {
        noorig_1.insert(std::pair<int, std::string>(no_begin->first, no_begin->second));
        ++no_begin;
    }

    print_map(os, orig_1, noorig_1);
    print_size_map(os, orig_1, noorig_1);
    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(orig_1, noorig_1))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_find(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_find \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 find(2)\n";
    std::map<int, std::string>::const_iterator first_it = first.find(2);
    ft::map<int, std::string>::const_iterator second_it = second.find(2);

    os << "orig: " << first_it->first << " = " << first_it->second << std::endl;
    os << "noorig: " << second_it->first << " = " << second_it->second << std::endl;

    if (first_it->first != second_it->first || first_it->second != second_it->second)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 find(4)\n";
    first_it = first.find(4);
    second_it = second.find(4);

    os << "orig: " << first_it->first << " = " << first_it->second << std::endl;
    os << "noorig: " << second_it->first << " = " << second_it->second << std::endl;

    if (first_it->first != second_it->first || first_it->second != second_it->second)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 find(5)\n";
    first_it = first.find(5);
    second_it = second.find(5);

    os << "orig: " << first_it->first << " = " << first_it->second << std::endl;
    os << "noorig: " << second_it->first << " = " << second_it->second << std::endl;

    if (first_it->first != second_it->first || first_it->second != second_it->second)
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_count(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_count \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 count(1)\n";
    os << "Count orig: " << first.count(1) << std::endl;
    os << "Count noorig: " << second.count(1) << std::endl;

    if (first.count(1) != second.count(1))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 count(11)\n";
    os << "Count orig: " << first.count(11) << std::endl;
    os << "Count noorig: " << second.count(11) << std::endl;

    if (first.count(11) != second.count(11))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 count(8)\n";
    os << "Count orig: " << first.count(8) << std::endl;
    os << "Count noorig: " << second.count(8) << std::endl;

    if (first.count(8) != second.count(8))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#4 count(228)\n";
    first.insert(std::pair<int, std::string>(228, "1488228"));
    second.insert(std::pair<int, std::string>(228, "1488228"));
    os << "Count orig: " << first.count(228) << std::endl;
    os << "Count noorig: " << second.count(228) << std::endl;

    if (first.count(228) != second.count(228))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_lower_bound(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_lower_bound \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;
    std::map<int,std::string>::iterator first_it;
    ft::map<int,std::string>::iterator second_it;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 lower_bound(1)\n";
    first_it = first.lower_bound(1);
    second_it = second.lower_bound(1);
    os << "lower_bound orig: " << first_it->first << std::endl;
    os << "lower_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 lower_bound(2)\n";
    first_it = first.lower_bound(2);
    second_it = second.lower_bound(2);
    os << "lower_bound orig: " << first_it->first << std::endl;
    os << "lower_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 lower_bound(7)\n";
    first_it = first.lower_bound(7);
    second_it = second.lower_bound(7);
    os << "lower_bound orig: " << first_it->first << std::endl;
    os << "lower_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_upper_bound(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_upper_bound \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;
    std::map<int,std::string>::iterator first_it;
    ft::map<int,std::string>::iterator second_it;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 upper_bound(1)\n";
    first_it = first.upper_bound(1);
    second_it = second.upper_bound(1);
    os << "upper_bound orig: " << first_it->first << std::endl;
    os << "upper_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 upper_bound(2)\n";
    first_it = first.upper_bound(2);
    second_it = second.upper_bound(2);
    os << "upper_bound orig: " << first_it->first << std::endl;
    os << "upper_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 upper_bound(7)\n";
    first_it = first.upper_bound(7);
    second_it = second.upper_bound(7);
    os << "upper_bound orig: " << first_it->first << std::endl;
    os << "upper_bound noorig: " << second_it->first << std::endl;

    if (first_it->first != second_it->first)
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

bool map_check_equal_range(std::ofstream *out)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! map_check_equal_range \n";
    os << "\nCreaty map(first second)\n";
    std::map<int,std::string> first;
    ft::map<int,std::string> second;
    std::pair<std::map<int,std::string>::const_iterator, std::map<int,std::string>::const_iterator> first_it;
   std::pair<ft::map<int,std::string>::const_iterator, ft::map<int,std::string>::const_iterator> second_it;

    first[1]="10";
    first[2]="30";
    first[3]="50";
    first[4]="70";
    first[5]="101";
    first[6]="301";
    first[7]="501";
    first[8]="701";

    second[1]="10";
    second[2]="30";
    second[3]="50";
    second[4]="70";
    second[5]="101";
    second[6]="301";
    second[7]="501";
    second[8]="701";

    print_map(os, first, second);
    print_size_map(os, first, second);
    if (first.size() != second.size())
    {
        *out << os.str();
        return (false);
    }
    if (!check_map(first, second))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#1 equal_range(1)\n";
    first_it = first.equal_range(1);
    second_it = second.equal_range(1);
    os << "lower_bound orig: " << first_it.first->first << std::endl;
    os << "lower_bound noorig: " << second_it.first->first << std::endl;
    os << "upper_bound orig: " << first_it.second->first << std::endl;
    os << "upper_bound noorig: " << second_it.second->first << std::endl;
    if ((first_it.first->first != second_it.first->first) || (first_it.second->first != second_it.second->first))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#2 equal_range(2)\n";
    first_it = first.equal_range(2);
    second_it = second.equal_range(2);
    os << "lower_bound orig: " << first_it.first->first << std::endl;
    os << "lower_bound noorig: " << second_it.first->first << std::endl;
    os << "upper_bound orig: " << first_it.second->first << std::endl;
    os << "upper_bound noorig: " << second_it.second->first << std::endl;
    if ((first_it.first->first != second_it.first->first) || (first_it.second->first != second_it.second->first))
    {
        *out << os.str();
        return (false);
    }

    os << "\nTest#3 equal_range(7)\n";
    first_it = first.equal_range(7);
    second_it = second.equal_range(7);
    os << "lower_bound orig: " << first_it.first->first << std::endl;
    os << "lower_bound noorig: " << second_it.first->first << std::endl;
    os << "upper_bound orig: " << first_it.second->first << std::endl;
    os << "upper_bound noorig: " << second_it.second->first << std::endl;
    if ((first_it.first->first != second_it.first->first) || (first_it.second->first != second_it.second->first))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

void map_start(std::ofstream *out)
{
    std::cout << YELLOW << "\n[check constructor]: \t" << ((map_check_constructor(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check operator=]: \t" << ((map_check_operator_equal(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check iterator]: \t" << ((map_check_iterator(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check empty]: \t\t" << ((map_check_empty(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check size]: \t\t" << ((map_check_size(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check max_size]: \t" << ((map_check_max_size(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check operator[] ]: \t" << ((map_check_operator_skobki(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check insert]: \t" << ((map_check_insert(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check erase]: \t\t" << ((map_check_erase(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check swap]: \t\t" << ((map_check_swap(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check clear]: \t\t" << ((map_check_clear(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check key_comp]: \t" << ((map_check_key_comp(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check value_comp]: \t" << ((map_check_value_comp(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check find]: \t\t" << ((map_check_find(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check count]: \t\t" << ((map_check_count(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check lower_bound]: \t" << ((map_check_lower_bound(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check upper_bound]: \t" << ((map_check_upper_bound(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check equal_range]: \t" << ((map_check_equal_range(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
}

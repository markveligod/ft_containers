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

void map_start(std::ofstream *out)
{
    std::cout << YELLOW << "\n[check constructor]: \t" << ((map_check_constructor(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check operator=]: \t" << ((map_check_operator_equal(out)) ? GREEN"OK" : RED"FAIL") << std::endl;
}

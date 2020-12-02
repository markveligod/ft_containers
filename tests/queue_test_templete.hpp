#pragma once

#include "../main.hpp"


template<typename T>
bool queue_check_constructor(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_constructor \n";
    os << "\nCreaty constructor empty (orig_1 noorig_1)\n";

    std::queue<T> orig_1;
    ft::queue<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.size() << std::endl;
    os << "[noorig_1] => " << noorig_1.size() << std::endl;

    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor with list (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor with list (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.size() << std::endl;
    os << "[noorig_3] => " << noorig_3.size() << std::endl;

    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_empty(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_empty \n";
    os << "\nCreaty queue empty (orig_1 noorig_1)\n";

    std::queue<T> orig_1;
    ft::queue<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.empty() << std::endl;
    os << "[noorig_1] => " << noorig_1.empty() << std::endl;

    if (orig_1.empty() != noorig_1.empty())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_1 (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.empty() << std::endl;
    os << "[noorig_2] => " << noorig_2.empty() << std::endl;

    if (orig_2.empty() != noorig_2.empty())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.empty() << std::endl;
    os << "[noorig_3] => " << noorig_3.empty() << std::endl;

    if (orig_3.empty() != noorig_3.empty())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_size(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_size \n";
    os << "\nCreaty queue empty (orig_1 noorig_1)\n";

    std::queue<T> orig_1;
    ft::queue<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.size() << std::endl;
    os << "[noorig_1] => " << noorig_1.size() << std::endl;

    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_1 (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.size() << std::endl;
    os << "[noorig_3] => " << noorig_3.size() << std::endl;

    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_front(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_front \n";

    os << "\nCreaty queue with list -> data_1 (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.front() << std::endl;
    os << "[noorig_2] => " << noorig_2.front() << std::endl;

    if (orig_2.front() != noorig_2.front())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.front() << std::endl;
    os << "[noorig_3] => " << noorig_3.front() << std::endl;

    if (orig_3.front() != noorig_3.front())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_back(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_back \n";

    os << "\nCreaty queue with list -> data_1 (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.back() << std::endl;
    os << "[noorig_2] => " << noorig_2.back() << std::endl;

    if (orig_2.back() != noorig_2.back())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.back() << std::endl;
    os << "[noorig_3] => " << noorig_3.back() << std::endl;

    if (orig_3.back() != noorig_3.back())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_pop(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_pop \n";
    os << "\nCreaty queue with list -> data_1 (orig_2 noorig_2)\n";

    std::list<T> first(3, data_1);
    ft::list<T> second(3, data_1);

    std::queue<T, std::list<T> > orig_2(first);
    ft::queue<T, ft::list<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;
    
    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    orig_2.pop();
    noorig_2.pop();
    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }
    
    orig_2.pop();
    noorig_2.pop();
    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::queue<T, std::list<T> > orig_3(first);
    ft::queue<T, ft::list<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.size() << std::endl;
    os << "[noorig_3] => " << noorig_3.size() << std::endl;
    
    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }

    orig_3.pop();
    noorig_3.pop();
    os << "\n[orig_3] => " << orig_3.size() << std::endl;
    os << "[noorig_3] => " << noorig_3.size() << std::endl;

    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    
    orig_3.pop();
    noorig_3.pop();
    os << "\n[orig_3] => " << orig_3.size() << std::endl;
    os << "[noorig_3] => " << noorig_3.size() << std::endl;

    if (orig_3.size() != noorig_3.size())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_push(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_push \n";
    os << "\nCreaty queue with list -> data_1 data_2 (orig noorig)\n";

    std::queue<T> orig;
    ft::queue<T> noorig;
    
    for (size_t i = 0; i < 12; i++)
    {
        orig.push(data_1);
        noorig.push(data_1);
    }

    os << "\nAfter push -> data_1(orig noorig)\n";
    os << "\n[orig] => " << orig.size() << std::endl;
    os << "[noorig] => " << noorig.size() << std::endl;

    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }

    for (size_t i = 0; i < 22; i++)
    {
        orig.push(data_2);
        noorig.push(data_2);
    }
    
    os << "\nAfter push -> data_2(orig noorig)\n";
    os << "\n[orig] => " << orig.size() << std::endl;
    os << "[noorig] => " << noorig.size() << std::endl;

    if (orig.size() != noorig.size())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool queue_check_relational(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! queue_check_relational \n";
    os << "\nCreaty queue empty (orig_1 noorig_1 orig_2 noorig_2)\n";

    std::queue<T> orig_1;
    ft::queue<T> noorig_1;
    std::queue<T> orig_2;
    ft::queue<T> noorig_2;

    os << "\n[Orig]: After operator== " << (orig_1 == orig_2) << std::endl;
    os << "\n[No Orig]: After operator== " << (noorig_1 == noorig_2) << std::endl;
    if ((orig_1 == orig_2) != (noorig_1 == noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator!= " << (orig_1 != orig_2) << std::endl;
    os << "\n[No Orig]: After operator!= " << (noorig_1 != noorig_2) << std::endl;
    if ((orig_1 != orig_2) != (noorig_1 != noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator< " << (orig_1 < orig_2) << std::endl;
    os << "\n[No Orig]: After operator< " << (noorig_1 < noorig_2) << std::endl;
    if ((orig_1 < orig_2) != (noorig_1 < noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator<= " << (orig_1 <= orig_2) << std::endl;
    os << "\n[No Orig]: After operator<= " << (noorig_1 <= noorig_2) << std::endl;
    if ((orig_1 <= orig_2) != (noorig_1 <= noorig_2))
    {
        *out << os.str();
        return (false);
    }
    
    os << "\n[Orig]: After operator> " << (orig_1 > orig_2) << std::endl;
    os << "\n[No Orig]: After operator> " << (noorig_1 > noorig_2) << std::endl;
    if ((orig_1 > orig_2) != (noorig_1 > noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator>= " << (orig_1 >= orig_2) << std::endl;
    os << "\n[No Orig]: After operator>= " << (noorig_1 >= noorig_2) << std::endl;
    if ((orig_1 >= orig_2) != (noorig_1 >= noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty queue with list -> data_1 data_2 (orig noorig)\n";

    for (size_t i = 0; i < 12; i++)
    {
        orig_1.push(data_1);
        noorig_1.push(data_1);
    }

    for (size_t i = 0; i < 22; i++)
    {
        orig_2.push(data_2);
        noorig_2.push(data_2);
    }

    os << "\n[Orig]: After operator== " << (orig_1 == orig_2) << std::endl;
    os << "\n[No Orig]: After operator== " << (noorig_1 == noorig_2) << std::endl;
    if ((orig_1 == orig_2) != (noorig_1 == noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator!= " << (orig_1 != orig_2) << std::endl;
    os << "\n[No Orig]: After operator!= " << (noorig_1 != noorig_2) << std::endl;
    if ((orig_1 != orig_2) != (noorig_1 != noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator< " << (orig_1 < orig_2) << std::endl;
    os << "\n[No Orig]: After operator< " << (noorig_1 < noorig_2) << std::endl;
    if ((orig_1 < orig_2) != (noorig_1 < noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator<= " << (orig_1 <= orig_2) << std::endl;
    os << "\n[No Orig]: After operator<= " << (noorig_1 <= noorig_2) << std::endl;
    if ((orig_1 <= orig_2) != (noorig_1 <= noorig_2))
    {
        *out << os.str();
        return (false);
    }
    
    os << "\n[Orig]: After operator> " << (orig_1 > orig_2) << std::endl;
    os << "\n[No Orig]: After operator> " << (noorig_1 > noorig_2) << std::endl;
    if ((orig_1 > orig_2) != (noorig_1 > noorig_2))
    {
        *out << os.str();
        return (false);
    }

    os << "\n[Orig]: After operator>= " << (orig_1 >= orig_2) << std::endl;
    os << "\n[No Orig]: After operator>= " << (noorig_1 >= noorig_2) << std::endl;
    if ((orig_1 >= orig_2) != (noorig_1 >= noorig_2))
    {
        *out << os.str();
        return (false);
    }

    *out << os.str();
    return (true);
}

template<typename T>
void runner_cor_queue(std::ofstream *out, T (*f)())
{
    std::cout << YELLOW << "\n[check constructor]: \t" << ((queue_check_constructor<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check empty]: \t\t" << ((queue_check_empty<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check size]: \t\t" << ((queue_check_size<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check front]: \t\t" << ((queue_check_front<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check back]: \t\t" << ((queue_check_back<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check pop]: \t\t" << ((queue_check_pop<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check push]: \t\t" << ((queue_check_push<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check relational]: \t" << ((queue_check_relational<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << RESET;
}

template<typename T>
void queue_start(std::ofstream *out)
{
    if (typeid(T) == typeid(int))
    {
        runner_cor_queue<int>(out, gen_int);
    }
    else if (typeid(T) == typeid(char))
    {
        runner_cor_queue<char>(out, gen_char);
    }
    else if (typeid(T) == typeid(double))
    {
        runner_cor_queue<double>(out, gen_dd);
    }
    else if (typeid(T) == typeid(float))
    {
        runner_cor_queue<float>(out, gen_ff);
    }
    else if (typeid(T) == typeid(std::string))
    {
        runner_cor_queue<std::string>(out, gen_str);
    }
}
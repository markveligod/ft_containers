#pragma once

#include "../main.hpp"


template<typename T>
bool stack_check_constructor(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_constructor \n";
    os << "\nCreaty constructor empty (orig_1 noorig_1)\n";

    std::stack<T> orig_1;
    ft::stack<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.size() << std::endl;
    os << "[noorig_1] => " << noorig_1.size() << std::endl;

    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor with vector (orig_2 noorig_2)\n";

    std::vector<T> first(3, data_1);
    ft::vector<T> second(3, data_1);

    std::stack<T, std::vector<T> > orig_2(first);
    ft::stack<T, ft::vector<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty constructor with vector (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::stack<T, std::vector<T> > orig_3(first);
    ft::stack<T, ft::vector<T> > noorig_3(second);

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
bool stack_check_empty(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_empty \n";
    os << "\nCreaty stack empty (orig_1 noorig_1)\n";

    std::stack<T> orig_1;
    ft::stack<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.empty() << std::endl;
    os << "[noorig_1] => " << noorig_1.empty() << std::endl;

    if (orig_1.empty() != noorig_1.empty())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty stack with vector -> data_1 (orig_2 noorig_2)\n";

    std::vector<T> first(3, data_1);
    ft::vector<T> second(3, data_1);

    std::stack<T, std::vector<T> > orig_2(first);
    ft::stack<T, ft::vector<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.empty() << std::endl;
    os << "[noorig_2] => " << noorig_2.empty() << std::endl;

    if (orig_2.empty() != noorig_2.empty())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty stack with vector -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::stack<T, std::vector<T> > orig_3(first);
    ft::stack<T, ft::vector<T> > noorig_3(second);

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
bool stack_check_size(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_size \n";
    os << "\nCreaty stack empty (orig_1 noorig_1)\n";

    std::stack<T> orig_1;
    ft::stack<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.size() << std::endl;
    os << "[noorig_1] => " << noorig_1.size() << std::endl;

    if (orig_1.size() != noorig_1.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty stack with vector -> data_1 (orig_2 noorig_2)\n";

    std::vector<T> first(3, data_1);
    ft::vector<T> second(3, data_1);

    std::stack<T, std::vector<T> > orig_2(first);
    ft::stack<T, ft::vector<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.size() << std::endl;
    os << "[noorig_2] => " << noorig_2.size() << std::endl;

    if (orig_2.size() != noorig_2.size())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty stack with vector -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::stack<T, std::vector<T> > orig_3(first);
    ft::stack<T, ft::vector<T> > noorig_3(second);

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
bool stack_check_top(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_top \n";

// Its sega OMG!!!
/*   
    os << "\nCreaty stack empty (orig_1 noorig_1)\n";
    std::stack<T> orig_1;
    ft::stack<T> noorig_1;

    os << "\n[orig_1] => " << orig_1.top() << std::endl;
    os << "[noorig_1] => " << noorig_1.top() << std::endl;

    if (orig_1.top() != noorig_1.top())
    {
        *out << os.str();
        return (false);
    }
*/
    os << "\nCreaty stack with vector -> data_1 (orig_2 noorig_2)\n";

    std::vector<T> first(3, data_1);
    ft::vector<T> second(3, data_1);

    std::stack<T, std::vector<T> > orig_2(first);
    ft::stack<T, ft::vector<T> > noorig_2(second);

    os << "\n[orig_2] => " << orig_2.top() << std::endl;
    os << "[noorig_2] => " << noorig_2.top() << std::endl;

    if (orig_2.top() != noorig_2.top())
    {
        *out << os.str();
        return (false);
    }

    os << "\nCreaty stack with vector -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::stack<T, std::vector<T> > orig_3(first);
    ft::stack<T, ft::vector<T> > noorig_3(second);

    os << "\n[orig_3] => " << orig_3.top() << std::endl;
    os << "[noorig_3] => " << noorig_3.top() << std::endl;

    if (orig_3.top() != noorig_3.top())
    {
        *out << os.str();
        return (false);
    }
    
    *out << os.str();
    return (true);
}

template<typename T>
bool stack_check_pop(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_pop \n";
    os << "\nCreaty stack with vector -> data_1 (orig_2 noorig_2)\n";

    std::vector<T> first(3, data_1);
    ft::vector<T> second(3, data_1);

    std::stack<T, std::vector<T> > orig_2(first);
    ft::stack<T, ft::vector<T> > noorig_2(second);

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

    os << "\nCreaty stack with vector -> data_2 (orig_3 noorig_3)\n";

    first.assign(30, data_2);
    second.assign(30, data_2);

    std::stack<T, std::vector<T> > orig_3(first);
    ft::stack<T, ft::vector<T> > noorig_3(second);

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
bool stack_check_push(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_push \n";
    os << "\nCreaty stack with vector -> data_1 data_2 (orig noorig)\n";

    std::stack<T> orig;
    ft::stack<T> noorig;
    
    for (size_t i = 0; i < 12; i++)
    {
        orig.push(data_1);
        noorig.push(data_1);
    }

    for (size_t i = 0; i < 22; i++)
    {
        orig.push(data_2);
        noorig.push(data_2);
    }

    size_t i = 0;

    while (!orig.empty() && !noorig.empty())
    {
        if (orig.top() != noorig.top())
        {
            *out << os.str();
            return (false);
        }
        os << "\nNumber cicle: " << ++i << "\n[Orig] => " << orig.top() << std::endl;
        os << "[Noorig] => " << noorig.top() << std::endl;
        orig.pop();
        noorig.pop();
    }
    if (!noorig.empty() || !orig.empty())
    {
        *out << os.str();
        return (false);
    }     
    
    *out << os.str();
    return (true);
}

template<typename T>
bool stack_check_relational(std::ofstream *out, T data_1, T data_2)
{
    std::stringstream os;
    os << "\n|========> !(*_*)! stack_check_relational \n";
    os << "\nCreaty stack empty (orig_1 noorig_1 orig_2 noorig_2)\n";

    std::stack<T> orig_1;
    ft::stack<T> noorig_1;
    std::stack<T> orig_2;
    ft::stack<T> noorig_2;

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

    os << "\nCreaty stack with vector -> data_1 data_2 (orig noorig)\n";

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
void runner_cor_stack(std::ofstream *out, T (*f)())
{
    std::cout << YELLOW << "\n[check constructor]: \t" << ((stack_check_constructor<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check empty]: \t\t" << ((stack_check_empty<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check size]: \t\t" << ((stack_check_size<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check top]: \t\t" << ((stack_check_top<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check pop]: \t\t" << ((stack_check_pop<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check push]: \t\t" << ((stack_check_push<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << YELLOW << "[check relational]: \t" << ((stack_check_relational<T>(out, f(), f())) ? GREEN"OK" : RED"FAIL") << std::endl;
    std::cout << RESET;
}

template<typename T>
void stack_start(std::ofstream *out)
{
    if (typeid(T) == typeid(int))
    {
        runner_cor_stack<int>(out, gen_int);
    }
    else if (typeid(T) == typeid(char))
    {
        runner_cor_stack<char>(out, gen_char);
    }
    else if (typeid(T) == typeid(double))
    {
        runner_cor_stack<double>(out, gen_dd);
    }
    else if (typeid(T) == typeid(float))
    {
        runner_cor_stack<float>(out, gen_ff);
    }
    else if (typeid(T) == typeid(std::string))
    {
        runner_cor_stack<std::string>(out, gen_str);
    }
}
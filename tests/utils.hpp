#pragma once

#include "../main.hpp"

template<typename T>
bool Compare_my(const T &a, const T &b) { return (a > b);}

template<typename T>
bool Predict(const T &a) { return (a == a);}

int gen_int() { return (rand() % 1448228);}

char gen_char() 
{
    int i = rand() % 100;
    return (static_cast<char>((i < 33) ? i + 30 : i));
}

double gen_dd() { return ((rand() % 1448228) / 100.0);}

float gen_ff() { return ((rand() % 1448228) / 100.0f);}

std::string gen_str()
{
    std::string str[10] = {"Возьми это!", "Убирайся с моей лужайки!", "- Кофе? Черный... как моя душа.", "Я - огонь, Я - Смерть!", "Молния! Кукачев!", "Ты пытался открыть меня?", "Одной обоймы будет недостаточно!", "Давайте начнем эту вечеринку!", "Ты называешь себя крутым парнем?", "Неужели кто-то что-то почувствовал?"};
    return (str[rand() % 10]);
}

template<typename T, typename K>
bool check_iterators(T or_begin, T or_end, K no_begin, K no_end)
{
    while (no_begin != no_end && or_begin != or_end)
    {
        if (*or_begin != *no_begin)
            return (false);
        ++or_begin;
        ++no_begin;
    }
    if (no_begin != no_end || or_begin != or_end)
        return (false);
    return (true);
}

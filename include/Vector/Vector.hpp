#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "VecIterator.hpp"

namespace ft
{
    template<class T>
    class vector
    {
        private:
            T *v_array;
            size_t v_capacity;
            size_t v_size;
            double gold_up;

        public:
            typedef VecIterator<T> 	iterator;
			typedef VecIterator<T> 	const_iterator;
			typedef VecRevIterator<T> 	reverse_iterator;
			typedef VecRevIterator<T>	const_reverse_iterator;

            //main
            vector();
            vector(size_t count, T const &data);
            vector(iterator first, iterator last);
            vector(vector const &other);
            ~vector();
            vector &operator=(vector const &other);

            //iterators
            iterator                begin() { return (iterator(this->v_array));}
	        const_iterator          begin() const { return (const_iterator(this->v_array));}
	        reverse_iterator        rbegin() { return (reverse_iterator(&(this->v_array[this->v_size - 1])));}
	        const_reverse_iterator  rbegin() const { return (const_reverse_iterator(&(this->v_array[this->v_size - 1])));}
	        iterator                end() { return (iterator(&(this->v_array[this->v_size])));}
	        const_iterator          end() const { return (const_iterator(&(this->v_container[this->v_size])));}
	        reverse_iterator        rend() { return (reverse_iterator(this->v_array - 1));}
	        const_reverse_iterator  rend() const { return (const_reverse_iterator(this->v_array - 1));}

            //Capacity
            size_t 					size() const {return (this->v_size);}
            size_t                  capacity() const {return (this->v_capacity);}
			bool					empty() const {return ((this->v_size == 0) ? true : false);}
			size_t					max_size() const {return (std::numeric_limits<std::size_t>::max() / sizeof(T));}
            void                    reserve (size_t count);
            void                    resize (size_t count, T data = T());

            //Element access
            T &at (size_t count);
            T const &at (size_t count) const;
            T &operator[](size_t count) {return (*(this->v_array + count));}
            T const &operator[](size_t count) const {return (*(this->v_array + count));}
            T &front() { return (this->v_array[0]);}
	        T const &front() const { return (this->v_array[0]);}
	        T &back() { return (this->v_array[this->v_size - 1]);}
	        T const &back() const { return (this->v_array[this->v_size - 1]);}

            //Modifiers
            void clear();
            void push_back(const T &data);
            void pop_back();
            void assign(iterator first, iterator last);
            void assign(size_t count, const T &data);
            iterator insert (iterator position, const T &data);
            void insert(iterator position, size_t count, const T &data);
            void insert(iterator position, iterator first, iterator last);
            void swap(vector<T> &other);
            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);

    };

/*
**==========================
**       Constructor
**       Destructor
**       operator=
**==========================
*/

template<class T>
vector<T>::vector()
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->gold_up = (1 + sqrt(5)) / 2;
}

template<class T>
vector<T>::vector(size_t count, T const &data)
{
    this->gold_up = (1 + sqrt(5)) / 2;
    this->v_array = static_cast<T*>(operator new(sizeof(T) * count));
    this->v_size = count;
    this->v_capacity = count;
    for (size_t i = 0; i < count; i++)
        this->v_array[i] = data;
}

template<class T>
vector<T>::vector(iterator first, iterator last)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->gold_up = (1 + sqrt(5)) / 2;
    iterator temp_it = first;
    size_t temp_size = 0;
    while (temp_it != last)
    {
        ++temp_it;
        temp_size++;
    }
    this->reserve(temp_size);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(first.getData()), sizeof(T) * temp_size);
    this->v_size = temp_size;
}

template<class T>
vector<T>::vector(vector const &other)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->gold_up = (1 + sqrt(5)) / 2;
    this->reserve(other.v_capacity);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(other.v_array), other.v_size * sizeof(T));
    this->v_size = other.v_size;
}

template<class T>
vector<T>::~vector()
{
    if (this->v_size > 0)
        delete [] this->v_array;
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->gold_up = 0;
}

template<class T>
vector<T> &vector<T>::operator=(vector<T> const &other)
{
    if (!this->empty())
        delete [] this->v_array;
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->gold_up = (1 + sqrt(5)) / 2;
    this->reserve(other.v_capacity);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(other.v_array), other.v_size * sizeof(T));
    this->v_size = other.v_size;
    return (*this);
}

/*
**==========================
**        Capacity
**==========================
*/

template<class T>
void vector<T>::reserve(size_t count)
{
    if (count > this->v_capacity)
    {
        T *temp = static_cast<T*>(operator new(sizeof(T) * (count + 1)));
        if (this->v_size > 0)
        {
            std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), this->v_size * sizeof(T));
            delete [] this->v_array;
        }
        this->v_capacity = count;
        this->v_array = temp;
    }    
}

template<class T>
void vector<T>::resize(size_t count, T data)
{
    if (count >= this->v_capacity)
    {
        T *temp = static_cast<T*>(operator new(sizeof(T) * (count + 1)));
        if (this->v_size > 0)
        {
            std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), ((count > this->v_size) ? this->v_size : count) * sizeof(T));
            delete [] this->v_array;
        }
        this->v_array = temp;
        for (size_t i = this->v_size; i < count; i++)
            this->v_array[i] = data;
        this->v_size = count;
        this->v_capacity = count;
    }
    else
    {
        T temp_data = ((count > this->v_size) ? data : T());
        for (size_t i = this->v_size; i < count; i++)
            this->v_array[i] = temp_data;
        this->v_size = count;
    }
}

/*
**==========================
**     Element access
**==========================
*/

template<class T>
T &vector<T>::at(size_t count)
{
    if (count >= this->v_size)
        throw std::out_of_range("Index out of range !(-_-)!");
    return (this->v_array[count]);
}

template<class T>
T const &vector<T>::at(size_t count) const
{
    return (this->at(count));
}


/*
**==========================
**        Modifiers
**==========================
*/

template<class T>
void vector<T>::clear()
{
    for (size_t i = 0; i < this->v_size; i++)
        this->v_array[i] = T();
    this->v_size = 0;
}

template<class T>
void vector<T>::push_back(const T &data)
{
    this->v_size++;
    int up = this->v_size * this->gold_up;
    if (this->v_size >= this->v_capacity)
    {
        T *temp = static_cast<T*>(operator new(sizeof(T) * up));
        std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), (this->v_size - 1) * sizeof(T));
        delete [] this->v_array;
        this->v_capacity = up;
        this->v_array = temp;
        this->gold_up *= (1 + sqrt(5)) / 2;
    }
    this->v_array[this->v_size - 1] = data;
}

template<class T>
void vector<T>::assign(iterator first, iterator last)
{
    if (!this->empty())
        this->v_size = 0;
    iterator temp_it = first;
    size_t temp_size = 0;
    while (temp_it != last)
    {
        ++temp_it;
        temp_size++;
    }
    this->reserve(temp_size);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(first.getData()), sizeof(T) * temp_size);
    if (temp_size > this->v_size)
        this->v_size = temp_size;
}

template<class T>
void vector<T>::assign(size_t count, const T &data)
{
    if (!this->empty())
        this->v_size = 0;
    this->reserve(count);
    for (size_t i = 0; i < count; i++)
        this->v_array[i] = data;
    if (count > this->v_size)
        this->v_size = count;
}

template<class T>
typename vector<T>::iterator vector<T>::insert(iterator position, const T &data)
{
    iterator it_begin = this->begin();
    iterator it_end = this->end();
    T *temp;
    size_t i_gl = 0;
    size_t j_gl = 0;
    
    if (this->v_size + 1 >= this->v_capacity)
    {
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_size + 1 + 1)));
        this->v_capacity = this->v_size + 1;
    }
    else
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_capacity + 1)));
    while (it_begin != position)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++it_begin;
    }
    size_t temp_it = i_gl;
    temp[i_gl] = data;
    ++i_gl;
    while (position != it_end)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++position;
    }
    delete [] this->v_array;
    this->v_array = temp;
    this->v_size += 1;
    return (iterator(&(this->v_array[temp_it])));
}

template<class T>
void vector<T>::insert(iterator position, size_t count, const T &data)
{
    iterator it_begin = this->begin();
    iterator it_end = this->end();
    T *temp;
    size_t i_gl = 0;
    size_t j_gl = 0;

    if (this->v_size + count >= this->v_capacity)
    {
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_size + count + 1)));
        this->v_capacity = this->v_size + count;
    }
    else
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_capacity + 1)));
    while (it_begin != position)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++it_begin;
    }
    for (size_t i = 0; i < count; i++)
    {
        temp[i_gl] = data;
        ++i_gl;
    }
    while (position != it_end)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++position;
    }
    delete [] this->v_array;
    this->v_array = temp;
    this->v_size += count;
}

template<class T>
void vector<T>::insert(iterator position, iterator first, iterator last)
{
    size_t size_it = first - last;
    T *temp;
    iterator it_begin = this->begin();
    iterator it_end = this->end();
    size_t i_gl = 0;
    size_t j_gl = 0;
    
    if (this->v_size + size_it >= this->v_capacity)
    {
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_size + size_it + 1)));
        this->v_capacity = this->v_size + size_it;
    }
    else
        temp = static_cast<T*>(operator new(sizeof(T) * (this->v_capacity + 1)));
    while (it_begin != position)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++it_begin;
    }
    while (first != last)
    {
        temp[i_gl] = *first;
        ++i_gl;
        ++first;
    }
    while (position != it_end)
    {
        temp[i_gl] = this->v_array[j_gl];
        ++i_gl;
        ++j_gl;
        ++position;
    }
    delete [] this->v_array;
    this->v_array = temp;
    this->v_size += size_it;
}

template<class T>
void vector<T>::pop_back()
{
    if (this->v_size)
        this->v_size--;
}

template<class T>
void vector<T>::swap(vector<T> &other)
{
    vector<T> temp = *this;
    *this = other;
    other = temp;
}

template<class T>
typename vector<T>::iterator vector<T>::erase(iterator position)
{
    iterator it_begin = this->begin();
    iterator it_end = this->end();
    T *temp = static_cast<T*>(operator new(sizeof(T) * (this->v_capacity + 1)));
    size_t i_gl = 0;
    size_t temp_pos;

    while (it_begin != it_end)
    {
        if (it_begin == position)
        {
            temp_pos = i_gl;
            ++it_begin;
            continue ;
        }
        temp[i_gl] = *it_begin;
        ++i_gl;
        ++it_begin;        
    }
    delete [] this->v_array;
    this->v_array = temp;
    this->v_size--;
    return (iterator(&(this->v_array[temp_pos])));
}

template<class T>
typename vector<T>::iterator vector<T>::erase(iterator first, iterator last)
{
    iterator it_begin = this->begin();
    iterator it_end = this->end();
    T *temp = static_cast<T*>(operator new(sizeof(T) * (this->v_capacity + 1)));
    size_t i_gl = 0;
    size_t it_size = first - last;
    size_t temp_pos;

    while (it_begin != it_end)
    {
        if (it_begin == first)
        {
            temp_pos = i_gl;
            it_begin += it_size;
            continue ;
        }
        temp[i_gl] = *it_begin;
        ++it_begin;
        ++i_gl;
    }
    delete [] this->v_array;
    this->v_array = temp;
    this->v_size -= it_size;
    return (iterator(&(this->v_array[temp_pos])));
}

} //namespace
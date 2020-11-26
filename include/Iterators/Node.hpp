#pragma once

template <typename T>
class node
{
    public:
        typedef T value_type;
        typedef node* node_pointer;
        value_type data;
        node_pointer next;
        node_pointer prev;

        node(const value_type &data = value_type())
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        node(const node &other) { *this = other;}
        ~node() {}
        node &operator=(const node &rhs) 
        {
            if (this != &rhs) 
            {
                this->data = rhs.data;
                this->next = rhs.next;
                this->prev = rhs.prev;
            }
            return (*this);
        }
        bool            operator==(const node &rhs) const { return (this->data == rhs.data && this->next == rhs.next && this->prev == rhs.prev);}
        bool            operator!=(const node &rhs) const { return (*this != rhs);}
};
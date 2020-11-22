#pragma once

template <typename T>
class node
{
    public:
        typedef T value_type;
        typedef node* node_pointer;
        typedef node& node_reference;

    private:
        value_type data;
        node_pointer next;
        node_pointer prev;

    public:
        node(const value_type &data = value_type())
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        node(const node_reference other) { *this = other;}
        ~node() {}
        node_reference operator=(const node_reference rhs) 
        {
            if (this != &rhs) 
            {
                this->data = rhs.data;
                this->next = rhs.next;
                this->prev = rhs.prev;
            }
            return (*this);
        }
        bool            operator==(const node_reference rhs) const { return (this->data == rhs.data && this->next == rhs.next && this->prev == rhs.prev);}
        bool            operator!=(const node_reference rhs) const { return (*this != rhs);}
        node_pointer    getData() const {return (this->data);}
        node_pointer    getNext() const { return (this->next);}
        node_pointer    getPrevious() const { return (this->prev);}
};
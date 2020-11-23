# :black_square_button: ft_containers (project 2020)
## Todo list:
### Container ft::list\<\>:  

**Main coplien's form**  
- [x] (constructor)
```
default (1)	 
explicit list (const allocator_type& alloc = allocator_type());  
  
fill (2)  
explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());  
  
range (3)  
  
template <class InputIterator>  
list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());  
  
copy (4)  
list (const list& x);  
```
- [x] (destructor)
```
~list();
```
- [x] operator=
```
copy (1) list& operator= (const list& x);  
```

**Iterators:**  
- [x] (begin)  
```
      iterator begin();  
const_iterator begin() const;  
```
Returns an iterator pointing to the first element in the list container.  

- [x] (end)
```
      iterator end();  
const_iterator end() const;  
```
Returns an iterator referring to the past-the-end element in the list container.  

- [x] (rbegin)
```
      reverse_iterator rbegin();  
const_reverse_iterator rbegin() const;  
```
Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).  

- [x] (rend)
```
      reverse_iterator rend();  
const_reverse_iterator rend() const;  
```
Returns a reverse iterator pointing to the theoretical element preceding the first element in the list container (which is considered its reverse end).  

**Capacity:**  
- [x] (empty)  
```
bool empty() const;
```
Returns whether the list container is empty (i.e. whether its size is 0).  

- [x] (size)  
```
size_type size() const;
```
Returns the number of elements in the list container.  

- [x] (max_size)  
```
size_type max_size() const;  
```
Returns the maximum number of elements that the list container can hold.  


**Element access:**  
- [x] (front) 
```
      reference front();  
const_reference front() const;  
```
Returns a reference to the first element in the list container.  

- [x] (back) 
```
      reference back();  
const_reference back() const;  
```
Returns a reference to the last element in the list container.  

**Modifiers:**  
- [ ] (assign)
```
range (1)  
template <class InputIterator>  
void assign (InputIterator first, InputIterator last);  
  
fill (2)  
void assign (size_type n, const value_type& val);  
```
Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.  

- [ ] (push_back)  
```
void push_back (const value_type& val);
```
Adds a new element at the end of the list container, after its current last element. The content of val is copied (or moved) to the new element.  

- [ ] (pop_back)  
```
void pop_back();
```
Removes the last element in the list container, effectively reducing the container size by one.  

- [ ] (push_front)  
```
void push_front (const value_type& val);
```
Inserts a new element at the beginning of the list, right before its current first element. The content of val is copied (or moved) to the inserted element.  

- [ ] (pop_front)  
```
void pop_front();
```
Removes the first element in the list container, effectively reducing its size by one.  

- [ ] (clear)  
```
void clear();
```
Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.  

- [ ] (insert)  
```
single element (1)  
iterator insert (iterator position, const value_type& val);  
  
fill (2)  
void insert (iterator position, size_type n, const value_type& val);  
  
range (3)  
template <class InputIterator>  
void insert (iterator position, InputIterator first, InputIterator last);  
```
Insert elements  
The container is extended by inserting new elements before the element at the specified position.  
This effectively increases the list size by the amount of elements inserted.   

- [ ] (erase)  
```
iterator erase (iterator position);
iterator erase (iterator first, iterator last);
```
Removes from the list container either a single element (position) or a range of elements ([first,last)).  

- [ ] (swap)  
```
void swap (list& x);
```
Exchanges the content of the container by the content of x, which is another list of the same type. Sizes may differ.  

- [ ] (resize)  
```
void resize (size_type n, value_type val = value_type());
```
Resizes the container so that it contains n elements.  

**Operations:**  
- [ ] (splice)  
```
entire list (1)  
void splice (iterator position, list& x);  
  
single element (2)  
void splice (iterator position, list& x, iterator i);  
  
element range (3)  
void splice (iterator position, list& x, iterator first, iterator last);  
```
Transfers elements from x into the container, inserting them at position.  

- [ ] (remove)  
```
void remove(const value_type& val);
```
Removes from the container all the elements that compare equal to val. This calls the destructor of these objects and reduces the container size by the number of elements removed.

- [ ] (remove_if)  
```
template <class Predicate>  
void remove_if (Predicate pred);  
```
Removes from the container all the elements for which Predicate pred returns true. This calls the destructor of these objects and reduces the container size by the number of elements removed.

- [ ] (unique)  
```
(1)  
void unique();  
  
(2)  
template <class BinaryPredicate>  
void unique(BinaryPredicate binary_pred);  
```
The version with no parameters (1), removes all but the first element from every consecutive group of equal elements in the container.  




# :black_square_button: ft_containers (project 2020)
## Todo list:
### Container ft::list\<\>:  

**Main coplien's form**  
- [ ] (constructor)
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
- [ ] (destructor)
```
~list();
```
- [ ] operator=
```
copy (1) list& operator= (const list& x);  
```

**Iterators:**  
- [ ] (begin)  
```
      iterator begin();  
const_iterator begin() const;  
```
Returns an iterator pointing to the first element in the list container.  

- [ ] (end)
```
      iterator end();  
const_iterator end() const;  
```
Returns an iterator referring to the past-the-end element in the list container.  

- [ ] (rbegin)
```
      reverse_iterator rbegin();  
const_reverse_iterator rbegin() const;  
```
Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).  

- [ ] (rend)
```
      reverse_iterator rend();  
const_reverse_iterator rend() const;  
```
Returns a reverse iterator pointing to the theoretical element preceding the first element in the list container (which is considered its reverse end).  

**Capacity:**  
- [ ] (empty)  
```
bool empty() const;
```
Returns whether the list container is empty (i.e. whether its size is 0).  

- [ ] (size)  
```
size_type size() const;
```
Returns the number of elements in the list container.  

- [ ] (max_size)  
```
size_type max_size() const;  
```
Returns the maximum number of elements that the list container can hold.  


**Element access:**  
- [ ] (front) 
```
      reference front();  
const_reference front() const;  
```
Returns a reference to the first element in the list container.  

- [ ] (back) 
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

- [ ] (clear)  
```
void clear();
```
Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.  



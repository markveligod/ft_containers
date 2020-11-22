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
- [ ] (rbegin)
- [ ] (rend)
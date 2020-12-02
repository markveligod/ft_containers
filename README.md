# :heavy_check_mark: ft_containers (project 2020)
## Description
This project is aim to understand how work is containers from library STL and this project is a part methodology learning students from 42 schools (21 schools in Moscow).  
The project implements the following containers:  
  
**[List](https://codelessons.ru/cplusplus/spisok-list-v-s-polnyj-material.html)**  
**[Vector](https://codelessons.ru/cplusplus/vektory-v-c-dlya-nachinayushhix.html)**  
**[Map](https://codelessons.ru/cplusplus/map-v-c-chto-eto-i-kak-s-etim-rabotat.html)**  
**[Stack](https://codelessons.ru/cplusplus/realizaciya-steka-stack-v-c.html)**  
**[Queue](https://codelessons.ru/cplusplus/ochered-queue-v-c-realizaciya-i-chto-eto-voobshhe-takoe.html)**  
  
*P.s. On the website `www.cplusplus.com` you can find a very important information about containers library STL.*  
  
WARNING:exclamation:  
`std::allocator` is not implemented in this project because it is not required for the task at the moment... be careful:do_not_litter:  
  
<img src="https://github.com/markveligod/ft_containers/raw/master/img/1.gif" width="800">  
  
P.s. `INCHECK` is a proprietary algorithm memory allocation in the ft::vector\<\>  
  
## :moyai:Container ft::list\<\>:
  
**Main coplien's form**  
- [x] ([constructor](https://www.cplusplus.com/reference/list/list/list/))
- [x] ([destructor](https://www.cplusplus.com/reference/list/list/~list/))
- [x] ([operator=](https://www.cplusplus.com/reference/list/list/operator=/))
  
**Iterators:**  
- [x] ([begin](https://www.cplusplus.com/reference/list/list/begin/))
- [x] ([end](https://www.cplusplus.com/reference/list/list/end/))
- [x] ([rbegin](https://www.cplusplus.com/reference/list/list/rbegin/))
- [x] ([rend](https://www.cplusplus.com/reference/list/list/rend/))
  
**Capacity:**  
- [x] ([empty](https://www.cplusplus.com/reference/list/list/empty/))
- [x] ([size](https://www.cplusplus.com/reference/list/list/size/))
- [x] ([max_size](https://www.cplusplus.com/reference/list/list/max_size/))
  
**Element access:**  
- [x] ([front](https://www.cplusplus.com/reference/list/list/front/))
- [x] ([back](https://www.cplusplus.com/reference/list/list/back/))
  
**Modifiers:**  
- [x] ([assign](https://www.cplusplus.com/reference/list/list/assign/))
- [x] ([push_back](https://www.cplusplus.com/reference/list/list/push_back/))
- [x] ([pop_back](https://www.cplusplus.com/reference/list/list/pop_back/))
- [x] ([push_front](https://www.cplusplus.com/reference/list/list/push_front/))
- [x] ([pop_front](https://www.cplusplus.com/reference/list/list/pop_front/))
- [x] ([clear](https://www.cplusplus.com/reference/list/list/clear/))
- [x] ([insert](https://www.cplusplus.com/reference/list/list/insert/))
- [x] ([erase](https://www.cplusplus.com/reference/list/list/erase/))
- [x] ([swap](https://www.cplusplus.com/reference/list/list/swap/))
- [x] ([resize](https://www.cplusplus.com/reference/list/list/resize/)) 
  
**Operations:**  
- [x] ([splice](https://www.cplusplus.com/reference/list/list/splice/))
- [x] ([remove](https://www.cplusplus.com/reference/list/list/remove/))
- [x] ([remove_if](https://www.cplusplus.com/reference/list/list/remove_if/))
- [x] ([unique](https://www.cplusplus.com/reference/list/list/unique/))
- [x] ([merge](https://www.cplusplus.com/reference/list/list/merge/))
- [x] ([reverse](https://www.cplusplus.com/reference/list/list/reverse/))
- [x] ([sort](https://www.cplusplus.com/reference/list/list/sort/))
  
**Non-member function overloads:**  
- [x] ([relational operators (list)](https://www.cplusplus.com/reference/list/list/operators/))
- [x] ([swap (list)](https://www.cplusplus.com/reference/list/list/swap-free/))

## :moyai:Container ft::vector\<\>:
  
**Main coplien's form**  
- [x] ([constructor](https://www.cplusplus.com/reference/vector/vector/vector/))
- [x] ([destructor](https://www.cplusplus.com/reference/vector/vector/~vector/))
- [x] ([operator=](https://www.cplusplus.com/reference/vector/vector/operator=/))
  
**Iterators:**  
- [x] ([begin](https://www.cplusplus.com/reference/vector/vector/begin/))
- [x] ([end](https://www.cplusplus.com/reference/vector/vector/end/))
- [x] ([rbegin](https://www.cplusplus.com/reference/vector/vector/rbegin/))
- [x] ([rend](https://www.cplusplus.com/reference/vector/vector/rend/))
  
**Capacity:**  
- [x] ([size](https://www.cplusplus.com/reference/vector/vector/size/))
- [x] ([max_size](https://www.cplusplus.com/reference/vector/vector/max_size/))
- [x] ([resize](https://www.cplusplus.com/reference/vector/vector/resize/))
- [x] ([capacity](https://www.cplusplus.com/reference/vector/vector/capacity/))
- [x] ([empty](https://www.cplusplus.com/reference/vector/vector/empty/))
- [x] ([reserve](https://www.cplusplus.com/reference/vector/vector/reserve/))
  
**Element access:**  
- [x] ([operator[]](https://www.cplusplus.com/reference/vector/vector/operator[]/))
- [x] ([at](https://www.cplusplus.com/reference/vector/vector/at/))
- [x] ([front](https://www.cplusplus.com/reference/vector/vector/front/))
- [x] ([back](https://www.cplusplus.com/reference/vector/vector/back/))
  
**Modifiers:**  
- [x] ([assign](https://www.cplusplus.com/reference/vector/vector/assign/))
- [x] ([push_back](https://www.cplusplus.com/reference/vector/vector/push_back/))
- [x] ([pop_back](https://www.cplusplus.com/reference/vector/vector/pop_back/))
- [x] ([insert](https://www.cplusplus.com/reference/vector/vector/insert/))
- [x] ([erase](https://www.cplusplus.com/reference/vector/vector/erase/))
- [x] ([swap](https://www.cplusplus.com/reference/vector/vector/swap/))
- [x] ([clear](https://www.cplusplus.com/reference/vector/vector/clear/))
  
**Non-member function overloads:**  
- [x] ([relational operators (vector)](https://www.cplusplus.com/reference/vector/vector/operators/))
- [x] ([swap (vector)](https://www.cplusplus.com/reference/vector/vector/swap-free/))
  
## :moyai:Container ft::map\<\>:
  
**Main coplien's form**  
- [x] ([constructor](https://www.cplusplus.com/reference/map/map/map/))
- [x] ([destructor](https://www.cplusplus.com/reference/map/map/~map/))
- [x] ([operator=](https://www.cplusplus.com/reference/map/map/operator=/))
  
**Iterators:**  
- [x] ([begin](https://www.cplusplus.com/reference/map/map/begin/))
- [x] ([end](https://www.cplusplus.com/reference/map/map/end/))
- [x] ([rbegin](https://www.cplusplus.com/reference/map/map/rbegin/))
- [x] ([rend](https://www.cplusplus.com/reference/map/map/rend/))
  
**Capacity:**  
- [x] ([empty](https://www.cplusplus.com/reference/map/map/empty/))
- [x] ([size](https://www.cplusplus.com/reference/map/map/size/))
- [x] ([max_size](https://www.cplusplus.com/reference/map/map/max_size/))
  
**Element access:**  
- [x] ([operator[]](https://www.cplusplus.com/reference/map/map/operator[]/))

**Modifiers:**  
- [x] ([insert](https://www.cplusplus.com/reference/map/map/insert/))
- [x] ([erase](https://www.cplusplus.com/reference/map/map/erase/))
- [x] ([swap](https://www.cplusplus.com/reference/map/map/swap/))
- [x] ([clear](https://www.cplusplus.com/reference/map/map/clear/))
  
**Observers:**  
- [x] ([key_comp](https://www.cplusplus.com/reference/map/map/key_comp/))
- [x] ([value_comp](https://www.cplusplus.com/reference/map/map/value_comp/))

**Operations:**  
- [x] ([find](https://www.cplusplus.com/reference/map/map/find/))
- [x] ([count](https://www.cplusplus.com/reference/map/map/count/))
- [x] ([lower_bound](https://www.cplusplus.com/reference/map/map/lower_bound/))
- [x] ([upper_bound](https://www.cplusplus.com/reference/map/map/upper_bound/))
- [x] ([equal_range](https://www.cplusplus.com/reference/map/map/equal_range/))

## :moyai:Container ft::stack\<\>:
  
**Member functions:**  
- [x] ([constructor](https://www.cplusplus.com/reference/stack/stack/stack/))
- [x] ([empty](https://www.cplusplus.com/reference/stack/stack/empty/))
- [x] ([size](https://www.cplusplus.com/reference/stack/stack/size/))
- [x] ([top](https://www.cplusplus.com/reference/stack/stack/top/))
- [x] ([push](https://www.cplusplus.com/reference/stack/stack/push/))
- [x] ([pop](https://www.cplusplus.com/reference/stack/stack/pop/))
  
**Non-member function overloads:**  
- [x] ([relational operators (stack)](https://www.cplusplus.com/reference/stack/stack/operators/))
  
## :moyai:Container ft::queue\<\>:
  
**Member functions:**  
- [x] ([constructor](https://www.cplusplus.com/reference/queue/queue/queue/))
- [x] ([empty](https://www.cplusplus.com/reference/queue/queue/empty/))
- [x] ([size](https://www.cplusplus.com/reference/queue/queue/size/))
- [x] ([front](https://www.cplusplus.com/reference/queue/queue/front/))
- [x] ([back](https://www.cplusplus.com/reference/queue/queue/back/))
- [x] ([push](https://www.cplusplus.com/reference/queue/queue/push/))
- [x] ([pop](https://www.cplusplus.com/reference/queue/queue/pop/))
  
**Non-member function overloads:**  
- [x] ([relational operators (queue)](https://www.cplusplus.com/reference/queue/queue/operators/))
  
## Other
**Author:**  
:copyright:*[Mark Veligod](https://github.com/markveligod)*  

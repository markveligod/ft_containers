#pragma once 

/*
**==========================
**         Colors
**==========================
*/
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

/*
**==========================
**         Includes
**==========================
*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <iterator>
#include <memory>
#include <algorithm>
#include <fstream>
#include <list>
#include <vector>
#include <limits>
#include <cstddef>
#include <typeinfo>
#include <cmath>
#include <functional>
#include <map>
#include <stack>
#include <queue>

/*
**==========================
**       My Includes
**==========================
*/

#include "include/List.hpp"
#include "include/Vector.hpp"
#include "include/Map.hpp"
#include "include/Stack.hpp"
#include "include/Queue.hpp"

/*
**==========================
**         Tests
**==========================
*/

#include "tests/utils.hpp"
#include "tests/list_test_template.hpp"
#include "tests/vector_test_template.hpp"
#include "tests/map_test_template.hpp"
#include "tests/stack_test_template.hpp"
#include "tests/queue_test_templete.hpp"

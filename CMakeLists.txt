cmake_minimum_required(VERSION 3.13)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(str_basic 天勤/例题/04串/串的操作.cpp 天勤/例题/04串/习题真题.cpp)
add_executable(str_match 天勤/例题/04串/串的模式匹配.cpp)
add_executable(str_exercise 天勤/例题/04串/习题真题.cpp)
add_executable(matrix_example 天勤/例题/05数组矩阵广义表/特殊矩阵与稀疏矩阵.cpp 天勤/例题/09查找/二叉排序树&平衡二叉树.cpp 天勤/例题/09查找/B-树&B+树.cpp 天勤/例题/09查找/习题真题.cpp 天勤/例题/10分治法解释/例题.cpp)
add_executable(matrix_exercise 天勤/例题/05数组矩阵广义表/习题真题.cpp)

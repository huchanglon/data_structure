cmake_minimum_required(VERSION 3.13)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(str_basic 天勤/例题/04串/串的操作.cpp 天勤/例题/04串/习题真题.cpp)
add_executable(str_match 天勤/例题/04串/串的模式匹配.cpp)
add_executable(str_exercise 天勤/例题/04串/习题真题.cpp)
add_executable(matrix_example 天勤/例题/05数组矩阵广义表/特殊矩阵与稀疏矩阵.cpp)
add_executable(matrix_exercise 天勤/例题/05数组矩阵广义表/习题真题.cpp)
add_executable(tree_example 天勤/例题/06树与二叉树/二叉树的遍历算法.cpp 天勤/例题/06树与二叉树/二叉树遍历算法改进.cpp 天勤/例题/06树与二叉树/习题真题.cpp)

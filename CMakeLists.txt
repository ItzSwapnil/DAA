cmake_minimum_required(VERSION 3.30)
project(DAA C)

set(CMAKE_C_STANDARD 23)

add_executable(Merge_Sort Merge_Sort.c)
add_executable(DFS_BFS DFS_BFS.c)

add_executable(Merge_using_Divide_Conquer Merge_using_Divide_Conquer.c)
add_executable(Max_Min_using_Divide_Conquer Max_Min_using_Divide_Conquer.c)

add_executable(Kurskals_Algorithm Kurskals_Algorithm.c)
add_executable(Prims_Algorithm Prims_Algorithm.c)
add_executable(Knapsack_using_Greedy_Approach Knapsack_using_Greedy_Approach.c)
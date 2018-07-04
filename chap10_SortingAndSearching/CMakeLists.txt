cmake_minimum_required(VERSION 3.6)

file(GLOB sourceFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(oneSourceFile ${sourceFiles})
    string(REPLACE ".cc" "" execName ${oneSourceFile})
    add_executable(${execName} ${oneSourceFile})
endforeach(oneSourceFile ${sourceFiles})

target_link_libraries(10.1_SortedMerge singlylinkedlist printer)
target_link_libraries(10.2_GroupAnagrams printer)
target_link_libraries(10.7_MissingInt printer)

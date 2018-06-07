cmake_minimum_required(VERSION 3.1)

file(GLOB sourceFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(oneSourceFile ${sourceFiles})
    string(REPLACE ".cc" "" execName ${oneSourceFile})
    add_executable(${execName} ${oneSourceFile})
    target_link_libraries(${execName} graph binarytree)
endforeach(oneSourceFile ${sourceFiles})

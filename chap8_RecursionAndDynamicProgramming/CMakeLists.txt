cmake_minimum_required(VERSION 3.1)

file(GLOB sourceFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(oneSourceFile ${sourceFiles})
    string(REPLACE ".cc" "" execName ${oneSourceFile})
    add_executable(${execName} ${oneSourceFile})
endforeach(oneSourceFile ${sourceFiles})

target_link_libraries(8.1_TripleStep timer)
target_link_libraries(8.4_PowerSet mathematical printer)
target_link_libraries(timerSample timer)
target_link_libraries(8.7_PermutationsWithoutDups mathematical printer)
target_link_libraries(8.8_PermutationsWithDups printer)

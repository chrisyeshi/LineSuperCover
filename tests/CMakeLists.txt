include_directories("..")

add_executable(corner corner.cpp)
target_link_libraries(corner linesuper)
add_test(corner corner)

add_executable(horizontal horizontal.cpp)
target_link_libraries(horizontal linesuper)
add_test(horizontal horizontal)

add_executable(run run.cpp)
target_link_libraries(run linesuper)
add_test(run run)

add_executable(vertical vertical.cpp)
target_link_libraries(vertical linesuper)
add_test(vertical vertical)

add_executable(rise rise.cpp)
target_link_libraries(rise linesuper)
add_test(rise rise)

add_executable(steady steady.cpp)
target_link_libraries(steady linesuper)
add_test(steady steady)
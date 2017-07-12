add_executable(carl-parser-test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_link_libraries(carl-parser-test PUBLIC carl-parser)

add_test(NAME test COMMAND carl-parser-test)

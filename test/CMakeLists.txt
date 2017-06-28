# WARNING:
# add_custom_command makes the output files only visible in the same directory.
# Therefore, we cannot simply run this code here, but must export it as a function to be called in the right context.
set(CMAKE_DEBUG_TARGET_PROPERTIES INCLUDE_DIRECTORIES)
add_executable(carl-parser-test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_link_libraries(carl-parser-test PUBLIC carl-parser)
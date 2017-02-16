

#option(WITH_LIBCXX "Building with clang++ and libc++(in Linux). To enable with: -DWITH_LIBCXX=On" On)


set(ANTLR_JAR_LOCATION ${PROJECT_SOURCE_DIR}/src/carl/antlr/antlr4.jar)

if(CMAKE_VERSION VERSION_EQUAL "3.0.0" OR
   CMAKE_VERSION VERSION_GREATER "3.0.0")
  CMAKE_POLICY(SET CMP0026 OLD)
  CMAKE_POLICY(SET CMP0045 OLD)
  CMAKE_POLICY(SET CMP0042 OLD)
  #CMAKE_POLICY(SET CMP0059 OLD)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(UUID REQUIRED uuid)
endif()
if(APPLE)
  find_library(COREFOUNDATION_LIBRARY CoreFoundation)
endif()

#file(STRINGS "VERSION" ANTLR_VERSION)



find_package(Java COMPONENTS Runtime REQUIRED)

if (NOT ANTLR_JAR_LOCATION)
 message(FATAL_ERROR "Missing antlr4.jar location. You can specify its path using: -DANTLR_JAR_LOCATION=<path>")
else()
 get_filename_component(ANTLR_NAME ${ANTLR_JAR_LOCATION} NAME_WE)
 if(NOT EXISTS "${ANTLR_JAR_LOCATION}")
  message(FATAL_ERROR "Unable to find ${ANTLR_NAME} in ${ANTLR_JAR_LOCATION}")
 else()
 message(STATUS "Found ${ANTLR_NAME}: ${ANTLR_JAR_LOCATION}")
 endif()
endif()


#set(MY_CXX_WARNING_FLAGS "  -Wall -pedantic -W")

# Initialize CXXFLAGS.
#if("${CMAKE_VERSION}" VERSION_GREATER 3.1.0)
#  set(CMAKE_CXX_STANDARD 11)
#  set(CMAKE_CXX_STANDARD_REQUIRED ON)
#else()
#  set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -std=c++11")
#  set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
#  set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -std=c++11")
#  set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
#  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11")
#endif()

#set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -Wall ${MY_CXX_WARNING_FLAGS}")
#set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g ${MY_CXX_WARNING_FLAGS}")
#set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG ${MY_CXX_WARNING_FLAGS}")
#set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG ${MY_CXX_WARNING_FLGAS}")
#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g ${MY_CXX_WARNING_FLAGS}")

# Compiler-specific C++11 activation.
#if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
#    execute_process(
#        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    # Just g++-5.0 and greater contain <codecvt> header. (test in ubuntu)
#    if (NOT (GCC_VERSION VERSION_GREATER 5.0 OR GCC_VERSION VERSION_EQUAL 5.0))
#        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 5.0 or greater.")
#    endif ()
#elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND APPLE)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND CMAKE_SYSTEM_NAME MATCHES "Linux")
#    execute_process(
#        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE CLANG_VERSION)
 #   if (NOT (CLANG_VERSION VERSION_GREATER 4.2.1 OR CLANG_VERSION VERSION_EQUAL 4.2.1))
  #      message(FATAL_ERROR "${PROJECT_NAME} requires clang 4.2.1 or greater.")#
 #   endif ()
    # You can use libc++ to compile this project when g++ is NOT greater than or equal to 5.0.
 #   if (WITH_LIBCXX)
 #       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
 #   endif()
#else ()
#    message(FATAL_ERROR "Your C++ compiler does not support C++11.")
#endif ()




# -*- mode:cmake -*-
if(NOT UNIX)
  message(FATAL "Unsupported operating system")
endif()

set(antlr4-parser-GENERATED_SRC
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialLexer.cpp 
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialParser.cpp
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialParserBaseListener.cpp
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialParserBaseVisitor.cpp
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialParserListener.cpp
   ${CMAKE_CURRENT_BINARY_DIR}/generated/PolynomialParserVisitor.cpp
 )

foreach( src_file ${antlr4-parser-GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${antlr4-parser-GENERATED_SRC} )

#add_custom_target(GenerateParser ALL
#   COMMAND
 #  message("Calling the generator!!!")
#   COMMAND 
#   ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/generated/
#   COMMAND
#   "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${CMAKE_CURRENT_BINARY_DIR}/generated/ -package #antlrcpptest ${CMAKE_CURRENT_SOURCE_DIR}/Polynomial.g4
#   WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
#   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Polynomial.g4
#   )



include_directories(
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src/misc
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src/atn
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src/dfa
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src/tree
  ${PROJECT_SOURCE_DIR}/src/carl/antlr/runtime/src/support
  ${CMAKE_CURRENT_BINARY_DIR}/generated
  )

#file(GLOB antlr4-demo_SRC "${PROJECT_SOURCE_DIR}/demo/generated/*")
set(antlr4-parser_SRC 
  ${CMAKE_CURRENT_SOURCE_DIR}/ParserTest.cpp
  ${antlr4-parser-GENERATED_SRC}
  )

foreach( src_file ${antlr4-parser_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS -Wno-overloaded-virtual
          )
endforeach( src_file ${antlr4-parse_SRC} )

add_custom_target(antlr4-files
          ${antlr4-parser_SRC}
	  #DEPENDS GenerateParser
          )

#add_dependencies(antlr4-files GenerateParser)


#add_executable(antlr4-demo
#  ${antlr4-parser_SRC}
#  )
#add_precompiled_header(antlr4-demo ${PROJECT_SOURCE_DIR}/runtime/src/antlrcpp-Prefix.h)

#add_dependencies(antlr4-demo GenerateParser)

#target_link_libraries(antlr4-demo antlr4_static)

#install(TARGETS antlr4-demo 
#        DESTINATION "share" 
#        COMPONENT dev 
#        )


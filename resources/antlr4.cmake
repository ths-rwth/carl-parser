find_program(MAVEN mvn)
if(NOT MAVEN)
    message(SEND_ERROR "Can not build ANTLR4, missing binary for maven")
endif()

find_path(UUID_PATH NAMES uuid/uuid.h)
if(NOT UUID_PATH)
    message(WARNING "Building ANTLR4 C++ runtime will probably fail, could not find uuid.h")
endif()

ExternalProject_Add(
        ANTLR
        GIT_REPOSITORY "https://github.com/antlr/antlr4.git"
        GIT_TAG "${ANTLR_VERSION}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND mvn clean
        BUILD_COMMAND mvn -DskipTests package -pl tool -am
        INSTALL_COMMAND ""
)

ExternalProject_Get_Property(ANTLR SOURCE_DIR)

set(ANTLR_JAR "${SOURCE_DIR}/tool/target/antlr4-${ANTLR_VERSION}-complete.jar")
set(ANTLR-runtime_TARGETS "antlr4_shared")

ExternalProject_Add(
        ANTLR-runtime
        DOWNLOAD_COMMAND ""
        SOURCE_DIR "${SOURCE_DIR}"
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -G${CMAKE_GENERATOR} -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=ON -BUILD_TESTS=OFF  "<SOURCE_DIR>/runtime/Cpp" -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        BUILD_COMMAND make -j4 ${ANTLR-runtime_TARGETS}
)

ExternalProject_Get_Property(ANTLR-runtime INSTALL_DIR)
file(TO_CMAKE_PATH ${INSTALL_DIR} INSTALL_DIR)

add_library(antlr4shared SHARED IMPORTED GLOBAL)
file(MAKE_DIRECTORY "${INSTALL_DIR}/include")
file(MAKE_DIRECTORY "${INSTALL_DIR}/include/antlr4-runtime")
message("${INSTALL_DIR}/lib/libantlr4-runtime${DYNAMIC_EXT}")

set_target_properties(antlr4shared PROPERTIES IMPORTED_LOCATION ${INSTALL_DIR}/lib/libantlr4-runtime${DYNAMIC_EXT})

set_target_properties(antlr4shared PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${INSTALL_DIR}/include;${INSTALL_DIR}/include/antlr4-runtime")

add_dependencies(ANTLR-runtime ANTLR)
add_dependencies(antlr4shared ANTLR-runtime)

mark_as_advanced(MAVEN)
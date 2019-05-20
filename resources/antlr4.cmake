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
	GIT_REPOSITORY "https://github.com/volkm/antlr4.git"
	#GIT_TAG "${ANTLR_VERSION}"
	GIT_TAG "rpath_fix"
	BUILD_IN_SOURCE 1
	UPDATE_COMMAND ""
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
)

ExternalProject_Get_Property(ANTLR SOURCE_DIR)
ExternalProject_Get_Property(ANTLR INSTALL_DIR)

if (BUILD_JAR)
	ExternalProject_Add(
		ANTLR-jar
		EXCLUDE_FROM_ALL 1
		DOWNLOAD_COMMAND ""
		SOURCE_DIR "${SOURCE_DIR}"
		BUILD_IN_SOURCE 1
		UPDATE_COMMAND ""
		CONFIGURE_COMMAND mvn clean
		BUILD_COMMAND mvn -DskipTests package -pl tool -am
		INSTALL_COMMAND ""
	)
endif()

set(ANTLR-runtime_TARGETS "antlr4_shared")

ExternalProject_Add(
	ANTLR-runtime
	DOWNLOAD_COMMAND ""
	SOURCE_DIR "${SOURCE_DIR}"
	UPDATE_COMMAND ""
	CONFIGURE_COMMAND ${CMAKE_COMMAND} -G${CMAKE_GENERATOR} -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=ON -DBUILD_TESTS=OFF  -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR> "<SOURCE_DIR>/runtime/Cpp" -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
	BUILD_COMMAND ${CMAKE_COMMAND} --build . --target antlr4_shared
	COMMAND ${CMAKE_COMMAND} --build . --target antlr4_static
	BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/resources/lib/libantlr4-runtime${DYNAMIC_EXT}
)

ExternalProject_Get_Property(ANTLR-runtime INSTALL_DIR)

file(MAKE_DIRECTORY "${INSTALL_DIR}/include")
file(MAKE_DIRECTORY "${INSTALL_DIR}/include/antlr4-runtime")

add_library(antlr4shared SHARED IMPORTED GLOBAL)
set_target_properties(antlr4shared PROPERTIES IMPORTED_LOCATION ${INSTALL_DIR}/lib/libantlr4-runtime${DYNAMIC_EXT})
set_target_properties(antlr4shared PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${INSTALL_DIR}/include;${INSTALL_DIR}/include/antlr4-runtime")

add_library(antlr4static STATIC IMPORTED GLOBAL)
set_target_properties(antlr4static PROPERTIES IMPORTED_LOCATION ${INSTALL_DIR}/lib/libantlr4-runtime${STATIC_EXT})
set_target_properties(antlr4static PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${INSTALL_DIR}/include;${INSTALL_DIR}/include/antlr4-runtime")

if (USE_SHIPPED_JAR)
	add_dependencies(ANTLR-jar ANTLR)
endif()
add_dependencies(ANTLR-runtime ANTLR)
add_dependencies(antlr4shared ANTLR-runtime)
add_dependencies(antlr4static ANTLR-runtime)

mark_as_advanced(MAVEN)

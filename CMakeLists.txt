cmake_minimum_required(VERSION 3.1)

project(main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
	
add_executable(main src/main/main.cpp)

include_directories(${CMAKE_SOURCE_DIR})

set_property(GLOBAL PROPERTY TARGET_LIST main)

function(create_library LIBNAME)
	include_directories("src/${LIBNAME}")
	set(SOURCES src/${LIBNAME}/${LIBNAME}.cpp)
	set(HEADERS src/${LIBNAME}/${LIBNAME}.h)
	add_library(${LIBNAME} SHARED ${SOURCES} ${HEADERS})
	target_include_directories(${LIBNAME} PUBLIC ${PROJECT_SOURCE_DIR})

	get_property(TARGET_LIST_VAR GLOBAL PROPERTY TARGET_LIST)

	foreach(NAME ${TARGET_LIST_VAR})
		target_link_libraries(${NAME} ${LIBNAME})
		message("Linking ${LIBNAME} to ${NAME}")
	endforeach()

	set_property(GLOBAL PROPERTY TARGET_LIST "${TARGET_LIST_VAR};${LIBNAME}")
endfunction()

create_library(application)
create_library(interface)
create_library(comment)
create_library(registration)
create_library(square)
create_library(graphics)
create_library(utility)

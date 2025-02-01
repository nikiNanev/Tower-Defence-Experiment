cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

project(TDE VERSION 1.0.0)

file(GLOB_RECURSE SOURCE_DIRECTORIES_AND_FILES LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE INCLUDE_DIRECTORIES_AND_FILES LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/include/*.h")

set(SOURCE_DIRECTORIES "")
foreach(ITEM ${SOURCE_DIRECTORIES_AND_FILES})
    if(IS_DIRECTORY ${ITEM})
        list(APPEND SOURCE_DIRECTORIES ${ITEM})
    endif()
endforeach()

set(SRC_FILES "")
foreach(ITEM ${SOURCE_DIRECTORIES_AND_FILES})
    if(NOT IS_DIRECTORY ${ITEM})
        list(APPEND SRC_FILES ${ITEM})
    endif()
endforeach()

set(INCLUDE_DIRECTORIES "")
foreach(ITEM ${INCLUDE_DIRECTORIES_AND_FILES})
    if(IS_DIRECTORY ${ITEM})
        list(APPEND INCLUDE_DIRECTORIES ${ITEM})
    endif()
endforeach()

find_package(glfw3 REQUIRED)

#Append main.cpp to SOURCE_DIRECTORIES
list(APPEND SOURCE_DIRECTORIES "${CMAKE_SOURCE_DIR}/src/*")

message(STATUS "Sources found: ${SOURCE_DIRECTORIES}")
message(STATUS "includes found: ${INCLUDE_DIRECTORIES}")
message(STATUS "Source files found: ${SRC_FILES}")

include_directories("${INCLUDE_DIRECTORIES}")


add_library(glad STATIC include/lib/glad/glad.c)
target_include_directories(glad PUBLIC include/lib/glad)



add_executable(tde ${SRC_FILES}) #main

set_target_properties(tde PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(tde PRIVATE ${INCLUDE_FILES})


target_link_libraries(tde PRIVATE glfw3 pthread glad GL dl X11)


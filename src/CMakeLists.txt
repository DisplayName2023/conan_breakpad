cmake_minimum_required(VERSION 3.28)


set( CMAKE_CXX_STANDARD 20 )

# file( GLOB_RECURSE _headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.hpp" )
file( GLOB_RECURSE _headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.h" )

add_library( ${PROJECT_NAME}
    Example.cpp
    ${_headers}
    )


target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)


find_package(Microsoft.GSL REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Microsoft.GSL_INCLUDE_DIRS})


find_package(unofficial-breakpad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::breakpad::libbreakpad unofficial::breakpad::libbreakpad_client)

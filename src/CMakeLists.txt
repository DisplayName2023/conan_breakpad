cmake_minimum_required(VERSION 3.28)


set( CMAKE_CXX_STANDARD 20 )

# file( GLOB_RECURSE _headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.hpp" )
# file( GLOB_RECURSE _headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.h" )
file( GLOB _headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.h" )

add_library( ${PROJECT_NAME}
    Breakpad.cpp
    ${_headers}
    )


target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)


# Specify the path to the directory containing your libraries
set(LIB_DIR "${CMAKE_SOURCE_DIR}/src/solution")

# Link the appropriate library based on the configuration
target_link_libraries(${PROJECT_NAME}  PRIVATE
    ${LIB_DIR}/x64/Release/BreakpadDll.lib
)

# Optionally, specify the include directories if your libraries have headers
target_include_directories(${PROJECT_NAME} PRIVATE "${LIB_DIR}/BreakpadDll")




find_package(Microsoft.GSL REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Microsoft.GSL_INCLUDE_DIRS})

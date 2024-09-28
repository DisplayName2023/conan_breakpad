cmake_minimum_required(VERSION 3.28)

#==============================================================================
# set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum OS X deployment version")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE) 

project( BreakpadCpp LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 20 )

if (WIN32) 
    set (CMAKE_CXX_FLAGS "/EHsc") 
endif()

set( INTERPROCEDURAL_OPTIMIZATION OFF )
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
set( CMAKE_MAP_IMPORTED_CONFIG_DEBUG RELEASE )
set( CMAKE_MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE )


# Set the runtime library based on the configuration type
if(MSVC)
    # Check for configurations
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        # Release configuration uses the default settings
        message(STATUS "Using default runtime for Release")
    else()
        # For all other configurations (Debug, RelWithDebInfo, etc.), use /MD
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
        message(STATUS "Using /MD for non-Release configurations")
    endif()
endif()


add_subdirectory(src)


if( IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test )
    add_subdirectory(test)
endif()

cmake_minimum_required(VERSION 3.28)

#==============================================================================
# set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum OS X deployment version")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE) 

project( BreakpadCppSample LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 20 )

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


add_executable( ${PROJECT_NAME}
    main.cpp
    InvalidFunctions.h
    InvalidFunctions.cpp
    )

find_package(conan_breakpad REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${conan_breakpad_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${conan_breakpad_LIBRARIES})


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_BINARY_DIR}/bin $<TARGET_FILE_DIR:${PROJECT_NAME}> 
  COMMAND_EXPAND_LISTS
)


project( UnitTest )

# Add the test executable
add_executable(${PROJECT_NAME} Program.cpp)

# Find GTest
find_package(gtest REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${GTest_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTest_LIBRARIES})

target_link_libraries(${PROJECT_NAME} BreakpadCpp)


# Enable testing
enable_testing()

# Add a test
add_test(NAME AddTest COMMAND ${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different $<TARGET_FILE_DIR:BreakpadCpp> $<TARGET_FILE_DIR:${PROJECT_NAME}> 
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/src/solution/x64/Release $<TARGET_FILE_DIR:${PROJECT_NAME}> 
  COMMAND_EXPAND_LISTS
)
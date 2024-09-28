
project( ConsoleTest )


add_executable(${PROJECT_NAME} Program.cpp)



target_link_libraries(${PROJECT_NAME} BreakpadCpp)




add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different $<TARGET_FILE_DIR:BreakpadCpp> $<TARGET_FILE_DIR:${PROJECT_NAME}> 
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/src/solution/x64/Release $<TARGET_FILE_DIR:${PROJECT_NAME}> 
  COMMAND_EXPAND_LISTS
)
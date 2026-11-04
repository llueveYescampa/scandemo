# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
  
#Create a variable called linalg_SOURCES containing all .cpp files:


set(scandemo_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/scandemo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/message.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/check_specified_item.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/output_command.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/input_command.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/process_list.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/process_tokens_on_line.cpp
    PARENT_SCOPE
   )

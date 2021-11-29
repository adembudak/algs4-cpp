function(add_algs4_test name)
  set (options)
  set (one_value_args SOURCE WORKING_DIR)
  set (multi_value_args LINK ARGUMENTS)

  cmake_parse_arguments (${name} "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  add_executable (${name} ${${name}_SOURCE})
  target_link_libraries (${name} PRIVATE ${${name}_LINK})

  add_test (
    NAME ${name}
    COMMAND ${name} ${${name}_ARGUMENTS}
    WORKING_DIRECTORY ${${name}_WORKING_DIR})
endfunction()

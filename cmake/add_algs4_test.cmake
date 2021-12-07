function(add_algs4_test name)
  set (options TAKE_INPUT_FROM_STDIN)
  set (one_value_args WORKING_DIR)
  set (multi_value_args ARGUMENTS)

  cmake_parse_arguments (${name} "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(${${name}_TAKE_INPUT_FROM_STDIN})
    find_program (SHELL NAMES bash sh fish)
    add_test (
      NAME ${name}
      COMMAND ${SHELL} ${ALGS4_SOURCE_DIR}/cmake/from_stdin.sh ${name} ${${name}_ARGUMENTS}
      WORKING_DIRECTORY ${${name}_WORKING_DIR})
  else()
    add_test (
      NAME ${name}
      COMMAND ${name} ${${name}_ARGUMENTS}
      WORKING_DIRECTORY ${${name}_WORKING_DIR})
  endif()
endfunction()

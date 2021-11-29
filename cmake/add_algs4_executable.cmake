function(add_algs4_executable name)
  set (options)
  set (one_value_args SOURCE)
  set (multi_value_args LINK)

  cmake_parse_arguments (${name} "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  add_executable (${name} ${${name}_SOURCE})
  target_link_libraries (${name} PRIVATE ${${name}_LINK})
endfunction()

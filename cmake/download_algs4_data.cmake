function(download url output)
  file (
    DOWNLOAD ${url} ${output}
    SHOW_PROGRESS
    STATUS status)

  list (POP_FRONT ${status} success)
  if(NOT ${success})
    list (POP_BACK ${status} why)
    message (INFO "${why}")
  endif()

endfunction()

function(extract file where)
  file (ARCHIVE_EXTRACT INPUT ${file} DESTINATION ${where} VERBOSE)
endfunction()

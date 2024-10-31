include (FetchContent)

set (FETCHCONTENT_TRY_FIND_PACKAGE_MODE ALWAYS)

find_package (ftxui QUIET)
if(NOT ftxui_FOUND)
  message (STATUS "Getting dependency: FTXUI")
  fetchcontent_declare (FTXUI URL https://github.com/ArthurSonzogni/FTXUI/archive/refs/tags/v5.0.0.zip
                                  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  fetchcontent_makeavailable (FTXUI)
endif()

find_package (httplib QUIET)
if(NOT httplib_FOUND)
  message (STATUS "Getting dependency: cpp-htttplib")
  fetchcontent_declare (httplib URL https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.18.1.zip
                                    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
  fetchcontent_makeavailable (httplib)
endif()

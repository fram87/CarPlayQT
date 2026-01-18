# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GitCarPlAyQT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GitCarPlAyQT_autogen.dir/ParseCache.txt"
  "GitCarPlAyQT_autogen"
  )
endif()

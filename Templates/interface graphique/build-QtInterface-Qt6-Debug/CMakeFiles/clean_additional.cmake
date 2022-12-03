# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CC_autogen"
  "CMakeFiles/CC_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CC_autogen.dir/ParseCache.txt"
  )
endif()

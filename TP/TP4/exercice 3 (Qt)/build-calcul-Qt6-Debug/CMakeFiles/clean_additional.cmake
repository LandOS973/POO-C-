# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/calcul_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/calcul_autogen.dir/ParseCache.txt"
  "calcul_autogen"
  )
endif()

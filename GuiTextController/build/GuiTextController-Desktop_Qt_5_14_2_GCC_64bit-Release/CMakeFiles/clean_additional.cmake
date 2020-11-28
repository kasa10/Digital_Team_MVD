# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/SmartReferenceGUI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SmartReferenceGUI_autogen.dir/ParseCache.txt"
  "SmartReferenceGUI_autogen"
  )
endif()

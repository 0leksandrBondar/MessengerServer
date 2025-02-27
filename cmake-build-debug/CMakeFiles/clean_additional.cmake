# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Source\\CMakeFiles\\MessengerServer_autogen.dir\\AutogenUsed.txt"
  "Source\\CMakeFiles\\MessengerServer_autogen.dir\\ParseCache.txt"
  "Source\\MessengerServer_autogen"
  )
endif()

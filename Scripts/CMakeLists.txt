# CMakeList.txt : CMake project for Recreate_Standard_Functions, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Recreate_Standard_Functions "Main.c" "Main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Recreate_Standard_Functions PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()


message("${BoldYellow}========================")
message("orbitalgui starting")
message("========================${ColourReset}")

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

#Armadillo Library
#find_package(Armadillo REQUIRED)
#include_directories(${ARMADILLO_INCLUDE_DIRS})
#message("${Green}== Found Armadillo version ${ARMADILLO_VERSION_STRING}${ColourReset}")

link_directories(${GTKMM_LIBRARY_DIRS})

set(INCL
	windows
	)
include_directories(${INCL} ${GTKMM_INCLUDE_DIRS})

set(SRCS
	orbitgui.cpp
	windows/mainwin.cpp
	)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable(orbitalgui ${SRCS})

target_link_libraries(orbitalgui ${GTKMM_LIBRARIES})

message("${BoldYellow}========================")
message("orbitalgui done")
message("========================${ColourReset}")

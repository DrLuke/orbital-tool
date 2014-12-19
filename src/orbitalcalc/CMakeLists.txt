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
message("orbitalcalc starting")
message("========================${ColourReset}")

#Armadillo Library
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
message("${Green}== Found Armadillo version ${ARMADILLO_VERSION_STRING}${ColourReset}")

set(INCL
	space
	craft
	body
	time
	)
include_directories(${INCL})

set(SRCS
	main.cpp
	space/space.cpp
	body/body.cpp
	craft/craft.cpp
	time/julian.cpp
	)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable(orbitalcalc ${SRCS})

target_link_libraries(orbitalcalc ${ARMADILLO_LIBRARIES})

message("${BoldYellow}========================")
message("orbitalcalc done")
message("========================${ColourReset}")

cmake_minimum_required(VERSION 3.16)

project(
	"The Fighting Game Kernel (fgk)"
  VERSION
  1.0
  LANGUAGES
  CXX
)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(fgk ${SRC_FILES})
target_include_directories(fgk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
find_package(SFML 2 REQUIRED network audio graphics window system) 
target_include_directories(fgk PUBLIC ${SFML_INCLUDE_DIR}) 
target_link_libraries(fgk sfml-graphics)

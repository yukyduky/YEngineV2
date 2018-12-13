cmake_minimum_required (VERSION 3.8)

# List source file directories
file(GLOB_RECURSE SRC
	"*.h"
	"*.hpp"
	"*.cpp"
)

add_executable(tests ${SRC})

target_link_libraries(tests ${PROJECT_NAME} gtest gmock_main)
target_include_directories(${PROJECT_NAME} PUBLIC "${BINARY_DIR_TOP}/src/source")

add_test(NAME tests COMMAND tests)
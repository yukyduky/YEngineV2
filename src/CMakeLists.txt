cmake_minimum_required(VERSION 3.8)

# List source file directories
file(GLOB_RECURSE "${PROJECT_NAME}_SRC"
	"*.cpp"
	"*.h"
	"*.hpp"
)

# Create virtual folders to make it look nicer in VS
if(MSVC)
	set(curdir get_filename_component(${CMAKE_CURRENT_BINARY_DIR}))

	# Macro to preserve source files hierarchy in the IDE
	macro(GroupSources curdir)
		file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

		foreach(child ${children})
			if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
				GroupSources(${curdir}/${child})
			else()
				string(REPLACE "/" "\\" groupname ${curdir})
				string(REPLACE "src" "Sources" groupname ${groupname})
				source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
			endif()
		endforeach()
	endmacro()

	# Run macro
	GroupSources(src)
endif()

# Add source to this project's executable.
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC})

target_link_libraries(${PROJECT_NAME} general "${BINARY_DIR_TOP}/libs/x86/glfw/glfw3.lib")

target_link_libraries(${PROJECT_NAME} general "${BINARY_DIR_TOP}/libs/x86/assimp/assimp.lib")

target_link_libraries(${PROJECT_NAME} general "${BINARY_DIR_TOP}/libs/x86/sfml/openal32.lib")

target_link_libraries(${PROJECT_NAME} debug "${BINARY_DIR_TOP}/libs/x86/sfml/debug/sfml-audio-d.lib")
target_link_libraries(${PROJECT_NAME} debug "${BINARY_DIR_TOP}/libs/x86/sfml/debug/sfml-graphics-d.lib")
target_link_libraries(${PROJECT_NAME} debug "${BINARY_DIR_TOP}/libs/x86/sfml/debug/sfml-main-d.lib")
target_link_libraries(${PROJECT_NAME} debug "${BINARY_DIR_TOP}/libs/x86/sfml/debug/sfml-system-d.lib")
target_link_libraries(${PROJECT_NAME} debug "${BINARY_DIR_TOP}/libs/x86/sfml/debug/sfml-window-d.lib")

target_link_libraries(${PROJECT_NAME} optimized "${BINARY_DIR_TOP}/libs/x86/sfml/release/sfml-audio.lib")
target_link_libraries(${PROJECT_NAME} optimized "${BINARY_DIR_TOP}/libs/x86/sfml/release/sfml-graphics.lib")
target_link_libraries(${PROJECT_NAME} optimized "${BINARY_DIR_TOP}/libs/x86/sfml/release/sfml-main.lib")
target_link_libraries(${PROJECT_NAME} optimized "${BINARY_DIR_TOP}/libs/x86/sfml/release/sfml-system.lib")
target_link_libraries(${PROJECT_NAME} optimized "${BINARY_DIR_TOP}/libs/x86/sfml/release/sfml-window.lib")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/interface")
target_include_directories(${PROJECT_NAME} PUBLIC "${BINARY_DIR_TOP}/includes")

# Make sure that the linker language gets set to C++
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR_TOP}/output")
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR_TOP}/output")
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${BINARY_DIR_TOP}/output")
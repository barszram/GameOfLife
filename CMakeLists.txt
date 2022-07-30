cmake_minimum_required (VERSION 3.12)

project ("GameOfLifeAgain")
set(CMAKE_CXX_STANDARD 17)


set(RAYLIB_DIR "" CACHE PATH "Raylib install directory")
message("Raylib directory: " ${RAYLIB_DIR})


set(IMGUI_DIR "" CACHE PATH "ImGui source directory")
message("ImGui directory: " ${IMGUI_DIR})
file(GLOB IMGUI_SOURCES CONFIGURE_DEPENDS ${IMGUI_DIR}/*.cpp)


set(SPDLOG_DIR "" CACHE PATH "Spdlog source directory")
message("Spdlog directory: " ${SPDLOG_DIR})
file(GLOB SPDLOG_SOURCES CONFIGURE_DEPENDS ${SPDLOG_DIR}/src/*.cpp)
add_definitions(-DSPDLOG_COMPILED_LIB)


include_directories(${RAYLIB_DIR}/include ${IMGUI_DIR} ${SPDLOG_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

set(PROJECT_SOURCES main.cpp rlImGui/rlImGui.cpp utils/argparser.cpp logic/cell_field.cpp logic/game_of_life.cpp graphics/cell_board.cpp graphics/cell.cpp logic/controls.cpp logic/controls.hpp logic/gui.cpp logic/gui.hpp)

add_executable (${PROJECT_NAME} ${IMGUI_SOURCES} ${SPDLOG_SOURCES} ${PROJECT_SOURCES})

if (WIN32)
    target_link_libraries(${PROJECT_NAME} raylib Winmm Imm32)
else()
    target_link_libraries(${PROJECT_NAME} raylib)
endif()
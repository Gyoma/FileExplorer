cmake_minimum_required(VERSION 3.15)

project(FileExplorer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 14)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH "D:\\Qt\\5.14.1\\msvc2017_64")

find_package(Qt5 COMPONENTS Core Gui Widgets Charts REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(project_ui
	ui/FileExplorer.ui
)

set(project_headers 
	include/FileExplorer.h
	include/FilePercentageStrategy.h
	include/FolderPercentageStrategy.h
	include/StrategyContext.h
	include/TypePercentageStrategy.h
	include/FileExplorerTableModel.h
	include/QChartWidget.h
)

set(project_sources 
	src/main.cpp
	src/FileExplorer.cpp
	src/FilePercentageStrategy.cpp
	src/FolderPercentageStrategy.cpp
	src/StrategyContext.cpp
	src/TypePercentageStrategy.cpp
	src/FileExplorerTableModel.cpp
	src/QChartWidget.cpp
)

qt5_wrap_ui(project_headers_wrapped ${project_ui})

add_executable(${PROJECT_NAME}
	${project_ui}
	${project_headers}
	${project_sources}
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC 
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	Qt5::Charts
)

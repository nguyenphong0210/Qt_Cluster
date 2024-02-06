cmake_minimum_required(VERSION 3.16)

project(Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Core Qml)

qt_standard_project_setup()

qt_add_executable(appCluster
    src/main.cpp
)

qt_add_qml_module(appCluster
    URI Cluster
    VERSION 1.0
    QML_FILES Main.qml
)

add_subdirectory(content)
add_subdirectory(Backend)


target_link_libraries(appCluster PRIVATE
    Qt6::Quick
    Qt6::Qml
    Cluster_contentplugin
    Cluster_Backend
)


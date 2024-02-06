find_package(Qt6 REQUIRED COMPONENTS Gui Quick)

qt_add_library(Cluster_Backend STATIC
    Director.h
    Director.cpp
    dataThreading.h
    dataThreading.cpp
    ViewControlIF.h
    BaseViewControl.h
    BaseViewControl.cpp
    GaugesViewControl.h
    GaugesViewControl.cpp
)

add_subdirectory(DataModel)

target_link_libraries(Cluster_Backend PUBLIC
    Qt6::Gui
    DataModel_module
)

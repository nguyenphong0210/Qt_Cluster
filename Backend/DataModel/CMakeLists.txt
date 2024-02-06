find_package(Qt6 REQUIRED COMPONENTS Gui)

qt_add_library(DataModel_module STATIC
    DataDef.h
    DataModel.h
    DataModel.cpp
    DataSet.h
    DataSet.cpp
)


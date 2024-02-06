qt_add_library(Cluster_content STATIC)

find_package(Qt6 REQUIRED COMPONENTS Core Qml)

qt6_add_qml_module(Cluster_content
    URI "content"
    VERSION 1.0
    QML_FILES
        App.qml
        MainForm.ui.qml
    RESOURCES
        images/girl.png
)
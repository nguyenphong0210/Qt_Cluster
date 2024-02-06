import QtQuick 2.8
import QtQuick.Controls

Rectangle {
    id: mainFile
    width: 800
    height: 400
    color: "#ff262a"

    Label {
        id: label
        x: 180
        y: 141
        text: GaugesControl.SpeedValue
    }
}

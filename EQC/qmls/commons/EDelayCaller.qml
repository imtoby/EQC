pragma Singleton
import QtQuick 2.12

Item {
    id: e_delay_caller
    objectName: "EDelayCaller.qml"

    function run(interval, callback) {
        const delaycaller = e_delay_caller_component.createObject(
                              null, {"interval": interval});
        delaycaller.triggered.connect(function(){
            if (typeof delaycaller.destroy != "undefined") {
                callback();
                delaycaller.destroy();
            }
        });
        delaycaller.start();
    }

    Component {
        id: e_delay_caller_component
        ETimer {
            objectName: "EDelayCaller.qml.ETimer"
        }
    }
}

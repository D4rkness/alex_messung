#include <QApplication>
#include <src/model/DataModel.h>
#include <src/controller/Controller.h>
#include "src/view/mainscreen/mainwindow.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    ModelMessageHandler messageHandler;
    MainWindow w(0, messageHandler);
    DataModel dataModel(messageHandler);
    Controller controller = Controller(dataModel);
    w.setController(controller);

    w.show();
    return a.exec();
}

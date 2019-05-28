#include <QApplication>
#include <src/model/DataModel.h>
#include "src/view/mainscreen/mainwindow.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    DataModel model;

    w.show();
    return a.exec();
}

#pragma once

#include <QtCore/QObject>

class ModelMessageHandler: public QObject{
    Q_OBJECT


public:
    // ModelMessageHandler();

    void meh();

signals:

    void start_Dataloading();
    void progress_on_Dataloading(int percent);
    void finish_Dataloading();

    void start_Datacleaning();
    void progress_DataCleaning(int percent);
    void finish_DataCleaning();

    void start_datacomputation();
    void progress_datacomputation();
    void finish_datacomputation();

    void start_Dataexport();
    void progress_Dataexport(int percent);
    void finish_Dataexport();

    void start_Quickexport();
    void progress_Quickexport(int percent);
    void finish_Quickexport();

};

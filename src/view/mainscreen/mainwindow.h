#pragma once

#include <QtCore/QArgument>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <src/controller/Controller.h>
#include <QtWidgets/QProgressDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent, ModelMessageHandler &modelMessageHandler);

    ~MainWindow();

    void setController(Controller &controller);

private:
    Ui::MainWindow *ui;
    Controller *controller;
    QProgressDialog* progressDialog;


private slots:
    void selectInputPath();
    void selectOutputPath();
    void loadData();
    void computeLoadedData();
    void exportData();
    void quickExport();

    void formChanged();
    void typeChanged();

    void show_data_loading();
    void show_data_loading_progress(int percent);
    void finish_data_loading();

    void show_data_cleaning();
    void show_data_cleaning_progress(int percent);
    void finish_data_cleaning();

    void start_datacomputation();
    void progress_datacomputation(int progress);
    void finish_datacomputation();

    void set_data_computation_progress(int percent);
};

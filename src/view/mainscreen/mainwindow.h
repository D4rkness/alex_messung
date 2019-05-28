#pragma once

#include <QtCore/QArgument>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void selectInputPath();
    void selectOutputPath();
    void loadData();
    void computeLoadedData();
    void exportData();
    void quickExport();

};

#include <QtWidgets/QFileDialog>
#include "mainwindow.h"
#include "ui_main_screen.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnSelecInputPath, SIGNAL(clicked()), this, SLOT(selectInputPath()));
    connect(ui->btnSelectOutputPath, SIGNAL(clicked()), this, SLOT(selectOutputPath()));
    connect(ui->btnLoadData, SIGNAL(clicked()), this, SLOT(loadData()));
    connect(ui->btnComputeData, SIGNAL(clicked()), this, SLOT(computeLoadedData()));
    connect(ui->btnExportData, SIGNAL(clicked()), this, SLOT(exportData()));
    connect(ui->btnQuickExport, SIGNAL(clicked()), this, SLOT(quickExport()));

    ui->btnQuickExport->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectInputPath() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Load Measurement"), "./", tr("Exel Files (*.xls *.xlsx )"));
    if(fileName.length() < 1)
        return;
    ui->leInputPath->setText(fileName);
}

void MainWindow::selectOutputPath() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Converted Data"), "./", tr("Exel Files (*.xls *.xlsx )", ".xls"));
    if(fileName.length() < 1)
        return;

    if(!fileName.contains(".xls") && !fileName.contains(".xlsx")){
        fileName.append(".xls");
    }
    ui->leOutputPath->setText(fileName);
}

void MainWindow::loadData() {

}

void MainWindow::computeLoadedData() {

}

void MainWindow::exportData() {

}

void MainWindow::quickExport() {

}

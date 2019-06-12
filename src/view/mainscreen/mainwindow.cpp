#include <QtWidgets/QFileDialog>
#include "mainwindow.h"
#include "ui_main_screen.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent, ModelMessageHandler& modelMessageHandler) :
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

    connect(&modelMessageHandler, SIGNAL(start_Dataloading()), this, SLOT(show_data_loading()));
    connect(&modelMessageHandler, SIGNAL(progress_on_Dataloading(int)), this, SLOT(show_data_loading_progress(int)));
    connect(&modelMessageHandler, SIGNAL(finish_Dataloading()), this, SLOT(finish_data_loading()));

    connect(&modelMessageHandler, SIGNAL(start_Datacleaning()), this, SLOT(show_data_cleaning()));
    connect(&modelMessageHandler, SIGNAL(progress_DataCleaning(int)), this, SLOT(show_data_cleaning_progress(int)));
    connect(&modelMessageHandler, SIGNAL(finish_DataCleaning()), this, SLOT(finish_data_cleaning()));

    ui->btnQuickExport->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setController(Controller &controller) {
    this->controller = &controller;
}
void MainWindow::selectInputPath() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Load Measurement"), "./", tr("Exel Files (*.xls *.xlsx )"));
    if(fileName.length() < 1)
        return;
    ui->leInputPath->setText(fileName);
    controller->setInputPath(fileName.toStdString());
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
    controller->setOutputPath(fileName.toStdString());
}

void MainWindow::loadData() {
    controller->loadData();
}

void MainWindow::computeLoadedData() {
    if(ui->rbCircular->isChecked()){

    } else if (ui->rbRectangular->isChecked()){

        controller->computeData(
                ui->txtLenght->text().toDouble(),
                ui->txtHeight->text().toDouble(),
                ui->txtWidth->text().toDouble(),
                ui->txtExtra->text().toDouble()
        );

    }
}

void MainWindow::exportData() {
    progressDialog = new QProgressDialog("Task in progress.", "Cancel", 0, 100000);
}

void MainWindow::quickExport() {

}

void MainWindow::formChanged() {
    if(ui->rbRectangular->isChecked()){
        // Here change text and input field names
        controller->setFormType(RadioButtonTypes::FormType::RECTANGULAR);
    } else if (ui->rbCircular->isChecked()) {
        // Here change text and input field names
        controller->setFormType(RadioButtonTypes::FormType::CYRCLE);
    }
}

void MainWindow::typeChanged() {
    if(ui->rbTypeA->isChecked()){
        controller->setMeasureType(RadioButtonTypes::MeasureType::A);
    } else if (ui->rbTypeB->isChecked()){
        controller->setMeasureType(RadioButtonTypes::MeasureType::B);
    } else if (ui->rbTypeB->isChecked()){
        controller->setMeasureType(RadioButtonTypes::MeasureType::B);
    }
}

void MainWindow::show_data_loading() {
    std::cout << "Started Dataloading" << std::endl;
}

void MainWindow::show_data_loading_progress(int percent) {
    std::cout << "Dataloding Progress: " << std::to_string(percent) << std::endl;
}

void MainWindow::finish_data_loading() {
    std::cout << "Finished Dataloading" << std::endl;
}


void MainWindow::show_data_cleaning() {
    std::cout << "Started Datacleaning" << std::endl;
}

void MainWindow::show_data_cleaning_progress(int percent) {
    std::cout << "Cleaning Progress: " << std::to_string(percent) << std::endl;
}

void MainWindow::finish_data_cleaning() {
    std::cout << "Finished Datacleaning" << std::endl;
}

void MainWindow::set_data_computation_progress(int percent) {
    std::cout << "DataComputation Progress: " << std::to_string(percent) << std::endl;
}

void MainWindow::start_datacomputation() {

}

void MainWindow::progress_datacomputation(int progress) {

}

void MainWindow::finish_datacomputation() {

}

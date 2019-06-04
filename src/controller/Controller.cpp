//
// Created by main on 5/28/19.
//

#include "Controller.h"

Controller::Controller(DataModel &dataModel1) {
    this->dataModel = &dataModel1;
}

void Controller::setInputPath(const std::string& path) {
    dataModel->setInputPath(path);
}

void Controller::setOutputPath(const std::string& path) {
    dataModel->setOutputPath(path);
}

void Controller::setMeasureType(RadioButtonTypes::MeasureType type) {
    dataModel->setSelectedMeasureType(type);
}

void Controller::setFormType(RadioButtonTypes::FormType type) {
    dataModel->setSelectedFormType(type);
}

void Controller::loadData() {
    dataModel->loadDataFromFile();
}

void Controller::computeData(double length, double height, double width, double extra) {

}

void Controller::computeData(double diameter, double width, double extra) {

}

void Controller::exportData() {

}

void Controller::quickExportData() {

}





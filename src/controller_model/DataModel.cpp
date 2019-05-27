//
// Created by main on 5/27/19.
//

#include "DataModel.h"

DataModel::DataModel() {
    inputPath = "";
    outputPath = "";
    selectedMeasureType = RadioButtonTypes::MeasureType::A;
    selectedFormType = RadioButtonTypes::FormType::RECTANGULAR;
    measureDataContainer = std::vector<Measure>();
    rawDataBufferContainer = std::vector<MeasurePoint>();
}

const std::string &DataModel::getInputPath() const {
    return inputPath;
}

void DataModel::setInputPath(const std::string &inputPath) {
    DataModel::inputPath = inputPath;
}

const std::string &DataModel::getOutputPath() const {
    return outputPath;
}

void DataModel::setOutputPath(const std::string &outputPath) {
    DataModel::outputPath = outputPath;
}

RadioButtonTypes::MeasureType DataModel::getSelectedMeasureType() const {
    return selectedMeasureType;
}

void DataModel::setSelectedMeasureType(RadioButtonTypes::MeasureType selectedMeasureType) {
    DataModel::selectedMeasureType = selectedMeasureType;
}

RadioButtonTypes::FormType DataModel::getSelectedFormType() const {
    return selectedFormType;
}

void DataModel::setSelectedFormType(RadioButtonTypes::FormType selectedFormType) {
    DataModel::selectedFormType = selectedFormType;
}

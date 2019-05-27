#pragma once

#include <string>
#include <vector>
#include "Measure.h"

namespace RadioButtonTypes{
    enum MeasureType {
        A, B, C
    };
    enum FormType {
        RECTANGULAR, CYRCLE
    };
}

class DataModel {
public:
    DataModel();

private:
    std::string inputPath;

public:
    const std::string &getInputPath() const;

    void setInputPath(const std::string &inputPath);

    const std::string &getOutputPath() const;

    void setOutputPath(const std::string &outputPath);

    RadioButtonTypes::MeasureType getSelectedMeasureType() const;

    void setSelectedMeasureType(RadioButtonTypes::MeasureType selectedMeasureType);

    RadioButtonTypes::FormType getSelectedFormType() const;

    void setSelectedFormType(RadioButtonTypes::FormType selectedFormType);

    // void loadRawDataFrom
private:
    std::string outputPath;
    RadioButtonTypes::MeasureType selectedMeasureType;
    RadioButtonTypes::FormType  selectedFormType;
    std::vector<Measure> measureDataContainer;

    std::vector<MeasurePoint> rawDataBufferContainer; // Mhhh maybe not needed ?

public:



};


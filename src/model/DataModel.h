#pragma once

#include <string>
#include <vector>
#include "Measure.h"
#include "ModelMessageHandler.h"

namespace RadioButtonTypes{
    enum MeasureType {
        A, B, C
    };
    enum FormType {
        RECTANGULAR, CYRCLE
    };
}

class DataModel{



private:
    std::string inputPath;
    std::string outputPath;
    RadioButtonTypes::MeasureType selectedMeasureType;
    RadioButtonTypes::FormType  selectedFormType;

    std::vector<Measure> measureDataContainer;

    ModelMessageHandler* messageHandler;

public:

    DataModel(ModelMessageHandler& messageHandler);

    const std::string &getInputPath() const;
    RadioButtonTypes::FormType getSelectedFormType() const;
    const std::string &getOutputPath() const;
    RadioButtonTypes::MeasureType getSelectedMeasureType() const;

    void setInputPath(const std::string &inputPath);
    void setOutputPath(const std::string &outputPath);
    void setSelectedMeasureType(RadioButtonTypes::MeasureType selectedMeasureType);
    void setSelectedFormType(RadioButtonTypes::FormType selectedFormType);

    void loadDataFromFile();

    void computeRectangle(double length, double width, double height, double extra);;
    void computeCircle(double diameter, double height);


};


#pragma once

#include <src/model/DataModel.h>

class Controller {

public:
    Controller(DataModel &dataModel1);

    void setInputPath(const std::string& path);
    void setOutputPath(const std::string& path);

    void setMeasureType(RadioButtonTypes::MeasureType type);
    void setFormType(RadioButtonTypes::FormType type);

    void loadData();
    void computeData(double length, double height, double width, double extra);
    void computeData(double diameter, double width, double extra);
    void exportData();
    void quickExportData();


private:
    DataModel *dataModel;



};

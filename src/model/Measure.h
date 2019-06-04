#pragma once

#include <map>
#include <vector>
#include "MeasurePoint.h"

class Measure {

private:
    std::map<int , std::vector<MeasurePoint>> sectionContainer;
    int maxSections;
public:
    Measure();
    int getNumSections();
    const std::vector<MeasurePoint> *getSectionById(int id);
    const std::map<int , std::vector<MeasurePoint>> *getAllSections();
    void addMeasurePointToSection(int sectionId, MeasurePoint measurePoint);
    void removeSection(int sectionId);
    void clearAll();
};


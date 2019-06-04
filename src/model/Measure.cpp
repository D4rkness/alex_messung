//
// Created by main on 5/27/19.
//

#include "Measure.h"

Measure::Measure() {
    sectionContainer = std::map<int , std::vector<MeasurePoint>>();
    maxSections = 0;
}

int Measure::getNumSections() {
    return maxSections;
}

const std::vector<MeasurePoint> *Measure::getSectionById(int sectionId) {
    if(sectionContainer.count(sectionId) > 0){
        return &sectionContainer.at(sectionId);
    }

    return nullptr;
}

void Measure::addMeasurePointToSection(int sectionId, MeasurePoint measurePoint) {
    if(sectionContainer.count(sectionId) < 1){
        sectionContainer.insert(std::pair<int, std::vector<MeasurePoint>>(sectionId, std::vector<MeasurePoint>()) );
        if(sectionId > maxSections)
            maxSections = sectionId;
    }
    sectionContainer.at(sectionId).emplace_back(measurePoint);

}

void Measure::removeSection(int sectionId) {
    if(sectionContainer.count(sectionId) > 0)
        sectionContainer.erase(sectionId);
}

void Measure::clearAll() {
    sectionContainer.clear();
    maxSections = 0;
}

const std::map<int, std::vector<MeasurePoint>> *Measure::getAllSections() {
    return &sectionContainer;
}



#pragma once


#include <string>
#include <vector>

#include <src/controller_model/Measure.h>

namespace DataCleaner{
    void removeTransitionValues(){

    }
}

namespace DataLoader{
    int pageoffset = 3;
    int rowoffset = 3;

    char coll_time = 'A';
    char coll_cycle = 'B';
    char coll_force = 'C';
    char coll_current = 'D';
    char coll_voltage = 'E';


    void loadFileToRawDataBuffer(std::string &path, std::vector<Measure> &measureDataContainer ){

    }
}
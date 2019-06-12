#pragma once


#include <string>
#include <vector>
#include <xlnt/xlnt.hpp>
#include <iostream>



#include <src/model/Measure.h>


namespace DataCleaner{

    int running_midle_range = 4;
    int running_midle_max_deviation = 3;
    std::vector<int> middle_container = std::vector<int>();

    void removeTransitionValues(std::vector<Measure> &dirtyContainer, std::vector<Measure> &cleanContainer, ModelMessageHandler *messageHandler ){
        messageHandler->start_Datacleaning();
        for(Measure &measure : dirtyContainer){
            for(const auto& section: *measure.getAllSections()){

            }
        }

        messageHandler->finish_DataCleaning();
    }
}

namespace DataLoader{
    int rowoffset = 4;
    std::string titleNameSearch = "_Vergleich_";


    std::string coll_time = "A";
    char coll_cycle = 'B';
    char coll_force = 'C';
    char coll_current = 'D';
    char coll_voltage = 'E';



    void loadFileToRawDataBuffer(std::string &path, std::vector<Measure> &measureDataContainer, ModelMessageHandler *messageHandler ){

        messageHandler->start_Dataloading();

        xlnt::workbook wb;
        wb.load(path);

        std::vector<std::string> foundSheetNames = std::vector<std::string>();
        for(const std::string& title :wb.sheet_titles()){
            if (title.find(titleNameSearch) != std::string::npos) {
                foundSheetNames.emplace_back(title);
            }
        }

        for(std::string sheetName : foundSheetNames){

            Measure measure = Measure();

            xlnt::worksheet ws = wb.sheet_by_title(sheetName);

            bool row_empty = false;
            int row_counter = rowoffset;

            while(!row_empty){

                std::string cell_time_string = coll_time + std::to_string(row_counter);
                std::string cell_cycle_string = coll_cycle + std::to_string(row_counter);
                std::string cell_force_string = coll_force + std::to_string(row_counter);
                std::string cell_voltage_string = coll_voltage + std::to_string(row_counter);
                std::string cell_current_string = coll_current + std::to_string(row_counter);

                if( ws.cell(cell_time_string).to_string() == ""){
                    row_empty = true;
                } else {
                    measure.addMeasurePointToSection(ws.cell(cell_cycle_string).value<int>(), MeasurePoint(
                            ws.cell(cell_time_string).value<double>(),
                            ws.cell(cell_cycle_string).value<int>(),
                            ws.cell(cell_force_string).value<double>(),
                            ws.cell(cell_voltage_string).value<double>(),
                            ws.cell(cell_current_string).value<double>()
                            ));

                }
                row_counter += 1;
            }
            measureDataContainer.push_back(measure);
        }
        messageHandler->finish_Dataloading();
    }
}
namespace Datacomputation{

    void compute_circle(){

    }

    void computer_rectangle(){

    }

}
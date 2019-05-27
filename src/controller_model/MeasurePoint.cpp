//
// Created by main on 5/27/19.
//

#include "MeasurePoint.h"

MeasurePoint::MeasurePoint(double time, int cycle, double force, double current, double voltage) :
time(time), cycle(cycle), force(force), current(current), voltage(voltage) {}

double MeasurePoint::getTime() const {
    return time;
}

int MeasurePoint::getCycle() const {
    return cycle;
}

double MeasurePoint::getForce() const {
    return force;
}

double MeasurePoint::getCurrent() const {
    return current;
}

double MeasurePoint::getVoltage() const {
    return voltage;
}


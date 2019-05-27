#pragma once


class MeasurePoint {
private:
    double time;
    int cycle;
    double force;
    double current;
    double voltage;

public:
    MeasurePoint(double time, int cycle, double force, double current, double voltage);

    double getTime() const;

    int getCycle() const;

    double getForce() const;

    double getCurrent() const;

    double getVoltage() const;
};

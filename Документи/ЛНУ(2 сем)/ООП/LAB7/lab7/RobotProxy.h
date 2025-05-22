#ifndef ROBOTPROXY_H
#define ROBOTPROXY_H

#include <string>
#include <iostream>

class IRobot {
public:
    virtual void ConnectWireless(const std::string& wavelength) = 0;
    virtual void WalkStraightForward(int steps) = 0;
    virtual ~IRobot() {}
};

class RobotBombDefuser : public IRobot {
private:
    std::string connection;

public:
    void ConnectWireless(const std::string& wavelength) override;
    bool IsConnected() const;
    void WalkStraightForward(int steps) override;
};

class RobotProxy : public IRobot {
private:
    RobotBombDefuser* realRobot;
    std::string currentWavelength;

public:
    RobotProxy(RobotBombDefuser* robot);
    void ConnectWireless(const std::string& wavelength) override;
    void WalkStraightForward(int steps) override;
};

#endif 

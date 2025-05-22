#include "RobotProxy.h"

// ==== Robot ====

void RobotBombDefuser::ConnectWireless(const std::string& wavelength) {
    connection = wavelength;
    std::cout << "Robot connected to " << wavelength << std::endl;
}

bool RobotBombDefuser::IsConnected() const {
    return !connection.empty();
}

void RobotBombDefuser::WalkStraightForward(int steps) {
    std::cout << "Robot walking " << steps << " steps forward." << std::endl;
}

RobotProxy::RobotProxy(RobotBombDefuser* robot) : realRobot(robot) {}

void RobotProxy::ConnectWireless(const std::string& wavelength) {
    currentWavelength = wavelength;
    realRobot->ConnectWireless(wavelength);
}

void RobotProxy::WalkStraightForward(int steps) {
    if (realRobot->IsConnected()) {
        realRobot->WalkStraightForward(steps);
    } else {
        std::cout << "[Proxy] Connection lost. Cannot move robot." << std::endl;
    }
}

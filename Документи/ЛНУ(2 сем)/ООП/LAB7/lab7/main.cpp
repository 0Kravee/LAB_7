#include "LaptopBuilder.h"
#include "RobotProxy.h"
#include <iostream>

int main() {
    std::cout << "=== Builder Pattern: Laptop ===" << std::endl;
    LaptopBuilder builder;
    builder.CreateNewLaptop();
    builder.BuildMonitor();
    builder.BuildProcessor();
    builder.BuildRAM();
    builder.BuildStorage();

    Laptop* laptop = builder.GetLaptop();
    std::cout << laptop->ToString() << std::endl;

    std::cout << "\n=== Proxy Pattern: Robot ===" << std::endl;
    RobotBombDefuser realRobot;
    RobotProxy proxy(&realRobot);

    proxy.WalkStraightForward(5);  // fail
    proxy.ConnectWireless("5GHz");
    proxy.WalkStraightForward(5);  // success

    return 0;
}

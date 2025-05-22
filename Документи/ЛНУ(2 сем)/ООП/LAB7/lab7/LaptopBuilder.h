#ifndef LAPTOPBUILDER_H
#define LAPTOPBUILDER_H

#include <string>

class Laptop {
private:
    std::string monitor;
    std::string processor;
    std::string ram;
    std::string storage;

public:
    void setMonitor(const std::string& m);
    void setProcessor(const std::string& p);
    void setRAM(const std::string& r);
    void setStorage(const std::string& s);
    std::string ToString() const;
};

class LaptopBuilder {
private:
    Laptop* laptop;

public:
    LaptopBuilder();
    ~LaptopBuilder();
    void CreateNewLaptop();
    void BuildMonitor();
    void BuildProcessor();
    void BuildRAM();
    void BuildStorage();
    Laptop* GetLaptop() const;
};

#endif // LAPTOP_H

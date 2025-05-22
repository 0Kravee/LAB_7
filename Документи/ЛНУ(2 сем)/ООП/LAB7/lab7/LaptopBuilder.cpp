#include "LaptopBuilder.h"

// ==== Laptop ====

void Laptop::setMonitor(const std::string& m) { monitor = m; }
void Laptop::setProcessor(const std::string& p) { processor = p; }
void Laptop::setRAM(const std::string& r) { ram = r; }
void Laptop::setStorage(const std::string& s) { storage = s; }

std::string Laptop::ToString() const {
    return "Monitor: " + monitor + "\nProcessor: " + processor + "\nRAM: " + ram + "\nStorage: " + storage;
}

LaptopBuilder::LaptopBuilder() : laptop(nullptr) {}
LaptopBuilder::~LaptopBuilder() { delete laptop; }

void LaptopBuilder::CreateNewLaptop() {
    delete laptop;
    laptop = new Laptop();
}

void LaptopBuilder::BuildMonitor() {
    laptop->setMonitor("15.6\" IPS");
}

void LaptopBuilder::BuildProcessor() {
    laptop->setProcessor("Intel i7");
}

void LaptopBuilder::BuildRAM() {
    laptop->setRAM("16GB DDR4");
}

void LaptopBuilder::BuildStorage() {
    laptop->setStorage("512GB SSD");
}

Laptop* LaptopBuilder::GetLaptop() const {
    return laptop;
}

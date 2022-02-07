#include "Antivirus.hpp"
#include <iostream>


using namespace std;

AntiVirus::AntiVirus() {
    this->directory_path = "Not given";
}

AntiVirus::AntiVirus(string directory_path) {
    this->directory_path = directory_path;
}

AntiVirus::~AntiVirus() {
    //Nothing here
}

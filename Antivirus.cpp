#include "Antivirus.hpp"

using namespace std;

AntiVirus::AntiVirus() {
    this->directory_path = "Not given";
    this->virusDatabase_name = "Not given";
    this->virusDatabase.insert(pair<string,string>("", ""));
    this->currentPath = getcwd(tmp,256);
}

AntiVirus::AntiVirus(string directory_path, string virusDatabase_name, map<string,string> virusDatabase) {
    this->directory_path = directory_path;
    this->virusDatabase_name = virusDatabase_name;
    this->virusDatabase = virusDatabase;
    this->currentPath = getcwd(tmp,256);
}

AntiVirus::~AntiVirus() {

}

string AntiVirus::getCurrentPath(){
    return this->currentPath;
}


bool AntiVirus::findVirusDatabase(string directory,string virusDatabase_name) {


}

void AntiVirus::GetVirusDatabaseToMap(string virusDatabase_name) {

}

map<string,string> AntiVirus::GetVirusFromDatabase() {
    return this->virusDatabase;
}
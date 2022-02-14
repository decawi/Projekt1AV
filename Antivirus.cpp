// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se
#include "Antivirus.hpp"

void AntiVirus::insertDataInMap(string virusDatabaseFile) {
    string line;
    cout << virusDatabaseFile;
    ifstream myVirusDataFile (virusDatabaseFile);
    
    if(myVirusDataFile.is_open()) {
        while(getline(myVirusDataFile,line)) {

            size_t found = line.find("=");
            string data1 = line.substr(0,found);
            string data2 = line.substr(found + 1,line.length());
            virusDatabaseData.insert({data1,data2});
        }
    }
    myVirusDataFile.close();

    // Just checking the map
    for (auto itr = virusDatabaseData.begin(); itr != virusDatabaseData.end(); ++itr) {
        cout << itr->first << " " << itr->second << '\n';
    }
}


AntiVirus::AntiVirus() {
    this->directory_path_to_searh = "Not given";
    this->virusDatabase_name = "Not given";
    this->virusDatabaseData.insert({"", ""});


    this->currentPath = fs::current_path();
}


AntiVirus::AntiVirus(string directory_path_to_searh, string virusDatabase_name, map<string,string> virusDatabaseData) {
    this->directory_path_to_searh = directory_path_to_searh;
    this->virusDatabase_name = virusDatabase_name;
    this->virusDatabaseData = virusDatabaseData;


    this->currentPath = fs::current_path();
}

AntiVirus::~AntiVirus() {

}


void AntiVirus::setVirusDatabaseName(string virusDatabase_name) {
    this->virusDatabase_name = virusDatabase_name;
}

bool AntiVirus::checkIfVirusDatabaseIsInSameFolder(string virusDatabase_name) {

    bool check = false;
    if (fs::exists(virusDatabase_name)) {
        check = true;
    }
    this->databaseExistsInSameFolder = check;
    return check;
}

void AntiVirus::setVirusDatabaseData(string virusDatabasepath) {


    if(databaseExistsInSameFolder) {
        insertDataInMap(virusDatabasepath);
    }
    else {

        string path = virusDatabasepath + "/" + this->virusDatabase_name;
        insertDataInMap(path);

    }
}
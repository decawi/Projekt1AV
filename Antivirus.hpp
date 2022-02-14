#pragma once
// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>


namespace fs = std::filesystem;
using namespace std;
class AntiVirus {   

    private:
        //Behöver inte anges av användare
        int arrayCapacity = 50;
        int currentFilesInArray = 0;
        string currentPath;
        string directory_path_to_scan;
        string virusDatabase_name;
        string* fileArray = new string[arrayCapacity];
        bool databaseExistsInSameFolder;
        map<string,string> virusDatabaseData;

    public:

        AntiVirus();
        AntiVirus(string directory_path_to_scan, string virusDatabase_name); 
        ~AntiVirus();

        bool checkIfVirusDatabaseExist(); 
        void setVirusDatabaseData(string virusDatabaseNameFile);
        void checkAfterVirusInChoosenPath(string directory_path_to_scan);

    private:
        void insertDataInMap(string virusDatabaseFile);
        void setfileArrayData(string directory_path_to_scan);
        bool checkIfVIrusExistInfiles();
        void reportVirusToLogFile(string report);

};
#pragma once
// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;
using namespace std;
class AntiVirus {   

    private:
        //Behöver inte anges av användare
        string currentPath;
        int arrayCapacity = 50;
        int currentFilesInArray = 0;
        bool databaseExistsInSameFolder;
        string* fileArray = new string[arrayCapacity];


        string directory_path_to_searh;

    public:
        string virusDatabase_name;
        map<string,string> virusDatabaseData;

    // The three default
        AntiVirus();
        AntiVirus(string directory_path_to_searh, string virusDatabase_name, map<string,string> virusDatabase); 
        ~AntiVirus();


        void setVirusDatabaseName(string virusDatabase_name); // Sätter databasennamn enkelelelelel
        bool checkIfVirusDatabaseIsInSameFolder(string virusDatabase_name); //Hittar vi databasen i vår path?
        void setVirusDatabaseData(string virusDatabaseNameFile); // Denna kan vi använda till båda dvs oavsett om det är is amma folder eller i en given path
        bool checkAfterVirusInChoosenPath(string directory_path_to_searh);


    //Private functions
        //void setfileArrayData(string directory_path_to_searh);
    private:
        
        void insertDataInMap(string virusDatabaseFile); // Done
        void setfileArrayData(string directory_path_to_searh); // Done , functions finds all files in given path and stores it into the class array
        bool checkIfVIrusExistInfiles(string* fileArray);
        void reportVirusToLogFile();

};
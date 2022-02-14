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
    string directory_path_to_searh;

    //Behöver inte anges
    string currentPath;
    bool databaseExistsInSameFolder;


    void insertDataInMap(string virusDatabaseFile);
    protected:

    public:
    string virusDatabase_name;
    map<string,string> virusDatabaseData;




    // The three default
    
    AntiVirus();
    AntiVirus(string directory_path, string virusDatabase_name, map<string,string> virusDatabase); 
    ~AntiVirus();


    void setVirusDatabaseName(string virusDatabase_name); // Sätter databasennamn enkelelelelel
    bool checkIfVirusDatabaseIsInSameFolder(string virusDatabase_name); //Hittar vi databasen i vår path?
    void setVirusDatabaseData(string virusDatabaseNameFile); // Denna kan vi använda till båda dvs oavsett om det är is amma folder eller i en given path






    //Mer funktioner här




};
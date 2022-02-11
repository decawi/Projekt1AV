#pragma once

#include <unistd.h>
#include <string>
#include <iostream>
#include <map>
#include <dirent.h> //opendir
#include <string.h>

using namespace std;
class AntiVirus {   

    private:
    //Getting currentPath
    char tmp[256];

    string directory_path;  // Antar att denna ska finnas
    string virusDatabase_name;
    map<string,string> virusDatabase;

    string currentPath;


    protected:

    public:


    // The three default
    
    AntiVirus();
    AntiVirus(string directory_path, string virusDatabase_name, map<string,string> virusDatabase); 
    ~AntiVirus();


    string getCurrentPath();
    bool findVirusDatabase(string currentPath,string virusDatabase_name); //Hittar vi databasen i vår path?


    void GetVirusDatabaseToMap(string virusDatabase_name); //Funktionens syfte är att hämta data från virus databasen och sedan placera ditt i vår map
    map<string,string> GetVirusFromDatabase();

    string checkPathString(string strPath);
    void listdir(string initStrPath);

    //Mer funktioner här




};
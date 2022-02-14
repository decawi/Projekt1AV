// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se
#include "Antivirus.hpp"

void AntiVirus::insertDataInMap(string virusDatabaseFile) {

    string line;
    ifstream myVirusDataFile (virusDatabaseFile);
    
    if(myVirusDataFile.is_open()) {
        while(getline(myVirusDataFile,line)) {

            size_t found = line.find("=");
            string data1 = line.substr(0,found);
            string data2 = line.substr(found + 1,line.length());
            if (data1.length() > 32) {
                cout << "Error to insert virus : " << data1 << endl << "The virus name is over 32 characters. The program skips the virus and goes to next one";
            
            }
            else {
                virusDatabaseData.insert({data1,data2});
            }
        }
    }
    myVirusDataFile.close();

    // Just checking the map
    /*for (auto itr = virusDatabaseData.begin(); itr != virusDatabaseData.end(); ++itr) {
        cout << itr->first << " " << itr->second << '\n';
    }*/
}


AntiVirus::AntiVirus() {

    this->directory_path_to_searh = "Not set";
    this->virusDatabase_name = "Not set";
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

    delete[] fileArray;
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

void AntiVirus::setfileArrayData(string directory_path_to_searh) {

    string path = directory_path_to_searh;

    // What is happening here?
    for (const auto & file : fs::directory_iterator(path)) {
        string currentFilePath = file.path();

        if(fs::is_directory(currentFilePath) != true) {
            if(currentFilesInArray < arrayCapacity) {
                fileArray[currentFilesInArray] = currentFilePath;
                currentFilesInArray++;

            }
            else {
                // Allokera en större array med ny capacity
                arrayCapacity += 50;
                string* newArray = new string[arrayCapacity];
                for(int i = 0; i < currentFilesInArray; i++) {
                    newArray[i] = fileArray[i];
                }
                delete[] fileArray;
                fileArray = newArray;
                fileArray[currentFilesInArray] = currentFilePath;
                currentFilesInArray++;

            }
        }
        else {
            setfileArrayData(currentFilePath);
        }
    }
}

bool AntiVirus::checkIfVIrusExistInfiles(string* fileArray, map<string,string> virusDatabaseData) {
    //Funktionen tar emot en array o kollar som antas innehålla path till olika filer. Kontrollerar sen om virus finns i vald path
    // Tar även in datan från virus databasen
    return true;

}
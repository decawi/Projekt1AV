// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se
#include "Antivirus.hpp"


AntiVirus::AntiVirus() {
    this->directory_path_to_scan = "Not set";
    this->virusDatabasepath = "Not set";
    this->currentPath = fs::current_path();
}


AntiVirus::AntiVirus(string directory_path_to_scan, string virusDatabasepath) {
    this->directory_path_to_scan = directory_path_to_scan;
    this->virusDatabasepath = virusDatabasepath;
    this->currentPath = fs::current_path();
}

AntiVirus::~AntiVirus() {
    delete[] fileArray;
}

bool AntiVirus::checkIfVirusDatabaseExist() {

    bool check = false;
    if (fs::exists(this->virusDatabasepath)) {
        check = true;
    }
    return check;
}

void AntiVirus::setVirusDatabaseData(string virusDatabasepath) {
    if(this->virusDatabasepath == "signatures.db") {

        insertDataInMap(currentPath + "/signatures.db");
    }
    else {
        insertDataInMap(virusDatabasepath);
    }
}

void AntiVirus::checkAfterVirusInChoosenPath(string directory_path_to_scan) {
    setfileArrayData(directory_path_to_scan);
    bool check = checkIfVIrusExistInfiles();

    if(check) {
        cout << "------------WARNING!------------ \n Virus has been detected in choosen path and is now loged in dv1620.log" << endl;
    }
    else {
        cout << "No Virus was found in scanned directory!" << endl;
    }
}


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
}

void AntiVirus::setfileArrayData(string directory_path_to_scan) {

    string path = directory_path_to_scan;

    for (const auto & file : fs::directory_iterator(path)) {
        string currentFilePath = file.path();

        if(fs::is_directory(currentFilePath) != true) {
            if(currentFilesInArray < arrayCapacity) {
                fileArray[currentFilesInArray] = currentFilePath;
                currentFilesInArray++;

            }
            else {
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

bool AntiVirus::checkIfVIrusExistInfiles() {
    bool check = false;
    string report;

    for(int i = 0; i < currentFilesInArray; i++) {
        ifstream fileToCheck(fileArray[i]);
        string hexstring;
        char letter;

        while(fileToCheck.get(letter)) {
                unsigned short int value = static_cast<unsigned short int>(static_cast<unsigned char>(letter));
                char buffer[3];
                sprintf(buffer,"%02hx",value);
                hexstring += string(buffer);
        }
        for (auto itr = virusDatabaseData.begin(); itr != virusDatabaseData.end(); itr++) {
            int length = itr->second.length() / 2;
            if(hexstring.substr(0,length) == itr->second.substr(0,length)) {
                report += "Virus with name " + itr->first + " was detected at path : " + fileArray[i] + "\n";
                break;
            }
        }
        fileToCheck.close();
    }
    if(!report.empty()) {
        reportVirusToLogFile(report);
        check = true;
    }
    return check;

}


void AntiVirus::reportVirusToLogFile(string report) {
    ofstream logFile("dv1620.log");
    logFile << report;
}
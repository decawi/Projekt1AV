#include "Antivirus.hpp"

int main() {

    string databasename;



    AntiVirus AntivirusSystem;



    cout << "Virus Database Path : ";
    getline(cin, databasename);

    AntivirusSystem.setVirusDatabaseName(databasename);


    if (AntivirusSystem.checkIfVirusDatabaseIsInSameFolder(AntivirusSystem.virusDatabase_name)) {

        //Making virusdatabase info to map and storing the data
        AntivirusSystem.setVirusDatabaseData(AntivirusSystem.virusDatabase_name);
    }
    else {
        //Calling funktion where given path is 

    }






    return 0;
};
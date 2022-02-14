// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se
#include "Antivirus.hpp"

int main() {

    string databasename;
    string databasepath;



    AntiVirus AntivirusSystem;



    cout << "Virus Database Name : ";
    getline(cin, databasename);

    AntivirusSystem.setVirusDatabaseName(databasename);

    if (AntivirusSystem.checkIfVirusDatabaseIsInSameFolder(AntivirusSystem.virusDatabase_name)) {

        //Making virusdatabase info to map and storing the data
        AntivirusSystem.setVirusDatabaseData(AntivirusSystem.virusDatabase_name);
    }
    else {
        cout << fs::current_path();
        cout << "The database could not be found in samefolder as program. Pleas give the full path : ";
        getline(cin, databasepath);
        //Calling funktion where given path is /home/kulan/Skrivbord
        AntivirusSystem.setVirusDatabaseData(databasepath);

    }






    return 0;
};
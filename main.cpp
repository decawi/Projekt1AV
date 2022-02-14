// Simon Danielsson sidn21@student.bth.se
// Dennis Calza Wilhelmsson deca21@student.bth.se
#include "Antivirus.hpp"

int main(int argc, char* argv[]){

    string dirToScan;
    string virusDb;

    if(argc <= 1 || argc >= 5){
        cout << argv[0] << " <path/to/scan -d path/to/database>" << endl;
        exit(1);
    }

    for(int i = 0; i < argc;i++) {
        if(string(argv[i]) == "-d") {
            virusDb = argv[i+1];
            if((i+1) >= (argc-1)) {
                dirToScan = argv[i-1];
            }
            else {
                dirToScan = argv[i+2];
            }
        }
    }

    if(virusDb.empty()) {
        virusDb = "signatures.db";
        dirToScan = argv[1];

    }

    AntiVirus objAnti(dirToScan,virusDb);
    if(!objAnti.checkIfVirusDatabaseExist())  {
        cout << "Could not find your Virus database. Try again!";
    }
    else {
        objAnti.setVirusDatabaseData(virusDb);
        objAnti.checkAfterVirusInChoosenPath(dirToScan);

    }

    return 0;
}
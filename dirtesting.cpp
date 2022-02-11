#include <dirent.h> //opendir
#include <string.h>
#include <iostream>

using namespace std;

string checkPathString(string strPath);
void listdir(string initStrPath);

string checkPathString(string strPath){

    if(strPath[strPath.length()-1] == '/'){
        strPath = strPath.substr(0, strPath.length()-1);
    }
    return strPath;
}

void listdir(string initStrPath){

    struct dirent *dir;
    DIR *dp = opendir(initStrPath.c_str());
    if(dp){

        while((dir = readdir(dp)) != NULL){

            string strPath = "";
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) continue;
            if(dir->d_type == DT_DIR){

                initStrPath = checkPathString(initStrPath);
                strPath = initStrPath + "/" + dir->d_name;
                listdir(strPath);
            }
            else{

                initStrPath = checkPathString(initStrPath);
                strPath = initStrPath + "/" + dir->d_name;
                cout << strPath << endl;
            }
        }
        closedir(dp);
    }
}

int main(int argc, char *argv[]){
    if(argc <= 1){
        cout << argv[0] << " <dir>" << endl;
        exit(1);
    }
    listdir(argv[1]);
    return 0;
}
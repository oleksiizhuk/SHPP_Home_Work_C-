#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;

class File{
    private:
    char* arrayAddToFile;
    char* arrayReadInFile;
    const char ADD_LENGHT_FILE = 50;
    const char Read_IN_FILE = 100;

    public:
        File(){
            arrayAddToFile = new char[ADD_LENGHT_FILE];
            arrayReadInFile = new char[Read_IN_FILE];
        }
            /* чтение из файл */
        void readInFile(){
            ifstream file("file.txt");
            if(!file.is_open()){
                cout<<"ERR.. Sorry file is not found!"<<endl;
            }

            while (!file.eof())
            {
                file.getline(arrayReadInFile, Read_IN_FILE);
                cout << arrayReadInFile << endl;
            }
            file.close();
            return;
        }

        /*запись в файл*/
        void addToFile(){
            do{
                cout<<"add to a text in file"<<endl;
                gets(arrayAddToFile);
                if(strlen(arrayAddToFile) > 0 && strlen(arrayAddToFile) < 50){
                    break;
                }
                else{
                    cout<<"50 character limit"<<endl;
                }
            }while(1);
            cout<<"strlen arrayAddToFile :"<<strlen(arrayAddToFile)<<endl;
            ofstream file("file.txt");
            for(int i = 0; i < strlen(arrayAddToFile); i++){
                file<<arrayAddToFile[i];
            }
            file.close();
        }
        /*удаление из файла*/
        void remove(){
            ofstream file("file.txt", ios_base::trunc);
            if(!file){
                cout<<"ERR.. Sorry file is not found!"<<endl;
            }
            arrayAddToFile = "";
            file<<arrayAddToFile;//[i];
            file.close();
            cout<<"remove ready"<<endl;
        }

        /*добавление в конец файла*/
        void addition(){
            cout<<"write what you want to add"<<endl;
            ofstream additionFile("file.txt", ios_base::app);
            do{
                if(additionFile.is_open()==true){
                    cout<<"add text"<<endl;
                    gets(arrayAddToFile);
                    if(strlen(arrayAddToFile) > 0 && strlen(arrayAddToFile) < 50){
                        break;
                    }
                    else{
                        cout<<"50 character limit"<<endl;
                    }
                }
            }while(1);
            additionFile<<arrayAddToFile;
            additionFile.close();
        }
};

 /*LOGIN AND PASS*/
class Login{
    private:
        char* pass;
        char* login;
        char* checkPass;
        char* checkLogin;
        char* userAddpass;
        char* userAddLogin;
        const char MAX_LENGHT_PASS = 16;
        const char MAX_LENGHT_LOGIN = 50;
        int verificationP;
        int verificationL;
        int counter;
    public:
        Login(){
            pass = new char[MAX_LENGHT_PASS];
            login = new char[MAX_LENGHT_LOGIN];
            checkPass = new char[MAX_LENGHT_PASS];
            checkLogin = new char[MAX_LENGHT_LOGIN];
            userAddpass = new char[MAX_LENGHT_LOGIN];
            userAddLogin = new char[MAX_LENGHT_LOGIN];
            verificationP = NULL;
            verificationL = NULL;
            counter = NULL;
        }

        void createNewAcount(){
            cout<<"Add new passwords"<<endl;
            cin>>userAddpass;
            ofstream p("pass.txt");
            p<<userAddpass<<endl;
            p.close();
            cout<<"add new login"<<endl;
            cin>>userAddLogin;
            ofstream l("login.txt");
            l<<userAddLogin<<endl;
            l.close();
        }

        int checkL(char* checking){
            ifstream readLogin("login.txt");
            readLogin>>checkLogin;
            for(int i = 0;i < strlen(checking); i++){
                if(checkLogin[i] == checking[i]){
                    counter++;
                }
            }
            if(counter == strlen(checking)){
                counter = 0;
                return 0;
            }
            else{
                return 1;
            }

        }

        int checkP(char* checking){
            ifstream readpass("login.txt");
            readpass >> checkPass;
            for(int i = 0; i < strlen(checking);i++){
                if(checkPass[i] == checking[i]){
                    counter++;
                }
            }
            if(counter == strlen(checking)){
                counter = 0;
                return 0;
            }
            else{
                counter = 0;
                return 1;
            }
        }

        int loginAndPasswordVerification(){
            cout<<"add passwords"<<endl;
            cin>>pass;
            cout<<"add login"<<endl;
            cin>>login;
            verificationP = checkP(pass);
            cout<<"verificationP = "<<verificationP<<endl;
            verificationL = checkL(login);
            cout<<"verificationL = "<<verificationL<<endl;
            if(verificationP != 0){
                cout<<"ERR you add incorrect pass, pls enter pass again"<<endl;
            }
            else if(verificationL != 0){
                cout<<"ERR you add incorrect login, pls enter login again"<<endl;
            }
            else{
                cout<<"you verification"<<endl;
                return 0;
            }

        }
};

class Manager{
    private:
        char userChoice;
        char change;
        int exit;
        int menu;
        int countMass;
    public:
        File F;
        Login L;
        Manager(){
            userChoice = NULL;
            change = NULL;
            exit = 1;
            countMass = 0;
        }

        int verification(){
            do{
                cout<<"1: to come in"<<endl;
                cout<<"2: create new account"<<endl;
                cout<<"3: exit"<<endl;
                cin>>change;
                if(change >'3'){
                        system("cls");
                    cout<<"ERR...such an item is wrong"<<endl;
                }
                if(change <= '0'){
                    system("cls");
                    cout<<"ERR...such an item is wrong"<<endl;
                }
                if(change == '1'){
                    menu = L.loginAndPasswordVerification();
                        if(menu == 0){
                            system("cls");
                            exit = showMenu();
                            if(exit == 0){
                                return 0;
                            }
                        }
                }
                if(change == '2'){
                    L.createNewAcount();
                }
                if(change == '3'){
                        break;
                    return 0;
                }
            }while(1);
        }

        int showMenu(){
            do{
                cout<<"1: Read in file"<<endl;
                cout<<"2: Add to file"<<endl;
                cout<<"3: add to the end"<<endl;
                cout<<"4: remove is file"<<endl;
                cout<<"5: exit"<<endl;
                exit=userChange();
                if(exit == 0){
                    break;
                }
            }while(1);
            return 0;
        }

        int userChange(){
            cout<<"your choice"<<endl;
            cin >> userChoice;
            if(change >'5'){
                system("cls");
                cout<<"ERR...such an item is wrong"<<endl;
            }
            switch(userChoice){
                case '1':
                    system("cls");
                    F.readInFile();
                    break;
                case '2':
                    system("cls");
                    F.addToFile();
                    break;
                case '3':
                    system("cls");
                    F.addition();
                    break;
                case '4':
                    system("cls");
                    F.remove();
                    break;
                case '5':
                    system("cls");
                    return 0;
            }
        }
};

int main()
{
    Manager M;
    M.verification();
    return 0;
}

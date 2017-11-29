#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal{
    private:
        int SIZE_NAME_AND_VARIETY = 1000;
        int age;
        char* name;
        char* variety;
        int pawsNum;
        int health;
        bool runElseSlip;

    public:
        Animal(){
        age = 0;
        name = new char[SIZE_NAME_AND_VARIETY];
        variety = new char[SIZE_NAME_AND_VARIETY];
        strcpy(name, "No name");
        strcpy(variety, "No variety");
        pawsNum = 0;
        health = 0;
        runElseSlip = false;
        };

    void setAnimal(){
        system("cls");
        cout<<"Enter age: "<<endl;
        cin >> age;

        cout<<"Enter name: "<<endl;
        cin>> name;

        cout<<"Enter variety: "<<endl;
        cin>> variety;

        cout<<"Enter number of paws: "<<endl;
        cin>>pawsNum;

        health = 1 + rand() % 100;
        runElseSlip = 0 + rand() % 2;

        cout<<"you add animal"<<endl;
        system("pause");
        system("cls");
    }

    void getAnimal(){
        cout<<"Age: "<<age<<endl;
        cout<< "Name: "<< name<<endl;
        cout<< "Variety: "<< variety<<endl;
        cout<< "number of paws: "<< pawsNum<<endl;
        cout<< "Health: "<< health<<endl;

        if(runElseSlip == 1){
            cout<<"Animal run"<<endl;
        }else{
            cout<<"Animal Sleep"<<endl;
        }
    }

    ~Animal(){
    }
};

class Zoo{
    private:
        Animal animals[20];
        int countAnimal;
        int killAnimal;
    public:
        Zoo(){ countAnimal = 0;};

        void addAnimal(){
            animals[countAnimal].setAnimal();
            countAnimal++;
        }

        void showAnimal(){
            system("cls");
            for (int i = 0; i < countAnimal; i++){
                animals[i].getAnimal();
                cout<<endl;
            }
        }

        void deleteAnimal(){
            for(int i = 0; i < countAnimal;i++){
                animals[i].getAnimal();
                cout<<endl;
            }
            cout<<"Which animal do you want to remove?:"<<endl;
            cin>>killAnimal;
            Animal tmpAnimal[20];

            int curr_index = 0;

            for(int i = 0; i < countAnimal; i++){
                if (i != killAnimal){
                    tmpAnimal[curr_index] = animals[i];
                    curr_index++;
                }
            }
            countAnimal--;
            for (int i = 0; i < countAnimal; i++){
                animals[i] = tmpAnimal[i];
            }
        }

};

class Manager{

    private:
        int choice;

    int GetUserChoice(){

        cin >> choice;
        switch(choice){
            case 1:
                Z.showAnimal();
                return 1;
                break;

            case 2:
                Z.addAnimal();
                return 1;
                break;

            case 3:
                Z.deleteAnimal();
                return 1;
                break;

            case 4:
               return 0;
                break;
            }
        }

    public:
        Zoo Z;
        int k, a;

        Manager(int a = 1, int k = 1){
        };

        int showUserMenu(){
            do{
                cout<<"1: See animals"<<endl;
                cout<<"2: Add animal"<<endl;
                cout<<"3: remove animal"<<endl;
                cout<<"4: exit"<<endl;
                a = GetUserChoice();
                if(a == 0){
                    k = 0;
                }
            }while(k);
            return 1;
        }
};

int main()
{
    srand(time(0));
    Manager M;
    M.showUserMenu();
}

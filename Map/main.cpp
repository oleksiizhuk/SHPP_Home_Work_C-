#include <iostream>
#include <cstring>

using namespace std;

class Map{
    private:
        int* database;
        int factor;
        const int SIZE = 100000000;
    public:
        Map(){
            factor = 3;
            database = new int[SIZE];
        }
        int hashMap(char* str){
            unsigned hash = 1;
            for(int i = 0; i < strlen(str); i++){
                hash = (hash * factor) + str[i];
                cout<<"hash: "<<hash<<" factor : "<<factor<<"str[i]"<< str[i]<<endl;
            }
            cout<<"hash: "<<hash<<endl;
            return hash;
        }
        int get(char* str){
            return database[hashMap(str)];
        }
        void add(char* str, int data){
            database[hashMap(str)] = data;
        }
};

int main()
{
    Map M;

    M.add("Vaaaa", 1);
    M.add("Vaaaq", 2);
    M.add("Vaaaw", 3);
    M.add("Vaaae", 4);
    M.add("Vaaar", 5);
    M.add("vasya", 6);
    M.add("vasss", 7);
    M.add("Vasss", 12);
    M.add("igot", 15);
    M.add("a", 28);
    cout<<M.get("Vaaaa")<<endl;
    cout<<M.get("vasya")<<endl;
    cout<<M.get("vasya")<<endl;
    cout<<M.get("vasss")<<endl;
    cout<<M.get("igot")<<endl;
    cout<<M.get("Vasss")<<endl;
    cout<<M.get("a")<<endl;
}

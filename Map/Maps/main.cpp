#include <iostream>
#include <cstring>

using namespace std;

class Maps{
    private:
        int array[100];

    public:

        int hash(char* str){
            return strlen(str);
        }

        int get(char* str){
            return array[hash(str)];
        }

        void put(char* str, int data){
            array[hash(str)] = data;
        }
};

int main()
{
    Maps M;

    M.put("vasya", 24);
    M.put("igot", 15);

    cout<<M.get("vasya")<<endl;
}

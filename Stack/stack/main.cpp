#include <iostream>

using namespace std;

class Stack{
    private:
        const int SIZE = 10;
        int* stackArr = new int[SIZE];
        int* last;
        int count;
    public:
        Stack(){
            last = stackArr;
            count = 1;
        }

        void put(int num){
            if(check() == 1){
                cout<<"Sorry your stack is FULL"<<endl;
                return;
            }
            count++;
            *last = num;
            last++;
        }

        int get(){
            if(check() == 0){
                cout<<"Sorry your stack is empty"<<endl;
                return 1;
            }
            count--;
            int d = *(last-1);
            last--;
            return d;
        }

        int check(){
            if(count <= 1){
                return 0;
            }
            if(count == SIZE+1){
                return 1;
            }
        }

};
int main()
{
    Stack S;
    for(int i = 1;i< 15;i++){
        S.put(i);
    }

    for(int n = 1; n < 15; n++){
        cout<<S.get()<<endl;
    }

    S.put(11);
    S.put(12);
    S.put(13);
    cout<<S.get()<<endl;
    cout<<S.get()<<endl;
    cout<<S.get()<<endl;
}

#include <iostream>

using namespace std;

class Queue{
    private:
    const int SIZE  = 10;
    int* first;
    int* last;
    int elementCount;
    int* queueArr = new int [SIZE];

    public:
        Queue(){
            first = queueArr;
            last = queueArr;
            elementCount = 1;
        };

        void put(int num){
            if(check() == SIZE){
                cout<<"Q is full"<<endl;
                return;
            }
            if(elementCount == 1){
                *first == num;
            }
            *last = num;
            elementCount++;
            last++;
        }

        int get(){
            if(check() == 0){
                cout<<"queue is empty"<<endl;
                return 0;
            }
            elementCount--;
            int d = *first;
            first++;
           return d;
        }

        int check(){
            if(elementCount == 0){
                return 0;
            }
            if(elementCount == SIZE){
                return 0;
            }
        }
};

int main()
{
    Queue Q;
    for(int i = 1;i < 15;i++){
        Q.put(i);
    }
        for(int n = 0; n < 15;n++){
            cout<<Q.get()<<endl;
        }

    Q.put(11);
    Q.put(12);
    Q.put(13);
    cout<<Q.get()<<endl;
    cout<<Q.get()<<endl;
    cout<<Q.get()<<endl;
    cout<<Q.get()<<endl;
}

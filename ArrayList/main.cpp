#include <iostream>

using namespace std;

class ArrayList{

private:
    const int INT_SIZE = 10;
    int* array;
    int currentSize;
    int allocatedSize;

    void overwriteArray(int* newArray){
        for(int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
    }

    void addToNotFullArray(int n){
        array[currentSize] = n;
        currentSize++;
    }
    void addToFullArray(int n){
        int* newArray = new int [allocatedSize * 2];
        allocatedSize *= 2;
        overwriteArray(newArray);
        delete []array;
        array = newArray;
        addToNotFullArray(n);
    }

public:
    ArrayList(){
    array = new int [INT_SIZE];
    currentSize = 0;
    allocatedSize = INT_SIZE;
    }

    void add(int n){
        if(currentSize < allocatedSize){
            addToNotFullArray(n);
        }else{
            addToFullArray(n);
        }
    }

    void addToIndex(int n, int index){
        if(index < 0 || index > currentSize + 1){
            cout<<"Oops, warning: pls get correct add-index!!!"<<endl;
                return;
        }

        for(int i = currentSize + 1; i > index;i--){
            array[i] = array[i - 1];
        }
        currentSize++;
        array[index] = n;
    }

    void trimToSize(){
        int* newArray = new int [currentSize];
        for(int i = 0; i < currentSize;i++){
            newArray[i] = array[i];
        }
        delete []array;
        array = new int [currentSize];
        for(int i = 0; i < currentSize;i++){
            array[i] = newArray[i];
        }
        delete []newArray;
    }

    int get(int index){
        if(index >= currentSize){
            cout<<"oops, warning: index out of bound"<<endl;
            return -1;
        }
        return array[index];
    }

    void removeIndex(int index){
        if(index < 0 || index > currentSize){
            cout<<"Oops, warning: pls get correct remove-index!!!"<<endl;
            return;
        }
        for(int i = index - 1; i < currentSize - 1; i++){
            array[i] = array[i + 1];
        }
        currentSize--;
    }

    void print(){
        for(int i = 0; i < currentSize;i++){
            cout<<" "<<array[i]<<" ";
        }
    }

    ~ArrayList(){}
};

int main(){

};



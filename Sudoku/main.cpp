#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sudoku{
    private:

        const int SIZE = 9;
        const int height = 9;
        const int width = 9;
        int arraySudoku[9][9];

    public:
        Sudoku(){
            for(int i = 0; i < 9;i++){
                for(int n =0;n < 9; n++){
                    arraySudoku[i][n] = 1;
                }
            }
        }

        void readOfFile(){
            ifstream readOfFile("INPUT.txt");
            for(int i = 0;i < SIZE;i++){
                for(int n = 0;n < SIZE;n++){
                   readOfFile >> arraySudoku[i][n];
                }
            }
        }

        void showDisplay(){
            for(int i = 0; i < height;i++){
                for(int n =0;n < width; n++){
                    cout<<arraySudoku[i][n]<< " ";
                }
                cout<<endl;
            }
        }

        void outputCorrect(){
            string Correct = "Correct";
            ofstream file("OUTPUT.txt");
                file << Correct << endl;
        }

        void outputIncorrect(){
            string Incorrect = "Incorrect";
            ofstream file("OUTPUT.txt");

                file << Incorrect << endl;
        }

         int checkFile(){
            int checkArray[9] = {0};
            int notTrue = 0, right = 0, arrayIndex = 0, arrayIndexCheck = 0;

            for(int n = 0; n < SIZE; n++){
                for(int i = 0; i < SIZE;i++){
                    checkArray[n] += arraySudoku[n][i];
                }
                if(checkArray[n] != 45){
                    cout<< "check false";
                    cout<<checkArray[n]<<endl; // check line
                    notTrue++;
                }
                else{
                    cout<<"check true";
                    cout<<checkArray[n]<<endl; // check line
                    right++;
                }
            }

            for (int i = 0; i < 9; i++){
                checkArray[i] = 0;
            }
            for(int n = 0; n < SIZE; n++){
                for(int i = 0; i < SIZE;i++){
                     checkArray[n] +=  arraySudoku[i][n];
                }
                if(checkArray[n] != 45){
                    cout<< "check false"<< " ";
                    cout<<checkArray[n]<<endl;
                    notTrue++;
                }
                else{
                    cout<<"check true";
                    cout<<checkArray[n]<<endl;
                    right++;
                }
            }
            int key;
                    for(int i = 0; i < 9;i = i + 3){
                        for(int n = 0; n < 9; n = n + 3){
                            key = arraySudoku[i][n];
                                arrayIndex = 1;
                            for(int k = i;k < i + 3;k++){
                                for(int j = n; j < n + 3;j++){
                                ++arrayIndexCheck;
                                if(arrayIndexCheck == 9){
                                    arrayIndexCheck = 0;
                                }

                            if(key != arraySudoku[k][j] || arrayIndex == arrayIndexCheck){
                                cout<<"true "<<key<<" "<<arraySudoku[k][j]<<endl; // check line
                                right++;
                            }else{
                                cout<<"false "<<key<<" "<<arraySudoku[k][j]<<endl; // check line
                                notTrue++;
                            }
                        }
                    }
                }
            }
            cout<<right<<endl; // check right
            cout<<notTrue<<endl; // check notTrue

            if(right == 99 && notTrue == 0){
                return 0;
            }
            else{
                return 1;
            }
        }

    ~Sudoku()
    {
        cout<<"disruptor"<< endl;
    }
};

class Manager{

    private:
    int right;
    Sudoku S;

    public:

        Manager(){
        right = 1;
        };

        void start(){
            S.readOfFile();
            S.showDisplay();
            right = S.checkFile();
            cout<<right<<endl; // check return
            if(right == 0){
                S.outputCorrect();
                cout<<"GOOD!"<<endl;
            }
            else{
                S.outputIncorrect();
                cout<<"bad!"<<endl;
            }
        }
};

int main()
{
    Manager M;
    M.start();
}

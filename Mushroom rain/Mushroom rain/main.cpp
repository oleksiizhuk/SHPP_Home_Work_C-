#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Manager{
    private:
        double radius = 0;
        int mashrum;
        double x[10];
        double y[10];
        double rezult = 0;
    public:
    int addMashrum(){
        cout<<"what quantity of mushrooms to add: ";
        cin>>mashrum;
        if(mashrum < 2 || mashrum > 10){
            cout<<"add correct number mushrooms"<<endl;
            return 1;
        }
        cout<<"add raius: "<<endl;
        cin>>radius;
        if(radius < 0 || mashrum > 10){
            cout<<"add correct number mushrooms"<<endl;
            return 1;
        }
        for(int i = 0;i < mashrum;i++){
            cout<<"mashrum "<<i<<", coordinate X"<<endl;
            cin>>x[i];
            cout<<"Y coordinate"<<endl;
            cin>>y[i];
        }
    }

    double Lenght(int x1, int y1, int x2, int y2){
        return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2));
        }

    void check(){
        double dis[mashrum], rad =0;
        int counter = 0;
        int countSecond = 0;
        double tmp;
        double minRadius = 0;

        for(int i = 0; i < mashrum; i++){
            for(int n = 1 + i; n < mashrum; n++){
                cout<<"distanshion mejdu tochkami "<< i <<" and "<<n<<" =  "<<(dis[counter] = Lenght(x[i],y[i],x[n],y[n]))<<" counter = "<<counter<<endl;
                counter++;
            }
        }

        if (counter > 1){
            for(int i = 0; i < mashrum - 1; i++){
                for (int n = 0; n < mashrum - 1;n++){
                    if(dis[n] > dis[n + 1]){
                        tmp = dis[n];
                        dis[n] = dis[n + 1];
                        dis[n + 1] = tmp;
                    }
                }
            }
        }

        for(int t = 1; t <=60;t++){
            countSecond++;
            cout<<t<<endl;
                rad = radius + radius;
                if(rad>dis[0]){
                    cout<<"sekond"<<countSecond<<"they grew up on: "<<rad / 2<<" vurosla na: "<<rezult<<endl;
                    break;
                    return;
                }
                else{
                    cout<<"mushrooms grew on: "<<rad<<endl;
                    radius+=0.016;
                    rezult+=0.016;
                }
        }
        cout<<"mushrooms did not touch each other "<<endl;
    }
};
int main(){
    int check = 0;
    Manager manager;
    check = manager.addMashrum();
    if(check == 1){
        return 1;
    }

    manager.check();
}

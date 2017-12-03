#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
const int MAX_MASHRUMS = 10;
class Manager{
    private:
        double radius = 0;
        int mashrum;
        double x[MAX_MASHRUMS];
        double y[MAX_MASHRUMS];
        double onHowManyMushrooms = 0;
        const int SHORTEST_DISTANCE = 0;
    public:

        /*add Mashrum and radius*/
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
        /*computation of distances*/
    double Lenght(int x1, int y1, int x2, int y2){
        return sqrt((double)(x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2));
        }

    void check(){
        double distanceBetweenTwoPoints[mashrum], sumOfTheRadiiOfTwoPoints =0 ;
        int counterDistanceMeter = 0;
        int countSecond = 0;
        double tmp;
        double minRadius = 0;
        /*counter distance*/
        for(int i = 0; i < mashrum; i++){
            for(int n = 1 + i; n < mashrum; n++){
                cout<<"distanshion mejdu tochkami "<< i <<" and "<<n<<" =  "<<(distanceBetweenTwoPoints[counterDistanceMeter] = Lenght(x[i],y[i],x[n],y[n]))<<" counterDistanceMeter = "<<counterDistanceMeter<<endl;
                counterDistanceMeter++;
            }
        }
        /* Sorting a bubble is needed to sort the most find the shortest distance*/
        if (counterDistanceMeter > 1){
            for(int i = 0; i < mashrum - 1; i++){
                for (int n = 0; n < mashrum - 1;n++){
                    if(distanceBetweenTwoPoints[n] > distanceBetweenTwoPoints[n + 1]){
                        tmp = distanceBetweenTwoPoints[n];
                        distanceBetweenTwoPoints[n] = distanceBetweenTwoPoints[n + 1];
                        distanceBetweenTwoPoints[n + 1] = tmp;
                    }
                }
            }
        }
        /*the function is intended to simulate the rain and reads how long
            it will be before the two fungus
            touch each other, if not touch, say how much they have grown*/
        for(int second = 1; second <=60;second++){
            countSecond++;
            cout<<second<<endl;
                sumOfTheRadiiOfTwoPoints = radius + radius;
                if(sumOfTheRadiiOfTwoPoints>distanceBetweenTwoPoints[SHORTEST_DISTANCE]){
                    cout<<"sekond"<<countSecond<<"they grew up on: "<<sumOfTheRadiiOfTwoPoints / 2<<" vurosla na: "<<onHowManyMushrooms<<endl;
                    break;
                    return;
                }
                else{
                    cout<<"mushrooms grew on: "<<sumOfTheRadiiOfTwoPoints<<endl;
                    radius+=0.016;
                    onHowManyMushrooms+=0.016;
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

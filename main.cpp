#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
int number_of_h;
int number_of_g;
float g(float angle);
float h(float angle)
{
    number_of_h++;
    float t = 1e-6;
    if (angle > -t && angle < t)
        return angle + angle * angle * angle / 6;
    return 2 * h(angle / 2) * g(angle / 2);
}
float g(float angle)
{
    number_of_g++;
    float t = 1e-6;
    if (angle > -t && angle < t)
        return 1 + angle * angle / 2;
    float bd = h(angle / 2);
    return 1 + 2 * bd * bd;
}

int main(int argc, char **argv)
{
        cout <<setw(15)<< "Angle"<<setw(15)<<"sinh"<<setw(15)<<"h()" <<setw(15)<<"#h" <<setw(15)<< "#g"<<
               setw(15)<< "Angle"<<setw(15)<<"cosh"<<setw(15)<<"h()" <<setw(15)<<"#h" <<setw(15)<< "#g"<<
               endl;

//Testing out recursive trig functions
    double angDeg;
    for(double i=-1;i<1.0000001f;i=i+0.1f){
        if(abs(i)<0.0000001){
            angDeg=0;
        }else{
            angDeg =i;
        }

        float angRad = angDeg * atan(1) / 45;
        number_of_g=0;
        number_of_h=0;
        cout << setw(15)<<angDeg <<setw(15)<<sinh(angRad) << setw(15)<<h(angRad) <<setw(15)<<number_of_h<<setw(15)<<number_of_g<<
                setw(15)<<angDeg <<setw(15)<<cosh(angRad) << setw(15)<<g(angRad) <<setw(15)<<number_of_h<<setw(15)<<number_of_g<<endl;
    }

    cout<<endl;
    cout<<"The number of function calls agree with what I predict it."<<endl;


//Exit stage right
    return 0;
}
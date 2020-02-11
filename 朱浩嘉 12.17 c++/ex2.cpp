#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
    unsigned seed;
    seed = time(0);
    srand(seed);
    double times;
    cout << "input the time you want to dice:";
    cin >> times;
    double a[11]={0,0,0,0,0,0,0,0,0,0,0};
    for (double i = 0; i < times;i++){

        int dice1 = rand()%6+1;
        int dice2 = rand()%6+1;
        a[dice1+dice2-2]++;
    }
    cout<< "sum        total        expected      actual" << endl;
    for (int n = 2; n <= 12; n++)
    {
        double p = n;
        cout<< n << "          " << a[n-2] << "          "<<(6-fabs(7-p))/36 << "          " << a[n-2]/times<< endl;
    }
}
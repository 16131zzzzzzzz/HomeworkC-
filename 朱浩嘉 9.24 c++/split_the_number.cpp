#include<iostream>
using namespace std;
int main(){
    int number;
    cout << "Enter a five-digit integer:";
    cin >> number;
    int a,b,c,d,e;
    a = number / 10000;
    number = number % 10000;
    b = number / 1000;
    number = number % 1000;
    c = number / 100;
    number = number % 100;
    d = number / 10;
    e = number % 10;
    cout << a << " " << b << " " << c << " " << d << " "<< e;
}
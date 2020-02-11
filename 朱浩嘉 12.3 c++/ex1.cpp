#include<iostream>
using namespace std;

int power(int base,int exponent){
    return(exponent==0?1:base*power(base,exponent-1));
}

int main(){
    int a,b;
    cout << "enter 2 numbers:";
    cin >> a >> b;
    cout << power(a,b);
}
#include<iostream>
using namespace std;

int gcd(int a,int b){
    return (b==0?a:gcd(b,a%b));
}

int main(){
    int x,y;
    cout << "enter two numbers:";
    cin >> x >> y;
    cout << x*y/gcd(x,y);
}
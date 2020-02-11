#include<iostream>
using namespace std;
int main(){
    int a ,b;
    cout << "num1:";
    cin >> a;
    cout << "num2:";
    cin >> b;
    if (a % b == 0)
    {
        cout << a << " is a multiple of " << b;
    }
    else
    {
        cout << b << " is not a multiple of " << b;
    }
}

#include<iostream>
using namespace std;

int main()
{
    int x;
    cout << "input:";
    cin >> x;
    int otp = 1;
    while (x > 0)
    {
        otp *= x;
        x--;
    }
    cout << otp;
}
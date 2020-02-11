#include<iostream>
using namespace std;

int main()
{
    int x;
    cout << "input:";
    cin >> x;
    int num = x;
    int otp = 0;
    int counter = 1;
    while (num != 0)
    {
        otp += counter*(num % 10);
        num /= 10;
        counter *= 2;
    }
    cout << otp;
}
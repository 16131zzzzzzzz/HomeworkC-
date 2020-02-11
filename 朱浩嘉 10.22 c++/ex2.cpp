#include<iostream>
using namespace std;

int main()
    {
    int x;
    cout << "input:";
    cin >> x;
    int cur = 0;
    int num = x;
    while(num != 0)
    {
        cur = cur * 10 + num % 10;
        num /= 10;
    }
    if (cur == x)
    {
        cout << x << " " << "is a pseudocode";
    }
    else
    {
        cout << x << " " << "isn't a pseudocode";
    }
    }

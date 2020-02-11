#include<iostream>
using namespace std;

int main()
{
    float x;
    cout << "input:";
    cin >> x;
    float e = 1;
    float i = x;
    while (i > 0)
    {
        float addon = 1;
        float counter = i;
        while (counter > 0)
        {
            addon *= counter;
            counter--;
        }
        e += (1 / addon);
        i--;
    }
    cout << e;
}
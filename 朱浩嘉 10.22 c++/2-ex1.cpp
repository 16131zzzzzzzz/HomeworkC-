#include<iostream>
using namespace std;

int main()
{
    int value = 0;
    int count = 0;
    int total = 0;
    for(;;)
    {
        cout << "Enter intergers(9999 to end):";
        cin >> value;
        if (value != 9999)
        {
            total += value;
            count += 1;
        }
        else
        {
            break;
        }
    }
    int average = total / count;
    cout << average;
}
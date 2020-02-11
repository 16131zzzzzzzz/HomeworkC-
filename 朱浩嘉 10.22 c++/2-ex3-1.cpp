#include<iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int space = 5-i; space > 0 ; space--)
        {
            cout << " ";
        }
        for (int star = 2*i - 1; star > 0 ; star--)
        {
            cout << "*";
        }
        for (int space = 5-i; space > 0 ; space--)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 4; i > 0; i--)
    {
        for (int space = 5-i; space > 0 ; space--)
        {
            cout << " ";
        }
        for (int star = 2*i - 1; star > 0 ; star--)
        {
            cout << "*";
        }
        for (int space = 5-i; space > 0 ; space--)
        {
            cout << " ";
        }
        cout << endl;
    }
}
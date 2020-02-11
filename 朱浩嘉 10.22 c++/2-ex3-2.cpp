#include<iostream>
using namespace std;

int main()
{
    int line;
    cout << "line:";
    cin >> line;
    if (1 <=  line && line <= 19 && line % 2 == 1)
    {
        int a = (line + 1)/2;
        for (int i = 1; i <= a; i++)
        {
            for (int space = a-i; space > 0 ; space--)
            {
                cout << " ";
            }
            for (int star = 2*i - 1; star > 0 ; star--)
            {
                cout << "*";
            }
            for (int space = a-i; space > 0 ; space--)
            {
                cout << " ";
            }
            cout << endl;
        }
        for (int i = a - 1; i > 0; i--)
        {
            for (int space = a-i; space > 0 ; space--)
            {
                cout << " ";
            }
            for (int star = 2*i - 1; star > 0 ; star--)
            {
                cout << "*";
            }
            for (int space = a-i; space > 0 ; space--)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "not permitted";
    }
}
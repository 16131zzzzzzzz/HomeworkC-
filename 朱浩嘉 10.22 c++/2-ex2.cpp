#include<iostream>
using namespace std;

int main()
{
    int counter = 0;
    for (int a = 500; a>0 ; a--)
    {
        for (int b = 500; b>a; b--)
        {
            for (int c = 500; c>0; c--){
                if (a*a + b*b == c*c)
                {
                    cout << a << " " << b << " " << c << endl;
                    counter++;
                }
            }
        }
    }
    cout << "total:" << counter;
}
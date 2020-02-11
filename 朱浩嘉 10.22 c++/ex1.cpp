#include<iostream>
using namespace std;

int main()
{
    int counter = 1;
    int number;
    int largest = 0;
    while (counter <= 10)
    {
        cout << "sale:";
        cin >> number;
        if (largest <= number)
        {
            largest = number;
        }
        counter++;
    }
    cout << largest;
}
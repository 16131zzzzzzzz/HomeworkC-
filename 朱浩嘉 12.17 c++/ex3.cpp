#include<iostream>
#include<array>
using namespace std;

int main(){
    int a[10] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    cout << "Data items in original order\n";
    for (int k = 0; k < 10; k++)
    {
       cout << a[k] << " ";
    }
    cout << endl;
    for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++)
		{
			if (a[j]>a[j + 1]) {
				int ch;
				ch = a[j];
				a[j] = a[j + 1];
				a[j + 1] = ch;
			}
		}
	}
    cout << "Data items in ascending order\n";
    for (int j = 0; j < 10; j++)
    {
       cout << a[j] << " ";
    }
    cout << endl;
}
#include<iostream>
using namespace std;

int main(){
    char c1[10], c2[22];
	int l1, l2;
	cout << "Please input two strings" << endl;
	cin.getline(c1, 11, '\n');
	cin.getline(c2, 22, '\n');
    for(int i=0;i<10;i++){
        if(*(c1+i)>='a'&&*(c1+i)<='z'){
            *(c1+i)-=32;
        }
    }

    for(int i=0;i<21;i++){
        if(*(c2+i)>='a'&&*(c2+i)<='z'){
            *(c2+i)-=32;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << c1[i];
    }
    cout << ", ";
    for (int i = 0; i < 22; i++)
    {
        cout << c2[i];
    }
}
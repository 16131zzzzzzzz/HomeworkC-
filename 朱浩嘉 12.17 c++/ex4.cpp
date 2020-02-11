#include<iostream>
#include<array>
using namespace std;

int main(){
    int a[1000];
    for (int i = 0; i < 1000; i++)
    {
        a[i]=i;
    }
    for (int k = 2; k < 1000; k++)
    {
        if (a[k]!=0){
            for (int j = k+1; j < 1000; j++){
                if (a[j]!=0){
                    if (a[j]%a[k]==0){
                        a[j]=0;
                    }
                }
            }
        }
    }
    for (int n = 2; n < 1000; n++){
        if (a[n]!=0)
        {
            cout << a[n] << " ";
        }
    }
}
#include<iostream>
#include<array>
using namespace std;


int main(){
    array<int,20>n;
    array<int,20>un;
    cout << "input 20 numbers:";
    int count = 0;
    int a;

    for (int p=0;p<20;p++){
        cin >> n[p];
    }

    for (int i=0;i<20;i++){
        int re = 0;
        for (int j=0;j<20;j++){
            if((n[j]==n[i])&&(i!=j)){
                re = 1;
            }
        }
        if (!re&&(n[i]>=10)&&(n[i]<=100)){
            un[count]=n[i];
            count++;
        }
    }

    for (int q=0;q<count;q++){
        cout << un[q] << " ";
    }
}

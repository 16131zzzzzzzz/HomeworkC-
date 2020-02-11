#include<iostream>
using namespace std;

bool isPerfect(int input){
    int sum = 0;
    for (int i=1;i<input;i++){
        if (input%i==0){
            sum += i;
        }
    }
    if (sum == input){
        return 1;
    }
    else{
        return 0;
    }
}
void display(int a){
    cout << a << " = ";
    for (int i=1;i<a;i++){
        if (a%i==0){
            if(i!=1){
                cout << " + " << i;
            }
            else{
                cout << i;
            }
        }
    }
}
int main(){
    for (int i=1; i<=1000;i++){
        if (isPerfect(i)){
            display(i);
            cout << endl;
        }
    }
}
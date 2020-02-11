#include<iostream>
using namespace std;

bool ifPrime(int a){
    bool isprime = 1;
    for(int i=2;i<a;i++){
        if (a%i==0){
            isprime = 0;
            break;
        }
    }
    return isprime;
}

int main(){
    int sum = 0;
    for (int k=2;k<=10000;k++){
        if (ifPrime(k)){
            cout << k << " ";
            sum++;
        }
    }
    cout << endl;
    cout << "Total of " << sum << " prime numbers between 1 and 10000";
}
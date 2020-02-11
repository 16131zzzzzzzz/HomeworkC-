#include<iostream>
using namespace std;
void square( int side, string fillCharacter){
        for (int i = side; i>0; i--){
            for (int k = side; k>0; k--){
                cout << fillCharacter;
            }
            cout << endl;
        }
    }
int main(){
    square(5,"@");
    square(10,"A");
}
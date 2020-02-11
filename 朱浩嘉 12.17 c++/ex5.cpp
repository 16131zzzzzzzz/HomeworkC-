#include<iostream>
#include<array>
using namespace std;

int a[8][8];
int map;

bool check(int k,int j){
    for(int i=0;i<8;i++){
        if(a[i][j]==1){
                return false;
        }
    }
    for(int i=k-1,m=j-1; i>=0 && m>=0; i--,m--){
        if(a[i][m]==1){
                return false;
        }
    }
    for(int i=k-1,m=j+1; i>=0 && m<=7; i--,m++){
        if(a[i][m]==1){
                return false;
        }
    }
    return true;
}

void findQueen(int i){
    if(i>7){
        map++;
    }

    for (int m = 0; m < 8; m++)
    {
        if(check(i,m)){
            a[i][m]=1;
            findQueen(i+1);
            a[i][m]=0;
        }
    }
}

int main(){
    findQueen(0);
    cout << "The eight queen problem has " << map << " solutions.";
}
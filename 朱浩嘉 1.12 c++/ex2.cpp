#include<iostream>
#include<string>
using namespace std;

int main(){
    int a[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int (*p)[5] = a;
    for (int d = 0; d < 3; d++){
        for (int i = 0; i < 5; i++){
            cout << *(*(p+d)+i) << " ";
        }
        cout << endl;
    }
}
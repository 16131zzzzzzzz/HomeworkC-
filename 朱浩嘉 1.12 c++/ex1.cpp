#include <iostream>
using namespace std;
// void swap1(int a, int b){
//         int temp = a;
//         a = b;
//         b = temp;
//         cout << a << " " << b << endl;
//     }

void swap2(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int num1 = 1;
    int num2 = 2;
    swap2(&num1,&num2);
    cout << num1 << " " << num2 << endl;
}

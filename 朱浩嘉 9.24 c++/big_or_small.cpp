#include<iostream>
using namespace std;
int main(){
	int num1 ,num2 ,num3;\
	cout << "num1:";
	cin >> num1;
	cout << "num2:";
	cin >> num2;
	cout << "num3:";
	cin >> num3;

	int sum = num3 + num2 + num3;
	cout << "sum:" << sum << endl;

	int average = sum / 3;
	cout << "average:" << average << endl;

	int product = num1*num2*num3;
	cout << "product:" << product << endl;

	int max = num1;
	if(num2 > num1){
		max = num2;
	}
	if(num3 > max){
		max = num3;
	}
	cout << "largest:" << max << endl;

	int min = num1;
	if(num2 < num1){
		min = num2;
	}
	if(num3 < min){
		min = num3;
	}
	cout << "smallest:" << min << endl;
}
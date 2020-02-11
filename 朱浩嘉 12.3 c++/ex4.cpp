#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

template<typename T>
int TwoSmallest(T a, T b, T c, T& s1, T& s2)
{
	T arr[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr, arr+3);
	s1 = arr[0];
	s2 = arr[1];
	if (s1 == s2) return 1;
	else return 2;
}

template<typename T>
void ShowTwoSmallest(int smallnum,T s1,T s2)
{
	if (smallnum==2) {
        cout << "The smallest number: " << (s1<s2?s1:s2) << endl << "The second smallest number: " << (s1<s2?s2:s1);
    }
	else {
        cout << "The smallest number: " << s1;
    }
}

void Line()
{
	for (int counter=0;counter<21;counter++)
	{
		cout << "*";
	}
	cout << endl;
}

void demand()
{
	Line();
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. char" << endl;
	cout << "4. string" << endl;
	cout << "0. exit" << endl;
	Line();
}

int main(){
	int choice = 1, jug;
	while (choice != 0){
		demand();
		cout << "Input choice: ";
		cin >> choice;
        switch(choice){
            case 0:
            break;

            case 1:
            int Int1, Int2, Int3, in1, in2;
            cout << "Int1:";
			cin >> Int1;
			cout << "Int2:";
			cin >> Int2;
			cout << "Int3:";
			cin >> Int3;
			jug = TwoSmallest(Int1, Int2, Int3, in1, in2);
			ShowTwoSmallest(jug, in1, in2);
            break;

            case 2:
            double Dob1, Dob2, Dob3, db1, db2;
            cout << "Double1:";
			cin >> Dob1;
			cout << "Double2:";
			cin >> Dob2;
			cout << "Double3:";
			cin >> Dob3;
			jug = TwoSmallest(Dob1, Dob2, Dob3, db1, db2);
			ShowTwoSmallest(jug, db1, db2);
            break;

            case 3:
            char Cha1, Cha2, Cha3, ch1, ch2;
            cout << "Char1:";
			cin >> Cha1;
			cout << "Char2:";
			cin >> Cha2;
			cout << "Char3:";
			cin >> Cha3;
			jug = TwoSmallest(Cha1, Cha2, Cha3, ch1, ch2);
			ShowTwoSmallest(jug, ch1, ch2);
            break;

            case 4:
            string Str1, Str2, Str3, st1, st2;
            cout << "String1:";
			cin >> Str1;
			cout << "String2:";
			cin >> Str2;
			cout << "String3:";
			cin >> Str3;
			jug = TwoSmallest(Str1, Str2, Str3, st1, st2);
			ShowTwoSmallest(jug, st1, st2);
            break;
        }
		cout << endl;
	}
}



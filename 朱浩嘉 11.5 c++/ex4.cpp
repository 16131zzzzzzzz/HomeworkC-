#include<iostream>
#include<ctime>
using namespace std;

bool ifHead(){
    if(rand()%2==0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    for(;;){
        double sum = 0;
        double times;
        cout << "Times you want to roll:";
        cin >> times;
        srand(time(0));
        for (int i=1;i<=times;i++){
            if (ifHead()){
                sum++;
            }
        }
        double per = sum/times;
        cout << "Your head rate is:" << per << endl;
    }
}
#include <windows.h>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<string>
using namespace std;

struct unocard{
    int num, color, tag;
};//牌包括数字颜色和状态（0在牌堆，1在手上，2已被打出）

vector<unocard> cards;//牌堆

unocard player[4][30];
int cardnum[4] = {0,0,0,0};

void shuffle(){
	srand(static_cast<unsigned int>(time(NULL)));
	int i = 108;
	while (i>1)
	{
		i--;
		int j = rand() % (i + 1);
		swap(cards[i], cards[j]);
	}
}//洗牌

void cardgenerate(){
    for(int i = 0; i < 13; i++){
        for (int j = 0; j < 4;j++){
            unocard a;
            a.num = i;
            a.color = j;
            a.tag = 0;
            cards.push_back(a);
        }
    }
    for(int i = 1; i < 13; i++){
        for (int j = 0; j < 4;j++){
            unocard a;
            a.num = i;
            a.color = j;
            a.tag = 0;
            cards.push_back(a);
        }
    }
    for (int j = 0; j < 4;j++){
        unocard a,b;
        a.color,b.color = 4;
        a.num = 0;
        b.num = 1;
        a.tag,b.tag = 0;
        cards.push_back(a);
        cards.push_back(b);
    }
}//卡牌生成并放进牌堆

/* void showcardplie(){
    for (int i = 0; i < 108; i++){
        unocard a = cards[i];
        cout << a.color << a.num << "   ";
    }
} */
//显示牌堆

bool gamestate = 1;//游戏状态，可以是1进行，0是结束
bool order = 1;//1顺时针，0逆时针

bool judgecardplie(){
    unocard a = cards.back();
    return a.tag==2?1:0;
};//检查牌堆第一张是否是打出过的,打出过为1

bool judgecard(unocard fcard, unocard out){
    return fcard.color == out.color||fcard.num == out.num;
};//检查出卡是否合法

int flag = -1;//到谁出牌

void moveflag(int a){
    flag = (order?flag+a:flag-a);
    if(flag == -2) {flag = 2;}
    if(flag == -1) {flag = 3;}
    if(flag == 4) {flag = 0;}
    if(flag == 5) {flag = 1;}
}

void givecard(int who){
    unocard a = cards.back();
    a.tag = 1;
    player[who][cardnum[who]+1] = a;
    cards.pop_back();
    cardnum[who]++;
};//输入给谁，然后从牌堆那张牌给他

void showunocard(unocard a){
        string co;
        switch(a.color){
            case 0:
                co = "红";
                break;
            case 1:
                co = "蓝";
                break;
            case 2:
                co = "黄";
                break;
            case 3:
                co = "绿";
                break;
            case 4:
                co = "黑";
                break;
        }
        cout << co;
        if(a.color == 4){
            cout << (a.num == 1)?"+4":"变色";
        }
        else{
            if(a.num > 9){
                switch(a.num){
                    case 10:
                        cout << "禁止";
                        break;
                    case 11:
                        cout << "转向";
                        break;
                    case 12:
                        cout << "+2";
                        break;
                }
            }
            else{
                cout << a.num;
            }
        }
        cout << "  ";
    cout << endl;
}


void showcard(int who){
    cout << who+1 << "号玩家的手牌：";
    for (int i = 0; i < cardnum[who]; i++){
        unocard a = player[who][i];
        string co;
        switch(a.color){
            case 0:
                co = "红";
                break;
            case 1:
                co = "蓝";
                break;
            case 2:
                co = "黄";
                break;
            case 3:
                co = "绿";
                break;
            case 4:
                co = "黑";
                break;
        }
        cout << i+1 << "." << co;
        if(a.color == 4){
            cout << (a.num == 1)?"+4":"变色";
        }
        else{
            if(a.num > 9){
                switch(a.num){
                    case 10:
                        cout << "禁止";
                        break;
                    case 11:
                        cout << "转向";
                        break;
                    case 12:
                        cout << "+2";
                        break;
                }
            }
            else{
                cout << a.num;
            }
        }
        cout << "  ";
    }
    cout << endl;
};//输入谁，显示玩家手牌

unocard begincard(){
    unocard a = cards.back();
    while (a.color == 4 && a.num == 1){
        shuffle();
        a = cards.back();
    }
    return a;
}//抽起始牌

unocard frontcard;

void card(unocard a){
    if(a.color == 4){
        if(a.num == 1){
            for (int i = 0; i < 4; i++){
                givecard(order?flag+1:flag-1);
            }
            moveflag(2);
        }
        else{
            unocard a;
            a.num = 20;
            cout << "which color?(0=red/1=blue/2=yellow/3=green)";
            int co;
            cin >> co;
            a.color = co;
            frontcard = a;
            moveflag(1);
        }
    }
    else{
        if(a.num > 9){
            switch(a.num){
                case 10:
                    moveflag(2);
                    break;
                case 11:
                    order = !order;
                    moveflag(1);
                    break;
                case 12:
                    for (int i = 0; i < 2; i++){
                        givecard(order?flag+1:flag-1);
                    }
                    moveflag(2);
                    break;
            }
        }
        else{
            moveflag(1);
        }
    }
}//卡牌生效，flag变动，加牌操作

bool judgeend(){
    for (int i = 0; i < 4; i++)
    {
        if(cardnum[i] == 0){
            cout << "player" << i << "win";
            return 0;
            break;
        }
    }
}//检测游戏是否结束,并打印winner

void deletecard(int a){
    for (int i = a; i <= cardnum[flag]; i++){
        player[flag][i-1] = player[flag][i];
    }
    cardnum[flag]--;
}

int main(){
    SetConsoleOutputCP(65001);
    cardgenerate();
    shuffle();
    //showcardplie();
    for (int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            givecard(j);
        }
    }//发起始牌
    frontcard = begincard();//前一张牌，开始的时候翻一张赋值
    showunocard(frontcard);
    card(frontcard);
    while(gamestate){
        if(judgecardplie()) shuffle();//如果牌堆已经全部拿过了就洗牌
        showcard(flag);
        cout << "出牌？[y/n]";
        string a;
        cin >> a;
        if(a == "y"){
            bool judger = 0;
            int b;
            do
            {cout << "which?";
            cin >> b;
            b-=1;
            judger = judgecard(frontcard,player[flag][b]);
            }while(!judger);//玩家输入直到出牌合法
            frontcard = player[flag][b];
            showunocard(frontcard);
            frontcard.tag =2;
            cards.insert(cards.begin(),frontcard);
            card(player[flag][b]);
            deletecard(b);
            gamestate = judgeend();//判断是否打光了手牌
        }
        else{
            givecard(flag);
            showcard(flag);
            cout << "出牌？[y/n]";
            string a;
            cin >> a;
            if(a == "y"){
                bool judger = 0;
                int b;
                {cout << "which?";
                cin >> b;
                b-=1;
                judger = judgecard(frontcard,player[flag][b]);
                }while(judger)//玩家输入直到出牌合法
                gamestate = judgeend();//判断是否打光了手牌
                card(player[flag][b]);
                frontcard = player[flag][b];
            }
            else{
                moveflag(1);
            }
        }
    }
}
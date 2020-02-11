//#include "stdafx.h"
#include <windows.h>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<string>
using namespace std;
struct node
{
	int num, color;
};
int n;
vector<node> card;
vector<node> handcard[100];
node e;
int bankerpos, startpos;
int pos;
int x;
char o;
int tab, flag;
void shuffle(vector<node>& V)
{
	srand(static_cast<unsigned int>(time(NULL)));
	size_t i = V.size();
	while (i>1)
	{
		i--;
		size_t j = rand() % (i + 1);
		swap(V[i], V[j]);
	}
}
void initialization()
{
	cout << "本次游戏：\n功能牌有“反转”、“罚牌2张”\n万能牌有“罚牌4张”\n";
	cout << "0-9数字牌   10反转   11罚牌+2   12罚牌+4\ncolor 1、2、3、4、5分别代表红黄蓝绿黑" << endl;//只有功能牌是黑色
	//0
	e.num = 0; e.color = 1; card.push_back(e);
	e.num = 0; e.color = 2; card.push_back(e);
	e.num = 0; e.color = 3; card.push_back(e);
	e.num = 0; e.color = 4; card.push_back(e);
	//1-9数字牌
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 4; j++)
		{
			e.num = i;
			e.color = j;
			card.push_back(e);
			card.push_back(e);
		}
	//功能牌  反转和+2
	for (int i = 1; i <= 4; i++)
	{
		e.color = i;
		e.num = 10;
		card.push_back(e); card.push_back(e);
		e.num = 11;
		card.push_back(e); card.push_back(e);
	}
	e.color = 5;
	e.num = 12;
	//万能牌  +4
	for (int i = 1; i <= 4; i++)
		card.push_back(e);
	cout << "总牌数： " << card.size() << endl;
	cout << "----------------------------------\n";
}
void initNumOfPlayer()//读入玩家个数并给玩家编号
{
	cout << "请输入玩家个数：";
	cin >> n;
	cout << n << "个人的编号从左到右为: ";
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
}
void confirmTheOrderOfPlay()//确定发牌顺序
{
	cout << "首先玩家各抽一张牌\n";
	shuffle(card);//洗牌
	int maxnum = 0, bankerpos = 0;
	cout << "玩家: ";
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl << "手牌: ";
	for (int i = 1; i <= n; i++)
	{
		e = card.back();
		while (e.num > 9)//如果摸的牌为非数字牌，则重摸
		{
			card.push_back(e);
			shuffle(card);
			e = card.back();
		}
		cout << card.back().num << ' ';
		if (card.back().num > maxnum)//确定庄家
		{
			maxnum = card.back().num;
			bankerpos = i;
		}
		card.pop_back();
	}
	cout << endl;
	if (bankerpos == 1)
		startpos = n;
	else startpos = bankerpos - 1;
	cout << "最大牌为" << maxnum << ",对应" << bankerpos << "号玩家" << endl;
	cout << "庄家为" << bankerpos << "号玩家,从" << startpos << "号玩家开始发牌\n";
}
string getcolor(int x)
{
	//color 1、2、3、4、5分别代表红黄蓝绿黑
	if (x == 1)return "红";
	if (x == 2)return "黄";
	if (x == 3)return "蓝";
	if (x == 4)return "绿";
	if (x == 5)return "黑";
}
void getHandCard()
{
	cout << "玩家摸牌\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 7; j++)//每人摸7张牌
		{
			handcard[i].push_back(card.back());
			card.pop_back();
		}
	}
	for (int i = 1; i <= n; i++)//输出每个选手的手牌
	{
		cout << i << "号手牌：";
		for (int j = 0; j<handcard[i].size(); j++)
			cout << handcard[i][j].num << ' ';
		cout << endl << "         ";
		for (int j = 0; j<handcard[i].size(); j++)
			cout << getcolor(handcard[i][j].color) << ' ';
		cout << endl;
	}
}
bool gameOver()
{
	for (int i = 1; i <= n; i++)
		if (!handcard[i].empty())
			return 0;
	return 1;
}
void Over(int x)
{
	cout << "----------游戏结束-------\n";
	if (x != -1)cout << x << "号玩家赢\n";
	cout << "现在根据其他玩家手上纸牌的数字统计分数：\n";
	for (int i = 1; i <= n; i++)
	{
		if (handcard[i].size() == 0)continue;
		int sum = 0;
		for (int j = 0; j<handcard[i].size(); j++)
		{
			if (handcard[i][j].num == 12)sum += 50;
			else if (handcard[i][j].num == 11 || handcard[i][j].num == 10)sum += 20;
			else sum += handcard[i][j].num;
		}
		cout << i << "号玩家：" << sum << "分\n";
	}
}
void havePenalty()
{
	cout << "上位玩家打出的罚牌" << flag << "张现在生效，" << pos << "号玩家本次停止出牌，并罚抽" << flag << "张牌\n";
	for (int i = 1; i <= flag; i++)
	{
		handcard[pos].push_back(card.back());
		card.pop_back();
	}
	cout << pos << "号选手手牌：";
	for (int i = 0; i<handcard[pos].size(); i++)
		cout << handcard[pos][i].num << ' '; cout << endl;
	cout << "           ";
	for (int i = 0; i<handcard[pos].size(); i++)
		cout << getcolor(handcard[pos][i].color) << ' '; cout << endl;
	pos += tab;
	if (pos>n)pos = 1;
	if (pos<1)pos = n;
	flag = 0;
}
int main()
{
	SetConsoleOutputCP(65001);
    initialization();
	initNumOfPlayer();
	cout << endl << "-----------------现在游戏开始！--------------\n";
	confirmTheOrderOfPlay();
	getHandCard();

	node nowcard = card.back();
	card.pop_back();
	cout << "从牌堆摸一张牌：" << nowcard.num << ' ' << getcolor(nowcard.color) << endl;
	//先数字后花色
	cout << "------现在开始发牌!(注意手牌编号是从0开始的)------\n";
	pos = startpos;
	tab = 1;
	flag = 0;

	while (!gameOver())
	{
		if (flag != 0)
		{
			havePenalty();
			continue;
		}
		if (card.size() == 0)
		{
			cout << "牌堆已无牌\n";
			Over(-1);
			system("pause");
			return 0;
		}
		cout << "请" << pos << "号玩家发牌：\n";
		cout << pos << "号选手手牌：";
		for (int i = 0; i < handcard[pos].size(); i++)
			cout << handcard[pos][i].num << ' '; cout << endl;
		cout << "           ";
		for (int i = 0; i < handcard[pos].size(); i++)
			cout << getcolor(handcard[pos][i].color) << ' '; cout << endl;
		cout << "是否有合适的手牌(Y/N)?";
		o = getchar();
		cin >> o;
		while (o == 'N')
		{
			cout << "请摸牌\n";
			handcard[pos].push_back(card.back());
			card.pop_back();
			cout << pos << "号选手手牌：";
			for (int i = 0; i < handcard[pos].size(); i++)
				cout << handcard[pos][i].num << ' '; cout << endl;
			cout << "           ";
			for (int i = 0; i < handcard[pos].size(); i++)
				cout << getcolor(handcard[pos][i].color) << ' '; cout << endl;
			cout << "是否有合适的手牌(Y/N)?";
			o = getchar();
			cin >> o;
		}
		cout << "是否发牌(Y/N)？";
		o = getchar();
		cin >> o;
		if (o == 'Y')
		{
			cout << "请发牌：";
			o = getchar();
			cin >> x;
			if (x >= handcard[pos].size() || (handcard[pos][x].num != nowcard.num && handcard[pos][x].color != nowcard.color&&handcard[pos][x].color != 5))
			{
				cout << "发牌不符合规则，请重新发：";
				cin >> x;
			}
			nowcard = handcard[pos][x];
			vector<node>::iterator iter = handcard[pos].begin() + x;
			handcard[pos].erase(iter);//删除第x个元素
			cout << pos << "号玩家手牌变为：";
			for (int i = 0; i < handcard[pos].size(); i++)
				cout << handcard[pos][i].num << ' '; cout << endl;
			cout << "           ";
			for (int i = 0; i < handcard[pos].size(); i++)
				cout << getcolor(handcard[pos][i].color) << ' '; cout << endl;
			if (handcard[pos].size() == 1)
				cout << "-----------NUO----------\n";
			if (handcard[pos].size() == 0)
			{
				Over(pos);
				system("pause");
				return 0;
			}
			if (nowcard.num == 10)//如果打出了反转牌
			{
				cout << pos << "号玩家打出反转牌，现在调转发牌顺序!\n";
				if (tab == 1)tab = -1;
				else tab = 1;
			}
			if (nowcard.num == 11 || nowcard.num == 12)//如果打出了罚牌2张
			{
				if (nowcard.num == 11)flag = 2; else flag = 4;
				cout << pos << "号玩家发出罚牌" << flag << "张，下位玩家将停止出牌，并罚抽" << flag << "张\n";
			}
			cout << "-----------当前桌面牌：" << nowcard.num << ' ' << getcolor(nowcard.color) << endl;

		}
		pos += tab;
		if (pos > n)pos = 1;
		if (pos < 1)pos = n;
	}
	system("pause");
	return 0;
}
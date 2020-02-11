//this program was made for playing uno.
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
char start = NULL;
const int cards_size = 108;
int cards[cards_size][2] = {}, current_card=cards_size-1; //player_score[4] = {};//[0]stands for number and [1] stands for colors
int player_cards[4][108][2] = {}, player[4] = {},*playerPtr=&player[0],winner=-1;//record the cards of each player
int wasted_cards[108][2] = {}, waste_num = 0;//record the numbers of cards.
int stop=0, reverse1=0, discolor=0, plus2=0, plus4=0;
void suffle() {
	for (int i = cards_size; i >= 1; i--) {
		int temp = rand() % i;
		swap(cards[i-1][0],cards[temp][0]);
		swap(cards[i - 1][1], cards[temp][1]);
	}
}//Suffle the cards.

void create() {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 9; j++) {
			cards[i * 10 + j][0] = j; cards[i * 10 + j][1] = i;
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 1; j <= 9; j++) {
			cards[i * 9 + j + 39][0] = j; cards[i * 9 + j + 39][1] = i;
		}
	}//0-75normal cards
	for (int i = 0; i <= 11; i++) { 
		cards[i + 76][0] = (i % 3) - 3; cards[i + 76][1] = i % 4; cards[i + 88][0] = (i % 3) - 3; cards[i + 88][1] = i % 4; 
	}//the funtion cards.-1 stands for stop, -2 stands for reverse and -3 stands for +2.
	for (int i = 0; i <= 3; i++) {
		cards[i + 100][0] = 10; cards[i + 100][1] = 4;
		cards[i + 104][0] = 11; cards[i + 104][1] = 4;
	}//10 stands for discolor and 11 stands for +4.
	for (int i = 0; i <= 3; i++) { for (int j = 0; j <= 107; j++) { player_cards[i][j][0] = 0; player_cards[i][j][1] = 0; } }
	current_card = cards_size - 1;
	player[0] = 0, player[1] = 0, player[2] = 0, player[3] = 0;//originally every player has no card.
	stop = 0, reverse1 = 0, discolor = 0, plus2 = 0, plus4 = 0;
	for (int i = 0; i <= 107; i++) { for (int& elem : wasted_cards[i]) { elem = 0; } } waste_num = 0;//there should bu nothing in the wasted cards.
}//this part will initiallize a game.

void recreate() {}

void waste(int player,int i,int num,int color) {
	player_cards[player][i][0]=0, player_cards[player][i][1] = 0;
	wasted_cards[waste_num][0] = num;wasted_cards[waste_num][1] = color;
	waste_num++; *(playerPtr + player)-=1;
}//this part will waste a card from player and may use it later.

string color(int color) {
	switch (color) {
	case 0:
		return "red";
		break;
	case 1:
		return "yellow";
		break;
	case 2:
		return "blue";
		break;
	case 3:
		return "greem";
		break;
	default:
		return "black";
		break;
	}
}//this part will return the color of one card.

bool check_end() { for (int i = 0; i <= 3; i++) { if (player[i] == 0) { winner = i+1; return 1; } }return 0; }

bool check_valiable(int a[2],int player) {
	if (player_cards[player][*(playerPtr + player)][0] == 4) { return 1; }
	else if (player_cards[player][*(playerPtr + player)][0] == a[0] && player_cards[player][*(playerPtr + player)][1] == a[1]) { return 1; }
	else return 0;
}

void display_player(int player,bool flag) {}//this part will display all card or card avaliable.

void display(int num,int color) {}//this will display one card.

int deal(int player) {
	if (current_card == 0) {}
	player_cards[player][*(playerPtr + player)][0] = cards[current_card][0], player_cards[player][*(playerPtr + player)][1] = cards[current_card][1];
	cards[current_card][0] = 0; cards[current_card][1] = 0;
	current_card--;
}//this part will give a player a card.unfinished yet

void move(int player, int removed_card) {
	if (removed_card >= *(playerPtr + player)) {
		return; 
	}
	else {
		for (int j = removed_card; j <= *(playerPtr + player); j++) {
			swap(player_cards[player][j][0],player_cards[player][j+1][0]); swap(player_cards[player][j][1], player_cards[player][j + 1][1]);
		}
	}
}

bool  biggest(int a ,int b) {
	if (a > b) { return 0; }
	else if (a < b) { return 1; }
	return 0;
}
//void positive_score() {}
//void negative_score(){}
//void competion_score(){}
//void constant_score(){}
int main() {
	srand(static_cast<int>(time(NULL)));
	cout<< "----Welcome to UNO1.0----\n    Enter Y to start a new game or N to exit.\n    (Y/N)?";
	cin >> start;
	if (start == 'Y') {//main game
		while (true) {
		create(); suffle();
			int max=50000,banker_card=0,banker=0,play_card=0;
			cout << "Every one take a card to decide who is the banker.\nThe first who get the biggest number should be the banker\n";
			for (int i = 0; i <= 3; i++) {
				deal(i); display(i,1);
				if (biggest(banker_card, player_cards[i][*(playerPtr + i)][0])) { 
				banker_card= player_cards[i][*(playerPtr + i)][0],
					banker = i+1; 
				} 
			}
			cout << "The banker is player" << banker;
			//waste four card.
			while(true) {
				if (check_end()) { break; }
				if (stop) { cout << "Current player is passed.\n"; stop = 0; continue; }
				if (reverse1) { max++; }
				else { max--; }
				cout << "Current player is player" <<(max%4+banker)<<endl;
				if (plus2) {for(int i=0;i<=1;i++) deal((max % 4) + banker-1); }
			if (plus4) {for (int i=0;i<=3;i++) deal((max % 4) + banker-1); }
				display_player((max % 4) + banker-1,1);
				cout << "Above is all your card.\n";
				display_player((max % 4) + banker-1, 0);
				cout << "Above is your card avaliable now.\nEnter the number before the card you want to play.\n";
				while (true) {
					cin >> play_card;
					if (play_card<=*(playerPtr+ (max % 4) + banker-1)) {
						cout << "The player played the card" <<endl ;
						//Should store the information of the played cards.
						waste((max % 4) + banker, play_card - 1, player_cards[(max % 4) + banker-1][play_card - 1][0], player_cards[(max % 4) + banker-1][play_card - 1][1]);
						move((max % 4) + banker, play_card - 1);
						break;
					}
					else { cout << "Don't mess up it! Just play your card!\n"; }
				}
				//Should check if it"s a discolor or puls4
			}
			cout << "The winner is player" << winner<<endl;
			cout << "Enter Y to continue or N to end this game.\n(Y\N)?";
			while (true) {
				cin >> start;
				if (start == 'Y') { continue; }
				else if (start == 'N') { cout << "See you next time!"; return 0; }
				else { cout << "It's not funny to disobey my instruction.\n"; }
			}
		}
	}
	else if (start == 'N') { cout << "See you next time!"; return 0; }
	else { cout << "F**k you man,can't you just enter a Y or N?Get outta here!"; }
	return 0;
}
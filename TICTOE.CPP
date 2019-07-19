#include<iostream.h>
#include<conio.h>

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void loadBoard(){
	cout<<"\n\n\t\t--------TIC TAC TOE-----------\n\n";
   //	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char ch1,ch2; //for selecting either X or 0
	cout<<"\t\t "<<   board[0][0]  <<"  |   "<<  board[0][1]  <<"  |  "<<  board[0][2]  <<"\n";
	cout<<"\t\t    |      |                       \n";
	cout<<"\t\t------------------\n";
	cout<<"\t\t "<<   board[1][0]  <<"  |   "<<   board[1][1]  <<"  |  "<<  board[1][2]  <<"\n";
	cout<<"\t\t    |      |                \n";
	cout<<"\t\t------------------\n";
	cout<<"\t\t "<<   board[2][0]  <<"  |   "<<   board[2][1]  <<"  |  "<<board[2][2]<<"\n";
	cout<<"\t\t    |      |                  \n";
}

void play(char ch,int place){
	switch(place)
	{
		case 1:
			board[0][0]=ch;
			break;
		case 2:
			board[0][1]=ch;
			break;
		case 3:
			board[0][2]=ch;
			break;
		case 4:
			board[1][0]=ch;
			break;
		case 5:
			board[1][1]=ch;
			break;
		case 6:
			board[1][2]=ch;
			break;
		case 7:
			board[2][0]=ch;
			break;
		case 8:
			board[2][1]=ch;
			break;
		case 9:
			board[2][2]=ch;
		default:
			cout<<"\nInvalid..!!";


	}
	clrscr();
	loadBoard();
}
char check(){
	if((board[0][0]=='X'&&board[0][1]=='X'&&board[0][2]=='X') ||
	  (board[0][0]=='X'&&board[1][0]=='X'&&board[2][0]=='X') ||
	  (board[0][1]=='X'&&board[1][1]=='X'&&board[2][1]=='X') ||
	  (board[0][2]=='X'&&board[1][2]=='X'&&board[2][2]=='X') ||
	  (board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X') ||
	  (board[1][0]=='X'&&board[1][1]=='X'&&board[1][2]=='X') ||
	  (board[2][0]=='X'&&board[2][1]=='X'&&board[2][2]=='X') ||
	  (board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X')){
		cout<<"\n----------CONGRATULATIONS----------------";
	   //	cout<<"\n----------PLAYER1 WON..!!!-------------\n";
		return 'X';//so that we understand who won the player who chooses X will win
		}
	else if((board[0][0]=='0'&&board[0][1]=='0'&&board[0][2]=='0') ||
	  (board[0][0]=='0'&&board[1][0]=='0'&&board[2][0]=='0') ||
	  (board[0][1]=='0'&&board[1][1]=='0'&&board[2][1]=='0') ||
	  (board[0][2]=='0'&&board[1][2]=='0'&&board[2][2]=='0') ||
	  (board[0][2]=='0'&&board[1][1]=='0'&&board[2][0]=='0') ||
	  (board[1][0]=='0'&&board[1][1]=='0'&&board[1][2]=='0') ||
	  (board[2][0]=='0'&&board[2][1]=='0'&&board[2][2]=='0') ||
	  (board[0][0]=='0'&&board[1][1]=='0'&&board[2][2]=='0')){
		cout<<"\n----------CONGRATULATIONS----------------";
	   //	cout<<"\n----------PLAYER2 WON..!!!-------------\n";
		return '0';//so that we understand ----
		}
	return 'N';
}
void selectionOfXor0(){
	char ch1,ch2;//for selecting either X or 0
	cout<<"\tPlease select X or 0: \t";
	cin>>ch1;
	if(ch1=='x')   //For checking if entered lowercase letter
		ch1=ch1-32;  //x->120   120-32='X'
	cout<<"\n\tPLAYER 1 : "<<ch1;   //ch1 for player1

	if(ch1=='X'){
		ch2='0';
		cout<<"\n\tPLAYER 2 : "<<ch2; //ch2 for player2
		}
	else{
		ch2='X';
		cout<<"\n\tPLAYER 2 : "<<ch2;
		}
	int place; //which place u want to enter X or 0
	int player_no=1;// player1 will play
	 char x;//for storing return character  from check()
	for(int i=0;i<9;i++){

		if(player_no==1){
		//--------THIS IS PLAYER1 PART----------
			cout<<"\nPLAYER1:Enter["<<ch1<<"] on above board: ";
			cin>>place;
			play(ch1,place);
			x=check(); //x is storing returned value of check()
			if(x=='X'||x=='0'){
				cout<<"\n----------PLAYER1 WON-------------\n\n";
				break; }
			player_no++;

			}//closing if
		else{
		//----------THIS IS PLAYER2 PART---------
			cout<<"\nPLAYER2:Enter["<<ch2<<"] on above board: ";
			cin>>place;
			play(ch2,place);
			x=check();
			if(x=='X'||x=='0'){
				cout<<"\n-----------------PLAYER2 WON--------------\n\n";
				break;
				}
			player_no--;
			}//closing else
		if(i==8&&x=='N'){
		//for checking if no player wins
			cout<<"\n---------------------MATCH-TIE----------------\n\n";
			}//closing if
		}//closing for loop
}
void main()
{
	clrscr();
	loadBoard();
	selectionOfXor0();
	cout<<"\n\n	THANK YOU...\n";
	getch();
}
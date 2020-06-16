//simple program used to play a tictac toe game with two players
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
using namespace std;

char board[5][5];

void startboard()
{       //prints the initial board
	//system("cls");
	board[0][0] = ' ';
	board[0][1] = '|';
	board[0][2] = ' ';
	board[0][3] = '|';
	board[0][4] = ' ';

	board[1][0] = '-';
	board[1][1] = '-';
	board[1][2] = '-';
	board[1][3] = '-';
	board[1][4] = '-';

	board[2][0] = ' ';
        board[2][1] = '|';
        board[2][2] = ' ';
        board[2][3] = '|';
        board[2][4] = ' ';

	board[3][0] = '-';
        board[3][1] = '-';
        board[3][2] = '-';
        board[3][3] = '-';
        board[3][4] = '-';

	board[4][0] = ' ';
        board[4][1] = '|';
        board[4][2] = ' ';
        board[4][3] = '|';
        board[4][4] = ' ';

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout<<board[i][j] <<" ";
		}
		cout<<endl;
	}

}
void prompt(char player1, int num)
{
	int pos;
	cout<< "Player "<<num<<": "<<endl;
	cout<<"Enter a number 1 through 9, representing the position: ";
	cin >> pos;

	if( pos == 1 && board[0][0] == ' ')
	{
		board[0][0] = player1;
	}
	else if ( pos == 2 && board[0][2] == ' ')
	{
		board[0][2] = player1;
	}
	else if ( pos == 3 && board[0][4] == ' ')
        {
                board[0][4] = player1;
        }
	else if ( pos == 4 && board[2][0] == ' ')
        {
                board[2][0] = player1;
        }
	else if ( pos == 5 && board[2][2] == ' ')
        {
                board[2][2] = player1;
        }
	else if ( pos == 6 && board[2][4] == ' ')
        {
                board[2][4] = player1;
        }
	else if ( pos == 7  && board[4][0] == ' ')
        {
                board[4][0] = player1;
        }
	else if ( pos == 8 && board[4][2] == ' ')
        {
                board[4][2] = player1;
        }
	else if ( pos == 9 && board[4][4] == ' ')
        {
                board[4][4] = player1;
        }
	else
	{
		cout<< "Invalid move ";
	}

}
bool win(char player1)
{
        if((board[0][0] == player1) &&( board[0][2] == player1) && (board[0][4] == player1))
	{
		return true;
	}
	else if((board[0][0] == player1)&&(board[2][0] == player1)&& (board[4][0] == player1))
	{
		return true;
	}
	else if((board[0][0] == player1)&&(board[2][2] == player1)&& (board[4][4] == player1))
	{
		return true;
	}
	else if((board[2][0] == player1)&&(board[2][2] == player1)&& (board[2][4] == player1))
	{
		return true;
	}
	else if((board[4][0] == player1)&&(board[4][2] == player1)&& (board[4][4] == player1))
        {
                return true;
        }
	else if((board[4][0] == player1)&&(board[2][2] == player1)&& (board[0][4] == player1))
        {
                return true;
        }
	else if((board[0][2] == player1)&&(board[2][2] == player1)&& (board[4][2] == player1))
        {
                return true;
        }
	else if((board[0][4] == player1)&&(board[2][4] == player1)&& (board[4][4] == player1))
        {
                return true;
        }
	else
	{
		return false;
	}

}
void check(bool value, char player)
{
	if(( board[0][0] != ' ' )&& (board[0][2] != ' ' ) && (board[0][4] != ' ')&& ( board[2][0] != ' ') && (board[2][2] != ' ') &&(board[2][4] != ' ')&&(board[4][0] != ' ')&&(board[4][2] != ' ')&&(board[4][4] != ' '))
	{
		cout<<"The letter "<< player << " associated with a player won!"<<endl;
                exit(1);
        }
	else if(value == true)
	{
		cout<<"The letter "<<player << " associated with a player won!"<<endl;
		exit(1);
	}
	else
	{
		return;
	}

}
void print()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}


}
int main()
{
	cout<< "T I C  T A C  T O E "<<endl;
	startboard();
	
	
	int num;
        char player1, player2;

        cout<< "Enter a game piece for player 1: X or O ";
        cin >> player1;
        player1 = toupper(player1);

        if(player1 == 'X')
        {
                player2 = 'O';
        }
        else
        {
                player2 = 'X';
        }

   	cout<<"Therefore, player 2 is: "<< player2<<endl;
	
	bool value2;
	while( (win(player1) == false) && (win(player2) == false))
	{
		prompt(player1, 1);
		bool value1 = win(player1);
		check(value1, player1);
		print();
		prompt(player2, 2);
		value2 = win(player2);
		check(value2, player2);
		print();
	}

	return 0;
}

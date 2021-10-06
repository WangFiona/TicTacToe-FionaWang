#include <iostream>
#include <cstring>
using namespace std;

/*
  Author: Fiona Wang
  Date: Sept. 30, 2021
  This program lets two players play TicTacToe against each other.
*/

//Initialize functions
void printBoard(int move[4][4]);
bool checkWins(int board[4][4], int XO);
bool checkTies(int board[4][4]);

int main() {
  //Initialize variables
  int board[4][4]; //0=Empty, 1=X, 2=O
  char input[3];
  int move = 0; //0=X, 1=O
  bool playing = true;
  int letter = 0;
  int number = 0;
  int oWins = 0;
  int xWins = 0;

  //A while loop that runs when the player is still playing
  while (playing == true) {
    //Ask the player to input a coordinate
    cout << "Please enter a coordinate with a lowercase letter followed by a number (eg. a1) for X's turn:" << endl;
    while (checkWins(board, 1)!=true && checkWins(board, 2)!=true && checkTies(board)!=true) {
      cin.get(input,3);
      cin.get();
      letter = input[0]-96;
      number = input[1]-48;

      //Check if the coordinate is valid
      if(!((input[0]>='a' && input[0]<='c') && (input[1]>='1' && input[1]<='3') && (board[letter][number]==0))){
	cout << "Please enter a valid coordinate" << endl;
      }
      else { //If the coordinate is valid
	//Update the board
	if (move == 0) {
	  board[letter][number] = 1;
	  move=1;
	} else {
	  board[letter][number] = 2;
	  move=0;
	}
	printBoard(board);

	//Check if anybody has won or tied
	if (checkWins(board, 1)==true) {
	  cout << "X wins!" << endl;
	  xWins++;
	}
	if (checkWins(board, 2)==true) {
	  cout << "O wins!" << endl;
	  oWins++;
	}
	if (checkTies(board)==true) {
	  cout << "Tie!" << endl;
	}
	if (checkWins(board, 1)!=true && checkWins(board, 2)!=true && checkTies(board)!=true) { //Instructions for the player
	  if (move==1) {
	    cout << "Please enter a coordinate with a lowercase letter followed by a number (eg. a1) for O's turn:" << endl;
	  }
	  else {
	    cout << "Please enter a coordinate with a lowercase letter followed by a number (eg. a1) for X's turn:" << endl;
	  }
	}
	
	//If the game is over announce the wins and ask if the player wants to play again
	if (checkWins(board, 1)==true || checkWins(board, 2)==true || checkTies(board)==true) {
	  cout << "X Wins: " << xWins << endl;
	  cout << "O Wins: " << oWins << endl;
	  cout << "Would you like to play again? (y/n)" << endl;
	  char yn[2];
	  char n[2];
	  n[0]='n';
	  n[1]='\0';
	  cin.get(yn, 2);
	  cin.get();
	  
	  //If the player does not want to play again
	  if (strcmp(yn,n)==false) {
	    playing = false;
	  }
	  //If the player does want to play again
	  else {
	    for (int row=1; row<4; row++){
	      for (int column=1; column<4; column++) {
		board[row][column] = 0;
		move=0;
	      }
	    }
	    cout << "Please enter a coordinate with a lowercase letter followed by a number (eg. a1) for X's turn:" << endl;
	  }
	}
      }
    }
  }
}


//Function for checking for wins
bool checkWins(int board[4][4], int XO) {
  if (board[1][1]==XO && board[1][2]==XO && board[1][3]==XO) {
    return true;
  }
  else if (board[2][1]==XO && board[2][2]==XO && board[2][3]==XO) {
    return true;
  }
  else if (board[3][1]==XO && board[3][2]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][1]==XO && board[2][1]==XO && board[3][1]==XO) {
    return true;
  }
  else if (board[1][2]==XO && board[2][2]==XO && board[3][2]==XO) {
    return true;
  }
  else if (board[1][3]==XO && board[2][3]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][1]==XO && board[2][2]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][3]==XO && board[2][2]==XO && board[3][1]==XO) {
    return true;
  }
  else {
    return false;
  }
}


//Function for checking for ties
bool checkTies(int board[4][4]) {
  for (int row=1; row<4; row++){
    for (int column=1; column<4; column++) {
      if (board[row][column] == 0) {
	return false;
      }
    }
  }
  return true;
}


//Function to print out the board
void printBoard(int move[4][4]) {
  cout << "\t1\t2\t3" << endl;
  for (int row=1; row<4; row++) {
    char output[9];
    char abc = 'a'+(row-1);
    output[0] = abc;
    output[1] = '\t';
    int x=2;
    for (int column = 1; column<4; column++) {
      if (move[row][column] == 0) {
	output[x] = ' ';
      } else if (move[row][column] == 1) {
	output[x] = 'X';
      } else {
	output[x] = 'O';
      }
      x++;
      output[x]= '\t';
      x++;
      output[8]='\0';
    }
    cout << output << endl;
  }
}

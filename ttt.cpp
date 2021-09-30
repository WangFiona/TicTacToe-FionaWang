#include <iostream>
#include <cstring>
using namespace std;

void printBoard(int move[4][4]);
bool checkWins(int board[4][4], int XO);
bool checkTies(int board[4][4]);

int main() {
  int board[4][4]; //0=Empty, 1=X, 2=O
  char input[3];
  int move = 0; //0=X, 1=O
  bool playing = true;
  int letter = 0;
  int number = 0;
  int oWins = 0;
  int xWins = 0;
  
  while (playing == true) {
    cout << "Please enter a coordinate (eg. a1)" << endl;
    cin.get(input,3);
    cin.get();
    letter = input[0]-96;
    number = input[1]-48;

    if((input[0]>='a' && input[0]<='c') && (input[1]>='1' && input[1]<='3') && (board[letter][number]==0)){
	if (move == 0) {
          board[letter][number] = 1;
          move=1;
        } else {
          board[letter][number] = 2;
          move=0;
        }
        printBoard(board);

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

	if (checkWins(board, 1)==true || checkWins(board, 2)==true || checkTies(board)==true) {
          cout << "X Wins: " << xWins << endl;
    	  cout << "O Wins: " << oWins << endl;
	  cout << "Would you like to play again? (y/n)" << endl;
	  char yn='y';
	  cin >> yn;

	  if (yn == 'n') {
	    playing = false;
	  }
	  else if (yn == 'y') {
            for (int row=1; row<4; row++){
              for (int column=1; column<4; column++) {
                board[row][column] = 0;
		move=0;
              }
            }
	  }
	}
    } else {
      cout << "Please enter a valid coordinate" << endl;
    }
  }
}


bool checkWins(int board[4][4], int XO) {
  if (board[1][1]==XO && board[1][2]==XO && board[1][3]==XO) {
    return true;
  }
  else if (board[2][1]==XO && board[2][2]==XO && board[2][3==XO]) {
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

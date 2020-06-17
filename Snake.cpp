#include <iostream>
#include <conio.h>

using namespace std;

enum eDirectron {STOP = 0 , LEFT , RIGHT , TOP , DOWN};


/*
build board only in chrage of buillding the borad with all parameters given
*/
void build_board(const int high , const int wide , int& furit_in_wide,  int& furit_in_high , const int snake_in_high , const int snake_in_wide, int& score, bool& gameover) {
	system("cls");
	for (int i = 0; i < high; i++)
	{
		for (int j = 0; j < 1; j++)
		{

			if (i == 0 || i == wide - 1) {
				for (int w{}; w < wide; w++)
					cout << "#"; // builds floor and celling
			}
			else {
				cout << "#"; // builds left wall
				for (int w{}; w < wide - 2; w++) {
					if (i == furit_in_high && w == furit_in_wide)
						cout << "%"; // put furit in random place
					else if (snake_in_high == high || snake_in_wide == wide || snake_in_high == 0 || snake_in_wide == 0) { // checking if snake hits walls or celling
						gameover = true; // setting gameover
						return; // return to break funcation 
					}
					else if (i == snake_in_high && w == snake_in_wide)
						cout << "*"; //puts the snake in the middle at the starts and move dynamically with snake move
					else if (snake_in_high == furit_in_high && snake_in_wide == furit_in_wide) { //checking if snake touching furit
						score++; //adding score
						furit_in_wide = rand() % wide; // changing the furit place in y
						furit_in_high = rand() % high; // changing the furit place in x
					}
					else
						cout << " "; //blank spaces for right wall
				}
				cout << "#"; // for right wall
			}
			cout << endl; // finishes the for loop with endline for the next for loop 
		}
	}
}

/*
waiting for user input and still looping in main funcation
using & to return movement
*/
void movment_input(eDirectron& movement) {
	if (_kbhit()) { // waiting until key is being pressed
		switch (_getch()) {
		case 'a':
			movement = LEFT; // assigning LEFT to movement
			break;
		case 's':
			movement = DOWN; // assigning DOWN to movement
			break;
		case 'w':
			movement = TOP; // assigning TOP to movement
			break;
		case 'd':
			movement = RIGHT; // assigning RIGHT to movement
			break;
		}
	}

}
/*
based on eDirection chagning the snake in board 
*/
void snake_move(const eDirectron movement, int& snake_in_high, int& snake_in_wide) {
	switch (movement) {
	case TOP:
		snake_in_high--; // adding 1 for snake in high to move snake top
		break;
	case DOWN:
		snake_in_high++; // adding 1 for snake in high to move snake down
		break;
	case RIGHT:
		snake_in_wide++; // adding 1 for snake in high to move snake right
		break;
	case LEFT:
		snake_in_wide--;// adding 1 for snake in high to move snake left
		break;
	}

}


int main()
{
	int score{};
	bool gameover = false;
	const int borad_hight{ 40 };
	const int borad_wide{ 40 };
	eDirectron movement = STOP;
	int snake_in_wide = borad_wide / 2; // snake in the middle of the borad 
	int snake_in_high = borad_hight / 2; // snake in the middle of the borad 
	int furit_in_wide = rand() % borad_wide; // random place fruit in first run
	int furit_in_high = rand() % borad_hight; // random place fruit in first run
	while (!gameover)
	{
		//increase_all_element(snake_in_x);
		build_board(borad_hight, borad_wide, furit_in_wide, furit_in_high, snake_in_high, snake_in_wide, score,gameover);
		movment_input(movement);
		snake_move(movement, snake_in_high, snake_in_wide);
	}
	system("cls");
	cout << "Game over " << endl;
	cout << "Your score is " << score;
	return 0;
}
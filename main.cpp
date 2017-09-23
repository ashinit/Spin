/***************************************************

Created by Ashini Tennakoon
COMPSCI1037 Assignment 2
Nov. 24 2016
Copyright 2016, Ashini Tennakoon, All rights reserved.

****************************************************/

#include"TopSpin.h"
#include<iostream>

using std::cout;
using std::cin;

int main()
{
	TopSpin board(20, 4);
	int move, choice, direction,shifts;
	cout << "Enter the number of random moves you would like to initialize the puzzle with: ";
	cin >> move;
	for (int i = 0; i < move; i++)
	{
		board.shiftLeft();
		board.spin();
	}
	while (board.isSolved() == false)
	{
		cout << "Please choose from the following options enter your choice by entering the corresponding number : \n1. Shift \n2. Spin\n3. Exit\n";
		board.print();
		cin >> choice;
		switch (choice)
		{
		case 1:
			do {
				cout << "By how many would you like to shift by?\n";
				cin >> shifts;
			} while (shifts <= 0);

			cout << "Would you like to shift Left or Rigth? \n 1. Left \n 2. Right\n";
			cin >> direction;
			
			if (direction == 1) {
				for (int i = 1; i <= shifts; i++) {
					board.shiftLeft();
				}
			}
			else if (direction == 2) {
				for (int i = 1; i <= shifts; i++) {
					board.shiftRight();
				}
			}
			else{
				cout << "Invalid Entry!\n";
			}
			break;
		case 2:
			board.spin();
			break;
		case 3:
			cout << "Thank you for playing!\n";
			return 0;
				
		default:
			cout << "Invalid Entry!\n";
			break;
		}
	}
	board.print();
	cout << "Congratulations! You solved the puzzle.\n";

	return 0;
}
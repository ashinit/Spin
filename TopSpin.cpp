/***************************************************

Created by Ashini Tennakoon
COMPSCI1037 Assignment 2
Nov. 24 2016
Copyright 2016, Ashini Tennakoon, All rights reserved.

****************************************************/

#include"TopSpin.h"
#include<iostream>
using std::cout;

TopSpin::TopSpin(int size, int spinsize){
	_size = size > 0 ? size : 20;
	_spinsize = spinsize < size ? spinsize : 4;
	for (int i = 1; i <= _size; i++)
	{
		board.addTail(i);
	}
}

void TopSpin::print(){
	cout << "[ ";
	for (int i = 1; i <= _spinsize; i++)
	{
		cout << board.retrieve(i) << ' ';
	}
	cout << "] ";
	for (int i = _spinsize + 1; i <= _size; i++)
	{
		cout << board.retrieve(i) << ' ';
	}
	cout << "\n";
}

void TopSpin::spin(){
	
	for (int i = 1; i < _spinsize / 2 + 1; i++)
	{
		if (i != (_spinsize + 1 - i)) board.swap(i, _spinsize + 1 - i);
	}
}

void TopSpin::shiftLeft(){
	board.left();
}

void TopSpin::shiftRight(){
	board.right();
}

bool TopSpin::isSolved(){
	TopSpin temp(_size, _spinsize);
	int x = 0;
	for (int i = 1; i <= _size; i++)
	{
		if (temp.board.retrieve(i) == board.retrieve(i)) x++;
	}
	if (x == _size) return true;
	else return false;
}

ostream& operator << (ostream& os, const TopSpin& s)
{
	os << "[ ";
	for (int i = 1; i <= s._spinsize; i++)
	{
		cout << s.board.retrieve(i) << ' ';
	}
	cout << "] ";
	for (int i = s._spinsize + 1; i <= s._size; i++)
	{
		cout << s.board.retrieve(i) << ' ';
	}
	os << "\n";
	return os;
}

/***************************************************

Created by Ashini Tennakoon
COMPSCI1037 Assignment 2
Nov. 24 2016
Copyright 2016, Ashini Tennakoon, All rights reserved.

****************************************************/

#pragma once
#define TopSpin_h
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std; 

class TopSpinADT {
public:
	virtual void shiftLeft() = 0;
	virtual void shiftRight() = 0;
	virtual void spin() = 0;
	virtual bool isSolved() = 0;

};

class TopSpin : public TopSpinADT
{
private:
	int _size, _spinsize;
	CircularDoublyLinkedList<int> board;

public:
	TopSpin(int size = 20, int spinsize = 4);
	~TopSpin() {};
	void print(); 
	void spin();
	void shiftLeft();
	void shiftRight();
	bool isSolved();
	friend ostream& operator<< (ostream& os, const TopSpin& s);
};


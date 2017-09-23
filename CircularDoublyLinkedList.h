/***************************************************

Created by Ashini Tennakoon
COMPSCI1037 Assignment 2
Nov. 24 2016
Copyright 2016, Ashini Tennakoon, All rights reserved.

****************************************************/

#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "TopSpin.h"

template <class Item>
class CircularDoublyLinkedList {
public:
	struct Node
	{
		Item value;
		Node* next;
		Node* previous;
		Node(int val, Node* nxt = nullptr, Node* prv = nullptr) :value(val), next(nxt), previous(prv) {}
	};
private:
	unsigned m_size;
	Node* m_head;
	Node* m_tail;
public:
	CircularDoublyLinkedList(); 
	~CircularDoublyLinkedList();    
	void addTail(Item item); 
	Item retrieve(int n) const; 
	void swap(int a, int b); 
	void left(); 
	void right(); 

	unsigned int size() const;
	bool isEmpty();
	void addHead(Item item);
	void add(Item item, int position);
	Item removeHead();
	Item replace(unsigned int n, Item item);
	Item remove(unsigned int n);
	Item retrieveTail() const;
	Item retrieveHead() const;
	Item removeTail();

public:
	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		Item operator *() { return m_ptr->value; }
		Item getValue() { return m_ptr->value; }
		void setValue(Item val) { m_ptr->value = val; }
	};

	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(nullptr); }
};

template <class Item>
CircularDoublyLinkedList<Item>::CircularDoublyLinkedList() :m_size(0), m_head(NULL), m_tail(NULL) {}

template <class Item>
CircularDoublyLinkedList<Item>::~CircularDoublyLinkedList(){
	Node * here = m_head, *nextNode;
	int n = 0;
	while (n != m_size)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
		n++;
	}
}

template <class Item>
void CircularDoublyLinkedList<Item>::addTail(Item item){
	if (m_head == nullptr&&m_tail == nullptr)
	{
		m_head = new Node(item);
	}
	else if (m_head != nullptr&&m_tail == nullptr)
	{
		m_tail = new Node(item);
		m_head->next = m_head->previous = m_tail;
		m_tail->next = m_tail->previous = m_head;
	}
	else
	{
		Node* n = m_tail;
		m_tail = new Node(item);
		n->next = m_tail;
		m_tail->previous = n;
		m_tail->next = m_head;
		m_head->previous = m_tail;
	}
	m_size++;
}

template <class Item>
Item CircularDoublyLinkedList<Item>::retrieve(int n) const{
	if (n == 1) return m_head->value;
	Node * here = m_head;
	for (int k = 2; k <= n; k++) here = here->next;
	return here->value;
}

template <class Item>
void CircularDoublyLinkedList<Item>::swap(int a, int b){
	Node* n1 = m_head;
	Node* n2 = m_head;
	for (int k = 1; k < a; k++) n1 = n1->next;
	for (int k = 1; k < b; k++) n2 = n2->next;
	unsigned i = n1->value;
	n1->value = n2->value;
	n2->value = i;
}
template <class Item>
void CircularDoublyLinkedList<Item>::left(){
	m_head = m_head->next;
}
template <class Item>
void CircularDoublyLinkedList<Item>::right(){
	m_head = m_head->previous;

}

//FUNCTIONS BELOW ARE NOT USED FOR TOPSPIN
template <class Item>
unsigned int CircularDoublyLinkedList<Item> ::size() const{
	return m_size;
}

template <class Item>
bool CircularDoublyLinkedList<Item>::isEmpty() {

	return (m_size == 0);
}

template <class Item>
void CircularDoublyLinkedList<Item>::addHead(Item item) {

	if (m_tail == NULL) {
		Node *added;
		added = new struct Node<Item>(item);
		added->value = item;
		added->next = added->next
			added->previous = added->previous;
	}
	else {
		Node *temp;
		temp = new struct Node<Item>();
		temp = m_head;
		Node *added;
		added = new struct Node<Item>(item);
		added - value = item;
		added->next = temp->previous;
		temp->previous = added->next;
		added->previous = m_tail->next;
		m_tail->next = added->previous;
		m_head = added;
		size1++;
	}
}

template <class Item>
void CircularDoublyLinkedList<Item>::add(Item item, int position) {
	//check if position specified is valid first
	if (position>m_size || position <1) {
		cout << "\n Out of range, please enter a number between 1 and " << m_size << endl;
	}
	if (isEmpty) {
		addHead(item);
	}
	else {
		Node *here = m_head;
		Node *temp = new struct Node<Item>();
		for (int k = 1; k < position - 1; k++)
			here->
	}
}

template <class Item>
Item CircularDoublyLinkedList<Item> ::removeHead()
{
	// PRECONDITION: list is not already empty
	Node * oldNode = m_head;
	T returnVal = m_head->value;
	m_head = m_head->next;
	if (m_head == nullptr) m_tail = nullptr;
	m_size--;
	delete oldNode;
	return returnVal;
}

template <class Item>
Item CircularDoublyLinkedList<Item> ::replace(unsigned int n, Item item)
{
	// PRECONDITION: n must be a valid current list position
	T returnValue;
	Node * here = m_head;
	for (unsigned int k = 1; k < n; k++)
		here = here->next;
	returnValue = here->value;
	here->value = item;
	return returnValue;

}

template <class Item>
Item CircularDoublyLinkedList<Item> ::remove(unsigned int n)
{
	// PRECONDITION: n must be a valid current list position
	if (n == 1) return removeHead();
	if (n == size()) return removeTail();

	Node * here = m_head;
	for (unsigned int k = 1; k < n - 1; k++)
		here = here->next;
	Node * kill = here->next;
	Item returnVal = kill->value;
	here->next = kill->next;
	delete kill;
	m_size--;
	return returnVal;
}

template <class Item>
Item CircularDoublyLinkedList<Item> ::retrieveTail() const
{
	// PRECONDITION: list is not already empty
	return m_tail->value;
}


template <class Item>
Item CircularDoublyLinkedList<Item>::retrieveHead() const
{
	// PRECONDITION: list is not already empty
	return m_head->value;
}


template <class Item>
Item CircularDoublyLinkedList<Item> ::removeTail()
{
	// PRECONDITION: list is not already empty
	if (m_head == m_tail) return removeHead();
	Item returnVal = m_tail->value;
	Node * preTail = m_head;
	while (preTail->next != m_tail)
		preTail = preTail->next;
	preTail->next = nullptr;
	delete m_tail;
	m_tail = preTail;
	m_size--;
	return returnVal;
}


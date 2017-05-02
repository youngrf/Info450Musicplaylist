#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// list Node Class
class node
{
	string songName;
	string songArtist;
	node * next;

public:
	node();
	node(string name, string artist);
	void displaysong();
	friend class linkedList;
};

node::node()
{

}

node::node(string name, string artist)
{
	next = NULL;
	songName = name;
	songArtist = artist;

}
// Linked List Class
class linkedList
{
	node *head;
	node *tail;
public:
	linkedList();
	~linkedList();
	int readList(string filename);
	int removeNode(int i);
	void addNode(node *nptr);
	void showList();
	node *findItem(int i);
	
};

// linkedList constructor
linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

linkedList::~linkedList()
{

}

void node::displaysong()
{
	cout << songName << endl;
}

int linkedList::readList(string filename)
{
	string isong, iname;
	ifstream infile(filename, ios::in);
	if (!infile)
	{
		cout << "Cannot open file.. Try again.. Goodbye!" << endl;
		return -1;
	}


	while (!infile.eof())
	{
		getline(infile, iname, '|');
		if (!iname.empty())
		{
			getline(infile, isong);

			node* newnode = new node(isong, iname);
			addNode(newnode);

			numofrecords++;
		}
	}

	infile.close();
	return 0;
}

void linkedList::addNode(node *ptr)
{
	// if list is empty
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

void linkedList::showList()
{
	node *ptr;
	ptr = head;
	char answer;
	if (ptr == NULL)
	{
		cout << "list is empty " << endl;
	
		return;
	}
}


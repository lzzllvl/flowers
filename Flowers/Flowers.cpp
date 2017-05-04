// Flowers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mazenode.h"
#include <iostream>

using namespace std;


MazeNode* generateMaze(int numNodes) {
	//pointer to start of maze data structure
	MazeNode* start = new MazeNode;
	//pointer to the most recent node
	MazeNode* next = nullptr;

	while (--numNodes) {
		MazeNode* nextLeft = new MazeNode;
		MazeNode* nextRight = new MazeNode;
		start->setLeft(nextLeft);
		start->setRight(nextRight);

		next = nextLeft;
		(start->getRight())->setCheese(true);
	}

	return start; 
}



int main()
{
	MazeNode* maze = generateMaze(2);
	
    return 0;
}


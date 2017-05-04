// Flowers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mazenode.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


MazeNode* generateMaze(int numNodes) {
	//pointer to start of maze data structure
	MazeNode* start = new MazeNode;
	//pointer to the most recent node
	MazeNode* next = start;

	while (--numNodes) {
		//Random number corresponding to sides of the Maze node
		srand(time(NULL));
		int which = rand() % 4 + 1;

		//create next node
		MazeNode* connection = new MazeNode;

		switch (which) {
			//set both forward and backward pointers for both connected nodes
			case(1):
				next->setLeft(connection);
				connection->setRight(next);
				break;
			case(2):
				next->setRight(connection);
				connection->setLeft(next);
				break;
			case(3):
				next->setUp(connection);
				connection->setDown(next);
				break;
			case(4):
				next->setDown(connection);
				connection->setUp(next);
				break;
		}
		//set next to the next node
		//TODO - check needed for existence of direction pointer existence
		next = connection;

		
	}

	return start; 
}



int main()
{
	MazeNode* maze = generateMaze(2);
	
    return 0;
}


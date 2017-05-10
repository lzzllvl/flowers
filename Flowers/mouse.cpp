#include "stdafx.h"
#include "mouse.h"

#define MAX_SIDES 4

Mouse::Mouse()
{
	moveCounter = 0;
	historyStart = historyLocation;
}

void Mouse::setLocation(MazeNode* nextLoc)
{
	location = nextLoc;
}

bool Mouse::cheeseCheck(MazeNode* current)
{
	return current->cheese();
}

bool canTurnLeft(MazeNode* current) 
{
	return current->getLeft() != nullptr;
}

bool canTurnRight(MazeNode* current) 
{
	return current->getRight() != nullptr;
}

bool canTurnUp(MazeNode* current) 
{
	return current->getUp() != nullptr;
}

bool canTurnDown(MazeNode* current) 
{
	return current->getDown() != nullptr;
}

void Mouse::makeTurn(MazeNode* current, char direction)
{
	moveCounter++;
	switch (direction) {
	case 'l':
		//setting the new mouse location to next maze node
		setLocation(current->getLeft());

		//adding move to the history linked list
		historyLocation->move = 'l';
		
		break;
	case 'r':
		setLocation(current->getRight());
		historyLocation->move = 'r';
		break;
	case 'u':
		setLocation(current->getUp());
		historyLocation->move = 'u';
		break;
	case 'd':
		setLocation(current->getDown());
		historyLocation->move = 'd';
		break;
	}
	//create next history node
	struct historyNode nextNode;
	historyLocation->next = &nextNode;
	historyLocation = historyLocation->next;
}

char Mouse::chooseDirection(MazeNode* current) {

}

void Mouse::foundCheese(MazeNode* current) {
	if (current->cheese())
	{
		historyLocation->isLast = true;
		//TODO Show End Condition
	}
	else {
		//keep running maze
	}

}

void Mouse::effeciencyAnalysisUpdate()
{
}


#include "stdafx.h"
#include "mouse.h"
#include <vector>
#include <map>
#include <time.h>

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
	incrementCounter();
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
	nextNode.prev = historyLocation;
	historyLocation = historyLocation->next;
	
}

char Mouse::chooseDirection(MazeNode* current) {

	std::vector<char> choices;

	if (canTurnDown(current)) {
		choices.push_back('d');
	}
	if (canTurnUp(current)) {
		choices.push_back('u');
	}
	if (canTurnLeft(current)) {
		choices.push_back('l');
	}
	if (canTurnRight(current)) {
		choices.push_back('r');
	}

	int length = choices.size();

	std::map<char, double> weight_map;
	
	for (int i = 0; i < length; i++) {
		switch (choices[i]) {
		case 'l':
			weight_map['l'] = w_left;
			break;
		case 'u':
			weight_map['u'] = w_up;
			break;
		case 'd':
			weight_map['d'] = w_down;
			break;
		case 'r':
			weight_map['r'] = w_right;
			break;
		default:
			break;
		}
	}
	std::map<char, double>::iterator iter = weight_map.begin();
	srand((int)time(NULL));
	int choice = (rand() % 100 + 1);
	while (iter != weight_map.end()) {
		
	}
	return 'l';
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


#include "stdafx.h"
#include "mouse.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 4

Mouse::Mouse()
{
	moveCounter = 0;
	numRuns = 0;
	running = true;


	struct historyNode begin;
	begin.isLast = false;
	begin.prev = nullptr;
	historyLocation = &begin;
	historyLocation->prev = nullptr;
	historyStart = historyLocation;

	//set inital weights to equal chances
	w_down = 0.25;
	w_up = 0.25;
	w_left = 0.25;
	w_right = 0.25;

	decreaser = 0.05;
	increaser = 0.05;

	opposites['r'] = 'l';
	opposites['l'] = 'r';
	opposites['d'] = 'u';
	opposites['u'] = 'd';
}

void Mouse::setLocation(MazeNode* nextLoc)
{
	location = nextLoc;
}

bool Mouse::cheeseCheck()
{
	return location->cheese();
}


bool Mouse::canTurnLeft(MazeNode* current) 
{
	return current->getLeft() != nullptr;
}

bool Mouse::canTurnRight(MazeNode* current) 
{
	return current->getRight() != nullptr;
}

bool Mouse::canTurnUp(MazeNode* current) 
{
	return current->getUp() != nullptr;
}

bool Mouse::canTurnDown(MazeNode* current) 
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

	//before we set the history location to the next, we analyze the weight options
	analyzeMoveWeights(historyLocation);
	historyLocation = historyLocation->next;
	
}

char Mouse::chooseDirection(MazeNode* current)
{
	//getting the choices available
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
	//map weights to chars
	std::map<char, double>::iterator iter = weight_map.begin();

	double total_prob = 0.0; 
	while (iter != weight_map.end()) {
		total_prob += iter->second;
		iter++; 
	}
	unsigned int temp = time(NULL);
	//while (temp == time(NULL)) {
		//printf("%d\n", temp);
	//}
	srand((unsigned)time(NULL));
	int choice = (rand() % (int)(total_prob * 100));
	//printf("Random Choice: %d\n", choice);
	iter = weight_map.begin();
	int range = (int)(iter->second * 100);
	do {
		if (choice <= range) {
			return iter->first;
		}
		iter++;
		range += (int) (iter->second * 100);
	} while (iter != weight_map.end());
	return 'e';
}

void Mouse::runMaze() {
	if (location->cheese())
	{
		historyLocation->isLast = true;
		//End Condition
		running = false;
		numRuns++;
		multipleMoveCounter += moveCounter;
		averageMoveCount = multipleMoveCounter / numRuns;
		printf("Run Number: %d\nTotal Moves Taken: %d\nCurrent Average Moves: %.2lf\n\n", numRuns, moveCounter, averageMoveCount);
		manageDeltas();
	}
	else {
		//keep running maze
		char direction = chooseDirection(location);
		makeTurn(location, direction);
	}
}

void Mouse::analyzeMoveWeights(historyNode* loc)
{
	//don't do anything if it is the first two moves
	if (moveCounter > 1) {
		char prevTwo = loc->prev->prev->move;
		char prevOne = loc->prev->move;
		char curr = loc->move;
		if (opposites[prevTwo] == prevOne && opposites[prevOne] == curr) {
			decreaseWeight(prevOne);
		}
		if (prevOne == curr) {
			increaseWeight(curr);
		}
	}
}

void Mouse::increaseWeight(char which) {
		double amount = increaser;
		switch (which) {
		case 'l':
			
			w_left += amount;
			break;
		case 'r':
			w_right += amount;
			break;
		case 'u':
			w_up += amount;
			break;
		case 'd':
			w_down += amount;
			break;
		}
	}

void Mouse::decreaseWeight(char which) {
	double amount = decreaser;
	switch (which) {
	case 'l':
		//don't want to go negative
		if (w_left - amount > 0.00) {
			w_left -= amount;
		}
		else {
			w_left = 0.01;
		}
		break;
	case 'r':
		if (w_right - amount > 0.00) {
			w_right -= amount;
		}
		else {
			w_right = 0.01;
		}
		break;
	case 'u':
		if (w_up - amount > 0.00) {
			w_up -= amount;
		}
		else {
			w_up = 0.01;
		}
		break;
	case 'd':
		if (w_down - amount > 0.00) {
			w_down -= amount;
		}
		else {
			w_down = 0.01;
		}
		break;
	}
}

void Mouse::manageDeltas() {
	std::vector<char> sequence;
	historyNode* here = historyStart;
	//populate vector with moves
	while (!here->isLast) {
		sequence.push_back(here->move);
		here = here->next; 
	}
	//don't change method if best performance
	if (moveCounter >= averageMoveCount) {
		int i = 1;//second move
		while (i < sequence.size()) {
			if (opposites[sequence[i]] == sequence[i - 1]) {
				decreaser += 0.01;
			}
			else {
				increaser += 0.01;
			}
		}
	}
	 
}

void Mouse::reset() {
	
	/*historyNode* liberator; 
	liberator = historyStart;
	int i = 0;
	//while (i < moveCounter) {
		//historyNode* temp = liberator->next;
		//free(liberator);
		//liberator = temp; 
		i++;
	}
	free(liberator); // last one */
	moveCounter = 0;
	struct historyNode nextStart;
	historyStart = &nextStart;
	running = true;
}

#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include "mazenode.h"
#include <map>


class Mouse {
private:
	int moveCounter;
	int multipleMoveCounter;
	int numRuns; 
	double averageMoveCount; 

	struct historyNode {
		char move;
		bool isLast = false;
		//doubly linked list
		struct historyNode* next = nullptr;
		struct historyNode* prev = nullptr;
	};

	struct historyNode* historyLocation;
	struct historyNode* historyStart;

	//weighted options for each direction
	double w_up, w_down, w_left, w_right;
	//how much to change by
	double increaser, decreaser;

	MazeNode* location;

	//map for backwards moves
	std::map<char, char> opposites;

	bool running; 
	

public:
	Mouse();

	bool isRunning() { return running; };

	void setLocation(MazeNode* nextLoc);

	void incrementCounter() { moveCounter++; };

	bool cheeseCheck();

	bool canTurnLeft(MazeNode* current);

	bool canTurnRight(MazeNode* current);

	bool canTurnUp(MazeNode* current);

	bool canTurnDown(MazeNode* current);

	void makeTurn(MazeNode* current, char direction);

	void runMaze();

	char chooseDirection(MazeNode* current);
	
	void decreaseWeight(char which);

	void increaseWeight(char which);

	void analyzeMoveWeights(historyNode* loc);

	void manageDeltas();

	void reset();

};

#endif MOUSE_H
#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include "mazenode.h"



class Mouse {
private:
	int moveCounter;
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

	MazeNode* location;
	

public:
	Mouse();

	void setLocation(MazeNode* nextLoc);

	void incrementCounter() { moveCounter++; };

	bool cheeseCheck(MazeNode* current);

	bool canTurnLeft(MazeNode* current);

	bool canTurnRight(MazeNode* current);

	bool canTurnUp(MazeNode* current);

	bool canTurnDown(MazeNode* current);

	void makeTurn(MazeNode* current, char direction);

	void foundCheese(MazeNode* current);

	char chooseDirection(MazeNode* current);

	void effeciencyAnalysisUpdate();

};





#endif MOUSE_H
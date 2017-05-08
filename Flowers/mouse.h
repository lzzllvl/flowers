#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#include "mazenode.h"



class Mouse {
private:
	int moveCounter;
	struct historyNode {
		char move;
		bool isLast;
		struct historyNode* next;
	} llhistory;
	

public:
	Mouse();

	void incrementCounter() { moveCounter++; };

	bool cheeseCheck(MazeNode* current);

	char getTurnOptions(MazeNode* current);

	void makeTurn(MazeNode* current, char direction);

	void effeciencyAnalysisUpdate();

};





#endif ALGERNON_H

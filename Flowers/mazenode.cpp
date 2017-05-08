#include "stdafx.h"
#include "mazenode.h"


//constructor functions
MazeNode::MazeNode() {
	left = nullptr;
	right = nullptr;
	up = nullptr;
	down = nullptr;
}

//boolean argument constructor overload
MazeNode::MazeNode(bool cheese) {
	left = nullptr;
	right = nullptr;
	up = nullptr;
	down = nullptr;
	hasCheese = cheese;
}


//function definitions for the mazeNodes
void MazeNode::setLeft(MazeNode* nextNode)
{
	left = nextNode;
}

void MazeNode::setRight(MazeNode* nextNode)
{
	right = nextNode;
}

void MazeNode::setUp(MazeNode* nextNode)
{
	up = nextNode;
}

void MazeNode::setDown(MazeNode* nextNode)
{
	down = nextNode;
}


//consider making these inline functions in mazenode.h
MazeNode* MazeNode::getLeft() const
{
	return left;
}

MazeNode* MazeNode::getRight() const
{
	return right;
}
MazeNode* MazeNode::getUp() const
{
	return up;
}
MazeNode* MazeNode::getDown() const
{
	return down;
}
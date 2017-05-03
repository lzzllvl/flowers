#include "stdafx.h"
#include "mazenode.h"


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
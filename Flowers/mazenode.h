#pragma once
#ifndef MAZENODE_H
#define MAZENODE_H

//maze node declaration

class MazeNode {
	private:
		//four sides simulates a rectangular maze
		MazeNode* left;
		MazeNode* right;
		MazeNode* up;
		MazeNode* down;
		bool hasCheese = false;


	public:
		//constructors
		MazeNode();
		MazeNode(bool cheese);

		//setters
		void setLeft(MazeNode* nextNode);
		void setRight(MazeNode* nextNode);
		void setUp(MazeNode* nextNode);
		void setDown(MazeNode* nextNode);
		void setCheese(bool b) { hasCheese = b; }

		//getters
		MazeNode* getLeft() const;
		MazeNode* getRight() const;
		MazeNode* getUp() const;
		MazeNode* getDown() const;
		bool cheese() const { return hasCheese; }

};

#endif

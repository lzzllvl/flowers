#pragma once
#ifndef MAZENODE_H
#define MAZENODE_H

//maze node declaration

class MazeNode {
	private:
		//four sides simulates a rectangular maze
		MazeNode* left = nullptr;
		MazeNode* right = nullptr;
		MazeNode* up = nullptr;
		MazeNode* down = nullptr;
		bool hasCheese;
	public: 
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

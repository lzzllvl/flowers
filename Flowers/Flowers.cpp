// Flowers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mazenode.h"
#include "mouse.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


MazeNode* generateMaze(int numNodes) {
	//pointer to start of maze data structure
	MazeNode* start = new MazeNode;
	//pointer to the most recent node
	MazeNode* next = start;

	while (--numNodes) {
		//create next node
		MazeNode* connection;
		if(numNodes == 0){
			//set the cheese for the last node 
			connection = new MazeNode(true);
		}
		else {
			connection = new MazeNode;
		}

		//Random number corresponding to sides of the Maze node
		srand((int) time(NULL));
		int which = rand() % 4 + 1;

		switch (which) {
			//set both forward and backward pointers for both connected nodes
			case(1):
				next->setLeft(connection);
				connection->setRight(next);
				break;
			case(2):
				next->setRight(connection);
				connection->setLeft(next);
				break;
			case(3):
				next->setUp(connection);
				connection->setDown(next);
				break;
			case(4):
				next->setDown(connection);
				connection->setUp(next);
				break;
		}
		//set next to the next node
		
		next = connection;
		
	}

	return start; 
}






int main()
{
	//generate maze nodes
	MazeNode* a = new MazeNode;
	MazeNode* b = new MazeNode;
	MazeNode* c = new MazeNode;
	MazeNode* d = new MazeNode;
	MazeNode* e = new MazeNode;
	MazeNode* f = new MazeNode;
	MazeNode* g = new MazeNode;
	MazeNode* h = new MazeNode;
	MazeNode* i = new MazeNode;
	MazeNode* j = new MazeNode;
	MazeNode* k = new MazeNode;
	MazeNode* l = new MazeNode;
	MazeNode* m = new MazeNode;
	MazeNode* n = new MazeNode;
	MazeNode* o = new MazeNode;
	MazeNode* p = new MazeNode;
	MazeNode* q = new MazeNode(true);
	MazeNode* r = new MazeNode;
	MazeNode* s = new MazeNode;
	MazeNode* t = new MazeNode;
	MazeNode* u = new MazeNode;
	MazeNode* v = new MazeNode;
	MazeNode* w = new MazeNode;
	MazeNode* x = new MazeNode;

	//connect them
	a->setRight(b);
	b->setLeft(a);
	b->setDown(h);
	b->setRight(c);
	c->setLeft(b);
	c->setDown(i);
	d->setDown(j);
	d->setRight(e);
	e->setLeft(d);
	e->setRight(f);
	f->setLeft(e);
	g->setDown(m);
	g->setRight(h);
	h->setLeft(g);
	h->setUp(b);
	i->setUp(c);
	i->setRight(j);
	i->setDown(o);
	j->setUp(d);
	j->setDown(p);
	j->setLeft(i);
	j->setRight(k);
	k->setLeft(j);
	k->setRight(l);
	l->setLeft(k);
	l->setDown(r);
	m->setUp(g);
	m->setRight(n);
	m->setDown(s);
	n->setLeft(m);
	n->setDown(t);
	n->setRight(o);
	o->setUp(i);
	o->setLeft(n);
	p->setDown(v);
	p->setUp(j);
	q->setRight(r);
	r->setUp(l);
	r->setDown(x);
	r->setLeft(q);
	s->setUp(m);
	s->setRight(t);
	t->setLeft(s);
	t->setRight(u);
	t->setUp(n);
	u->setRight(v);
	u->setLeft(t);
	v->setLeft(u);
	v->setUp(p);
	w->setRight(x);
	x->setLeft(w);
	x->setUp(r);

	

	for (int i = 0; i < 10; i++) {
		Mouse* algernon = new Mouse;
		algernon->setLocation(a);
		while (algernon->isRunning()) {
			algernon->runMaze();
		}
		//reset mouse and place at start of maze
		delete algernon;
	//	Sleep(5000);
	}
    return 0;
}


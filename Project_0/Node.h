/*
 * Node.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Dennis Moyseyev
 */



#ifndef NODE_H_
#define NODE_H_
#include <list>

using namespace std;

class Node {

public:
	Node();
	list <int> values;
	Node *left;
	Node *right;



	virtual ~Node();
};

#endif /* NODE_H_ */

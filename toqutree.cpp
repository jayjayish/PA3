
/**
 *
 * toqutree (pa3)
 * significant modification of a quadtree .
 * toqutree.cpp
 * This file will be used for grading.
 *
 */

#include "toqutree.h"

toqutree::Node::Node(pair<int,int> ctr, int dim, HSLAPixel a)
	:center(ctr),dimension(dim),avg(a),NW(NULL),NE(NULL),SE(NULL),SW(NULL)
	{}

toqutree::~toqutree(){
	clear(root);
}

toqutree::toqutree(const toqutree & other) {
	root = copy(other.root);
}


toqutree & toqutree::operator=(const toqutree & rhs){
	if (this != &rhs) {
		clear(root);
		root = copy(rhs.root);
	}
	return *this;
}

toqutree::toqutree(PNG & imIn, int k){ 

/* This constructor grabs the 2^k x 2^k sub-image centered */
/* in imIn and uses it to build a quadtree. It may assume  */
/* that imIn is large enough to contain an image of that size. */

/* your code here */
}

int toqutree::size() {
	return size(root);
}

int toqutree::size(const Node * node) {
	if (node != NULL){
		return 1 + size(node->NW) + size(node->NE) + size(node->SE) + size(node->SW);
	}
	else{
		return 0;
	}
}

toqutree::Node * toqutree::buildTree(PNG * im, int k) {

/* your code here */

// Note that you will want to practice careful memory use
// In this function. We pass the dynamically allocated image
// via pointer so that it may be released after it is used .
// similarly, at each level of the tree you will want to 
// declare a dynamically allocated stats object, and free it
// once you've used it to choose a split point, and calculate
// an average.

}

PNG toqutree::render(){

// My algorithm for this problem included a helper function
// that was analogous to Find in a BST, but it navigated the 
// quadtree, instead.

/* your code here */

}

/* oops, i left the implementation of this one in the file! */
void toqutree::prune(double tol){

	prune(root,tol);

}

void toqutree::prune(Node* node, double tol){

}

/* called by destructor and assignment operator*/
void toqutree::clear(Node * & curr){
	clear(curr->NW);
	clear(curr->NE);
	clear(curr->SE);
	clear(curr->SW);
	delete(curr);
}

void toqutree::clear(Node * curr){
	if(curr != NULL){
		clear(curr->NW);
		clear(curr->NE);
		clear(curr->SE);
		clear(curr->SW);
		delete(curr);
	}
	else{
		return;
	}
}

/* done */
/* called by assignment operator and copy constructor */
toqutree::Node * toqutree::copy(const Node * other) {
	if (other != NULL){
		Node *node = new Node(other->center, other->dimension, other->avg);
		node->NW = copy(other->NW);
        node->NE = copy(other->NE);
        node->SE = copy(other->SE);
        node->SW = copy(other->SW);

        return node; 
	}
	else {
		return NULL;
	}

}




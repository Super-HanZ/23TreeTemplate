#include <iostream>

template <class Type>
class twoThree {
	
	class Split;//forward declare split class for use by node class

	//Enumeration type
	//Little too on the nose, probably change later
	//too many things with left and right in their name
	enum WHERE_FROM{ FROM_LEFT, FROM_MIDDLE, FROM_RIGHT };
	
	//Node structure carries two data pointers
	//Three pointers left right and middle
	//Used as nodes (duh)

	//---------- Some notes about how it is organized ----------------
	// @ Private data will only be accessed thorugh function

	// @LOWER value is on the left, if there is only one data item it 
	// will be on the left 
	class Node {
		
		public:	
			Node();//Default constructor sets all data members to null
			Node(Type *);//Constructor that takes pointer to Type			
			
			//functions return left, right, and middle pointers	
			Node*& moveLeft();
			Node*& moveMiddle();
			Node*& moveRight();
			
			//Return the values		
			Type * leftValue();
			Type * rightValue();
	
			//sorts the data
			void sort();
			
			//checks if the node is empty
			bool empty();

			//Add Function
			//returns a split object
			Split* add(Type *);

			//Is leaf function determines if it is 
			//A leaf
			bool leaf();

			//insert nessasary functions here
		private:
			//data pointers left and right data
			Type * leftData;
			Type * rightData;

			//Next pointers left, middle, and right
			Node * left;
			Node * middle;
			Node * right;
			
	};
	
	//When inserting in a Two Three Tree nodes must be split
	//When this happens three data items should be pushed up
	//two newly created nodes storing the left and right as well
	//as the middle value(but not as a node or part of a sub tree)
	// this class may help, may be removed later
	struct Split 
	{
			Split(Node *, Type *);	

			//left and right nodes and or sub trees
			Node * leftNode;

			Node * rightNode;
			
			Type * data;//The pushed value
					
	};

	
	public:
		twoThree();
	



	private:
		Node * head;//head pointer



		

};

//--------------------------------------- N O D E  C L A S S  M E M B E R  F U N C T I O N S -----------------------------------

//Node default constructor intalize all pointer to NULL
template <class Type>
twoThree<Type>::Node::Node() : leftData(NULL), rightData(NULL), left(NULL), middle(NULL), right(NULL) {}

//Constructor that takes pointer to a TYPE
template <class Type>
twoThree<Type>::Node::Node(Type * to_add) : leftData(to_add), rightData(NULL), left(NULL), middle(NULL), right(NULL) {}

//Three Move functions return left, middle, and right pointers
template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveRight() { return right; }

template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveMiddle() { return middle; }

template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveLeft() { return left; }

//return the data values
template <class Type>
Type * twoThree<Type>::Node::leftValue() { return leftData; }

template <class Type>
Type * twoThree<Type>::Node::rightValue() { return rightData; }

//function to determine if node is leaf
bool twoThree<Type>::Node::leaf() 
{
	//if all three pointers are NULL
	if(!left)
		return true;
	else
		return false;
}

//Sort function is basic (possibly too runtime heavy will examine use later)
//Checks to see if one-two data items are in-order
template <class Type>
void twoThree<Type>::Node::sort() 
{
	//If only one data item--and its on the left return
	if(leftData && !rightData) return;
	
	//check if it is empty just in case	
	if(empty()) return;	
	
	//If it isnt empty and left data is null
	//rightdata exisits so switch	
	if(!leftData) {

		leftData = rightData;
		rightData = NULL;
		return;
	}
	
	//if left data has a greater value than right
	//switch
	if((*leftData) > (*rightData))
	{
		Type * temp = leftData;
		leftData = rightData;
		rightData = temp;
		return;
	}

}

//Checks if node has no data items
//should not happen outside of a few functions
template <class Type>
bool twoThree<Type>::Node::empty() 
{
	//if both are NULL return true	
	if(!leftData && !rightData)
		return true;	
	else
		return false;//otherwise return false
}

//Insert data member into a node
//Will return NULL value if successfuly added
//otherwise it will return a "Split" pointer
template <class Type>
typename twoThree<Type>::Split* twoThree<Type>::Node::add(Type * to_add)
{
	//if left is empty add to left
	//Should'nt happen but just to make sure
	if(!left) {

		left = to_add;
		sort();
		return NULL;//return NULL
	}
		
	//If right is empty
	else if(!right) {
	
		right = to_add;
		sort();
		return NULL;//retun NULL
	}
	//otherwise it must be split//But what if this Isnt a leaf
	else if {
		Split * toReturn;

		return toReturn = new Split(this, to_add);
	}

}

//=================================================Split Structure===========================================================

//Split Constructor
//Determines middle value
template <class Type>
twoThree<Type>::Split::Split(Node * aNode, Type * toInsert) : data(toInsert)
{
	//If the left vale is greater than toInsert
	//Then left is middle
	if( *aNode.leftValue() > *toInsert) {
		
		leftNode = new Node(toInsert);	
		rightNode = new Node(aNode.rightValue());
		
		data = *aNode.leftValue();//set middle to left
		
		return;
	}
	//than to toInsert is the right value and 
	if(*aNode.rightValue() < *toInsert) {
		
		rightNode = new Node(toInsert);
		leftNode = new Node(aNode.leftValue());	

		data = aNode;	
		return;
	}	
	
	//otherwise toInsert is the middle value
	leftNode = new Node(aNode.leftValue());
	rightNode = new Node(aNode.rightValue());	
	
	data = toInsert;

	return;
}




//============================================= TWO THREE TREE CLASS MEMBER FUNCTION ========================================

//Default construtor
//intalize head to NULL
template <class Type>
twoThree<Type>::twoThree() : head(NULL) {}



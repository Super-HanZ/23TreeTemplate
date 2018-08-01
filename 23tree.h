#include <iostream>

template <class Type>
class twoThree {
	
	class Split;//forward declare split class for use by node class

	
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
			
			//functions return left, right, and middle pointers	
			Node*& moveLeft();
			Node*& moveMiddle();
			Node*& moveRight();
			
			//sorts the data
			void sort();
			
			//checks if the node is empty
			bool empty();
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
	class Split 
	{
		
		private:	

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

//Three Move functions return left, middle, and right pointers
template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveRight() { return right; }

template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveMiddle() { return middle; }

template <class Type>
typename twoThree<Type>::Node*& twoThree<Type>::Node::moveLeft() { return left; }

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

template <class Type>
bool twoThree<Type>::Node::empty() 
{
	//if both are NULL return true	
	if(!leftData && !rightData)
		return true;	
	else
		return false;//otherwise return false
}


//============================================= TWO THREE TREE CLASS MEMBER FUNCTION ========================================

//Default construtor
//intalize head to NULL
template <class Type>
twoThree<Type>::twoThree() : head(NULL) {}



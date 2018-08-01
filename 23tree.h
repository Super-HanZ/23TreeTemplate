#include <iostream>

template <class Type>
class twoThree {
	
	class Split;//forward declare split class for use by node class

	
	//Node structure carries two data pointers
	//Three pointers left right and middle
	//Used as nodes (duh)
	class Node {
		
		public:	
			Node();//Default constructor sets all data members to null

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
	//as the middle value, this class may help, althought it may be removed later
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








//============================================= TWO THREE TREE CLASS MEMBER FUNCTION ========================================

//Default construtor
//intalize head to NULL
template <class Type>
twoThree<Type>::twoThree() : head(NULL) {}



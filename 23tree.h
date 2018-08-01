template <class Type>
class twoThree {

	//Node structure carries two data pointers
	//Three pointers left right and middle
	class Node {
		
		public:	


		private:
		//data pointers left and right data
		Type * leftData;
		Type * rightData;

		//Next pointers left, middle, and right
		Node * left;
		Node * middle;
		Node * right;
		
		//insert nessasary functions for nodes	
		//----	
	};	

	
	public:
		twoThree();

	



	private:
		Node * head;//head pointer ==== DUH



		

};

//Default construtor
//intalize head to NULL
template <class Type>
twoThree<Type>::twoThree() : head(NULL) {}



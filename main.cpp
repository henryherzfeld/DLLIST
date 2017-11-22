/* Henry Herzfeld COP 3530
 * 12/3/17 11:59pm
 */

#include <iostream>
using namespace std;


class TNode
{
public:
    int val;
    TNode* left;
    TNode* right;
    TNode* parent;

    TNode() //default constructor
    {
        val = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    explicit TNode(int v) //int parameter constructor
    {
        val = v;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};


class minHeap // binary heap
{
    int size;
    TNode *top;

public:
    //== HELPER FUNCTIONS ==//
    TNode* getTop();
    void setTop(TNode* t);
    int getSize();
    void setSize(int n);
	bool isLeaf(const TNode* t);
	bool isTop(const TNode* t);
    TNode* copyHelper(TNode *h);      //does all copy logic, copy constructor calls this if h != NULL
    void bubbleUp(TNode* t);
    void bubbleDown(TNode* t);

    //=== HEAP FUNCTIONS ===//
    void in(const TNode &t);// you should new a new node and then add into the heap
    void removemin();
    TNode* getmin();
    void Heapify(const int n, const int *p);// p is an array of size n, representing a (full) binary tree of size n-1. (The tree starts at location 1). You should not modify the array p.

	
    //===========================================//
    //=============== CONSTRUCTORS ==============//
    //===========================================//
    minHeap() //default constructor
    {
        size = 0;
        top = NULL;
    }

    minHeap(const minHeap &h) //copy constructor
    {
        if(h.size == 0)//case for empty heap
        {
            size = 0;
            top = NULL;
        }
        else
        {
            top = copyHelper(h.top);
        }
    }
};


//===========================================//
//================ DEFINITIONS ==============//
//===========================================//

//============ HELPER FUNCTIONS =============//
TNode* minHeap::getTop()
{
    return top;
}

void minHeap::setTop(TNode* t)
{
    if(size == 0)
    {
        size++;
    }
    top = t;
}

int minHeap::getSize()
{
    return size;
}

void minHeap::setSize(int n)
{
    size = n;
}

bool ::minHeap::isLeaf(const TNode* t)
{
	if(!(t->left || t->right)) //if both children are null
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ::minHeap::isTop(const TNode* t)
{
	if(!t->parent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

TNode* minHeap::copyHelper(TNode *h)   //does all copy logic, copy constructor calls this if h != NULL
{
    TNode *ret = new TNode;
    ret->val = h->val;              //assigning val and
    ret->parent = h->parent;        //parent to each input TNode
	
	if(isLeaf(h))
	{
	
	}
	
	if(h->left != NULL) {                   //if left child isn't null
		ret->left = copyHelper(h->left);
	}
	else
	{
		ret->left = NULL;
	}
	
	if(h->right != NULL)
	{
		ret->right = copyHelper(h->right);
	}
	else
	{
		ret->right = NULL;
	}
    return ret;
}

void minHeap::bubbleUp(TNode* t) //takes in TNode and bubbles up until either top or smaller node and returns it
{
    if(!isTop(t)) //avoiding referencing null parent pointer
    {
	    if(t->val < t->parent->val) //testing input node val against parent val
	    {
		    int temp = t->parent->val;     //swapping node values using temp int
		    t->parent->val = t->val;
		    t->val = temp;
		
		    bubbleUp(t->parent);            //recursive call to move up
	    }
    }
}

void minHeap::bubbleDown(TNode* t)
{
    if(t->left != NULL || t->right != NULL && t->val < t->parent->val) //checking to
    {
        bubbleUp(t->parent);
    }
}

//============== HEAP FUNCTIONS ==============//
void minHeap::in(const TNode &t)
{
    TNode* in = new TNode;
    in->val = t.val;
    
    
}
    
void minHeap::removemin()
{

}

TNode* minHeap::getmin()
{

}
    
    void Heapify(const int n, const int *p) // p is an array of size n, representing a (full) binary tree of size n-1. (The tree starts at location 1). You should not modify the array p.
    {
    
    }
    
//============ EXTERNAL FUNCTIONS ============//
int * HeapSort(const int n, const int *arr)// arr is an integer array of numbers. You should output a pointer to a new array which is a sorted version of arr
{

}

void Test()
{

}

int main(int argc, const char * argv[])
{
    //CONSTRUCTORS
    cout << "//====== CONSTRUCTORS: ======//" << endl;
    minHeap ConHeap1;
	TNode* ConNode1 = new TNode;
    
    ConNode1->val = 10;
	
    ConHeap1.setTop(ConNode1); //default
    cout << "1: " << ConHeap1.getTop()->val << endl; //copy
    minHeap ConHeap2(ConHeap1); //copy
    cout << "2: " << ConHeap2.getTop()->val << endl; //copy

    //BUBBLE UP/DOWN
    cout << endl << "//====== BUBBLE UP/DOWN: ======//" << endl;
	TNode* BubNode1 = new TNode;
    TNode* BubNode2 = new TNode;
    TNode* BubNode3 = new TNode;
    TNode* BubNode4 = new TNode;
    minHeap BubHeap1;
    
    BubNode1->val = 5;
    BubNode2->val = 12;
    BubNode3->val = 20;
    BubNode4->val = 25;
    
    BubHeap1.setTop(BubNode3);  //setting up test heap
    BubHeap1.getTop()->left = BubNode1;
    BubNode1->parent = BubNode2;
    BubNode2->parent = BubNode3;
    BubHeap1.setSize(BubHeap1.getSize()+2);
    
    cout << BubHeap1.getTop()->val << endl;
    BubHeap1.bubbleUp(BubNode1);
    cout << BubHeap1.getTop()->val << endl;
    
    
    
    
    return 0;
}
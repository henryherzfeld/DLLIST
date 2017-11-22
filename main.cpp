#include <iostream>
using namespace std;

class Item
{
public:
    int val;
    Item *next, *prev;
    Item()        //default constructor
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    Item(int val)   //copy constructor
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }

};

class DLinkedList
{
    int size;
    Item *front;
    Item *back;

public:
    DLinkedList() //default constructor
    {
      size = 0;
      front = NULL;
      back = NULL;
    }

    DLinkedList(const DLinkedList &list) //copy constructor
    {
      if (list.front == NULL) //conditional for an empty list
      {
          this->front = NULL;
          this->back = NULL;
      }

      else
      {
          //defining items for loop
          Item* current = new Item;
          Item* objFront = new Item;
          Item* currentObj = new Item;

          current = this->front; //current points to current object's front, and is used to move through current obj
          objFront = list.front; //objFront points to list's front (other obj)
          currentObj = objFront; //currentObj points to list's front and is used to move through list obj
    
          while (currentObj->next != NULL) //moving through list obj
          {
              current->next->val = currentObj->next->val; //assigning value of list obj to current obj
              currentObj = currentObj->next; //moving through list obj
              current->next->prev = current; //making sure current obj's prev item points to next item
              current = current->next;       //moving through current obj
          }

          this->back = current; //reassigning back of current obj to current (which points to last item post-loop)
      }
    }

    Item* getFront()
    {
      return front;
    }

    Item* getBack()
    {
      return back;
    }

    int getSize()
    {
      return size;
    }

    void push_back(Item *a)
    {
        if (this->size == 0)
        {
          this->front = a;
          this->back = a;
        }
        else
        {
          this->back->next = a;
          a->prev = this->back;
          this->back = a;
        }
      this->size += 1;
    }

    void push_front(Item *a)
    {
      if (this->size == 0)
      {
        this->front = a;
        this->back = a;
      }
      else
      {
        a->next = this->front;
        this->front->prev = a;
        this->front = a;
      }
      this->size += 1;
    }

    Item* pop_front()
    {
      Item* temp = new Item;
      temp = this->front;
      if(this->size == 0)
      {
        cout << "The list is empty." << endl;
      }
      else if(this->size == 1)
      {
        this->front = NULL;
        this->back = NULL;
      }
      else
      {
        this->front = this->front->next;
        this->front->prev = NULL;
      }
      this->size -= 1;
    }

    Item* pop_back()
    {
      if(this->size == 0)
      {
        cout << "The list is empty." << endl;
      }
      else if(this->size == 1)
      {
        this->front = NULL;
        this->back = NULL;
      }
      else
      {
        this->back = this->back->prev;
        this->back->next = NULL;
      }
      this->size -= 1;
    }

    void insert(Item *a, int t)
    {
      if(t == 0)
      {
        push_front(a);
      }
      else if(t < 0)
      {
        cout << "Invalid input." << endl;
      }
      else if(t == size)
      {
        push_back(a);
      }
      else
      {
        Item * temp = new Item;
        temp = this->front;
        while(temp->next != NULL && t > 0)
        {
          temp = temp->next;
          t--;
        }
        a->next = temp;
        a->prev = temp->prev;
        temp->prev->next = a;
        temp->prev = a;



        this->size + 1;
      }
    }

    void insertlist(DLinkedList &list, int t)
    {
      if(list.front = NULL)
      {
        cout << "Whoops! The list you're trying to append is empty..." << endl;
      }
      else
      {
        if(t == 0)
        {
          list.back->next = this->front;
          this->front->prev = list.back;
          this->front = list.front;
        }
        else if(t < 0)
        {
          cout << "Invalid input." << endl;
        }
        else if(t == this->size)
        {
          this->back->next = list.front;
          list.front->prev = this->back;
          this->back = list.back;
        }
        else
        {
          Item* temp = new Item;
          temp = this->front;
          while(temp->next != NULL && t > 0)
          {
            temp = temp->next;
            t --;
          }
          list.back->next = temp;
          list.front->prev = temp->prev;
          temp->prev = list.back;
          temp->prev->next = list.front;

          list.back->next->prev = list.back;
        }
      }
      this->size = this->size + list.size;
    }

    void display(ostream &out)
    {
      if(this->front == NULL)
      {
        out << "Empty List." << endl;
      }
      else
      {
        Item *temp;
        temp = this->front;
        while(temp != NULL)
        {
          out << temp->val << "::";
          temp = temp->next;
        }
        cout << endl;
      }
    }

    void swap(Item *p, Item *q)
    {
      int temp;
      temp = p->val;
      p->val = q->val;
      q->val = temp;
    }

    Item* extractmin(Item *a)
    {
      if(a->next == NULL)
      {
        return a;
      }
      else
      {
        Item * min = new Item;
        min = a;
        while(a != NULL)
        {
          a = a->next;
          if(a->val < min->val)
          {
            min = a;
          }
        }
        return min;
      }
    }

    Item* extractmax(Item *a)
    {
      if(a->next == NULL)
      {
        return a;
      }
      else
      {
        Item * max = new Item;
        max = a;
        while(a != NULL)
        {
          a = a->next;
          if(a->val > max->val)
          {
            max = a;
          }
        }
        return max;
      }
    }

};

class myStack
{
    DLinkedList list;
public:
    myStack();
    int getSize()
    {
      return list.getSize();
    }
    void in(Item *a)
    {
      list.push_back(a);
    }
    Item *top()
    {
      return list.getBack();
    }
    void out()
    {
      Item * poppedEl = new Item;
      poppedEl = list.pop_back();
      cout << "Popped element is: " << poppedEl->val;
    }

};

class myQueue
{
    DLinkedList list;
public:
    myQueue();
    int getSize()
    {
      return list.getSize();
    }
    void in(Item *a)
    {
      list.push_front(a);
    }
    Item *front()
    {
      return list.getFront();
    }
    void out()
    {
      Item * poppedEl = new Item;
      poppedEl = list.pop_back();
      cout << "Popped element is: " << poppedEl->val;
    }
};






  int main() {

    DLinkedList list;

    DLinkedList list2;

    Item *D = new Item;
    D->val = 10;

    Item *P = new Item;
    P->val = 9;

    Item *Q = new Item;
    Q->val = 8;

    Item *G = new Item;
    G->val = 7;

    Item *F = new Item;
    F->val = 6;

    Item *S = new Item;
    S->val = 55;


  list.push_front(D);
  list.push_front(P);
  list.push_back(Q);

  list.display(cout); //pdq

  list.pop_back();
  list.display(cout);
  list.swap(P, D);
  list.display(cout);
  list.pop_front();
  list.display(cout);

  list2.push_front(G);
  list2.push_front(F);

  int q = list.getSize();
  cout << "list1 size: " << q << endl;

  int t = list2.getSize();
  cout << "list2 size: " << t << endl;
  list2.insert(S, 1);

  list.display(cout);
  list2.display(cout);

  Item *max = new Item;
  max = list.extractmax(D);

  cout << max->val << endl;

  Item *min = new Item;
  min = list2.extractmin(G);

  cout << min->val << endl;

  list2.display(cout);

  return 0;
 }

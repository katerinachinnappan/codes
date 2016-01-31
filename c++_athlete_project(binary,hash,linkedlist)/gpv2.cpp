#include <string>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <vector>
#include "math.h"
#include <fstream>
#include <cstdlib>
#include <istream>
#include <sstream>
using namespace std;

class Athlete
{
    public:
        string name;
        string age;
        string country;
        string year;
        int numSearch;
    public:
        Athlete()
        {
            name = age = country = year = "";
            numSearch = 0;
        }
        Athlete(string n, string a, string c, string y, int num = 0)
        {
            name = n;
            age = a;
            country = c;
            year = y;
            numSearch = num;
        }
     // setters -- sets the data
        void setName(string n)	        {name = n;}
        void setAge(string a)	        {age = a;}
        void setCountry(string c)		{country = c;}
        void setYear(string y)		    {year = y;}

        void updateSearch ()			{numSearch++;}	// Increments the search function

        // Getters -- returns the data
        string getName() const	    {return name;}
        string getAge() const		{return age;}
        string getCountry() const	{return country;}
        string getYear() const		{return year;}

        int getNumSearch () const	{return numSearch;}	// Gets the number searched

        //Overload Operators
        bool operator > (const Athlete &obj) const;
        bool operator < (const Athlete &obj) const;
        bool operator == (const Athlete &obj) const;

        void printKey() {cout <<left<<getName()<<endl;}	// Prints out the key (name of the athlete)
        void printLayout() {cout << left << getName() << "," <<getAge()<<","<<getCountry()<<","<<getYear()<<endl;}
        void printAll() {cout << "Name: " << getName() << endl << "Age: " << getAge() << endl
        << "Country: " << getCountry() << endl << "Year: " << getYear() << endl << "Searching times: " <<
        getNumSearch() << endl;}
        // prints out everything
};

bool Athlete::operator > (const Athlete &obj) const
{
    int holdSize1 = static_cast<int>(name.size());
    int holdSize2 = static_cast<int>(obj.name.size());
    int holdSize = holdSize1;

    if (holdSize1 < holdSize2)
    {
        holdSize = holdSize2;
    }

    string name1 = name;
    string name2 = obj.name;

    for (int i = 0; i < holdSize; i++)
    {
        if (i < holdSize1)
            name1[i] = tolower(name1[i]);
        if (i < holdSize2)
            name2[i] = tolower(name2[i]);
    }

    if (name1 > name2)
        return true;
    else
        return false;
}

bool Athlete::operator < (const Athlete &obj) const
{
    int holdSize1 = static_cast<int>(name.size());
    int holdSize2 = static_cast<int>(obj.name.size());
    int holdSize = holdSize1;

    if (holdSize1 < holdSize2)
    {
        holdSize = holdSize2;
    }

    string name1 = name;
    string name2 = obj.name;

    for (int i = 0; i < holdSize; i++)
    {
        if (i < holdSize1)
            name1[i] = tolower(name1[i]);
        if (i < holdSize2)
            name2[i] = tolower(name2[i]);
    }

    if (name1 < name2)
        return true;
    else
        return false;
}

bool Athlete::operator == (const Athlete&obj) const
{
    int holdSize1 = static_cast<int>(name.size());
    int holdSize2 = static_cast<int>(obj.name.size());
    int holdSize = holdSize1;

    if (holdSize1 < holdSize2)
    {
        holdSize = holdSize2;
    }

    string name1 = name;
    string name2 = obj.name;

    for (int i = 0; i < holdSize; i++)
    {
        if (i < holdSize1)
            name1[i] = tolower(name1[i]);
        if (i < holdSize2)
            name2[i] = tolower(name2[i]);
    }

    if (name1 == name2)
        return true;
    else
        return false;
}

// Node class
template<class AthleteType>
class Node
{
private:
    AthleteType        item;
    Node<AthleteType>* next;

public:
	Node()										    {next = 0;}
	Node(const AthleteType& anItem)				    {item = anItem; next = 0; }
	void setItem(const AthleteType& anItem)		    {item = anItem;}
	void setNext(Node<AthleteType>* nextNodePtr)	{next = nextNodePtr;}
	AthleteType getItem() const					    {return item;}
	Node<AthleteType>* getNext() const				{return next;}
};


template <class T>
class LinkedList
{
protected:

	Node<T> *headPtr;   // List head pointer
	int itemCount;

public:
	LinkedList() { headPtr = NULL; itemCount = 0; }
    ~LinkedList()
    {
        Node<T> *nodePtr = headPtr;
        while (nodePtr != 0)
        {
            headPtr = headPtr->getNext();
            delete nodePtr;
            nodePtr = headPtr;
        }
    }

	// Linked list functions
	void insertNode(T); // inserts node
	bool deleteNode(T); // deleted node
	void displayList(void visit (T)) const;
};

template <class T>
void LinkedList<T>::displayList (void visit (T)) const
{
	Node<T> *nodePtr = headPtr;
	while (nodePtr != 0)
	{
		visit (nodePtr->getItem());
		nodePtr = nodePtr->getNext();
	}
    cout << endl;
}

template <class T>
void LinkedList<T>::insertNode(T nodePtr)
{
	Node<T> *newNode;
	Node<T> *previousLocation;
	Node<T> *previousPtr = NULL;

	newNode = new Node<T>(); // create new node
	newNode->data = nodePtr;
	newNode->next = 0;

	if (headPtr == 0)
	{
        headPtr = newNode;
    }
	else
	{

		previousLocation = headPtr;
		previousPtr = 0;

		while (previousLocation != 0 && previousLocation->data < nodePtr)
		{
			previousPtr = previousLocation;
			previousLocation = previousLocation->next;
		}

		if (previousPtr == 0)
        {
            headPtr = newNode;
			newNode->next = previousLocation;
        }

        else
		{
			previousPtr->next = newNode;
			newNode->next = previousLocation;
		}
	}
	itemCount++; // increment the count
}

template <class T>
bool LinkedList<T>::deleteNode(T nodePtr)
{
	Node<T> *previousLocation;
	Node<T> *previousNodePtr;

	if (!headPtr)
		return false;


    previousLocation = headPtr;
	previousNodePtr = 0;
	while (previousLocation != 0 && previousLocation->data < nodePtr)
    {
        previousNodePtr = previousLocation;
        previousLocation = previousLocation->next;
	}

    if (previousLocation != 0 && previousLocation->data == nodePtr)
    {
		itemCount--;
 		if (previousNodePtr)
			previousNodePtr->next = previousLocation->next;
		else
			headPtr = previousLocation->next;
        delete previousLocation;
		return true;
    }
	return false;
}

template<class AthleteType>
class List : public LinkedList<AthleteType>  // inherited from LinkedList class
{
    private:
        Node<AthleteType>* getNodeAt(int position) const;
    public:
        bool insert(const AthleteType &, int newPosition = 1);
        bool remove(int position);
        bool getEntry(int position, AthleteType &) const;
};


template<class AthleteType>
bool List<AthleteType>::insert(const AthleteType& entry, int newPosition)
{
    if (newPosition < 1 || newPosition > List::itemCount + 1)
        return false;

    Node<AthleteType>* newNodePtr = new Node<AthleteType>(entry);
    if (newPosition == 1)
    {
        newNodePtr->setNext(List::headPtr);
        List::headPtr = newNodePtr;
    }
    else
    {
        Node<AthleteType>* prevPtr = getNodeAt(newPosition - 1);
        newNodePtr->setNext(prevPtr->getNext());
        prevPtr->setNext(newNodePtr);
    }
    List::itemCount++;
    return true;
}

template<class AthleteType>
bool List<AthleteType>::remove(int position)
{
    if (position < 1 || position > List::itemCount)
        return false;

    Node<AthleteType>* deletePtr = 0;
    if (position == 1)
    {
        deletePtr = List::headPtr;
        List::headPtr = List::headPtr->getNext();
    }
    else
    {
        Node<AthleteType>* prevPtr = getNodeAt(position - 1);
        deletePtr = prevPtr->getNext();
        prevPtr->setNext(deletePtr->getNext());
    }
    delete deletePtr;
    List::itemCount--;
    return true;
}

template<class AthleteType>
bool List<AthleteType>::getEntry(int position, AthleteType & entry) const
{
    if (position < 1 || position > List::itemCount)
        return false;

    Node<AthleteType>* copyPtr = getNodeAt(position);
    entry = copyPtr->getItem();
    return true;
}


template<class AthleteType>
Node<AthleteType>* List<AthleteType>::getNodeAt(int position) const
{
    Node<AthleteType>* currentPtr = List::headPtr;
    for (int i = 1; i < position; i++)
        currentPtr = currentPtr->getNext();
    return currentPtr;
}

//HashTable class
class HashTable
{
private:
   Athlete* nodePtr;
   bool        status;
   int         numberOfCollisions;
public:
   HashTable()
   {
       nodePtr = 0;
       status = false;
       numberOfCollisions = 0;
   }
   ~HashTable()
   {
       if (nodePtr != 0)
        delete nodePtr;
   }
   void setWasUsed(bool value)      {status = value; }
   void setItemPtr(Athlete* ptr) {nodePtr = ptr; status = true; }
   void deleteNode()
   {
       if (nodePtr)
        delete nodePtr;
       nodePtr = 0;
       status = true;
   }
   void displayNode()
   {
       cout << nodePtr->getName() << " " << nodePtr->getYear() << endl;
   }
   void collisionIncrease(int num)  { numberOfCollisions = num; }
   int  getCollisions()             { return numberOfCollisions; }
   Athlete* getItemPtr ()           {return nodePtr;}
   bool hadBeenUsed ()              {return status;}
};


class HashedTable
{
    private:
        int size;
        int numberOfAthletes;
        HashTable *nodePtr;

        int hashingFunction(string name);
        int collisionResolution(int index, string name);
    public:
        HashedTable(int size)
        {
            this->size = size;
            nodePtr = new HashTable[this->size];
            numberOfAthletes = 0;
        }
        HashedTable(HashedTable* oldTable, const vector <Athlete*> &array,
                    int numOfAthletes);
        ~HashedTable()
        {
            delete [] nodePtr;
        }
        bool insert (Athlete* nodePtr);
        string stringToLower (string name);
        bool deleteAthlete (string Athlete);
        bool deleteAthlete(Athlete* nodePtr);
        void display(void visit(Athlete* ptr));
        bool findAthlete(string Athlete, class Athlete* & returnPointerToAthlete);
        void displayStats();
};

template<class AthleteType>
class BinaryNode
{
    private:
        AthleteType item;
        BinaryNode<AthleteType>* left;
        BinaryNode<AthleteType>* right;
    public:
        BinaryNode()
        {
            left = 0;
            right = 0;
        }
        BinaryNode(const AthleteType & anItem)
        {
            item = anItem;
            left = 0;
            right = 0;
        }
        BinaryNode(const AthleteType & anItem,BinaryNode<AthleteType>* left1,
                   BinaryNode<AthleteType>* right1)
        {
            item = anItem; left = left1; right = right1;
        }
        void setItem(const AthleteType & anItem)		   {item = anItem;}
        void setLeftPtr(BinaryNode<AthleteType>* left1)	   {left = left1;}
        void setRightPtr(BinaryNode<AthleteType>* right1)  {right = right1;}
        AthleteType getItem()const					       {return item;}
        BinaryNode<AthleteType>* getLeftPtr() const	       {return left;}
        BinaryNode<AthleteType>* getRightPtr() const	   {return right;}
        bool checkLeaf() const
        {
            return (left == 0 && right == 0);
        }
};

template<class AthleteType>
class BinaryTree
{
    private:
        void destroyTree(BinaryNode<AthleteType>* nodePtr);
        BinaryNode<AthleteType>* _copyTree(const BinaryNode<AthleteType>* nodePtr, vector <AthleteType> &arr, AthleteType visit (AthleteType));
        void _preorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const;
        void _inorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const;
        void _postorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const;
        void _RNLorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const;
        void _RNLorder (void visit(AthleteType &, int), BinaryNode<AthleteType>* nodePtr, int & width) const;
    protected:
        BinaryNode<AthleteType>* root;
        int count;
    public:
        BinaryTree()
        {
            root = 0;
            count = 0;
        }
        BinaryTree(const BinaryTree<AthleteType> & tree, AthleteType visit (AthleteType))
        {
            root = _copyTree(tree.root, visit);
            count = tree.count;
        }
        virtual ~BinaryTree() {clear();}
        BinaryTree & operator=(const BinaryTree & sourceTree);
        bool isEmpty() const				{return count == 0;}
        int size() const					{return count;}
        void clear()						{destroyTree(root); root = 0; count = 0;}
        void preOrder(void visit(AthleteType &)) const							{_preorder(visit, root);}
        void inOrder(void visit(AthleteType &)) const							{_inorder(visit, root);}
        void postOrder(void visit(AthleteType &)) const						    {_postorder(visit, root);}
        void RNLOrder(void visit(AthleteType &)) const							{_RNLorder(visit, root);}
        void RNLOrder (void visit(AthleteType &, int), int & width) const		{_RNLorder(visit, root, width);}
        void deleteBackup ()
        {
            root = 0;
            count = 0;
        }
        void copyTree (const BinaryTree<AthleteType> & copyItem, vector <AthleteType> &arr,
                       AthleteType visit (AthleteType))
        {
             clear(); root = _copyTree (copyItem.root, arr, visit);
             count = copyItem.count;
        }
        virtual bool insert(AthleteType & newData, bool visit (AthleteType, AthleteType, string)) = 0;
        virtual bool remove(const AthleteType & data, bool visit (AthleteType, AthleteType, string)) = 0;
        virtual bool getEntry(const AthleteType & anEntry, AthleteType & returnedItem, bool visit (AthleteType, AthleteType, string)) const = 0;
};

template<class AthleteType>
BinaryNode<AthleteType>* BinaryTree<AthleteType>::_copyTree(const BinaryNode<AthleteType>* nodePtr, vector <AthleteType> &arr, AthleteType visit (AthleteType))
{
	BinaryNode<AthleteType>* newNodePtr = 0;

	if (nodePtr != 0)
	{
		AthleteType tempCopy = visit (nodePtr->getItem());
		arr.push_back (tempCopy);
		newNodePtr = new BinaryNode<AthleteType> (tempCopy);
		newNodePtr->setLeftPtr(_copyTree (nodePtr->getLeftPtr(), arr, visit));
		newNodePtr->setRightPtr(_copyTree (nodePtr->getRightPtr(), arr, visit));
	}

    return newNodePtr;
}

template<class AthleteType>
void BinaryTree<AthleteType>::destroyTree(BinaryNode<AthleteType>* nodePtr)
{
	if (nodePtr != 0)
	{
		destroyTree (nodePtr->getLeftPtr());
		destroyTree (nodePtr->getRightPtr());
		delete nodePtr;

	}
}

template<class AthleteType>
void BinaryTree<AthleteType>::_preorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		AthleteType item = nodePtr->getItem();
		visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	}
}

template<class AthleteType>
void BinaryTree<AthleteType>::_inorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_inorder(visit, nodePtr->getLeftPtr());
		AthleteType item = nodePtr->getItem();
		visit(item);
		_inorder(visit, nodePtr->getRightPtr());
	}
}

template<class AthleteType>
void BinaryTree<AthleteType>::_postorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_postorder(visit, nodePtr->getLeftPtr());
		_postorder(visit, nodePtr->getRightPtr());
		AthleteType item = nodePtr->getItem();
		visit(item);
	}
}

template <class AthleteType>
void BinaryTree<AthleteType>::_RNLorder(void visit(AthleteType &), BinaryNode<AthleteType>* nodePtr) const	// For reverse alphabetical order.
{
	if (nodePtr != 0)
	{
		_RNLorder(visit, nodePtr->getRightPtr());
		AthleteType item = nodePtr->getItem();
		visit(item);
		_RNLorder(visit, nodePtr->getLeftPtr());
	}
}

template <class AthleteType>
void BinaryTree<AthleteType>::_RNLorder (void visit(AthleteType &, int), BinaryNode<AthleteType>* nodePtr, int & width) const
{
	if (nodePtr != 0)
	{
		width += 4;
		_RNLorder(visit, nodePtr->getRightPtr(), width);
		AthleteType item = nodePtr->getItem();
		visit(item, width);
		_RNLorder(visit, nodePtr->getLeftPtr(), width);
		width -= 4;
	}
}

template <class AthleteType>
BinaryTree<AthleteType> & BinaryTree<AthleteType>::operator=(const BinaryTree<AthleteType> & sourceTree)
{
	clear ();
	root = sourceTree.root;
	count = sourceTree.count;

    return *this;
}

template<class AthleteType>
class BinarySearchTree : public BinaryTree<AthleteType>
{
    private:
        BinaryNode<AthleteType>* _insert(BinaryNode<AthleteType>* nodePtr, BinaryNode<AthleteType>* newNode,
                                      bool visit (AthleteType, AthleteType, string));
        BinaryNode<AthleteType>* _remove(BinaryNode<AthleteType>* nodePtr, const AthleteType & target, bool & success,
                                      bool visit (AthleteType, AthleteType, string));
        BinaryNode<AthleteType>* deleteNode(BinaryNode<AthleteType>* targetNodePtr);
        BinaryNode<AthleteType>* removeLeftmostNode(BinaryNode<AthleteType>* nodePtr, AthleteType & successor);
        BinaryNode<AthleteType>* findNode(BinaryNode<AthleteType>* treePtr, const AthleteType & target,
                                       bool visit (AthleteType, AthleteType, string)) const;
    public:
        bool insert(AthleteType & newEntry, bool visit (AthleteType, AthleteType, string));
        bool remove(const AthleteType & anEntry, bool visit (AthleteType, AthleteType, string));
        bool getEntry(const AthleteType & target, AthleteType & returnedItem, bool visit (AthleteType, AthleteType, string)) const;
};

template<class AthleteType>
bool BinarySearchTree<AthleteType>::insert(AthleteType & newEntry, bool visit (AthleteType, AthleteType, string))
{
	BinaryNode<AthleteType> * newNodePtr = new BinaryNode<AthleteType> (newEntry);
	BinarySearchTree::root = _insert(BinarySearchTree::root, newNodePtr, visit);
	BinarySearchTree::count++;

	return true;
}

template<class AthleteType>
bool BinarySearchTree<AthleteType>::remove(const AthleteType & target, bool visit (AthleteType, AthleteType, string))
{
	bool isSuccessful = false;
	BinarySearchTree::root = _remove(BinarySearchTree::root, target, isSuccessful, visit);
	if (isSuccessful)
	{
		BinarySearchTree::count--;
	}

	return isSuccessful;
}

template<class AthleteType>
bool BinarySearchTree<AthleteType>::getEntry(const AthleteType & anEntry, AthleteType & returnedItem, bool visit (AthleteType, AthleteType, string)) const
{
	BinaryNode<AthleteType> * tempFind;
	tempFind = findNode(BinarySearchTree::root, anEntry, visit);
	if (tempFind)
	{
		returnedItem = tempFind->getItem();
		return true;
	}

	return false;
}

template<class AthleteType>
BinaryNode<AthleteType>* BinarySearchTree<AthleteType>::_insert(BinaryNode<AthleteType>* nodePtr,
BinaryNode<AthleteType>* newNodePtr, bool visit (AthleteType, AthleteType, string))
{
	if (nodePtr != 0)
	{
		if (visit (nodePtr->getItem(), newNodePtr->getItem(), ">"))
		{
			nodePtr->setLeftPtr(_insert (nodePtr->getLeftPtr(), newNodePtr, visit));
		}
		else if (visit (nodePtr->getItem(), newNodePtr->getItem(), "<"))
		{
			nodePtr->setRightPtr(_insert (nodePtr->getRightPtr(), newNodePtr, visit));
		}
	}
	else
	{
		return newNodePtr;
	}

	return nodePtr;
}

template<class AthleteType>
BinaryNode<AthleteType>* BinarySearchTree<AthleteType>::_remove(BinaryNode<AthleteType>* nodePtr,
const AthleteType & target, bool & success, bool visit (AthleteType, AthleteType, string))
{
	if (nodePtr == 0)
	{
		success = false;
		return 0;
	}

	if (visit (nodePtr->getItem(), target, ">"))
		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success, visit));
	else if (visit (nodePtr->getItem(), target, "<"))
		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success, visit));
	else
	{
		nodePtr = deleteNode(nodePtr);
		success = true;
	}
	return nodePtr;
}

template<class AthleteType>
BinaryNode<AthleteType>* BinarySearchTree<AthleteType>::deleteNode(BinaryNode<AthleteType>* nodePtr)
{
	if (nodePtr->checkLeaf())
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)
	{
		BinaryNode<AthleteType>* nodeToConnectPtr = nodePtr->getRightPtr();

		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0)
	{
		BinaryNode<AthleteType>* nodeToConnectPtr = nodePtr->getLeftPtr();

		delete nodePtr;

		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else
	{
		AthleteType newNodeValue = nodePtr->getItem();

		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);

		return nodePtr;
	}
}

template<class AthleteType>
BinaryNode<AthleteType>* BinarySearchTree<AthleteType>::removeLeftmostNode
(BinaryNode<AthleteType>* nodePtr,AthleteType & successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		AthleteType tempDelete = successor;
		successor = nodePtr->getItem();
		nodePtr->setItem(tempDelete);

		return deleteNode(nodePtr);
	}
	else
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}
}

template<class AthleteType>
BinaryNode<AthleteType>* BinarySearchTree<AthleteType>::findNode(BinaryNode<AthleteType>* nodePtr,
const AthleteType & target, bool visit (AthleteType, AthleteType, string)) const
{
	if (nodePtr != 0)
	{
		if (visit (nodePtr->getItem(), target, "=="))
		{
			return nodePtr;
		}
		else if (visit (nodePtr->getItem(), target, "<"))
		{
			return findNode (nodePtr->getRightPtr(), target, visit);
		}
		else
		{
			return findNode (nodePtr->getLeftPtr(), target, visit);
		}
	}
	else
	{
		return 0;
	}
}

template <class AthleteType>
class HeapMostSearch
{
    private:
        int count;
        int sizeArr;
        AthleteType * heapArr;

        void heapCreate (int numElements, bool visit (AthleteType, AthleteType, string));			// Function creates the heap from the array
        void heapRebuild (int index, bool visit (AthleteType, AthleteType, string));				// Rebuild heap after delete
        void swap (int a, int b);													// Function swaps value in the heap array
    public:
        HeapMostSearch ()
        {
            count = 0;
            heapArr = 0;
            sizeArr = 0;
        }
        ~HeapMostSearch ()            {clear();}
        bool isEmpty () const         {return count == 0;}
        int getNumberOfNodes () const {return count;}
        int getHeight () const
        {
            return static_cast <int> (ceil((log(count + 1.0)/log(2.0))));
        }
        bool getTop (AthleteType & returnItem) const
        {
            if (isEmpty()) return false; returnItem = heapArr[0]; return true;
        }
        bool add (AthleteType & addNode, bool visit (AthleteType, AthleteType, string),
                  bool visit1 (AthleteType, AthleteType));
        bool remove (bool visit (AthleteType, AthleteType, string));
        bool update (const AthleteType & updateNode, bool visit (AthleteType, AthleteType, string),
                  bool visit1 (AthleteType, AthleteType));
        void clear()
        {
            count = 0;
            sizeArr = 0;
            delete [] heapArr;
            heapArr = 0;
        }
        void copy (const HeapMostSearch<AthleteType> & copyHeap, const vector <AthleteType> & arr,
                   bool visit (AthleteType, AthleteType));
        void deleteBackup ()
        {
            count = 0;
            sizeArr = 0;
            heapArr = 0;
        }
};

template <class AthleteType>
void HeapMostSearch<AthleteType>::swap (int index1, int index2)
{
	AthleteType temp = heapArr[index1];
	heapArr[index1] = heapArr[index2];
	heapArr[index2] = temp;
}

template <class AthleteType>
void HeapMostSearch<AthleteType>::heapCreate (int numElements, bool visit (AthleteType, AthleteType, string))
{
	for (int i = (numElements - 2) / 2; i >= 0; i--)
	{
		heapRebuild(i, visit);
	}
}

template <class AthleteType>
void HeapMostSearch<AthleteType>::heapRebuild (int index, bool visit (AthleteType, AthleteType, string))
{
	AthleteType leftValue, rightValue;
	int largeIndex;

	if ((index * 2) + 1 < count)
	{
		leftValue = heapArr[(index * 2) + 1];
		if ((index * 2) + 2 > (count - 1))
		{
			largeIndex = (index * 2) + 1;
		}
		else
		{
			rightValue = heapArr[(index * 2) + 2];
			if (visit (leftValue, rightValue, ">"))
			{
				largeIndex = (index * 2) + 1;
			}
			else
			{
				largeIndex = (index * 2) + 2;
			}
		}
		if (visit (heapArr[index], heapArr[largeIndex], "<"))
		{
			swap (index, largeIndex);
			heapRebuild (largeIndex, visit);
		}
	}
}

template <class AthleteType>
bool HeapMostSearch<AthleteType>::add (AthleteType & addNode,
bool visit (AthleteType, AthleteType, string), bool visit1 (AthleteType, AthleteType))
{
	if (count == 0)
	{
		sizeArr = 10;
		heapArr = new AthleteType [sizeArr];
		heapArr[count] = addNode;
		count++;
		return true;
	}

	if (count >= sizeArr)
	{
		double height = ceil((log(count + 1.0)/log(2.0)));
		int fullSize = static_cast <int> (pow(2, height)) - 1;

		AthleteType * newHeap = heapArr;
		heapArr = new AthleteType [fullSize];
		for (int i = 0; i < sizeArr; i ++)
		{
			heapArr[i] = newHeap[i];
		}
		sizeArr = fullSize;

		delete [] newHeap;
	}

	bool duplicate = false;
	int index = 0, duplicateIndex;

	while (index < count && !duplicate)
	{
		if (visit1 (heapArr[index], addNode))
		{
			duplicateIndex = index;
			duplicate = true;
		}
		index++;
	}

	if (duplicate)
	{
		heapArr[duplicateIndex] = addNode;
		heapCreate (count, visit);
		return true;
	}

	heapArr[count] = addNode;
	count++;
	heapCreate (count, visit);

	return true;
}

template <class AthleteType>
bool HeapMostSearch<AthleteType>::remove (bool visit (AthleteType, AthleteType, string))
{
	if (count == 0)
	{
		return false;
	}
	if (count == 1)
	{
		count--;
		return true;
	}
	swap (0, count - 1);
	count--;
	heapRebuild (0, visit);

	return true;
}

template <class AthleteType>
bool HeapMostSearch<AthleteType>::update (const AthleteType & updateNode,
bool visit (AthleteType, AthleteType, string), bool visit1 (AthleteType, AthleteType))
{
	bool same = false;
	int index = 0, sameIndex;

	while (index < count && !same)
	{
		if (visit1 (heapArr[index], updateNode))
		{
			sameIndex = index;
			same = true;
		}
		index++;
	}

	if (same)
	{
		heapArr[sameIndex] = heapArr[count - 1];
		count--;
		heapCreate (count, visit);
	}

	return true;
}

template <class AthleteType>
void HeapMostSearch<AthleteType>::copy (const HeapMostSearch<AthleteType> & copyHeap,
const vector <AthleteType> & arr, bool visit (AthleteType, AthleteType))
{
	count = copyHeap.count;
	sizeArr = copyHeap.sizeArr;
	heapArr = new AthleteType [sizeArr];

	bool found = false;

	for (int i = 0; i < copyHeap.count; i++)
	{
		for (unsigned int j = 0; j < arr.size() && !found; j++)
		{
			found = visit (copyHeap.heapArr[i], arr[j]);
			if (found)
			{
				heapArr[i] = arr[j];
			}
		}
	}
}

class AthleteRecord
{
    private:
        int count;
        BinarySearchTree<Athlete*> item;
        HashedTable *hashPtr;
        HeapMostSearch<Athlete*> heapSearch;
        int backupCount;
        BinarySearchTree<Athlete*> backupItem;
        HashedTable * backupHashPtr;
        HeapMostSearch<Athlete*> backupHeapSearch;
    public:
        static Athlete * copyValue (Athlete * copyItem);
        AthleteRecord();
        ~AthleteRecord() {delete hashPtr; delete backupHashPtr;}
        static void printFull(Athlete& sample) {sample.printAll(); cout << endl;}
        static void print(Athlete * & sample) {sample->printKey();}
        static void visit(Athlete* ptr) {cout << ptr->getName() << endl;}
        static void copy(Athlete*ptr, HashedTable* hashPtr);
        void add(string input, string age, string country, string year);	// Adds into BST and HashedTable
        void deleteData(string input);										// Delete function
        bool search(string input);											// Search function (HashedTable)
        void hashList() const {hashPtr->display(visit); cout << endl;}		// Displays the HashedTable
        void bstKey() const {item.inOrder(print); cout << endl;}			// Prints out the BST data in order
        void hashStats() const {hashPtr->displayStats(); cout << endl;}		// Prints out the Hash Statistics
        void backUp();														// Back up for BST and HashedTable
        void useBackup ();													// Uses the Back up for BST and HashedTable
        void compare();														// Compare function
        void mostSearched(int num);											// HONORS: Shows the most searched for items
        bool save();														// Saves to output file
        //void printTree()		{int width = 0; item.RNLOrder (indentedTree, width);}	// Prints out the indented tree

};

void readInputFile(BinarySearchTree<Athlete*> &item, HashedTable * &hashPtr);
void output(Athlete*);
void deleteMemory();
bool compareValue (Athlete * operand1, Athlete * operand2, string symbol);
Athlete* copyValue (Athlete* copyItem);
void indentedTree (Athlete * & anItem, int width);
bool compareHeap (Athlete * operand1, Athlete * operand2, string symbol);
bool checkDuplicate (Athlete * operand1, Athlete * operand2);
void displayLinkedList (Athlete * item);
bool checkError (string & input);

Athlete * AthleteRecord :: copyValue (Athlete * copyItem)
{
	Athlete * tempCopy = new Athlete(*copyItem);
	return tempCopy;
}

AthleteRecord:: AthleteRecord()
{
	backupCount = 0;
	backupHashPtr = 0;
	hashPtr = 0;
    readInputFile(item, hashPtr);
    count = item.size();
}

void AthleteRecord:: add(string input, string age, string country, string year)
{
    Athlete* temp = new Athlete(input, age, country, year);
    item.insert(temp, compareValue);
    hashPtr->insert(temp);
}

void AthleteRecord:: deleteData(string input)
{
    cout << "You are in the deleteData function of DataRecord" << endl;
    bool success = false;
	Athlete * deleteItem = new Athlete(input, "unknown", "unknown", "unknown");

	heapSearch.update (deleteItem, compareHeap, checkDuplicate);

	success = item.remove(deleteItem, compareValue);

    if(success == true)
    {
        cout << input << " was deleted from BST." << endl;
    }
    else
        cout << input << " is not found in the BST." << endl;

    success = hashPtr->deleteAthlete(deleteItem);

    if(success == true)
    {
        cout << input << " was deleted from HashTable." << endl;
    }
    else
        cout << input << " is not found in HashTable." << endl;
}

bool AthleteRecord::search(string input)
{
    bool found = false;
    Athlete* returnedItem;

    found = hashPtr->findAthlete(input, returnedItem);
    if(found==false)
    {
		cout << input << " is not found among these athletes: " << endl;
		item.inOrder(print);
		cout <<endl;
    }
	else
	{
		returnedItem->updateSearch();
		heapSearch.add(returnedItem, compareHeap, checkDuplicate);
		cout << endl;
		returnedItem->printAll();
		cout << endl;
	}

    return found;
}

void AthleteRecord:: backUp()
{
	if (!(hashPtr == backupHashPtr || backupHashPtr == 0))
	{
		backupItem.clear();
		backupCount = 0;
		backupHeapSearch.clear();
		delete backupHashPtr;
		backupHashPtr = 0;
	}

	backupCount = count;
	vector <Athlete*> arrayTree;

	backupItem.copyTree (item, arrayTree, copyValue);

    backupHashPtr = new HashedTable (hashPtr, arrayTree, count);

	backupHeapSearch.copy(heapSearch, arrayTree, checkDuplicate);

}

void AthleteRecord::useBackup ()
{
	count = backupCount;
	item.clear();
	delete hashPtr;
	hashPtr = 0;
	heapSearch.clear();

	item = backupItem;
	hashPtr = backupHashPtr;
	heapSearch = backupHeapSearch;

	backupHeapSearch.deleteBackup();
	backupItem.deleteBackup();
	backupHashPtr = 0;
}

void AthleteRecord:: compare()
{
    string data;
    string choice1, choice2, choice3, choice4;
    char loc;
	int location;
    char key = ' ';
    int i = 1;
	bool found = false;
	List<Athlete*> compareList;
	Athlete * compareAthlete;
	bool validInput;

    cout << "What athletes would you like to compare? "<< endl;

	do
	{
		cout << "\t First Athlete: ";
		getline(cin, choice1);

		validInput = checkError(choice1);

		if (validInput)
		{
			found = hashPtr->findAthlete(choice1, compareAthlete);
			if(found)
			{
				compareList.insert (compareAthlete, 1);
				i++;
			}
			if (!found)
			{
				bstKey();
			}
		}
	} while (!found || !validInput);

	do
	{
	   cout << "\t Second Athlete: ";
		getline(cin, choice2);

		validInput = checkError(choice2);

		if (validInput)
		{

		found = hashPtr->findAthlete(choice2, compareAthlete);
		 if(found)
		 {
			 compareList.insert (compareAthlete, 2);
			  i++;
		 }
		 if (!found)
		 {
			 bstKey();
		 }

		}
	} while (!found || !validInput);

    compareList.displayList (displayLinkedList);

    while (key != 'e')
    {
		if (i <= 4)
		{
	        cout << "\t a. Compare another athlete"<< endl;
		}
		cout << "\t p. Put athletes together" << endl;
		cout << "\t e. Exit to Menu Chocies" << endl;
        cout << "Choice: ";
        cin >> key;
        key = tolower(key);
        cin.ignore(100,'\n');

        if (key=='a' && i <= 4)
        {
			do
			{
                cout << "\t Next Athlete: ";
                getline(cin, choice3);
				do
				{
					cout << "\t Location: ";
					cin >> loc;
					cin.ignore(100, '\n');
					if (!isdigit(loc))
					{
						cout << "\t Input has to be a number" << endl;
					}
				} while(!isdigit(loc));

                found = hashPtr->findAthlete(choice3, compareAthlete);
				if (!found)
				 {
					bstKey();
				 }
			}while (!found);

			if(found)
			{
				char * temp = &loc;
				if (atoi(temp) > i)
				{
					location = i;
				}
				else
				{

					location = atoi(temp);
				}

				 compareList.insert (compareAthlete, location);
				i++;
			}
			compareList.displayList (displayLinkedList);
		}
		else if (key == 'p')
		{
			char location1, location2;
			char * temp;

			do
			{
				cout << "\t Location: ";
				cin >> location1;
				cin.ignore(100, '\n');
				if (!isdigit(location1))
				{
					cout << "\t Input has to be a number" << endl;
				}
				else
				{
					temp = &location1;
					if (atoi(temp) > i)
					{
						cout << "\t Input has to be in between the number of athlete\n";
					}
				}
			} while(!isdigit(location1) || (atoi(temp) > i));
			do
			{
				cout << "\t and: ";
				cin >> location2;
				cin.ignore(100, '\n');
				if (!isdigit(location2))
				{
					cout << "\t Input has to be a number" << endl;
				}
				else
				{
					temp = &location2;
					if (atoi(temp) > i)
					{
						cout << "\t Input has to be in between the number of athlete\n";
					}
				}
			} while(!isdigit(location2) || (atoi(temp) > i));

			char * tempLocation1 = &location1;
			char * tempLocation2 = &location2;
			Athlete * holdValue1;
			Athlete * holdValue2;
			compareList.getEntry(atoi(tempLocation1), holdValue1);
			compareList.getEntry(atoi(tempLocation2), holdValue2);

			compareList.remove(atoi(tempLocation1));
			compareList.remove(atoi(tempLocation2) - 1);

			compareList.insert(holdValue1, 1);
			compareList.insert(holdValue2, 2);



			compareList.displayList(displayLinkedList);
		}
		else if (key == 'e')
		{
			cout << "\t Exit compare option\n";
		}
		else
		{
			cout << "\t Invalid input\n";
		}
	}

}

void AthleteRecord:: mostSearched(int num)
{
	if (heapSearch.isEmpty())
	{
		cout << "There is no athlete which is searched" << endl;
		return;
	}

	Athlete * tempArr [10];
	Athlete * hold;
	int check = num;

	if (heapSearch.getNumberOfNodes() < num)
	{
		check = heapSearch.getNumberOfNodes();
		cout << "The number of athletes that have been searched up to now is less than your resquest" << endl;
	}

	cout << endl;

    for (int i = 0; i < check; i++)
	{
		heapSearch.getTop (hold);
		tempArr[i] = hold;
		heapSearch.remove (compareHeap);

		cout << "Number " << i + 1 << endl;
		tempArr[i]->printAll();
		cout << endl;
	}
	cout << endl;
	while (check < 10 && heapSearch.getTop(hold) && tempArr[check - 1]->getNumSearch() == hold->getNumSearch())
	{
		tempArr[check] = hold;
		cout << "Number " << check + 1 << endl;
		tempArr[check]->printAll();
		cout << endl;
		heapSearch.remove(compareHeap);
		check++;
	}

	for (int i = 0; i < check; i++)
	{
		heapSearch.add (tempArr[i], compareHeap, checkDuplicate);
	}
}

bool AthleteRecord:: save()
{
   bool save = true;
   deleteMemory(); //Clears .txt file for output
   hashPtr->display(output);
   cout << "Data Saved!" << endl;
   return save;
}

HashedTable::HashedTable(HashedTable* oldTable, const vector <Athlete*> &array, int numOfAthletes)
{
   this->size = oldTable->size;
   this->numberOfAthletes = numOfAthletes;
   this->nodePtr = new HashTable[this->size];

   for (int i = 0; i < size; i++)
   {
        this->nodePtr[i].setWasUsed(oldTable->nodePtr[i].hadBeenUsed());
        this->nodePtr[i].collisionIncrease(oldTable->nodePtr[i].getCollisions());

    if (oldTable->nodePtr[i].hadBeenUsed() && oldTable->nodePtr[i].getItemPtr() != 0)
    {
        bool   found = false;
        int    counter = 0;
        string name = (oldTable->nodePtr[i].getItemPtr())->getName();

           while (found == false && counter < numOfAthletes)
           {
               if (array[counter] != 0)
               {
                   if (array[counter]->getName() != name)
                       counter++;
                   else if (array[counter]->getName() == name)
                       break;
               }
           }

           if (array[counter]->getName() == name)
           {
               found = true;
               this->nodePtr[i].setItemPtr(array[counter]);
           }
       }
   }
}

string HashedTable::stringToLower(string name)
{
    for (unsigned int i = 0; i<name.length(); i++)
        name[i] = tolower(name[i]);
    return name;
}

int HashedTable::collisionResolution(int index, string name)
{
    string temp;
    for (int i = 0; i< name.length(); i++)
    {
        temp += name[name.length() - i - 1];
    }
    index += hashingFunction(temp);
    return index;
}
bool HashedTable::insert(Athlete *itemPtr)
{
    int numberColls = 0;
    if (numberOfAthletes == size)
    {
        cout << "Too many items! Insert fail" << endl;
        return false;
    }
    if (itemPtr == 0)
        return false;
    string name = itemPtr->getName();
    int index = 0;
    index = hashingFunction(name);

    while (nodePtr[index].hadBeenUsed() && nodePtr[index].getItemPtr() != 0)
    {
        // Check if the restaurant at the current node is equal to the one trying to be inserted
        if (nodePtr[index].getItemPtr()->getName() == itemPtr->getName())
        {
            cout << "Item already exists in the list. Insert will not happen to avoid duplicates: ";
            string temp= nodePtr[index].getItemPtr()->getName();
            cout << temp << endl;
            return false;
        }
        index = (collisionResolution(index, itemPtr->getName())) % size;
        numberColls++;
    }

    nodePtr[index].setItemPtr(itemPtr);
    nodePtr[index].collisionIncrease(numberColls);

    numberOfAthletes++;
	return true;
}

void HashedTable::display(void visit(Athlete* ptr))
{
    for (int i = 0; i < size; i++)
    {
        if(nodePtr[i].hadBeenUsed() && nodePtr[i].getItemPtr() != 0)
        {
            visit(nodePtr[i].getItemPtr());
        }
    }
}

void HashedTable::displayStats()
{
    int     temp = 0;
    int     maxColls = 0;
    string  athletesMaxColls;
    cout << "There are " << numberOfAthletes << " athletes in the directory" << endl;
    cout << "The size of the Hash Table is: " << size << endl;
    cout << "The load factor is " << fixed << setprecision(2) << (100.0*numberOfAthletes / size) << "%\n" << endl;

    for (int i = 0; i < size; i++)
    {
        if (nodePtr[i].hadBeenUsed() && nodePtr[i].getItemPtr() != 0)
        {
            temp = nodePtr[i].getCollisions();

            if (temp > maxColls && temp > 0)
            {
                maxColls = temp;
                athletesMaxColls.clear();
                athletesMaxColls = (nodePtr[i].getItemPtr())->getName();
                athletesMaxColls += ", ";
            }
            else if (temp == maxColls && temp != 0)
            {
                athletesMaxColls += (nodePtr[i].getItemPtr())->getName();
                athletesMaxColls += ", ";
            }
        }
    }
    if (maxColls > 0)
    {
        cout << "Max number of collisions is " << maxColls << " which occurs at athletes: " << endl;
        cout << athletesMaxColls << endl;
        cout << endl << endl;
    }
}

bool HashedTable::findAthlete(string name, Athlete* & pointerToAthlete)
{
    name = stringToLower(name);
    if (numberOfAthletes == 0)
        return false;
    bool found = false;
    int index = 0;
    index = hashingFunction(name);

    while ((nodePtr[index].hadBeenUsed()) && nodePtr[index].getItemPtr() != 0
           && (stringToLower((nodePtr[index].getItemPtr())->getName()))  != name)
    {
        index = (collisionResolution(index, name)) % size;
    }

    if ((nodePtr[index].hadBeenUsed()) &&
        nodePtr[index].getItemPtr() != 0 &&
        (stringToLower((nodePtr[index].getItemPtr())->getName())) == name)
    {
        pointerToAthlete = nodePtr[index].getItemPtr();
        found = true;
        return found;
    }
    else
        return false;
}

bool HashedTable::deleteAthlete(string name)
{
    if (numberOfAthletes == 0)
        return false;
    int index = 0;
    index = hashingFunction(name);

    while (nodePtr[index].hadBeenUsed())
    {
        if (nodePtr[index].getItemPtr() == 0)
            index = (collisionResolution(index, name)) % size;
        else if ((nodePtr[index].getItemPtr())->getName() != name)
            index = (collisionResolution(index, name)) % size;
        else if ((nodePtr[index].getItemPtr())->getName() == name)
        {
            nodePtr[index].setItemPtr(0);
            nodePtr[index].collisionIncrease(0);
            numberOfAthletes--;
            return true;
        }
        else
            return false;
    }
    return false;
}

bool HashedTable::deleteAthlete(Athlete* itemPtr)
{
    if (numberOfAthletes == 0)
        return false;
    int index = 0;
    index = hashingFunction(itemPtr->getName());

    while (nodePtr[index].hadBeenUsed())
    {
        if (nodePtr[index].getItemPtr() == 0)
            index = (collisionResolution(index, itemPtr->getName())) % size;
        else if (!(*(nodePtr[index].getItemPtr()) == *itemPtr))
            index = (collisionResolution(index, itemPtr->getName())) % size;
        else if (*(nodePtr[index].getItemPtr()) == *itemPtr)
        {
            nodePtr[index].setItemPtr(0);
            nodePtr[index].collisionIncrease(0);
            numberOfAthletes--;
            return true;
        }
        else
            return false;
    }
    // Xcode doesn't like not having a return outside the loop
    return false;
}

// This hashing algorithm assigns an index to a word based on its components letters using a switch and while loop.
// The more common letters have smaller values, the less common get larger ones.
// Any clustering that comes from this function is random and unpredictable
// since a single letter difference between words would cause a substantial difference in index. For example the word
// "car" gets an index of 651 while "cat" gets 137.
// The larger/more exotic the word the farther spaced out the are.

// The numbr of probes reached a max of 4 and each word again displayed the functions ability to produce an
// unexpected, unpredictable index for each word.

int HashedTable::hashingFunction(string name)
{
    long int placement = 0;
    int i = 1;
    int a = i;


    name = stringToLower(name);
    while (i <= name.length())
    {
        // This if will guarantee placement never gets too long
        if (a > 6)
            a = 3;
        switch (name[i-1])
        {
            case('e'): placement += 1*pow(3.18,a);
                break;
            case('t'): placement += 2*pow(2.988,a);
                break;
            case('a'): placement += 3*pow(3.98,a);
                break;
            case('o'): placement += 4*pow(3.98,a);
                break;
            case('i'): placement += 5*pow(3.98,a);
                break;
            case('n'): placement += 6*pow(3.98,a);
                break;
            case('s'): placement += 7*pow(3.98,a);
                break;
            case('h'): placement += 8*pow(3.98,a);
                break;
            case('r'): placement += 9*pow(3.98,a);
                break;
            case('d'): placement += 10*pow(3.2128,a);
                break;
            case('l'): placement += 11*pow(3.2018,a);
                break;
            case('c'): placement += 12*pow(3.1008,a);
                break;
            case('u'): placement += 13*pow(3.338,a);
                break;
            case('m'): placement += 14*pow(3.328,a);
                break;
            case('w'): placement += 15*pow(3.318,a);
                break;
            case('f'): placement += 16*pow(3.308,a);
                break;
            case('g'): placement += 17*pow(3.208,a);
                break;
            case('y'): placement += 18*pow(3.808,a);
                break;
            case('p'): placement += 19*pow(3.48,a);
                break;
            case('b'): placement += 20*pow(2.8,a);
                break;
            case('v'): placement += 21*pow(3.98,a);
                break;
            case('k'): placement += 22*pow(3.08,a)*(i+0.324);
                break;
            case('j'): placement += 23*pow(3.9,a)*(i+0.334);
                break;
            case('x'): placement += 24*pow(3.48,a)*(i+0.344);
                break;
            case('q'): placement += 25*pow(3.18,a)*(i+0.354);
                break;
            case('z'): placement += 26*pow(3.28,a)*(i+0.364);
                break;
            default: placement += 31;
        }
        placement = (placement%size);
        i++;
        a = i;
    }

    return static_cast<int>(placement);
}



void readInputFile(BinarySearchTree<Athlete*> &item, HashedTable * &hashPtr)
{
   string name, age, country, year;
   ifstream infile;
   string fname;
   string blank;
   int count = 0;
   cout << "Please enter filename with extenstion: " <<endl;
   getline(cin,fname);
   infile.open(fname.c_str());

   while (!infile)
   {
       cout << "Error opening file, please enter filename with extension for file type: " << endl;
       getline(cin, fname);
       infile.open(fname.c_str());
   }

   while (!infile.eof())
   {
       getline(infile, blank); // store data to walk full file
       count++;
   }

   int arraySize = (count*1.97) - 1;

   hashPtr = new HashedTable(arraySize);
   infile.close();

   infile.open(fname.c_str());

   while (!infile.eof() && infile.peek() != 10)		//Prevent the blank in the file
   {
       getline(infile, name, ',');
       getline(infile, age, ',');
       getline(infile, country, ',');
       getline(infile, year);
       Athlete* temp = new Athlete(name, age, country, year); //Place into Dynamic Memory

       if (hashPtr->insert(temp)) // Insert into Hashed Table
			item.insert(temp, compareValue); // Insert into BST

   }

   infile.close();

}

//this function will create an output file
void output(Athlete *data)
{
   string fname;
   ofstream outFile;
   outFile.open("copy.txt", ofstream::app);

   outFile << data-> getName() << ',';
   outFile << data-> getAge() << ',';
   outFile << data-> getCountry() << ',';
   outFile << data-> getYear() << endl;

  outFile.close();
}

void deleteMemory()
{
   ifstream infile;
   infile.open("copy.txt", std::ofstream::out | std::ofstream::trunc);
   infile.close();
}

bool compareValue (Athlete * operand1, Athlete * operand2, string symbol)
{
	if (symbol == "<")
	{
		return *operand1 < *operand2;
	}
	else if (symbol == ">")
	{
		return *operand1 > *operand2;
	}
	else if (symbol == "==")
	{
		return *operand1 == *operand2;
	}

	cout << "Invalid comparison symbol (<,>, ==)" << endl;
	return false;
}

Athlete* copyValue(Athlete* copyItem)
{
	Athlete *tempCopy = new Athlete (*copyItem);

	return tempCopy;
}

void indentedTree (Athlete * & anItem, int width)
{
	cout << right << setw(width + static_cast<int>(anItem->getName().size())) << setfill('-') << anItem->getName() << setfill (' ') << endl;
}

bool compareHeap (Athlete * operand1, Athlete * operand2, string symbol)
{
   if (symbol == "<")
   {
       return operand1->getNumSearch() < operand2->getNumSearch();
   }
   else if (symbol == ">")
   {
       return operand1->getNumSearch() > operand2->getNumSearch();
   }
   else if (symbol == "==")
   {
       return operand1->getNumSearch() == operand2->getNumSearch();
   }

   cout << "Invalid comparison symbol (<,>,==)" << endl;

   return false;
}

bool checkDuplicate (Athlete * operand1, Athlete * operand2)
{
   return *operand1 == *operand2;
}

void displayLinkedList (Athlete * item)
{
   item->printAll();
   cout << endl;
}

bool checkError (string & input)
{
	bool validInput;

	if (input.empty())
	{
		cout << "Need a name for athlete in order to work.\n";
		validInput = false;
	}

	if (!input.empty())
	{
		validInput = false;
		bool frontSpace = isspace(input[0]);
		bool backSpace = isspace(input[input.size() - 1]);

		for (unsigned int i = 0; i < input.size() && !validInput; i++)
		{
			if (isalnum(input[i]))
			{
				validInput = true;
			}
		}

		for (unsigned int i = 0; i < input.size() && validInput; i++)
		{
			while (frontSpace)
			{
				input.erase(0, 1);
				if (!isspace(input[0]))
					frontSpace = false;
			}

			while (backSpace)
			{
				input.erase(input.size() - 1, 1);
				if (!isspace(input[input.size() - 1]))
				backSpace = false;
			}
		}

		if (!validInput)
		{
			cout << "Name of athlete cannot contain space (' ') only.\n" << endl;
		}
	}

	return validInput;
}

void mainMenu(AthleteRecord test);
void addAthlete(string input, string age, string country, string year,
AthleteRecord test, bool save);
void deleteAthlete(string input, AthleteRecord test, bool save);
void findAthlete(string input, AthleteRecord test);
void listAthlete(char key, AthleteRecord test);
void frequentlySearched(string input, AthleteRecord test);
int quitMenu(char key, bool save, AthleteRecord test);

int main ()
{
    AthleteRecord test;
    mainMenu(test);
}

void mainMenu(AthleteRecord test)
{
    char key = ' ';
    string input, age, country, year;
    bool backup = false, save = true;

   while (key != 'q') // Loops until user wants to quit
    {
        cout    << "Main Menu" << endl
                << "\t a. Add New Data" << endl
                << "\t d. Delete Data" << endl
                << "\t f. Find and Display Data Using Primary Key"<< endl
                << "\t l. List Data" << endl
                << "\t p. Print Indented Tree" << endl
                << "\t h. Hash Statistics" << endl
                << "\t b. Backup" << endl;

		if (backup == true)
            cout << "\t u. Use Backup"<<endl;

        cout    << "\t c. Compare Data" << endl
                << "\t m. Most Searched (Honors)" << endl
                << "\t s. Save" << endl
                << "\t q. Quit" << endl << endl;

        cout << "Choice: ";
        cin >> key; // Only grabs the first character of input.
        key = tolower(key); // Convert to lower case

		// temp solution.
		cin.ignore (100, '\n');

        if (key == 'a')
        {
              addAthlete(input, age, country, year, test, save); // adds athlete
        }

        else if (key == 'd')
        {
            deleteAthlete(input, test, save); // deletes athlete
        }

        else if (key == 'f')
        {
            findAthlete(input, test); // finds athlete
        }

        else if(key == 'l')
        {
            listAthlete(key, test); // lists athlete
        }
          else if (key == 'p')
        {
			//test.printTree(); // prints indented tree
        }

        else if (key=='h')
        {
            test.hashStats(); // displays hash statistics
        }

        else if (key=='b') // backup
        {
			backup = true;
            test.backUp();
        }

        else if (backup && key == 'u') // uses backup
        {
			backup = false;
            test.useBackup();
        }

        else if (key == 'c') // compares athlete
        {
			test.compare();
        }

        else if (key == 'm') // frequently searched athlete
        {
            frequentlySearched(input, test);
        }

        else if (key == 's') // saves data
        {
			save = test.save();
        }

        else if (key != 'q') // quits
        {
            cout<<"Not a valid menu choice."<<endl;
        }

        else if (key == 'q' && save == false)
        {
            quitMenu(key, save, test);
        }
    }
}

void addAthlete(string input, string age, string country, string year,
                AthleteRecord test, bool save)
{
    bool validInput = true;
    cout << "Enter new Athlete: ";
    getline(cin, input);
    validInput = checkError(input);

    if (validInput && test.search(input) == false)
    {
                cout << "Please enter age of athlete: ";
                //cin.ignore(100, '\n');
                getline(cin, age);
                cout << "Please enter country of athlete";
                //cin.ignore(100, '\n');
                getline(cin, country);
                cout << "Please enter the year";
                //cin.ignore(100, '\n');
                getline(cin, year);

                test.add(input, age, country, year);
				save = false;
    }
            else if (validInput)
                cout << "Already exists" << endl;
}

void deleteAthlete(string input, AthleteRecord test, bool save)
{
    cout << "Enter an athlete to delete: ";
    getline(cin, input);

    bool validInput;
    validInput = checkError(input);

    if (validInput && test.search(input) == true)
    {
        save = false;
        test.deleteData(input);
    }
    else
        cout << "Does not exist" << endl;
}

void findAthlete(string input, AthleteRecord test)
{
    cout << "Enter an athlete to find: ";
    getline(cin, input);

    bool validInput;
    validInput = checkError(input);

    if(validInput && test.search(input) == false)
        cout << input << " is not found in the list" << endl;
}

void listAthlete(char key, AthleteRecord test)
{
    cout	<< "\t h. Hash Table Data" << endl
					<< "\t b. BST Sorted Order"<<endl;
    cout << "Choice: ";
    cin >> key; // Only grabs the first character of input.
    key = tolower(key);
    cin.ignore (100, '\n');

    if (key == 'h') // List Hash
    {
        test.hashList(); // Calls display function in HashTable
    }
    else if (key == 'b') // List BST Key
    {
        test.bstKey(); // Calls displayKey from DataRecord
    }
}

void frequentlySearched(string input, AthleteRecord test)
{
    int num = 0;
    bool validInput;
    do
    {
        validInput = true;
        cout << "Most searched athlete: "<< endl;
        cout << "How many athletes do you want to display?(max is 10): ";
        cin >> input;
        cin.ignore (100, '\n');
        if (input.size() >= 100)
        {
            validInput = false;
        }
        else
        {
            for (int i = 0; i < input.size() && validInput; i++)
            {
                if (isalpha(input[i]))
                {
                    validInput = false;
                }
            }
        }
        if (!validInput)
        {
            cout << "Invalid input. Input is only number from 1 to 10.\n";
        }
    } while (!validInput);

        istringstream convert (input);
        if (!(convert >> num))
            num = 10;

        if (num > 10)
            num = 10;
        test.mostSearched(num);
}

int quitMenu(char key, bool save, AthleteRecord test)
{
    do
    {
        cout << "\t y. Quit without saving data" << endl
             << "\t n. Do Not Quit & Save Data" << endl;
        cout << "Choice: ";
        cin >> key;
        key = tolower(key);
        cin.ignore (100, '\n');
    } while (key != 'n' && key != 'y');

    if (key=='n')
    {
        save = test.save();
        return 0;
    }
    else
        return 0;
}

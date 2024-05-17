#include "library.h"

// constructor and destructor (given to you)
Library::Library()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Library::~Library()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// display and add functions (given to you)
void Library::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->title << " by " << temp->author << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void Library::append(string title, string author)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(title, author);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node(title, author);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

// this shows selection sort
// as applied to linked lists
// sorting on TITLE basis
void Library::sort()
{
    // example shows: selection sort
    for(int i = 0; i < size - 1; i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            // gets node at j
            Node *jItem = head;
            for(int k = 0; k < j; k++)
            {
                jItem = jItem->next;
            }

            // gets node at smallIndex
            Node *smallIndexItem = head;
            for(int k = 0; k < smallIndex; k++)
            {
                smallIndexItem = smallIndexItem->next;
            }

            // runs comparison
            if(jItem->title < smallIndexItem->title)
            {
                smallIndex = j;
            }
        }

        // grabs node at index i
        Node *current = head;
        for(int k = 0; k < i; k++)
        {
            current = current->next;
        }

        // grabs node at index smallIndex
        Node *small = head;
        for(int k = 0; k < smallIndex; k++)
        {
            small = small->next;
        }

        // grabs the information at the current node
        // stores it
        string tempTitle = current->title;
        string tempAuthor = current->author;

        // swaps current data to small data
        current->title = small->title;
        current->author = small->author;

        // overwrites small data to the stored data
        // (what used to be in current)
        small->title = tempTitle;
        small->author = tempAuthor;
    }
}

// ****************************************************************
// ** you should make **
// all of these should work on a TITLE of the book basis
// ****************************************************************

// any links to resources to make it work:
/*
* Base  code for binary search of an array is from Zybooks 10.2 I am somewhat using it as an idea for the comparisions and basic structure
* .compare references:
* https://stackoverflow.com/questions/45950646/what-is-lexicographical-order
*/
int Library::binarySearch(string title)
{
    //Intiializing variables
    int high = size - 1, low = 0, mid;
    
   
  
    //checks the values of each of the variables
    //cout << high << endl << mid << endl << low << endl;
    while (high >= low) {
        
        Node* middleEntry = head;
        
        mid = (high + low) / 2;
        
            for (int i = 0; i < mid; i++) {
               
                    middleEntry = middleEntry->next;
                
            }
            int comparrison = middleEntry->title.compare(title);
            //checking and setting
            if (comparrison < 0) {
                low = mid + 1;
                
            }
            else if (comparrison > 0) {
                high = mid - 1;
               
                //higerEntry = middleEntry;
            }
            else {
                return mid; // returning the index
            }
    }

    return -1;
}

// strategy: Randomly swapping a random item in the list with the starting item
// any links to resources to make it work:
/*
* https://stackoverflow.com/questions/23094055/randomly-shuffling-a-linked-list
*/
void Library::shuffle()
{
    Node* swapper = head;
    Node* Header = head;
    Node* temp;
    double swapchance = 0.25;
    while (swapper->next != nullptr) {
        swapper = swapper->next;
        if (rand() % 1000 / 1000.0 < swapchance) { // random chance to swap the data of the nodes
            //Swapping from the sort() function
            


            // grabs the information at the current node
        // stores it
            string tempTitle = swapper->title;
            string tempAuthor = swapper->author;

            // swaps current data to small data
            swapper->title = Header->title;
            swapper->author = Header->author;

            // overwrites small data to the stored data
            // (what used to be in current)
            Header->title = tempTitle;
            Header->author = tempAuthor;
        }
    }
    display();
}

// algorithm of choice:Selection sort using the sort given in the code then reversing it
// any links to resources to make it work:
/*
https://www.geeksforgeeks.org/reverse-a-linked-list/ 
Bubble sort on zybooks
*/
void Library::reverseSort()
{
    Node* nodeI = head;
    
    //Bubble sort
    while (nodeI != nullptr) {
        Node* nodeJ = head;
        while(nodeJ->next != nullptr) {
            if (nodeI->title.compare(nodeJ->title)>0) {
                string tempTitle = nodeI->title;
                string tempAuthor = nodeI->author;

                // swaps current data to small data
                nodeI->title = nodeJ->title;
                nodeI->author = nodeJ->author;

                // overwrites small data to the stored data
                // (what used to be in current)
                nodeJ->title = tempTitle;
                nodeJ->author = tempAuthor;
            }
            nodeJ = nodeJ->next;
            
        }
        nodeI = nodeI->next;

    }
    //sort();
    // Initialize current, previous and next pointers
    Node* current = head;
    Node* prev = NULL, * next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}


// ****************************************************************
// ****************************************************************

// DID No DO Might in future. 
// HONORS / BONUS credit 
// optional unless you're honors
// if not implementing, just leave it her


//Linear Search cause its easier but have to code the author sort

/// <summary>
using namespace std;
/// </summary>
void Library::sortByAuthor()
{

    //linear search
    string author;

    cout << "What book title would you like to search? ";
    cin.ignore();
    getline(cin, author);

    Node* searcher = head;
    int index = 0;
    while (true) {
        if (searcher->author == author) {
            cout << "Found at Index " << index << endl;
            break;
        }
        if (searcher->next == nullptr) {
            cout << "404 Not found" << endl;
            break;
        }
        index++;
        searcher = searcher -> next;
        


    }
}

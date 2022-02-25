#include <bits/stdc++.h>

using namespace std;

// struct Car{
//     string model;
//     string maker;
//     string 

// };

class Node {
    public:
        int data;
  
  Node *next;
};

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"The given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data){
    /* 1. allocate node */
    Node* new_node = new Node();

    Node *last = *head_ref; /* used in step 5*/
 
    // |Data: n | Next: ?|
    /* 2. setting the data for the new node */
    new_node->data = new_data;

    // |Data: n | Next: NULL|
    /* 3. Since this is going to be the tail, ei the end, the next node would be NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node. Traverse will be taxxing on cpu*/
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;


}

void print_list(Node * n) {

    //cout << "          v HEAD v" << endl;
    while (n != NULL) {
        //cout << "|Data: " << n->data << "|Node: " << n << "| Next: ";
        cout << "|Data: " << n->data << "|";


        if(n->next == NULL)
            cout << "NULL";
        else
            //cout << n->next;

        cout << "\n";

        n = n->next;
    }
    //cout << "                                   ^ TAIL ^" << endl;
    cout << endl;
}

/* Given a reference (pointer to pointer)
to the head of a list and an int,
inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    // cout << "*head_ref: " << *head_ref << endl;
    // cout << "*new_node: " << new_node << endl;
    *head_ref = new_node;
}
 
// This code is contributed by rathbhupendra

int main(int argc, char *argv[]){

    Node * head = NULL;
    int num;

	ifstream infile;                                
	infile.open(argv[1]);					
	if (!infile) {cout << "input.txt did not open"; exit(-1);} 												 // exits out
	infile >> num;                                  // takes the first word of the input and puts it in 'word' temperally
	while (infile) {                                 // loop until hit the end of line, i.e. hits the '\o' it will get out of the loop
        push(&head, num);
		infile >> num;              
	}
	infile.close();                   // after we are done with the input text, we close the file. The program will close it after its done, but its good practice.
					
    insertAfter(head->next, 8);
    //push(&head, 7);


    // Node * second = NULL;
    // Node * third = NULL;

    // head = new Node();
    // second = new Node();
    // third = new Node();

    // head->data = 1;
    // head->next = second;

    // second->data = 2;
    // second->next = third;

    // third->data = 3;
    // third->next = NULL;

    print_list(head);

}
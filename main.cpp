
// C++ program to delete a node in
// singly linked list recursively
 
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int info;
    node* link = NULL;
    node() {}
    node(int a) : info(a) {}
};
 
 int list_size = 0;

 void print(node * n) {

    int index = 0;
    while (n != NULL) {
        cout << "|Data: " << n->info << "|Node: " << n << "| Next: ";
        //cout << setw(3) << index++ << "=|Data:" << setw(3) <<n->info << "|";


        if(n->link == NULL)
            cout << "NULL";
        else
            cout << n->link;

        cout << "\n";

        n = n->link;
    }
    cout << endl;
}

/* Function to swap data of two nodes a and b*/
node* swap2(node* a, node* b){
   
    node* tmp = b->link;
    b->link = a;
    a->link = tmp;
    return b;
}

/* Function to bubble sort the given linked list */
int bubbleSort(node** head){

 
    bool isSwapped = false;

    for(int i = 0; i <= list_size; i++){ //pass and there is a hard limit of list_size
        node** h = head; //resets the head
        isSwapped = false;
        
        for(int j = 0; j < list_size - i - 1; j++){
            
            node *p1 = *h;
            node *p2 = p1->link;

           
            if(p1->info > p2->info){
               
                *h = swap2(p1,p2);
                isSwapped = true;
            }
        
            
            h = &(*h)->link;
        }


        if( !isSwapped )  //we went through the linked list without swapping, no lets stop
            break;

    }

}
  

/*
Deletes the node containing 'info' part as val and
alter the head of the linked list (recursive method)
*/
void deleteNode(node*& head, int val)
{
    //checks if the list is empty or we are already went through the list
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // If Found, we delete 
    if (head->info == val) {
        node* t = head;
        head = head->link; // If it's start of the node head
                           // node points to second node
        delete (t); // Else changes previous node's link to
                    // current node's link
        return;
    }
    //else keep searching
    deleteNode(head->link, val);
}
 
// Utility function to add a
// node in the linked list
// Here we are passing head by
// reference thus no need to
// return it to the main function
void push(node*& head, int data)
{
    node* newNode = new node(data);
    newNode->link = head;
    head = newNode;
}
 

// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position
void deletePosNode(node** head_ref, int position)
{
 
    // If linked list is empty
    if (*head_ref == NULL)
        return;
 
    // Store head node
    node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0) {
 
        // Change head
        *head_ref = temp->link;
 
        // Free old head
        free(temp);
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->link;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->link == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    node* next = temp->link->link;
 
    // Unlink the node from linked list
    free(temp->link); // Free memory
 
    // Unlink the deleted node from list
    temp->link = next;
}

void enterFile(char *file, node*& head_ref){

    int num;
	ifstream infile;  

	infile.open(file);					
	if (!infile) {cout << file << " did not open!" << endl; exit(-1);}
	
    while (infile >> num){
        list_size++;
        push(head_ref, num);
        if(list_size == 10)
            break;
    }
	infile.close();                   // after we are done with the input text, we close the file. The program will close it after its done, but its good practice

}

int main(int argc, char *argv[]){

    node * head = NULL;

    enterFile(argv[1], head);
    print(head);
    bubbleSort(&head);
    print(head);


    return 0;
}
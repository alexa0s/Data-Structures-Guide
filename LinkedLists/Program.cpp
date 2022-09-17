//Information from: https://www.youtube.com/watch?v=B31LgI4Y4DQ&t=8444s&ab_channel=freeCodeCamp.org
//Created by Alexa Arreola | gitHub: @alexa0s
#include <iostream>
using namespace std;

//Data structure Node, stores int and pointer to Node
struct Node{
    int data;
    Node* next;
};

Node* head; //global variable, points to the beginning of the list

//Only inserts at the beginning
void Insert(int x){
    Node* temp = new Node(); //create new node
    temp -> data = x; //asign data value to the new node
    temp -> next = head; //new Node points to previous first value of linked list
    head = temp; //the new node is now the first node
}

//Inserts at n position
void Insert(int x, int n){
    Node* temp1 = new Node(); //new node
    temp1->data = x;
    temp1->next = nullptr;
    if (n ==1){
        temp1->next = head; //new node points to previous first value
        head = temp1; //first value is now new node
        return;
    }

    Node* temp2 = head; //pointer to node

    //start in 1 because we are at head, n-1 because we want to end 1 before
    for(int i = 1; i < n-1 ; i++){
        temp2 = temp2->next; //goes to next node
    }
    //now temp2 is in position n-1

    temp1->next = temp2->next; //next node of new node is next of temp2
    temp2->next = temp1; //temp2 points to new node
}

//Inserts at the end
void InsertLast(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;

    if(head == nullptr){
        head = temp;
        return;
    }

    Node* temp2 = head;

    while(temp2->next != nullptr){
        temp2 = temp2->next;
    }
    temp2->next = temp;

}

//Delets nth node, only valid values
void Delete(int n){
    Node* temp1 = head; //points to 1st element

    if(n ==1){
        head = head->next; //goes to next node
        delete(temp1); //free memory heap
        return;
    }

    //start in head so i = 1
    for(int i = 1; i < n-1 ; i++){
        temp1 = temp1->next;
    }
    //Now temp1 is in position n-1

    Node* temp2 = temp1->next; //tmep2 stores position of node I want to delete
    temp1->next = temp1->next->next; //updates value of temp1
    delete(temp2); //free memory heap
}

//Reverse linked list, return new head
void Reverse(){

    //works for when list is empty and there is only 1 value in the list
    Node *prev, *curr, *next;
    curr = head; //current points to beginning of list
    prev = nullptr; //previous to 1st element of list is null
    while(curr != nullptr){
        next = curr->next; //stores next node
        curr->next = prev; //changes the link of nodes, now points to previous value
        prev = curr; //now our previous value advances to next node
        curr = next; //and also our current variable advances to next node
    }

    head = prev; //curr points to null, so new head is the previous value
}

void PrintRecursive(Node* temp){

    //Return if temp points to null
    if(temp == nullptr){
        cout << endl;
        return;
    }
    cout << temp-> data << " "; //print data
    PrintRecursive(temp->next); //goes to next node
}

void PrintReverseRecursive(Node* temp){
    
    if(temp == nullptr){
        return;
    }
    PrintReverseRecursive(temp->next); //travels the whole list until being in last value
    cout << temp->data << " "; //prints data from last to first
}

void Print(){
    Node* temp = head; //temporal variable to store the first node
    cout << "List> ";

    //prints out the whole list while the temporal variable is not pointing to null
    while(temp != nullptr){
        cout << temp->data <<" "; //prints value
        temp = temp->next; //goes to next node
    }
    cout << endl;
}

int main(){
    
    head = NULL; //list is empty
    
    //TEST FUNCTION> INSERT(int x, int position) 
    /*
    Insert(2,1); //List> 2
    Insert(3,2); //List> 2 3
    Insert(4,1); //List> 4 2 3
    Insert(5,2); //List> 4 5 2 3
    Print();
    */

    //TEST FUNCTION> INSERT(int x) 
    /*
    //only insert at first position
    int num, temp;
    cout << "How many numbers? ";
    cin >> num;
    for(int i = 0; i < num; i++){
        cout << "Type num> ";
        cin >> temp;
        Insert(temp);
        Print();
    }*/

     //TEST FUNCTION> INSERTLAST(int x), DELETE(int n) and REVERSE()
    /*
    int n;
    InsertLast(2);
    InsertLast(4);
    InsertLast(5);
    InsertLast(6); //List> 2, 4, 5, 6
    Print();
    cout << "Enter a position> ";
    cin >> n;
    Delete(n);
    Print();

    cout<<"Reverse ";
    Reverse();
    Print();
    */

    InsertLast(2);
    InsertLast(4);
    InsertLast(6);
    InsertLast(5);
    PrintRecursive(head);
    PrintReverseRecursive(head);

    //Print iterative is more efficient, only uses a tempory variable, but in recursive we use space in stack memory


    return 0;
}
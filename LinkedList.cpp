#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* next;

    Node(int value){
        val=value;
        next=NULL;
    }
} ;

Node* head;

int length() {
    int c = 0;
    Node *temp = head;
    while(temp != NULL) {
        ++c;
        temp = temp->next;
    }
    return c;
}

void insertAtTheEnd(int x) {
    Node *newNode = new Node(x);
    if(head == NULL) {
        head=newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp=temp->next;
    }
    temp->next = newNode;
}

void insertAtTheBegining(int x) {
    Node *newNode = new Node(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int pos, int x) {
    int len = length();
    if(pos < 1 or pos > len+1) {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1) {
        insertAtTheBegining(x);
        return;
    }

    if(pos == len+1) {
        insertAtTheEnd(x);
        return;
    }

    Node *newNode = new Node(x);
    Node *temp1 = head;
    for(int i=2;i<pos;i++) {
        temp1 = temp1->next;
    }    
    Node *temp2 = temp1->next;

    newNode->next = temp2;
    temp1->next = newNode;
}

void deleteFromBegining() {
    if(head == NULL) {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete(temp);
}

void deleteFromEnd() {
    if(head == NULL) {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    if(head->next == NULL) {
        deleteFromBegining();
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *temp1 = temp->next;
    temp->next = NULL;
    delete(temp1);
}

void deleteAtPosition(int pos) {
    int len = length();
    if(pos < 1 or pos > len) {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(pos == 1) {
        deleteFromBegining();
        return;
    }

    if(pos == len) {
        deleteFromEnd();
        return;
    }

    Node *temp1 = head;
    for(int i=2;i<pos;i++) {
        temp1 = temp1->next;
    }    
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete(temp2);
}

void reverse() {
    Node *current, *previous, *temp;
    temp = head;
    current = head;
    previous = NULL;

    while(current != NULL) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    head = previous;
}

void print() {
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main() {

    head=NULL;
    
    for(int i=1;i<=10;i++) {
        insertAtTheEnd(i);
    }

    // Try All Functions:-
    // insertAtTheBegining(51);
    // insertAtPosition(7, 8);
    // cout<<length()<<endl;
    // reverse();
    // deleteAtPosition(6);
    // deleteFromBegining();
    // deleteFromEnd();

    return 0;
}
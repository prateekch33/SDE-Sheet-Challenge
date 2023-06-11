#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data>second->data) {
        Node<int>* temp=first;
        first=second;
        second=temp;
    }
    Node<int>* ans=first;
    while(first!=NULL and second!=NULL) {
        Node<int>* temp1=NULL;
        while(first!=NULL and first->data<=second->data) {
            temp1=first;
            first=first->next;
        }
        temp1->next=second;
        Node<int>* temp2=first;
        first=second;
        second=temp2;
    }
    return ans;
}

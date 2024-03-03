#include<bits/stdc++.h>
using namespace std;

// link list node
struct LNode{
int data;
LNode* next;
LNode(int data){
this->data = data;
this->next = NULL;
}
};

// binary tree node
struct TNode{
int data;
TNode* left;
TNode* right;
TNode(int data){
this->data = data;
this->left = NULL;
this->right = NULL;
}
};

// function to print nodes in a given linked list
void printList(LNode* node){
while(node != NULL){
cout<<node->data<<" ";
node = node->next;
}
}

void preOrder(TNode* root){
if(root == NULL) return;
cout<<root->data<<" ";
preOrder(root->left);
preOrder(root->right);
}
TNode* sortedListToBSTRecur(vector<int>& vec, int start, int end){
if(start > end) return NULL;
int mid = start + (end-start)/2;
if((end - start)%2 != 0) mid = mid+1;
TNode* root = new TNode(vec[mid]);
root->left = sortedListToBSTRecur(vec, start, mid-1);
root->right = sortedListToBSTRecur(vec, mid+1, end);
return root;
}

TNode* sortedListToBST(LNode* head){
vector<int> vec;
LNode* temp = head;
while(temp != NULL){
vec.push_back(temp->data);
temp = temp->next;
}
return sortedListToBSTRecur(vec, 0, vec.size()-1);
}

int main(){
// Let us create a sorted linked list to test the functions
// Created linked list will be 1->2->3->4->5->6->7
LNode* head = new LNode(1);
head->next = new LNode(2);
head->next->next = new LNode(3);
head->next->next->next = new LNode(4);
head->next->next->next->next = new LNode(5);
head->next->next->next->next->next = new LNode(6);
head->next->next->next->next->next->next = new LNode(7);

cout<<"Given Linked List: "<<endl;
printList(head);
cout<<endl;
// convert list to bst
TNode* root = sortedListToBST(head);
cout<<"Peorder Traversal of constructed BST: "<<endl;
preOrder(root);
return 0;
}

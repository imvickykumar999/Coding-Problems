#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);

};

void mirror(struct Node* node){
    if(node == NULL)
    return;
    else{
        struct Node* temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;

    }
}

void inOrder(struct Node* node){
    if(node==NULL)
    return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);

}

int main(){
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<< "INorder traversal of tree is:\n ";
    inOrder(root);

    mirror(root);

    cout<< "In order traversal of mirror tree is :\n ";
    inOrder(root);
    return 0;
}
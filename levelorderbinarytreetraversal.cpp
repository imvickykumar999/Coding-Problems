#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;

};

void printLevelOrder(Node *root){
    if(root == NULL)
    return;

    queue<Node *> q;
    q.push(root);

    while(q.empty() == false){
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node->right != NULL)
        q.push(node->right);
    }
}
Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left =temp->right = NULL;
    return temp;

}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level order traversal of binary tree is : ";
    printLevelOrder(root);
    return 0;
}
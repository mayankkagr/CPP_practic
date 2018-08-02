#include <iostream>
#include<cstring>
using namespace std;
struct bst_node{
	int  data;
	bst_node *left,*right;
};
bst_node* newNode(int item){
	bst_node * tmpNode =new bst_node;
	tmpNode->data=item;
	tmpNode->left=NULL;
	tmpNode->right=NULL;
	return tmpNode;
}

int inorder(bst_node* root){
	if (root != NULL)
    {
        inorder(root->left);
        cout<< root->data<< "  ";
        inorder(root->right);
    }
}
int preorder(bst_node* root){
	if (root != NULL)
    {
        cout<< root->data<< "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

int postorder(bst_node* root){
	if (root != NULL)
    {
        //cout<< root->data<< "  ";
        postorder(root->left);
        postorder(root->right);
        cout<< root->data<< "  ";
    }
}
bst_node* insertNode(bst_node* root, int item){
//	bst_node* tmpNode=newNode(item);
	if(root == NULL)
		return newNode(item);
	if(root->data > item)
		 root->left = insertNode(root->left,item);
	if(root->data <= item)
		 root->right=insertNode(root->right,item);
	return root;
}
bst_node* search(bst_node* root, int key)
{
    if (root == NULL || root->data == key)
       return root;
    
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
int main() {
	bst_node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    // print inoder traversal of the BST
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
	return 0;
}

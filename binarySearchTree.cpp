#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *root=NULL;

void insert(int item){
	struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->data=item;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
		root=newnode;
	else{
		struct Node*temp=root;
		while(true){
			if(item>temp->data){
				if(temp->right==NULL){
					temp->right=newnode;
					break;
				}
				else
					temp=temp->right;
			}
			else{
				if(temp->left==NULL){
					temp->left=newnode;
					break;
				}
				else
					temp=temp->left;	
			}
		}		
	}
}

struct Node *binarySearch(struct Node *node,int key){
	if(node!=NULL){
		if(key==node->data)
			return node;
		else if(key<node->data)
			return binarySearch(node->left,key);
		else
			return binarySearch(node->right,key);	
	}
	return NULL;
}

void inOrderTraversal(struct Node *node){
	if(root==NULL){
		printf("The tree is empty\n");
	}
	else if(node!=NULL){
		inOrderTraversal(node->left);
		printf("%d\t",node->data);
		inOrderTraversal(node->right);
	}
}

void preOrderTraversal(struct Node *node){
	if(root==NULL)
		printf("The tree is empty\n");
	else if(node!=NULL){
		printf("%d\t",node->data);
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}

void postOrderTraversal(struct Node *node){
	if(root==NULL)
		printf("The tree is empty\t");
	else if(node!=NULL){
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printf("%d\t",node->data);
	}
}

struct Node* findMin(struct Node* node){
	if(node->left==NULL)
		return node;
	else{
		return findMin(node->left);
	}
}

struct Node* findMax(struct Node* node){
	if(node->right==NULL)
		return node;
	else{
		return findMax(node->right);
	}
}

struct Node *deleteNode(struct Node *node, int key) {
    if (node == NULL)
        return node;
    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == NULL) {
            struct Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        struct Node *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int main(){
	inOrderTraversal(root);
	insert(30);
	insert(20);
	insert(40);
	insert(10);
	insert(25);
	insert(35);
	insert(60);
	printf("\nIn Order:\t");
	inOrderTraversal(root);
	printf("\nPre Order:\t");
	preOrderTraversal(root);
	printf("\nPost Order:\t");
	postOrderTraversal(root);
	struct Node* search=binarySearch(root,25);
	printf("\nSearched Node:%d\nSearched Node Data:%d",search,search->data);
	struct Node* min=findMin(root);
	printf("\nMin Node:%d\nMin Node Data:%d",min,min->data);
	struct Node* max=findMax(root);
	printf("\nMax Node:%d\nMax Node Data:%d",max,max->data);
	
		
	deleteNode(root,20);
	
	printf("\nIn Order after deletion:\t");
	inOrderTraversal(root);
	return 0;	
}
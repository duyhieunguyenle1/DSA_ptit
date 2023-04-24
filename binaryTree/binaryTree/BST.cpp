//Binary Search Tree: Insertion
#include<bits/stdc++.h> 
#define MAX 1000
using namespace std;   
struct node { //dinh nghia mot node
    int key; //thanh phan du lieu
    struct node *left;//con tro trai
	struct node *right; //con tro phai
}; 
// tao node roi rac co gia tri item 
node *newNode(int item) {     
    node *temp = new node;
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}    
// Duyet theo thu tu giua 
void inorder( node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        cout<<root->key<<" "; 
        inorder(root->right); 
    } 
}    
// Duyet theo thu tu giua 
void preorder( node *root) { 
    if (root != NULL) { 
    	cout<<root->key<<" ";
        preorder(root->left);          
        preorder(root->right); 
    } 
}    
// Duyet theo thu tu su 
void postorder( node *root) { 
    if (root != NULL) {     	
        postorder(root->left);          
        postorder(root->right); 
        cout<<root->key<<" ";
    } 
}

//them node vao cay tim kiem
node* insert( node* node, int key) { 
    //neu cay rong: node key chinh la goc
    if (node == NULL) return newNode(key);   
    //ney key nho hon goc
    if (key < node->key) 
        //them node sang cay ben trai
		node->left  = insert(node->left, key); 
    else if (key > node->key) //neu key lon hon goc
    	//them node sang cay ben phai
        node->right = insert(node->right, key);      
    /* return the (unchanged) node pointer */
    return node; 
}    
// Test solution 
int main() { 
	int A[MAX], n, T; cin>>T;
	while(T--) {
		cin>>n;struct node *root = NULL;
		cin>>A[0]; root = insert(root, A[0]);
		for(int i=1; i<n; i++) {
			cin>>A[i]; 	insert(root, A[i]);
		}
		postorder(root); cout<<endl;
	}
}

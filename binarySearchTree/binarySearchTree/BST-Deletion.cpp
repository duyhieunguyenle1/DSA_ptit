// Loai node tren cay tim kiem
#include<bits/stdc++.h> 
using namespace std;   
struct node { 
    int key; //thanh phan du lieu
    struct node *left;//con tro trai
	struct node *right; //con tro phai
}; 
  
// Tao node roi rac co gia tri Item 
struct node *newNode(int item) { 
    struct node *temp = new node; 
    temp->key = item; //thiet lap thanh phan du lieu
    temp->left = temp->right = NULL; //thiet lap lien ket
    return temp; 
}   
// Duyet theo thu tu giua
void inorder(struct node *root) { 
    if (root != NULL)  { 
        inorder(root->left); 
        cout<<  root->key; 
        inorder(root->right); 
    } 
} 
  
//them node vao cay tim kiem
struct node* insert(struct node* node, int key) { 
    // neu cay rong
    if (node == NULL) return newNode(key);       
    if (key < node->key) //neu key nho hon goc
        node->left = insert(node->left, key); 
    else //neu cay lon hon goc
        node->right = insert(node->right, key); 
    return node; 
} 
  
// tim node co gia tri nho nhat
struct node * minValueNode(struct node* node) { 
    struct node* current = node; //lay node hien tai  
    // tim node trai cuoi cung
    while (current && current->left != NULL) 
        current = current->left;   
    return current; //day la node nho nhat
} 
  
// loai node va tra ve node goc
struct node* deleteNode(struct node* root, int key) { 
    // neu cay rong
    if (root == NULL) return root;   
    if (key < root->key) //neu key nho hon node goc
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) //neu key lon hon node goc
        root->right = deleteNode(root->right, key);   
    else   { //neu dung la node ket
        // neu cay co mot cay con hoac khong co cay con
        if (root->left == NULL)  { //neu cay khong co cay con trai
            struct node *temp = root->right; //thiet lap lien ket phai
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL)  { //neu cay khong co cay con phai
            struct node *temp = root->left; //thiet lap lien ket trai
            free(root); 
            return temp; 
        }   
        //truong hop co ca hai cay con
        struct node* temp = minValueNode(root->right); //lay node nho nhat          
        root->key = temp->key; //thiet lap key  
        // loai node temp->key
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}   
// Test solution 
int main() { 
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    return 0; 
} 

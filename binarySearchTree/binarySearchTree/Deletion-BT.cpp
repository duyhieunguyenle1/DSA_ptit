// Loai node tren cay
//lay node sau nhat ben phai thay the 
#include <bits/stdc++.h> 
using namespace std;   
struct Node { //dinh nghia node cua cay
    int key; //thanh phan du lieu
    struct Node *left;//con tro cay con trai
	struct Node *right; //con tro cay con phai
};   
// tao node roi rac co gia tri ket
Node* newNode(int key) { 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
};   
// duyet theo thu tu truoc
void inorder( Node* temp) { 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
}   
// ham loai node sau nhat
void deletDeepest( Node* root, Node* d_node) { 
    queue< Node*> q; //tao hang doi q
    q.push(root);   //dua node goc vao queue
    // duet theo muc cho den node cuoi cung
    Node* temp; //tao node trung gian temp
    while (!q.empty()) { //lap khi nao hang doi rong
        temp = q.front(); //lay node dau hang doi
        q.pop(); //loai node dau hang doi
        if (temp == d_node) { //neu temp la d_node
            temp = NULL; //cho temp = NULL
            delete (d_node); //giai phong d_node
            return; 
        } 
        if (temp->right) { //neu temp co node con phai
            if (temp->right == d_node) { //neu node con phai la d_node
                temp->right = NULL; //cho no la NULL
                delete (d_node); //giai phong d_node
                return; 
            } 
            else //neu node con phai khong la d_node
                q.push(temp->right); //dua vao hang doi
        }   
        if (temp->left) { //neu temp co node con trai
            if (temp->left == d_node) { //neu node con trai la d_node
                temp->left = NULL; //cho no la NULL
                delete (d_node); //giai phong d_node
                return; 
            } 
            else //neu node con trai khong la d_node
                q.push(temp->left); //dua vao hang doi
        } 
    } 
}   
// ham loai bo node tren cay
Node* deletion( Node* root, int key) { 
    if (root == NULL) //neu cay rong
        return NULL; //khong co gi de loai      
	if (root->left == NULL && root->right == NULL) { //neu cay co 1 node
        if (root->key == key) //neu root dung la key
            return NULL; //tra lai NULL
        else
            return root; 
    }   
    queue< Node*> q; //tao hang doi q
    q.push(root); //dua node goc vao hang doi  
    Node* temp; //tao node trung gian temp
    Node* key_node = NULL; //tao key_node la NULL  
    // tim node xau nhat la temp va node can loai key_node
    while (!q.empty()) { 
        temp = q.front(); //lay temp trong hang doi
        q.pop(); //loai node trong hang doi  
        if (temp->key == key) //neu temp->key la key
            key_node = temp; //temp chinh la key_node can loai  
        if (temp->left) //neu temp co cay con trai
            q.push(temp->left); //dua no vao hang doi  
        if (temp->right) //neu temp co cay con phai
            q.push(temp->right); //dua no vao hang doi
    }   
    if (key_node != NULL) { //neu tim thay key_node
        int x = temp->key; //lay x = temp->key
        key_node->key = x; //thay the key_node la x
        delete(temp);
        //deletDeepest(root, temp); //loai node sau nhat temp
        
    } 
    return root; 
}   
// test solution 
int main() { 
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8);   
    cout << "Duyet theo thu tu giua: "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Duyet theo thu tu giua: "; 
    inorder(root); 
  
    return 0; 
} 

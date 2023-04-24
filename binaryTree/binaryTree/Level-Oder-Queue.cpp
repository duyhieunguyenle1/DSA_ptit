// Level oder su dung queue
// do phuc tap O(n)
#include <bits/stdc++.h> 
using namespace std;   
// dinh nghia node
struct Node { 
    int data; //thanh phan du lieu
    struct Node *left;//con tro trai
	struct Node *right; //con tro phai
};   
// duyet theo muc
void printLevelOrder(Node *root) { 
    // buoc co so 
    if (root == NULL)  //neu cay rong
		return; //khong co gi de duyet  
    // buoc lap: 
    queue<Node *> q; //tao hang doi q      
    q.push(root); //dua node goc vao hang doi  
    while (q.empty() == false) { //lap trong khi queue khong rong        
        Node *node = q.front(); //lay node dau queue
        cout << node->data << " "; //dua ra thanh phan thong tin
        q.pop(); //loai node khoi hang dou          
        if (node->left != NULL) //neu co cay con trai
            q.push(node->left); //dua vao hang doi          
        if (node->right != NULL) //neu co cay con phai
            q.push(node->right); //dua vao hang doi
    } 
}   
// tao node roi rac  co gia tri data
Node* newNode(int data) { 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}   
// Test solution 
int main() {     
    Node *root = newNode(1); //node goc la 1
    root->left = newNode(2); //node trai cua 1 la 2
    root->right = newNode(3);//node phai cua 1 la 3 
    root->left->left = newNode(4); //node trai cua 2 la 4
    root->left->right = newNode(5); //node phai cua 2 la 5  
    cout << "Phep duyet theo muc: \n"; 
    printLevelOrder(root); 
    return 0; 
} 

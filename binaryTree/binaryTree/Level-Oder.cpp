// Thu tuc de qui duyet theo muc (level oder: BFS)
//do phuc tap la O(n2)
#include <bits/stdc++.h> 
using namespace std;   
//dinh nghia node cua cay
class node {  
    public: 
    int data;  //thanh phan du lieu
    node  *left;//con tro cay con trai
	node  *right;//con tro cay con phai  
};  
// ham tao node roi rac co gia tri data 
node* newNode(int data)  {  
    node* Node = new node(); //cap phat mien nho cho node
    Node->data = data;  //thiet lap thanh phan du lieu
    Node->left = NULL;  //thiet lap lien ket trai
    Node->right = NULL; //thiet lap lien ket phai  
    return(Node);  
}
//tinh toan do cao cua cay
int height(node* node)  {  
    if (node == NULL)  //neu cay rong do cao la 0
        return 0;  
    else  {          
        //tin toan do cao cay con trai
		int lheight = height(node->left);  
		//tin toan do cao cay con phai
        int rheight = height(node->right);    
        // tim do cao cua cay la max(lheight,rheight)
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}      
//duyet theo muc
void printGivenLevel(node* root, int level)  {  
    if (root == NULL)  //neu cay rong
        return;  
    if (level == 1)  //neu muc la 1
        cout << root->data << " ";  
    else if (level > 1) {  //neu muc lon hon 1
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1);  
    }      
}    

// duyet theo muc 
void LevelOrder(node* root)  {  
    int h = height(root);  //lay do cai cay    
    for (int i = 1; i <= h; i++)  //in ra theo tung muc
        printGivenLevel(root, i);  
}  
// Test solution
int main()  {  
    node *root = newNode(1);  //thiet lap goc la 1
    root->left = newNode(2);  //node trai cua 1 la 2
    root->right = newNode(3); //node phai cua 1 la 3 
    root->left->left = newNode(4);  //node trai cua 2 la 4
    root->left->right = newNode(5); //node trai cua 2 la 5  
    cout << "Duyet theo muc: \n";  
    LevelOrder(root);    
    return 0;  
}  

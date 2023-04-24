// xay dung cay tu bieu dien canh
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	struct Node *left;
	struct Node *right;	
	Node(int x){
	    key = x; left = NULL; right = NULL;
	}
};

//duyet theo thu tu giua
void inorder(struct Node* temp){
	if (temp!=NULL) {
		inorder(temp->left);
		cout << temp->key << " ";		
		inorder(temp->right);
	}
} 

Node *BuildTree(void) {	
	map <int, Node *> m;//tao map m
	int n; scanf("%d",&n);//dua vao so node cua cay
	Node *root; //tao cay luc dau la NULL
	struct Node *child;
	while(n--) {
		Node *parent;
		char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr); //nhap vao mot canh
        if (m.find(n1) == m.end()){ //neu tim khong thay n1 trong m 
           parent = new Node(n1);//day la mot node con
           m[n1] = parent; //xac dinh m[n1] chinh la node
           if (root == NULL) //neu root dang la rong
             root = parent; //lay no luon lam goc
        }
        else
           parent = m[n1];//lay node cha parent la m[n1]
        child = new Node(n2);//tao node con moi
        if (lr == 'L') //neu la node con trai
          	parent->left = child;//thiet lap lien ket trai
        else // neu la node con phai
          	parent->right = child;//thiet lap lien ket phai
        m[n2]  = child;//thiet lap node con la n2
    }
    return root;
}
//Test solution
//7: so luong node
//Cac canh cua cay: 10 20 L 20 30 L 30 40 L 30 50 R 40 60 L 60 70 R 70 80 L
int main() {  	
	Node *root = BuildTree();
    inorder(root);cout<<endl;    
}

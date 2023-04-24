// Tinh toan gia tri cay bieu thuc
#include <bits/stdc++.h>  
using namespace std;    
// bieu dien node cho cay bieu thuc
class node  {  
public:  
    string data; //thanh phan thong tin 
    node *left = NULL, *right = NULL;  //con tro trai, phai
    node(string x)  {  //constructor
        data = x;  
    }  
};  
//ham kiem tra xau s co la phep toan hay khong
bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") 
		return true;
    return false;
}
//duyet theo thu tu giua
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
//xay dung cay bieu thuc tu mang s[] gom n xau
node *BuildTree(string s[], int n) {
    int p = 0;//lay phan tu la 0
    node *root = new node(s[p++]);//lay s[0] lam goc
    queue<node *> q;  q.push(root);//dua goc vao hang doi
    while (!q.empty()) {
        node *f = q.front(); q.pop();//lay va loai node dau hang doi
        node *l, *r; //tao hai node trai, phai
        if (isExpression(f->data)) { //neu f la phep toan 
            l = new node(s[p++]);//tao node trai
            r = new node(s[p++]);//tao node phai
            f->left = l; //lien ket f voi node trai
            f->right = r;//lien ket f voi node phai
            q.push(l); //dua l vao hang doi
            q.push(r);//dua r vao hang doi
        }
    } 
    return(root);
} 
//tinh toan gia tri bieu thuc
int evalTree(node* root)  {      
    if (!root)  //neu cay rong
        return 0;    
    // neu node trai va phai deu la cac so  
    if (!root->left && !root->right) {
    	char s[20]; strcpy(s,(root->data).c_str());
    	return atoi(s);  //doi thanh so   
	}         
    // tinh toan cay ben trai 
    int l_val = evalTree(root->left);    
    // tinh toan cay ben phai 
    int r_val = evalTree(root->right);    
    // Check which operator to apply  
    if (root->data=="+")  //neu la phep cong
        return l_val+r_val;    
    if (root->data=="-")  //neu la phep tru
        return l_val-r_val;    
    if (root->data=="*")  //neu la phep nhan
        return l_val*r_val;    
    return l_val/r_val;  //neu la phep chia    
}
//Test solution  
int main(void) {
	int T, n; cin>>T; 
	while(T--){
		cin>>n; string s[n]; //xau bieu thuc theo muc
	    for (int i = 0; i < n; i++) 
			cin >> s[i];
		node *root = BuildTree(s,n);
    	cout<<evalTree(root)<<endl;
    	delete root;		
	}    
}

 

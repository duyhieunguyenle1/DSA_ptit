// Them node theo muc
#include <bits/stdc++.h>
using namespace std;
struct Node {//dinh nghia node tren cay
    int data; //thanh phan du lieu
    struct Node* left;//con tro cay con trai
    struct Node* right;//con tro cay con phai
};
// Tao node roi rac co gia tri val
Node* newNode(int val) {
    Node* temp = new Node;//cap phat mien nho cho node
    temp->data = val;//thiet lap thanh phan du lieu
    temp->left = NULL;//thiet lap lien ket trai
    temp->right = NULL;//thiet lap lien ket phai    
    return temp;
} 
//Duyet theo thu tu truoc
void preOrder(struct Node* node){
  	if (node != NULL) {//neu cay khac rong
  		cout<<node->data<<" ";//dua ra thanh phan du lieu
		preOrder(node->left);//duyet theo thu tu truoc cay con trai				  		
		preOrder(node->right);//duyet theo thu tu truoc cay con phai
	}    
} 
//Duyet theo thu tu giua
void inOrder(struct Node* node){
  	if (node != NULL) {//neu cay khac rong
  		inOrder(node->left);//duyet theo thu tu giua cay con trai
		cout<<node->data<<" ";//dua ra thanh phan du lieu		  		
		inOrder(node->right);//duyet theo thu tu giua cay con phai
	}    
} 
//Duyet theo thu tu sau
void postOrder(struct Node* node){
  	if (node != NULL) {//neu cay khac rong
  		postOrder(node->left);//duyet theo thu sau cay con trai				
		postOrder(node->right);//duyet theo thu sau cay con phai
		cout<<node->data<<" ";//dua ra thanh phan du lieu		  
	}    
} 
//duyet theo muc
void levelOrder(Node* node){
    // buoc co so 
    if (node == NULL)  //neu cay rong
		return; //khong co gi de duyet  
    // buoc lap: 
    queue<Node *> q; //tao hang doi q      
    q.push(node); //dua node goc vao hang doi  
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
// Xay dung lai cay tu bieu dien Level Oder
Node* buildTree(string str) {   
    // neu cay rong hoac khong co node nao 
    if(str.length() == 0 || str[0] == 'N')
            return NULL;    
    // tao vector luu tru cac tu cua string str
    vector<string> ip;    
    istringstream iss(str);//goi iss la doi tuong istringstream
    for(string str; iss >> str; ) //dua tung tu vao vector
        ip.push_back(str);        
    // tao node goc cua cay la phan tu dau tien cua vector
    char s[20]; strcpy(s,ip[0].c_str());
    Node* root = newNode(atoi(s));        
    // dua node goc vao hang doi
    queue<Node*> queue;
    queue.push(root);        
    // bat dau tu muc so 2
    int i = 1;
    while(!queue.empty() && i < ip.size()) {            
        // lay node hien tai va dua r khoi hang doi
        Node* currNode = queue.front();queue.pop();
        // nhan gia tri hien tai tu vector ip
        string currVal = ip[i];            
        // neu node hien tai co cay con trai
        if(currVal != "N") {                            
            //doi currVal thanh char []//doi currVal thanh char []
            strcpy(s,currVal.c_str());
            // thiet lap lien ket trai cho node hien tai
            currNode->left = newNode(atoi(s));                
            // dua node vao hang doi
            queue.push(currNode->left);
        }            
        // doi voi node con ben phai
        i++;//nho phai tang i
        if(i >= ip.size()) //neu i vuot qua size()
            break;//khong con node de them
        currVal = ip[i];//lay gia tri node con phai                    
        // neu node con phai khong la NULL
        if(currVal != "N") {                
            // tao lien ket cho node phai
            strcpy(s, currVal.c_str());
            currNode->right = newNode(atoi(s));                
            // dua no vao hang doi
            queue.push(currNode->right);
        }
        i++;
    }    
    return root;
} 

// ham loai node sau nhat tren cay
void deletDeepest(Node* root, Node* d_node) { 
    queue<Node*> q; //tao hang doi q
    q.push(root); //dua node goc vao hang doi  
    // lap theo muc neu q khac rong
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); q.pop(); //lay temp ra khoi hang doi
        if (temp == d_node) { //neu temp la node can loai
            temp = NULL; //cho temp la NULL
            delete (d_node); //giai phong d_node
            return; //xong
        } 
        if (temp->right) {//neu temp co cay con phai 
            if (temp->right == d_node) { //neu node con phai cua temp la d-node
                temp->right = NULL; //cho lai no la NULL
                delete (d_node); //giai phong d-node
                return; //xong
            } 
            else //neu node con phai khong la d_node
                q.push(temp->right); //dua node vao hang doi
        }   
        if (temp->left) { //neu temp co node con trai
            if (temp->left == d_node) { //neu node con trai la d_node
                temp->left = NULL; //cho nola NULL
                delete (d_node); //loai d_node
                return; //xong
            } 
            else //neu node co trai khong la d-node
                q.push(temp->left); //dua node vao hang doi
        } 
    } 
}   
// Ham loai node khoi cay
Node* deletion(Node* root, int key) { 
    if (root == NULL) //neu cay rong
        return NULL; //khong co gi de loai
	//neu cay co moi mot node	  
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == key) //node loai bo dung la key
            return NULL; //loai luon
        else
            return root; //khong loai duoc
    }   
    queue< Node*> q; //tao hang doi q
    q.push(root); //dua node goc vao hang doi  
    Node* temp; 
    Node* key_node = NULL;   
    // lap theo muc tren cay de tim temp la node sau nhat
    // va node bi loai bo la key_node 
    while (!q.empty()) { 
        temp = q.front(); q.pop(); //lay temp ra khoi hang doi  
        if (temp->data == key) //neu temp dung la key
            key_node = temp; //node loai bo la temp  
        if (temp->left) //neu temp co node con trai
            q.push(temp->left); //dua node vao hang doi  
        if (temp->right) //neu temp co node con phai
            q.push(temp->right); //dua no vao hang doi
    }   
    if (key_node != NULL) { //neu ton tai key_node
        int x = temp->data; //x la gia tri can thay the
        deletDeepest(root, temp); //loai node sau nhat
        key_node->data = x; //thay the noi dung cua key_node
    } 
    return root; 
} 
// test solution
int main() {
  	string s = "10 20 30";
  	Node *roof = buildTree(s);  	
  	cout<<"Pre oder truoc khi loai node: 10 \n";
  	cout<<"preOder:"; preOrder(roof);cout<<endl;
  	cout<<"Ket qua sau khi loai node: 10 \n";
  	deletion(roof,10);  	
  	cout<<"preOder:"; preOrder(roof);cout<<endl;  	  	  	
}
 

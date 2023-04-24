#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;

// khoi tao node
node createNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// them cac phan tu vao vi tri cuoi cua node
void addNode(node &a,int x){
    if(a==NULL){
        a=createNode(x); 
        return ;
    }
    node tmp = a;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=createNode(x);
}

int main(){
    int n; cin>>n;
    // khoi tao node trong
    node a = NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        addNode(a,x);
    }
    int k; cin>>k;
    while(a!=NULL){
        if(a->data!=k){
            cout<<a->data<<" ";
        }
        a=a->next;
    }
    return 0;
}
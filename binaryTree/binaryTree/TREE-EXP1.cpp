// Cay bieu thuc: bieu thuc hau to 
#include<bits/stdc++.h> 
using namespace std; 
// bieu dien node cua cay bieu thuc
struct et { 
    char value; //gia tri node
    et* left, *right; //con tro trai, phai
};   
// Ham kiem tra c co phai la phep toan hay khong
bool isOperator(char c) { 
    if (c == '+'||c == '-'||c == '*'||c == '/'||c =='^') 
        return true; 
    return false; 
}   
// duyet theo thu tu giua
void inorder(et *t) { 
    if(t) { 
        inorder(t->left); 
        printf("%c ", t->value); 
        inorder(t->right); 
    } 
}   
// tao node roi rac co gia tri v
et* newNode(int v) { 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
};   
// tra lai goc cay bieu thuc duoc xay dung tu bieu thuc hau to
et* constructTree(char postfix[]) { 
    stack<et *> st; //tao stack voi con tro node
    et *t, *t1, *t2;   
    // duyet tren bieu thuc hau to
    for (int i=0; i<strlen(postfix); i++) { //"ab+ef*g*-"
        // neu la toan hang dua vao stach
        if (!isOperator(postfix[i])) { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // neu la phep toan 
        { 
            t = newNode(postfix[i]); //tao node t  
            // lay hai node tiep theo
            t1 = st.top(); st.pop();                     
            t2 = st.top(); st.pop();   
            //  tao thanh hai node con cua t 
            t->right = t1; 
            t->left = t2;   
            // dua bieu thuc con nay vao stack 
            st.push(t); 
        } 
    }   
    //  phan tu duy nhat con lai la goc cay bieu thuc
    t = st.top(); 
    st.pop();   
    return t; 
}   
// tra lai goc cay bieu thuc duoc xay dung tu bieu thuc hau to
string Tree(char postfix[]) { 
    stack < string> st; //tao stack 
    string t="", t1, t2;    
    // duyet tren bieu thuc hau to
    for (int i=0; i<strlen(postfix); i++) { //"ab+ef*g*-"
        t="";// lay string t la rong		
        if (!isOperator(postfix[i])) {//neu la toan hang dua vao stack
            t = t+ postfix[i]; //noi t them voi toan hang
            st.push(t); //dua t vao stack
        } 
        else  { // neu la phep toan
            t = t + postfix[i]; //lay t la phep toan  
            // lay hai node tiep theo
            t1 = st.top(); st.pop();//lay toan hang 1                     
            t2 = st.top(); st.pop();//lay toan hang 2   
            string s = t2 + t + t1;//noi t2 va t1 voi t
            st.push(s); 
        } 
    }   
    //  phan tu duy nhat con lai la goc cay bieu thuc
    t = st.top(); 
    st.pop();   
    return t; 
}   

// Test solution 
int main() { 
    char postfix[] = "ab+ef*g*-"; 
    cout<<Tree(postfix)<<endl;
    return 0; 
} 

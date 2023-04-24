#include<bits/stdc++.h> 
using namespace std;   
//tra lai thu tu uu tien cac phep toan
int Priority(char c) { 
    if(c == '^') //neu la phep luy thua
    	return 3; //muc do uu tien la 3
    else if(c == '*' || c == '/') //phep nhan hoac chia
    	return 2; //muc do uu tien la 2
    else if(c == '+' || c == '-') //phep cong hoac tru
    	return 1; //muc do uu tien la 1
    else //cac phep con lai
    	return -1; //muc do la 0
}   
//ham chuyen trung to ve hau to
void Solution(string exp) { 
    stack<char> st;     
    int l = exp.length(); //lay do dai xau exp
    string Result; //xau luu toan hang
    for(int i = 0; i < l; i++)  {         
        char x = exp[i];//dat x la exp[i]
        if((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z')) 
        	Result = Result + x; //dua x vao xau ket qua 
        else if(x == '(') //neu x la '('          
        	st.push(x); //dua x vao ngan xep
        else if(x == ')') { //neu x la ')'
            //lap den khi gap  '('
			while(!st.empty() && st.top() != '(') { 
                char c = st.top(); //lay phep toan
                st.pop(); //dua ra khoi ngan xep
               	Result = Result + c; //them vao xau ket qua
            } 
            if(st.top() == '(')  {//neu gap '(' 
                char c = st.top(); //lay '('
                st.pop(); //loai ra khoi stack
            } 
        }                   
        else { //neu gap phep toan
            //lap den khi muc do uu tien cua s[i]>st.top()
			while(!st.empty() && Priority(x) <= Priority(st.top())) { 
                char c = st.top(); //lay phep toan dau ngan xep
                st.pop();//loai c ra khoi ngan xep
                Result = Result + c; //cong them vao ket qua
            } 
            st.push(x); //dua vao ngan xep
        }   
    } 
    //dua tat ca phep toan con lai vao Result
    while(!st.empty()) { 
        char c = st.top(); 
        st.pop(); 
        Result = Result + c; 
    }       
    cout << Result << endl;   
}   
//Test Solution 
int main() { 
    int T; string exp; cin>>T;
    while(T--){
    	cin>>exp;Solution(exp);
	}
}

// Chuyen doi bieu thuc hau to ve tien to
#include <iostream>
#include <stack>
using namespace std; 
// Ham kiem tra x la phep toan hay khong
bool isOperator(char x) {
  	switch (x) {
  		case '+':
  		case '-':
  		case '/':
  		case '*':
    		return true;
  	}
  	return false;
} 
// Ham chuyen doi bieu thuc hau to thanh tien to
string postToPre(string post_exp) {
  	stack<string> s; //Khoi tao stack thinh nghi voi tuy bien string  	
  	int length = post_exp.size();//lay do dai bieu thuc hau to 
  	for (int i = 0; i < length; i++) { //duyet tu phai sang trai 
    	char x = post_exp[i]; // lay x la phan tu thu i
    	if (isOperator(post_exp[i])) { //neu x la phep toan 
    		//lay 2 toan hang ra khoi stack
    		string op1 = s.top();s.pop();//lay toan hang 1
    		string op2 = s.top();s.pop();//Lay toan hang 2 
    		// noi phep toan vao truoc op2+op1
    		string temp = post_exp[i] + op2 + op1;       
    		s.push(temp);//Dua nguoc tro lai stack
    	}     
    	else { //neu x la toan hang 	    
      		s.push(string(1, x));//dua vao stack duoi dang string
    	}
  	}	 
  	// stack[0] chua dung bieu thuc tien to
  	return s.top();
} 
// Chuong trinh chinh
int main() {
  	string post_exp = "ABC/-AK/L-*";
  	cout << "Prefix : " << postToPre(post_exp);  	
}

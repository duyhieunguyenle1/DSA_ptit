// Chuyen doi bieu thuc tien to ve hau to
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
// Chuyen doi bieu thuc tien to thanh hau to
string preToPost(string pre_exp) { 
  	stack<string> s;//stack thich nghi voi tuy bien string 
    int length = pre_exp.size();//lay do dai bieu thuc tien to   	
  	for (int i = length - 1; i >= 0; i--) {//duyet tu trai sang phai 
    	char x = pre_exp[i]; //x la phan tu thu i
    	if (isOperator(x)) {//neu x la phep toan 
      		// lay 2 toan hang ra khoi stack
      		string op1 = s.top(); s.pop();//lay toan hang 1
      		string op2 = s.top(); s.pop();//lay toan hang 2       		
      		string temp = op1 + op2 + x; // noi phep toan vao sau      		
      		s.push(temp);//dua nguoc temp tro lai stack
    	}     	
    	else { //neu x la toan hang       		
      		s.push(string(1, x));//dua x vao duoi dang string
    	}
  	} 
    return s.top();//day la bieu thuc hau to
} 
// Chuong trinh chinh
int main() {
  	string pre_exp = "*-A/BC-/AKL";
  	cout << "Postfix : " << preToPost(pre_exp);  	
}

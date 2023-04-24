// Chuyen doi bieu thuc hau to thanh trung to
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
 
// Chuyen doi tien to thanh trung to
string preToInfix(string pre_exp) {
  	stack<string> s;//tao lap mot stack string   
  	int length = pre_exp.size();//lay do dai bieu thuc hau to 
  	for (int i = length - 1; i >= 0; i--) { //duyet tu phai qua trai 
    	char x = pre_exp[i]; //lay x la phan tu thu i
    	if (isOperator(x)) { //neu x la phep toan 
      		// lay hai toan hang ra khoi stack
      		string op1 = s.top();   s.pop();//lay toan hang 1
      		string op2 = s.top();   s.pop();//lay toan hang 2 
      		// bo sung ky tu '(', ')'
      		string temp = "(" + op1 + pre_exp[i] + op2 + ")";       
      		s.push(temp);//dua temp nguoc tro lai stack
    	}     	
    	else { //neu x la toan hang 
      		s.push(string(1, pre_exp[i]));//dua vao stack voi kieu string
    	}
  	} 
  	// Day la bieu thuc trung to
  	return s.top();
} 
// Chuong trinh chinh
int main() {
  	string pre_exp = "*-A/BC-/AKL";
  	cout << "Infix : " << preToInfix(pre_exp);  	
}

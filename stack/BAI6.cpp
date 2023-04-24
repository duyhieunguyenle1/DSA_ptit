// Dich chuyen bieu thuc hau to thanh trung to
#include <bits/stdc++.h>
using namespace std; 
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
string postToInfix(string exp){
    stack<string> s; 
    for (int i=0; exp[i]!='\0'; i++)    {
        char x = exp[i]; // x la phan tu thu i
        if (!isOperator(x)) { //Neu x la toan hang
           string temp(1, x);s.push(temp); //Dua toan hang vao ngan xep 
    	}         
        else { //neu x la phep toan
            string op1 = s.top(); s.pop();//lay toan hang 1 
            string op2 = s.top(); s.pop();//lay toan hang 2
            s.push("(" + op2 + x +op1 + ")");//noi them voi '(',')'
        }
    }        
    return s.top();//phan tu con lai
}
//Chuong trinh chinh
int main(){
    string exp = "ab*c+";
    cout << postToInfix(exp);    
}

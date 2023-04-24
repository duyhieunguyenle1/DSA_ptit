#include <bits/stdc++.h> 
using namespace std;
void Solution(string exp, int n){
    int left = 1;//lay chi so luc dau left la 1
    stack<int> right;//tao stack voi tuy bien int
    for (int i = 0; i < n; i++) {//duyet tu trai qua phai exp[i]
        if (exp[i] == '(') { //neu gap '('
            cout << left << " ";//thu tu cua no la left
            right.push(left);//dua gia tri left vao ngan xep right
            left++;//thu tu cua '(' tiep theo
        }
        else if(exp[i] == ')') {//neu gap ')'
            cout << right.top() << " ";//gia tri ung voi '(' la left truoc do
            right.pop();//loai phan tu khoi stack right
        }
    }
}
int main(){
    string exp = "(a+(b*c))+(d/e)";
    int n = exp.size();     
    Solution(exp, n);
}

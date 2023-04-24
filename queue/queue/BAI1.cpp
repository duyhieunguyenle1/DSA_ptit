// Tim tong binh phuong nho nhat
// sau khi loai k ky tu
#include <bits/stdc++.h>
using namespace std; 
const int MAX_CHAR = 26;
int minStringValue(string str, int k) {
    int l = str.length(); // lay do dai str 
    if (k >= l) //neu k lon hon do dai str
        return 0; //ket qua se la 0
    // Luu so lan xuat hien moi ky tu vao F[]    
    int F[MAX_CHAR] = {0};
    for (int i=0; i<l; i++)
        F[str[i]-'a']++;
    priority_queue<int> q;//tao mot hang doi uu tien
    for (int i=0; i<MAX_CHAR; i++) //dua so lan xuat hien vao HDUT
        q.push(F[i]);
    // Tien hanh loai k ky tu
    while (k--) {        
        int temp = q.top(); q.pop();//loai phan tu dau hang doi uu tien
        temp = temp-1;//giam so lan xuat hien di 1
        q.push(temp); //dua lai hang doi uu tien
    } 
    // tinh toan gia tri string sau khi bo k ky tu
    int result = 0; // Khoi tao gia tri 0
    while (!q.empty()) {
        int temp = q.top();//lay so lan xuat hien moi ky tu
        result += temp*temp;//lay binh phuong 
        q.pop();
    } 
    return result;
}
// Driver Code
int main(){
	int T, k; cin>>T;
	while(T--){
		string str;
		cin>>str; cin>>k;
		cout << minStringValue(str, k) << endl;	
	}
}


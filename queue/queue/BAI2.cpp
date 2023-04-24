// Sinh ra so nhi phan tu 1 den n
#include <iostream>
#include <queue>
using namespace std;
void Result(int n) {    
    queue<string> q;//tao hang doi q 
    q.push("1");//1 la so dau tien
    while (n--) { //lap khi n khac 0        
        string s1 = q.front(); q.pop();//loai phan tu dau queue
        cout << s1 << " "; //dua ra s1 
        string s2 = s1;  // Luu s1 truoc khi thay doi
        q.push(s1.append("0"));//them 0 vao sau s1         
        q.push(s2.append("1"));//them 1 vao sau s2
    }
} 
int main(void) {
    int n, T; cin>>T;
    while(T--){
    	cin>>n;Result(n);cout<<endl;
	}
}


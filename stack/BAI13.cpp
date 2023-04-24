// Tim hinh chu nhat co dien tich lon nhat
// trong bieu do
#include<iostream>
#include<stack>
using namespace std; 
// H[]: mang luu do cao cac bars 
// n la so bars
int getMaxArea(int H[], int n){
    // tao stack luu tru vi tri cua H[] 
    // bars luu tru trong stack luon tang dan theo chieu cao    
    stack<int> s; 
    int max_area = 0; // Initalize max area
    int tp;  // tp dinh cua stack
    int area_top; // de luu dien tich bar dau tien 
                       // cung la bar co dien tich nho nhat
    // duyet tat ca cac bar cua luoc do
    int i = 0;//int H[] = {6, 2, 5, 4, 5, 1, 6};
    while (i < n) {
        // If stack rong hoac H[i]>=H[s.top() thi dua vao stack        
        if (s.empty() || H[s.top()] <= H[i]) {
        	s.push(i); 
			//cout<<"i="<<i<<endl; cin.get();
			i++;
		}             
        else  {        	
            tp = s.top();  // chi so bar o dau stack
            s.pop();  // dua ra khoi stack 
            // Calculate the area with H[tp] stack 
            // as smallest bar
            if(s.empty()) {
            	area_top = H[tp]*i;	
            	cout<<"IF Area_top="<<area_top<<endl; cin.get(); 
			}
            else {            	
            	area_top = H[tp]*(i - s.top() - 1);	            	
            	cout<<"ELSE Area_top="<<area_top<<endl; cin.get();
			}          	 
            if (max_area < area_top)
                max_area = area_top;
        } 
        //cout<<"Max="<<max_area<<endl; cin.get();
    }
    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        if(s.empty()) area_top = H[tp] * i;
		else area_top = H[tp] * (i - s.top() - 1); 
        if (max_area < area_top)
            max_area = area_top;
    } 
    return max_area;
} 
// Driver program to test above function
int main() {
    int H[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(H)/sizeof(H[0]);
    cout << "Maximum area is " << getMaxArea(H, n);
    return 0;
}

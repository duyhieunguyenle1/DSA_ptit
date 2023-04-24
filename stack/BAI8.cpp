// Tinh toan gia tri bieu thuc hau to 
#include <bits/stdc++.h> 
using namespace std;   
int Evaluation( char exp[]) {
	stack <int> st;int i, n = strlen(exp);	
	for(i=0; i<n; i++){				
		if(exp[i]==' ') continue;
		else if(isdigit(exp[i])) {
			int num=0; //lay gia tri so
			while(isdigit(exp[i])) {  
            	num = num * 10 + (int)(exp[i] - '0');  
                i++;  
            }  
            i--;  //lui i lai mot vi tri                           
            //cout<<num<<endl;
            st.push(num); //dua so vao stack
		}
		else { 
			int val1 = st.top(); st.pop();
			int val2 = st.top(); st.pop();
			cout<<val1<<" "<<val2<<endl;
			switch(exp[i]) {
				case '+': st.push(val2+val1);break;
				case '-': st.push(val2-val1);break;
				case '*': st.push(val2*val1);break;
				case '/': st.push(val2/val1);break;
			}
		}
	}
	int val = st.top();st.pop();
	return val;
} 
// Driver code 
int main()  {  
    char exp[] = "100 200 + 2 / 5 * 7 +";  
    cout << Evaluation(exp)<<endl;  
    return 0;  
}  
  

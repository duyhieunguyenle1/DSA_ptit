#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// mã gray sẽ gồm 2 phần 1 phần là gồm các prefix "0" ở đầu
// phần sau là gồm các prefix "1" ở sau
// đầu tiên ta lập dãy gồm toàn các số "0" và "1" ở đầu
// sau đó nếu thỏa mãn số chữ số thì sẽ nhân đôi mảng 
// và thêm "0" vào đầu nửa mảng đầu và "1" vào đầu nửa mảng cuối
// => print ra ta có kết quả

void grayArr(int n){
    vector<string>v;
    v.push_back("0");
    v.push_back("1");

    // 1<<n : 2^n, n<<1 : n*2
    for(int i=2;i<(1<<n);i=i<<1){

        // nhân đôi mảng
        for(int j=i-1;j>=0;j--){
            v.push_back(v[j]);
        }
        // thêm "0" vào đầu nửa mảng đầu
        for(int j=0;j<i;j++){
            v[j]="0"+v[j];
        }
        // thêm "1" vào đầu nửa mảng sau
        for(int j=i;j<2*i;j++){
            v[j]="1"+v[j];
        }
    }

    for(auto x:v)cout<<x<<" ";
    cout<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        grayArr(n);
    }
    return 0;
}

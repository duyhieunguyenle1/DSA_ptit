// C++ program to count all binary digit
// numbers smaller than N
#include <iostream>
#include <queue>
using namespace std;
 
int BinaryNumberLessThanN(int N){
    queue<int> q;//tao mot hang doi voi cac so int
    q.push(1);//So nhi phan nho hon N dau tien la 1
    int dem = 0, t;// 
    while (!q.empty()){//lap den khi hang doi rong
        t = q.front();//lay phan tu dau tien
        q.pop();//loai bo phan tu 
        //  push next binary digit numbers only if
        // current popped element is N
        if (t <= N){//neu t van nho hon N
            dem++;//xac nhan 1 so 
            // uncomment below line to print actual
            // number in sorted order
            cout << t << " "; 
            q.push(t * 10);//dua vao t*10
            q.push(t * 10 + 1);//dua vao t*10 +1
        }
    }
 
    return dem;
}
//    Driver code to test above methods
int main(){
    int N = 2000;
    cout << BinaryNumberLessThanN(N);
    return 0;
}

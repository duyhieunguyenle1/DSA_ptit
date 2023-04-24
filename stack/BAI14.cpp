// Giai ma xau
#include<bits/stdc++.h>
using namespace std;
string decode(string str) {
    stack<int> INT;//tao stack luu tru so
    stack<char> STR; //tao stack luu ky tu
    string temp = "", result = ""; 
    // duyet tu trai sang phai string input
    for (int i = 0; i < str.length(); i++) {
        int count = 0; 
        // If number, convert it into number
        // and push it into INT.
        if (str[i] >= '0' && str[i] <='9'){ //neu la ky tu so
            while (str[i] >= '0' && str[i] <= '9'){ //chuyen thanh so
                count = count * 10 + str[i] - '0';
                i++;
            } 
            i--;
            INT.push(count);
        }
 
        // If closing bracket ']', pop elemment until
        // '[' opening bracket is not found in the
        // character stack.
        else if (str[i] == ']'){ //
            temp = "";
            count = 0;
 
            if (! INT.empty()){
                count = INT.top();
                INT.pop();
            } 
            while (! STR.empty() && STR.top()!='[' ) {
                temp = STR.top() + temp;
                STR.pop();
            } 
            if (!STR.empty() && STR.top() == '[')
                STR.pop();
 
            // Repeating the popped string 'temo' count
            // number of times.
            for (int j = 0; j < count; j++)
                result = result + temp;
 
            // Push it in the character stack.
            for (int j = 0; j < result.length(); j++)
                STR.push(result[j]);
 
            result = "";
        }
 
        // If '[' opening bracket, push it into character stack.
        else if (str[i] == '[')
        {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                STR.push(str[i]);
 
            else
            {
                STR.push(str[i]);
                INT.push(1);
            }
        }
 
        else
            STR.push(str[i]);
    }
 
    // Pop all the elmenet, make a string and return.
    while (! STR.empty())    {
        result = STR.top() + result;
        STR.pop();
    }
 
    return result;
}
 
// Driven Program
int main()
{
    string str = "3[b2[ca]]";
    cout << decode(str) << endl;
    return 0;
}

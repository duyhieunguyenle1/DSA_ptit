/* C++ Program to check whether valid 
 expression is redundant or not*/
#include <iostream>
#include <stack>
using namespace std;
 
// Function to check redundant brackets in a
// balanced expression
bool checkRedundancy(string str)
{
    // create a stack of characters
    stack<char> st;
 
    // Iterate through the given expression
    char ch; int n=str.length();
    for ( int i=0; i<n; i++) {
 		ch=str[i];
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' || 
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of stack
                top = st.top();
                st.pop();
            }
 
            // If operators not found
            if (flag == true)
                return true;
        }
 
        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
 
// Function to check redundant brackets
void findRedundant(string& str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 
// Driver code
int main()
{
    string str = "((a+b))";
    findRedundant(str);
 
    str = "(a+(b)/c)";
    findRedundant(str);
 
    str = "(a+b*(c-d))";
    findRedundant(str);
 
    return 0;
}

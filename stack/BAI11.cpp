#include<bits/stdc++.h>
using namespace std;
  
void printWords(string str)
{
    // word variable to store word
    string word;
  
    // making a string stream
    stringstream iss(str);
  
    // Read and print each word.
    while (iss >> word){
        reverse(word.begin(),word.end());
        cout<<word<<" ";
    }
}
  
// Driver code
int main()
{
    string s = "Hello World";
    printWords(s);
    return 0;
}
// This code is contributed by Nikhil Rawat


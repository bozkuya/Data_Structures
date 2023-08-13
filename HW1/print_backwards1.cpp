#include <iostream>
using namespace std;
 
// reverse function
void print_backwards(string& str)
{
    int n = str.length();
 
    // change characters
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
// main
int main()
{
	//take input as string
    string y;
    cin>> y;
    string str = y;
    //use string in function
    print_backwards(str);
    //prints the reverse string
    cout << str;
    return 0;
}

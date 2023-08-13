#include <iostream>
#include<stdlib.h>
using namespace std;
 //function to find nth prime number
bool pri(int num)
        {
            int c = 0;
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    c = 1;
                    break;
                }
            }
            if (c == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
 
int main()
{
 
	int n,num=1;
    int y = 0;
    cout<<" Enter a number to find nth prime " ;
    cin>>n;
  
        while (true)
            {
                num++;
                if(pri(num))
                {
                    y++;
                }
                if(y==n)
                {
                    cout<<n<<". prime number is "<<num;
                    break;
               	}
}
	
}

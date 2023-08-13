#include <iostream>
using namespace std;
class disc{
    private:
    	// I decribed discs as integers. So that I can compare which is bigger
   int no_discs = 0;
   int disc1 =1;
   int disc2 =2;
   int disc3 =3;
   int disc4 =4;
   int disc5 =5;
   int disc6 =6;
   int disc7 =7;
   int disc8 =8;
   int disc9 =9;
   int disc10 =10;
   int disc11 =11;
   int disc12 =12;
   int disc13 =13;
   int disc14 =14;
   int disc15 =15;
   int disc16 =16;
   int disc17 =17;
   int disc18 =18;
   int disc19 =19;
   int disc20 =20;
   // Since rods are arrays of 20, there can be maximum f 20 discs.
   
    
    
};
class Hanoi{
    // Hanoi class includes rods which are array of 20 elements
    public:
    int rod0[20];
    int rod1[20];
    int rod2[20];
    int n;
    Hanoi(){
        // initialize the rods 
        cout << "Enter number of discs";
        
        if (n>20){
            cout<<"Number of discs can not be bigger than 20!";
           
        }
        for (int i=0;i<n;i++){
            rod0[i] =i+1;
        };
        for (int i=0;i<20;i++){
        rod1[i] = 0;
        rod2[i] = 0;
        };
    }
};
// move function search which is the top disc
// Then it takes the dics and write its value to given rod
//It deletes the disc from firs rod.
void move (int from, int to,Hanoi *example, int N){
    

    int j =0;
    int k =0;
    if(from == 0){
        
    while((*example).rod0[j] == 0)
    {
        j++;
    }
    if(to == 1){
        
        while ((*example).rod1[k] ==0){
            k++;
           
        }
         (*example).rod1[k] =(*example).rod0[j];
            (*example).rod0[j] = 0;
            
        cout<<"Disc "<<N<<" moved from rod0 to rod1\n";
      
    } else if (to==2){
        while ((*example).rod2[k] ==0){
            k++;
           
        }
         (*example).rod2[k] =(*example).rod0[j];
            (*example).rod0[j] = 0;
            
            
            
        cout<<"Disc "<<N<<" moved from rod0 to rod2\n";

        
    }
    else if(to==0){
          cout<<"Disc "<<N<<" moved from rod0 to rod0\n";
    }
    else{
        cout<<"Move is not legal!";
    }
  
 
    }
    else if(from == 1){
        int j = 0;
    while((*example).rod1[j] == 0)
    {
        j++;
    }
    
    if(to == 0){
        
        while ((*example).rod0[k] ==0){
            k++;
           
        }
         (*example).rod0[k] =(*example).rod1[j];
            (*example).rod1[j] = 0;
            
        cout<<"Disc "<<N<<" moved from rod1 to rod0\n";
      
    } else if (to==2){
        int k = 0;
        while ((*example).rod2[k] ==0){
            k++;
           
        }
         (*example).rod2[k] =(*example).rod1[j];
            (*example).rod0[j] = 0;
            
        cout<<"Disc "<<N<<" moved from rod1 to rod2\n";
        

        
    }
    else if(to==1){
          cout<<"Disc "<<N<<" moved from rod1 to rod1\n";
    }
    else{
        cout<<"Move is not legal!";
    }
  
 
    }
        else if(from == 2){
        
    while((*example).rod2[j] == 0)
    {
        j++;
    }
    
    if(to == 0){
        
        while ((*example).rod0[k] ==0){
            k++;
           
        }
         (*example).rod0[k] =(*example).rod2[j];
            (*example).rod2[j] = 0;
            
        cout<<"Disc "<<N<<" moved from rod2 to rod0\n";
      
    } else if (to==1){
        while ((*example).rod1[k] ==0){
            k++;
           
        }
         (*example).rod1[k] =(*example).rod2[j];
            (*example).rod2[j] = 0;
            
        cout<<"Disc "<<N<<" moved from rod2 to rod1\n";

        
    }
    else if(to==2){
          cout<<"Disc "<<N<<" moved from rod2 to rod2\n";
    }
    else{
        cout<<"Move is not legal!";
    }
  
 
    }
    else{
        cout<<"There are only 3 rods. Move is not legal!";
    }
}
// solver function use move function in recursion to solve the problem
void solve(int N, int from, int to, int aux, Hanoi * example)
{
    if (N == 0) {
        return;
    }
    solve(N - 1, from, aux, to, example);
    move(from, to, example, N);
    //cout << "Move disk " << N << " from rod " << from
     //   << " to rod " << to << endl;
    solve(N - 1, aux, to, from, example);
}
 
int main() {
    Hanoi ex;
    //move(0,1,&ex);
    int N;
    cin>> N;
     solve(N, 0, 1, 2, &ex);
  
    
    return 0;
}

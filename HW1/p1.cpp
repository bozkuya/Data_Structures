
#include <iostream>
using namespace std;


template <int N>
class Matrix
{
private:
 private:

public:
double data[N][N];
 int const SIZE = N;
 Matrix(){
  for (int i=0;i<=SIZE;i++){
     
     for(int j=0;j<=SIZE;j++){
         if (i== j){
             data[i][j] =1;
            }
             else {
                 data[i][j] =0;
             
         }
         
     }
     
 }};
};
int mul(){
    int i,j,r1,r2,c1,c2,k,n;
    int mul[n][n];
    int a[n][n];
    int b[n][n];
    // initilially mul matrix is 0
    for(i = 0; i < r1; i++)
        for(j = 0; j < c2; j++)
        {
            mul[i][j]=0;
        };
    
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            for(k = 0; k < c1; k++)
            {
                mul[i][j] = a[i][k] * b[k][j];
            }
    }};
}

int sum(){
    int N,i,j;
    int sum[N][N];
    int A[N][N];
    int B[N][N];
   for(i = 0; i < N; i++){
        for(j = 0; j < N;j++){
            sum[i][j] = A[i][j] + B[i][j];}}

    
}
int substract(){
    int N,i,j;
    int substract[N][N];
    int A[N][N];
    int B[N][N];
   for(i = 0; i < N; i++){
        for(j = 0; j < N;j++){
            substract[i][j] = A[i][j] - B[i][j];}}

    
}
int main()
{
    Matrix<100> get;
  int row,column;
  cin >> row;
  cin >> column;
 
  cout << get.data[row][column];
   Matrix<100> set;
   int new_value;
  cin >> new_value;
  
  get.data[row][column] = new_value;
  cout << get.data[row][column];
  
}

#include <iostream>
  #include <fstream>
#include <bits/stdc++.h>
#include <list>
 using namespace std;
 /* reading the maze from file */
 ifstream input_file; /* input file stream */
 input_file.open ("input_maze.txt");
 int nrow, ncol; /* number of rows and columns */
 input_file >> nrow >> ncol; /* read the size from file */
 char state[nrow][ncol]; /* CAUTION! actual maze size might be different */
 for(int i=0; i<nrow; ++i){
 for(int j=0; j<ncol; ++j){
 input_file >> state[i][j];
 }
 }
 input_file.close();
 // It checks whether left space is # or . and turns 0 or 1 according to that
int can_move_left(){
if (state[i][j] == 'W'){
    if (state[i+1][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'N'){
    if (state[i][j-1]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'E'){
    if (state[i-1][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'S'){
    if (state[i][j+1]== '#'){
        return 0;}
        else {return 1;}
}


}
// Can move forward function and all other move functions does the same operation
int can_move_forward(){
if (state[i][j] == 'W'){
    if (state[i][j-1]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'N'){
    if (state[i-1][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'E'){
    if (state[i][j+1]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'S'){
    if (state[i+1][j]== '#'){
        return 0;}
        else {return 1;}
}


}
int can_move_right(){
if (state[i][j] == 'W'){
    if (state[i-1][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'N'){
    if (state[i][j+11]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'E'){
    if (state[i+11][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'S'){
    if (state[i][j-1]== '#'){
        return 0;}
        else {return 1;}
}


}

int can_move_back(){
if (state[i][j] == 'W'){
    if (state[i][j+1]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'N'){
    if (state[i+1][j]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'E'){
    if (state[i][j-1]== '#'){
        return 0;}
        else {return 1;}
}
if (state[i][j] == 'S'){
    if (state[i-1][j]== '#'){
        return 0;}
        else {return 1;}
}


}
// move functions check whether it is suitable to move
// If it is suitable, moves by passing one point by using array element increase
// After that it puts "." to previous location
int move_left(){
if (can_move_left(state[i][j]) == 1){

   if (state[i][j] == 'W'){
    state[i][j] = '.';
    state[i+1][j] = 'S';
   }
   else if (state[i][j] == 'E'){
    state[i][j] = '.';
    state[i-1][j] = 'N';
   }
   else if (state[i][j] == 'N'){
    state[i][j] = '.';
    state[i][j-1] = 'W';
   }
   else if (state[i][j] == 'S'){
    state[i][j] = '.';
    state[i][j+1] = 'N';
   }
}

}

int move_right(){
if (can_move_right(state[i][j]) == 1){

   if (state[i][j] == 'W'){
    state[i][j] = '.';
    state[i-1][j] = 'N';
   }
   else if (state[i][j] == 'E'){
    state[i][j] = '.';
    state[i+1][j] = 'S';
   }
   else if (state[i][j] == 'N'){
    state[i][j] = '.';
    state[i][j+1] = 'E';
   }
   else if (state[i][j] == 'S'){
    state[i][j] = '.';
    state[i][j-1] = 'S';
   }
}

}
int move_forward(){
if (can_move_forward(state[i][j]) == 1){

   if (state[i][j] == 'W'){
    state[i][j] = '.';
    state[i][j-1] = 'W';
   }
   else if (state[i][j] == 'E'){
    state[i][j] = '.';
    state[i][j+1] = 'E';
   }
   else if (state[i][j] == 'N'){
    state[i][j] = '.';
    state[i-1][j] = 'N';
   }
   else if (state[i][j] == 'S'){
    state[i][j] = '.';
    state[i+1][j] = 'S';
   }
}

}

int move_back(){
if (can_move_back(state[i][j]) == 1){

   if (state[i][j] == 'W'){
    state[i][j] = '.';
    state[i][j+1] = 'E';
   }
   else if (state[i][j] == 'E'){
    state[i][j] = '.';
    state[i][j-1] = 'W';
   }
   else if (state[i][j] == 'N'){
    state[i][j] = '.';
    state[i+1][j] = 'S';
   }
   else if (state[i][j] == 'S'){
    state[i][j] = '.';
    state[i-1][j] = 'N';
   }
}

}
//function that prints current state is basicly printing the array
int print_state(){for(int a = 0; a < nrow; a++)
  {
    for(int b = 0; b < ncol; b++)
    {
      cout << state[a][b] ;
    }
    cout << endl;
  } }

  // function that checks whether it is solved
  // It finds the finish and checks whether our player is at that point
  int is_solved(){
  for (int a = 0; a < nrow; a++)
    {
    for(int b = 0; b < ncol; b++)
    {
      if (state[a][b]== 'T'){
            if(a ==i && b==j){return 1;}

      }
      else return 0;
    }
  } }
  // template class
  StackQueue<T>
  class T
  private:

  public:
      // I created a list in order to apply push and pop
      std::yasin_list<int> list;
      int value;
  yasin_list.push_front(int value);
    yasin_list.pop_front(int value);
    yasin_list.pop_rear(int value);
    yasin_list.pop_rear(int value);
    void print(std::list<std::string> const &list)
{
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}
// I recall move funtions in order to implement solver
int solver(){
if(can_move_left){
    move_left();
}
else if(can_move_forward()){
    move_forward();
}
else if(can_move_right()){
    move_right();
}
else if(can_move_back()){
    move_back();
}
}
int main(){
return 0;
}
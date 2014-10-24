//queens.cpp
//
//Gabriel Chan
//Helen Chac
//
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

bool check(int row, vector<int> queens);
void place();

int main()
{
  place();

  return 0;

}//main


bool check(int row, vector<int> queens)
{ 
/*
  int i = 0;
  do{  
      if( (queens[i] == queens[k]) || (abs(queens[i] - queens[k]) == abs(i-k)))
       return false;
  

//     return true;



   i++;
  }while(i<k-1);
  return true;
*/

  for (int i = 0; i < row ; i++)
   { 
      if( (queens[i] == queens[row]) || (abs(queens[i] - queens[row]) == abs(i-row)))
        return false;
      if( i == row )
        return true;
   }//for
  return true;
}//check
void place()
{
  int row = 0;
  vector<int> queens(8), temp(8);
  int count = 1;
  while( row < 8)
  {
      while (    (row < 8)  && (check(row, queens)  == false ))
       {
          queens[row] = queens[row]+1;
         // cout << "k: " << k << endl;
         // cout << "queens[k] " << queens[k] << endl;
        }//while
      if (  (row ==7 && (queens[row] < 8) ) )
          {   
             for(row=0; row< 7; row++)
              cout << queens[row]+1 << ",";     
             if(row == 7)
	       cout << queens[7]+1 << endl;
           for ( int i=0; i < 8; i++)
            {
             temp[i] = queens[i];
             queens[i] = 0; 
            }//for
           queens[0] = count;
           count++;
        
   //        count++;
	   row = 0;
  // break;
          } // solution
      else if ( (row<7) && (queens[row] < 8) )
      {
//          cout << queens[row] << endl;
          row++;
          queens[row]= 0;
      }//elif
      else
      {
          row--;
          
          if (row < 0)
            break;
          queens[row] = queens[row]+1;
      }
  }//while

}//place



// Name: Muhammad Fawad Jawaid Malik
// Roll No. 11k - 2116
// Submitted To: Sir Rafi

#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

class PositionOfGrid
{
      public:
      int pos1, pos2;
      
      PositionOfGrid(int i, int j);
};

class MovingInGrid
{
      private:
      queue<PositionOfGrid> Q;        
      int i, j , k, l;
      
      public:
      MovingInGrid(int pos1, int pos2);
      
      PositionOfGrid Right(int p, int q);
     
      PositionOfGrid Up(int p, int q);
      
      bool ReachGoal(int p, int q);
      
      int Calculating_Paths();
      
};

/* Functions Definition */

//Constructor Of PositionOfGrid class
PositionOfGrid::PositionOfGrid(int i, int j)
{
       pos1=i;
       pos2=j;              
}

//Constructor Of MovingInGrid class
MovingInGrid::MovingInGrid(int pos1, int pos2)
{
        k = pos1;
        l = 0;
        i = pos1;
        j = pos2; 
}

//Function to move Right in the Grid
PositionOfGrid MovingInGrid::Right(int p, int q)
{
          return PositionOfGrid(p, ++q);
}

//Function to move Up in the Grid
PositionOfGrid MovingInGrid::Up(int p, int q)
{
         return PositionOfGrid(--p, q);                 
}

//Function to check whether we reach the goal or not
bool MovingInGrid::ReachGoal(int p, int q)
{
         if(p==0 && q==j)
           return true;
              
         return false;   
}

//Function to Calculate Paths to reach the top of the Grid 
int MovingInGrid::Calculating_Paths()
{
          int count = 0;
          k = i;
          l = 0;
          
          if (ReachGoal(k, l))
          {
              count++;                 
          }
          else
          {
              Q.push(PositionOfGrid(k, l));
              
              while(!Q.empty())
              {
                 PositionOfGrid t = Q.front();
                 Q.pop();
                 
                 k = t.pos1; 
                 l = t.pos2;
                 
                 PositionOfGrid R(-1, -1);
                 PositionOfGrid U(-1,-1);
                 
                 if(l == j)
                 {
                      U = Up(k, l);
                 }
                 else if (k == 0)
                 {
                      R = Right(k, l);
                 }
                 else
                 {
                     U = Up(k, l);
                     R = Right(k, l);
                 }
                           
                 if(R.pos1 != -1 && R.pos2 != -1)
                 {
                           if(ReachGoal(R.pos1, R. pos2))
                              count ++;
                           else
                                Q.push(R);
                 }
                 
                 if(U.pos1 != -1 && U.pos2 != -1)
                 {
                           if(ReachGoal(U.pos1, U. pos2))
                              count ++;
                           else
                                Q.push(U);
                 }          
                 
                 
                     
              }
          }
             return count;
}
 
/* MAIN */
int main()
{
    ifstream infile("A1P2in1.txt");
    ofstream outfile("A1P2out1.txt");
    
    int n; 
    int m;
    
    while(infile >> n >> m)
    {
       if(n==0 && m==0) 
         break;
     
       int result =0;
     
       MovingInGrid Raju(n, m);
       result = Raju.Calculating_Paths();
       outfile << result << endl;
       cout << result << endl;
    }    
    
    system("pause");
    return 0;
}

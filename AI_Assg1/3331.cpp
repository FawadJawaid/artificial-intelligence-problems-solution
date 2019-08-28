#include<iostream>
#include<fstream>

using namespace std;

int main()
{
 
 ifstream infile("A1P2in1.txt");
 //ofstream outfile("A1P2out1.txt");
 
 unsigned long int m;
 unsigned long int n;
 
 while(infile >> n >> m)
 {
     if(n==0 && m==0) 
       break;
     
     double val1;
     double val2;
     double result = 1.0;
     
     val1=min(n,m);
     
     val2=n+m;
      
     while(val1 > 0)
     {
       result = result * val2/val1;
       
       val2--;
       val1--;         
     } 
       
     //outfile << result << endl;
     cout << result << endl;            
 }
    
 system("pause");
 return 0;   
}

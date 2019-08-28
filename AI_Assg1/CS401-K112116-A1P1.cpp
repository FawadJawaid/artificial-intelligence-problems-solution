
// Name: Muhammad Fawad Jawaid Malik
// Roll No. 11k - 2116
// Submitted To: Sir Rafi

#include<iostream>
#include<fstream>

using namespace std;

// Function to Swap integers
void Swap(int *i, int *j) 
      {
           int tmp;
           tmp=*i;
           *i=*j;
           *j=tmp;
      }
      
// Function to push all zeros at the end of an array.
void pushZerosToEnd(int arr[], int n)
{
    int counter = 0;  
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[counter++] = arr[i]; 
            
    while (counter < n)
        arr[counter++] = 0;
}      

int main()
{
    ifstream infile("A1P1in1.txt");
    ofstream outfile("A1P1out1.txt");
    
    int myArray[10];
    int Array[10] = {10,5,1,2,6,7,3,4,4,5};
    int sr[10];
    int count = 0;
    int n = 0;
    
	 
     while (! infile.eof() )
     {                   
      for(int i=0; i <= 9; i++)
      {
           infile >> myArray[i]; 
      }
      
      for(int i=0; i<= 9; i++)
      {
         //sr[i]=myArray[i]*Array[i];
         
         //cout<<myArray[i];
         
         if(myArray[i] == 0)
         {
             sr[i] = 0;
         }
         else if(myArray[i] == 1)
         {
             sr[i] = Array[i];
         }
         else if(myArray[i] == 2)
         {
              sr[i] = Array[i] + Array[i];
         }
         else if(myArray[i] == 3)
         {
              sr[i] = Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 4)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 5)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 6)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 7)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 8)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }     
         else if(myArray[i] == 9)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }
         else if(myArray[i] == 10)
         {
              sr[i] = Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i] + Array[i];
         }                   
         
        
          if(sr[i]!=0)
          {    
             n++;
          }
      }
      
      pushZerosToEnd(sr, 10);
      
         int m;
         int result=0;
         int rs[n-1];
         for(int k=0; k <= 9; k++)
         {
          if(sr[k]!=0){
          
          int least;
           for(int i=0;i<n-1;i++)
           {
                least=i;
                for(int j=i+1;j<n;j++)
                {
                    if(sr[j]<sr[least] && sr[j]!=0)
                    {
                         least=j;
                    }
                }
                Swap(&sr[least],&sr[i]);
           }
               
           
           sr[0]=0;
           result+=sr[k];
           
          }
        } 
      
  
      cout << result;
      outfile << result;
      
     
      cout << endl;
      outfile << endl;
     }
  
    
    
    
 system("pause");
 return 0;   
}


// Name: Muhammad Fawad Jawaid Malik
// Roll No. 11k - 2116
// Submitted To: Sir Rafi

#include <iostream>
#include <string>
#include<fstream>

using namespace std;

int main()
{   
    ifstream infile("A1P3in1.txt");
    ofstream outfile("A1P3out1.txt");
    
    int myArray[10];
    int m;
    int counter=1;
    string inst;

    
	// Checking if file opened or not
	if(infile.is_open())
	{ 
      for(int i=0; i < 9; i++)
      {
           infile >> myArray[i]; 
      } 
    }
    
    int pos = 0;
    
    while(infile >> m >> inst)
    {
     for(int i=1; i<10; i++)
     {   
        
        if(myArray[i]==0)
          pos = i;
            
        if(inst=="left" && (i-1)==pos && myArray[i]==m)  // To move Left of the puzzle
        {
          int temp = 0;
          temp = myArray[i-1];
          myArray[i-1] = myArray[i];
          myArray[i] = temp;
          counter+1;       
        }
        else if(inst=="right" && (i+1)==pos  && myArray[i]==m)  // To move Right of the puzzle
        {
          int temp =0;
          temp = myArray[i+1];
          myArray[i+1] = myArray[i];
          myArray[i] = temp;
          counter+1;       
        }
        else if(inst=="up" && (i-3)==pos  && myArray[i]==m)    // To move Up of the puzzle
        {
          int temp =0;
          temp = myArray[i-3];
          myArray[i-3] = myArray[i];
          myArray[i] = temp;
          counter+1;       
        }
        else if(inst=="down" && (i+3)==pos  && myArray[i]==m)   // To move Down of the puzzle
        {
          int temp =0;
          temp = myArray[i+3];
          myArray[i+3] = myArray[i];
          myArray[i] = temp;
          counter+1;       
        }  
     }
     
     //cout << m << " " << inst <<endl;
     
     for(int i=0; i < 9; i++)
     {
         outfile << myArray[i] << " ";
         cout << myArray[i] << " ";
         
         if(i+2==4 || i+2==7)
         {
           outfile << endl;
           cout << endl;
         }
     }  
     outfile << endl;
     cout << endl; 
    }
      
    if(counter==1)
    {
         outfile << "Invalid Move" << endl;
         cout << "Invalid Move" << endl;
    }    
    
      
    system("pause");
    return 0;
}

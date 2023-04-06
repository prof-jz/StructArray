/**********************************************
 * Alabama A&M University - EE109 - Spring 2023
 * Lesson 24 sample code: Arrays of Structures 
 * By:            Prof J Zehnpfennig, PE
 * Created:       06 March 2023
 * Last Updated:  06 April 2023
 **********************************************/

#include <fstream>  //JZ - used to work with files
#include <iostream> //JZ - used to work with input/output streams
#include <string>   //JZ - used to work with strings

using namespace std;


/*Create a datatype using Structures.  Structures are formally interconnected records of datatypes.*/
struct DBRecord  //JZ - defines a new data structure called DBRecord.    
{
  string fName;  //JZ - first name record within every DBRecord instance
  string lName;  //JZ - last name record within every DBRecord instance
  int employeeN; //JZ - employee number record within every DBRecord instance
};


int main()
{
  string fileN = "sampData.txt";      // JZ - designate input filename
  int x = 0, records = 3;             // JZ - counter variables
  DBRecord empRecords[records];       // JZ - creates database empRecords with rec elements

  
  ifstream myFile;    //JZ - associates file input stream with myFile
  myFile.open(fileN);

  if (myFile.is_open()) 
  {
    while (myFile.good()) // JZ - iterates until program encounters the EOF (end
                       // of file) character
    {
      
      /* JZ - pipe stream from 'myfile' into the current empRecord element*/ 
      myFile >> empRecords[x].fName;
      myFile >> empRecords[x].lName;
      myFile >> empRecords[x].employeeN;  

      //JZ - output current record to verify good reads
      cout << "First " << x+1 << ": " << empRecords[x].fName << endl;
      cout << "Last " << x+1 << ": " << empRecords[x].lName << endl;
      cout << "Employee Num " << x+1 << ": " << empRecords[x].employeeN << endl;
      
      //JZ - add a line feed between records but not after last record
      if (x != records - 1)
        cout << "\n";          
      x++;
    }
  }
  myFile.close();
  
  
  /* JZ - Here we write the array of our data structure to a file*/
  
  fileN = "sampWrite";  //JZ - assign a name to the output file

  ofstream fileW;       //JZ - designate output data stream to fileW
  fileW.open(fileN);    //JZ - assign stream fileW to the file name
  
  for (x = 0; x < records; x++)
    {   
      fileW << "First" << x+1 << ": " << empRecords[x].fName << endl;
      fileW << "Last" << x+1 << ": " << empRecords[x].lName << endl;
      fileW << "Employee Num" << x+1 << ": " << empRecords[x].employeeN << endl;

      //JZ - add a line feed between records but not after last record
      if (x != records - 1)
        fileW << "\n";    
    }
  fileW.close();
  
return 0;
}
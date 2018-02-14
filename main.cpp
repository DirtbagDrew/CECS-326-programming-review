/*
Andrew Myer
CECS 326 Programming Review
This program is a review assignment allocating and deallocating memory
*/

#include <iostream>
using namespace std;

/*
This structure holds 3 items:
an array of pointers to corresponding character arrays
an integer array with the number of space to allocate to each of the corresponding pointers to arrays
a character array with the alphabet, used to populate the arrays
*/
struct structures
{
  char *ptrChar[20];
  int charsAllocated[20];
  char Alphabet[26];
};

//initialize strucure to be used for the program
structures structure;

/*
  populates the alphabet array in the structure with a capital
  letter A-Z to each index
*/
void setAlphabet()
{
  structure.Alphabet[0]='A';
  structure.Alphabet[1]='B';
  structure.Alphabet[2]='C';
  structure.Alphabet[3]='D';
  structure.Alphabet[4]='E';
  structure.Alphabet[5]='F';
  structure.Alphabet[6]='G';
  structure.Alphabet[7]='H';
  structure.Alphabet[8]='I';
  structure.Alphabet[9]='J';
  structure.Alphabet[10]='K';
  structure.Alphabet[11]='L';
  structure.Alphabet[12]='M';
  structure.Alphabet[13]='N';
  structure.Alphabet[14]='O';
  structure.Alphabet[15]='P';
  structure.Alphabet[16]='Q';
  structure.Alphabet[17]='R';
  structure.Alphabet[18]='S';
  structure.Alphabet[19]='T';
  structure.Alphabet[20]='U';
  structure.Alphabet[21]='V';
  structure.Alphabet[22]='W';
  structure.Alphabet[23]='X';
  structure.Alphabet[24]='Y';
  structure.Alphabet[25]='Z';
}
/*
  initializes the integer array charsAllocated in the structures
  with the algorithm
  f(0)=2700 & f(n+1)=2*f(n) where n is an index of the integer array for 0<n<19
*/

void initializeIntegerArray()
{
  cout<<"Initiallizing Memory..."<<endl;
  structure.charsAllocated[0]=2700;
  for(int i=0;i<19;i++)
  {
    structure.charsAllocated[i+1]=2*structure.charsAllocated[i];
  }
}
/*
  populates the arrays that the pointers point to with randon letters
  from the alphabet
*/
void populateArrays()
{
  setAlphabet();
  for(int i=0; i<20;i++)
  {
    for(int j=0;j<structure.charsAllocated[i];j++)
    {
      int random_number=rand()%25;
      structure.ptrChar[i][j]=structure.Alphabet[random_number];
    }
  }
}

/*
  allocates memory to each array that the pointers point to
*/
void allocateMemory()
{
  for(int i =0;i<20;i++)
  {
    structure.ptrChar[i]=new char[structure.charsAllocated[i]];
  }
  populateArrays();
}

/*
  reallocates a pointer if it is already deallocated
  variables
    int a: the specified pointer
*/
void deallocatedSingleCheck(int a)
{
  if(structure.ptrChar[a]==nullptr)
  {
    cout<<"Pointer is deallocated"<<endl<<"Realocating Memory..."<<endl;
    structure.ptrChar[a]=new char[structure.charsAllocated[a]];
    for(int j=0;j<structure.charsAllocated[a];j++)
    {
      int random_number=rand()%25;
      structure.ptrChar[a][j]=structure.Alphabet[random_number];
    }
  }
}

/*
  prints all pointers that have no memory allocated to them
*/
void printDeallocatedMemory()
{
  int counter=0;
  for(int i =0; i<20; i++)
  {
    if (structure.ptrChar[i]==nullptr)
    {
      counter++;
      break;
    }
  }
  if(counter>0) //pointer has array
  {
    cout<<"Deallocated Memory: "<<endl;
    for(int i =0; i<20; i++)
    {
      if (structure.ptrChar[i]==nullptr)
      {
        cout<<i<<endl;
      }
    }
  }
  else  //pointer has no array
  {
    cout<<"No Deallocated Memory"<<endl;
  }
}

/*
  takes integer input and validates to make sure the input is
  within a specified range
  variables:
    int low : the specified low boundary of the range accepted
    int high: the specified high boundary of the range accepted
  returns:
    verified input
*/
int inputIntRange(int low, int high)
{
  int userInput;
  cin>>userInput;
  while (cin.fail()||userInput < low || userInput > high)
  {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Invalid entry! Please enter a valid number between "<<low<<" and "<<high<<": "<<endl;
    cin >> userInput;
  }
  return userInput;
}
/*
  deallocates memory of a pointer
  variables:
    int a: the index of the pointer used to delete the array
*/
void deallocateMemory(int a)
{
  if(structure.ptrChar[a]==nullptr)
  {
    //pointer is already deallocated
  }
  else
  {
    delete structure.ptrChar[a];
    structure.ptrChar[a]=nullptr;
  }
}
/*
  deallocates all the memory the pointers point to
*/
void deallocateAllMemory()
{
  cout<<"Deallocating All Memory"<<endl;
  for(int i=0;i<20;i++)
  {
    deallocateMemory(i);
  }
}
/*
  prints the first 10 characters of the array pointed to, if it has
  memory allocated to it
  variables:
    int a: the index of the pointer to the array
*/
void printTenCharacters(int a)
{
  if(structure.ptrChar[a]==nullptr)
  {
    cout<<"pointer "<<a<<" has no characters to print"<<endl;
  }
  else
  {
    cout<<"First 10 characters: "<<endl;
    for(int i=0;i<10;i++)
    {
      cout<<structure.ptrChar[a][i]<<endl;
    }
  }

}
/*
  contains the main and submenu of the program
*/
void menu()
{
  int menuInput = 0;
  int pointerToAccess = 0;
  int subMenuInput=0;

  while(menuInput!=4)
  {
    cout<<"(1) Access A Pointer"<<endl;
    cout<<"(2) List Deallocated Memory"<<endl;
    cout<<"(3) Deallocate All Memory"<<endl;
    cout<<"(4) Exit Program"<<endl;
    menuInput= inputIntRange(1,4);

    switch(menuInput)
    {
      case 1: //access a pointer
        subMenuInput=0;
        cout<<"Which Pointer Do You Want to Access?: ";
        pointerToAccess=inputIntRange(0,19);
        deallocatedSingleCheck(pointerToAccess);
        cout<<"You Selected pointer: "<<pointerToAccess<<". What Would You Like to Do?"<<endl;
        while(subMenuInput!=3)
        {
          cout<<"(1) Print the First 10 Characters in the Array"<<endl;
          cout<<"(2) Delete All Chars Associated with Pointer"<<endl;
          cout<<"(3) Return to Main Menu"<<endl;
          subMenuInput = inputIntRange(1,3);
          switch(subMenuInput)
          {
            case 1: //print first 10 characters in array
              printTenCharacters(pointerToAccess);
              break;
            case 2: //delete all characters associated with pointer
              cout<<"Deleting All Characters Associated with "<<pointerToAccess<<endl;
              deallocateMemory(pointerToAccess);
              break;
            case 3: //return to main menu
              cout<<"Returning to Main Menu"<<endl;
              cout<<endl;
              break;
          }
        }

        break;

      case 2: //list deallocated memory
        printDeallocatedMemory();
        break;
      case 3: //deallocate all memory
        deallocateAllMemory();
        break;
      case 4: //exit program
        deallocateAllMemory();
        cout<<endl;
        cout<<"Exiting Program";
        break;
    }
  }
}

/*
  main method of the program
*/
int main()
{
  initializeIntegerArray();
  allocateMemory();
  menu();
  return 0;
}

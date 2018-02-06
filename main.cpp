#include <iostream>
using namespace std;

struct structures
{
  char *ptrChar[20];
  int charsAllocated[20];
  char Alphabet[26];
};
structures structure;

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

void initializeIntegerArray()
{
  structure.charsAllocated[0]=2700;
  for(int i=0;i<19;i++)
  {
    structure.charsAllocated[i+1]=2*structure.charsAllocated[i];
  }
}

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

void allocateMemory()
{
  for(int i =0;i<20;i++)
  {
    structure.ptrChar[i]=new char[structure.charsAllocated[i]];
  }
  populateArrays();
}

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
  if(counter>0)
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
  else
  {
    cout<<"No Deallocated Memory"<<endl;
  }
}

int inputIntRange(int low, int high)
{
  int userInput;
  cin>>userInput;
  while (userInput < low || userInput > high)
  {
    cout << "Invalid entry! Please enter a valid number between "<<low<<" and "<<high<<": ";
    cin >> userInput;
  }
  return userInput;
}
void deallocateMemory(int a)
{
  if(structure.ptrChar[a]==nullptr)
  {
    //cout<<"pointer: "<<a<<" is already deallocated"<<endl;
  }
  else
  {
    delete structure.ptrChar[a];
    structure.ptrChar[a]=nullptr;
  }
}
void deallocateAllMemory()
{
  for(int i=0;i<20;i++)
  {
    deallocateMemory(i);
  }
}
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
        cout<<"Which Pointer Do You Want to Access?: ";
        pointerToAccess=inputIntRange(0,19);
        cout<<"You Selected pointer: "<<pointerToAccess<<". What Would You Like to Do?"<<endl;
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
        break;

      case 2: //list deallocated memory
        printDeallocatedMemory();
        break;
      case 3: //deallocate all memory
        cout<<"Deallocating All Memory"<<endl;
        deallocateAllMemory();

        break;
      case 4: //exit program
        cout<<"Exiting Program";

        break;
    }
  }
}

int main()
{
  cout<<"Initiallizing Memory..."<<endl;
  initializeIntegerArray();
  allocateMemory();
  menu();
  return 0;
}

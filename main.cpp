#include <iostream>
using namespace std;

struct structures
{
  char *ptrChar[20];
  int charsAllocated[20];
};
structures structure;

void initializeIntegerArray()
{
  structure.charsAllocated[0]=2700;
  for(int i=0;i<19;i++)
  {
    structure.charsAllocated[i+1]=2*structure.charsAllocated[i];
  }
}

void allocateMemory()
{
  for(int i =0;i<20;i++)
  {
    *structure.ptrChar[i]=new char[structure.charsAllocated[i]];
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
void deallocateMemory()
{
  
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
            cout<<"First 10 Characters:"<<endl;
            break;
          case 2: //delete all characters associated with pointer
            cout<<"Deleting All Characters Associated with "<<pointerToAccess<<endl;
            break;
          case 3: //return to main menu
            cout<<"Returning to Main Menu"<<endl;
            cout<<endl;
            break;
        }
        break;

      case 2: //list deallocated memory
        cout<<"Deallocated Memory: "<<endl;

        break;
      case 3: //deallocate all memory
        cout<<"Deallocating All Memory"<<endl;

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

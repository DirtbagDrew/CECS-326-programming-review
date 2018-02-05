#include <iostream>
using namespace std;

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

void menu()
{
  int menuInput = 0;
  while(menuInput!=4)
  {
    cout<<"(1) Access A Pointer"<<endl;
    cout<<"(2) List Deallocated Memory"<<endl;
    cout<<"(3) Deallocate All Memory"<<endl;
    cout<<"(4) Exit Program"<<endl;
    menuInput= inputIntRange(1,4);

    switch(menuInput)
    {
      case 1:
        
        break;
      case 2:

        break;
      case 3:

        break
    }
  }
}


int main()
{
  menu();
  return 0;
}

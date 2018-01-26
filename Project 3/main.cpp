#include <iostream>
#include <algorithm>
using namespace std;

// Enter your 4 functions here
void sortHelper(int arr[], int first, int last)
{
  //Base case
  if(first < last)
  {   //find min value in arr
    int minIdx = first;
    
  for(int i = first + 1; i < last; i++)
    {
      if(arr[i] < arr[first]);
      {
        minIdx = i;
      }
    }
      swap(arr[first], arr[minIdx]);
      sortHelper(arr, first + 1, last-1);
  }
}

void mysort (int arr[], int size)
{
   sortHelper(arr,0,size);
}

void HiLoHelper ( int start, int stop)
{
   if(start == stop)
   {
      cout << "Your number is " << start <<"." << endl;
   }
   else if (start > stop)
   {
      cout << "you cheated!"<< endl;
   }
   else
   {
     char c;
     //added do while loop to make sure they enter the correct input, also so it will start over if they dont.
     do
     {
      int guess = (start + stop) / 2;
      cout <<" Is your number " << guess <<"?"<< endl;
      cin >> c;
      
      if(c =='y' || c =='Y')
      {
         return HiLoHelper(guess, guess);
      }
      else if (c =='l' || c =='L')
      {
         return HiLoHelper(guess +1, stop);
      }
      else if (c =='h' || c =='H')
      {
         return HiLoHelper(start, guess -1);
      }
      else
      {
        cout<<"Please enter a valid input."<<'\n';
      }
     }
     while(c != 'y' || 'Y' || 'l' || 'L' || 'h' || 'H');
   }
}

int hilo ( int n)
{
  HiLoHelper(1,n);
}

int main() 
{
   cout << "Think of a number between 1 and 100 I will try and guess it with your help."<<endl;
   cout <<'\n';
   cout << "Use the letter 'L' if the number I guessed is to low."<<'\n'<<"Use the letter 'H' if the number I guessed is to high."<<'\n'<<"Use the letter 'Y' if I guessed is your number correctly."<<'\n';
   cout << '\n';
    // Guess a number between 1 and 100
    // Your hilo() will call a slightly modified GuessNumber
    hilo(100);

    // Sort an array
    // Your mysort() will call a recursive helper function.
    int a[] = {5,4,3,2,1};
    const int n = 5;
    mysort(a,n);
    cout << "Sorted result:\n";
    for (int n: a)
        cout << n << endl;
    cout << endl;
}

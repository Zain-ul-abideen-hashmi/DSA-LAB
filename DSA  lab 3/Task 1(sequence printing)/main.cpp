#include <iostream>
using namespace std;

void printNumber(int n)

{
    //base case
    if (n < 0)
    {
        return;
    }

    cout << n << " ";

    // recursive case this will behave like a "loop" keep calling untill it is 0 i
    which case itwill not pass the first condition
        printNumber(n - 1);
}

int main()

{
    int n;
    cout << "Enter a number: ";
    cin >> n;



    printNumber(n);
    cout << endl;



    // this is to keep window open so it doesn’t close immediately

    cout << "\nPress Enter to exit";
    cin.ignore();
    cin.get();

    return 0;
}
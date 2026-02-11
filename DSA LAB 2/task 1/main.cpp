#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    int n;
    cout << "  Enter number of element : ";
    cin >> n;
    DynamicStack<int> s(n);

    cout << " Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (!s.push(x))
        {
            cout << " error ";
        }
    }

    int value;
    int maxVal, minVal;


    if (s.pop(value))
    {
        maxVal = minVal = value;
    }
    else
    {
        cout << " stack is empty  ";
        return 0;
    }

    while (!s.isEmpty())
    {
        s.pop(value);

        if (value > maxVal)
            maxVal = value;
        if (value < minVal)
            minVal = value;
    }
    cout << "  Max value: " << maxVal << endl;
    cout << " Min value: " << minVal << endl;


    cout << "---------------------" << endl;
    cin.ignore();
    cin.get();

    return 0;

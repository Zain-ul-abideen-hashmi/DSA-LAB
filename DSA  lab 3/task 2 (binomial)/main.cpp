#include <iostream>
using namespace std;

int binomial(int n, int k)

{
    if (k == 0)
    {
        return 1; // Base case (1)
    }

    if (k == n)
    {
        return 1; // Base case 2
    }

    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

int main()

{
    int n, k;
    cout << "Enter n: ";

    cin >> n;

    cout << "Enter k: ";

    cin >> k;

    cout << "Output: " << binomial(n, k) << endl;

    cout << "\nPress Enter to exit";

    cin.ignore();
    cin.get();

    return 0;
}
#include <iostream>
#include <stack>
#include "Queue.h"
using namespace std;

void reverseFirstK(DynamicQueue& q, int k)

{
    if (k <= 0 || k > q.size())

        return;

    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        s.push(q.dequeue());
    }

    while (!s.empty())

    {
        q.enqueue(s.top());
        s.pop();
    }

    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++)

    {
        q.enqueue(q.dequeue());
    }

}
int main()

{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    DynamicQueue q(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)

    {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    reverseFirstK(q, k);

    cout << "Output ";

    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }

    return 0;
}

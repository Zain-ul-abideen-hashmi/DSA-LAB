#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;
int main()
{
    cout << " Test Dynamic Queue with Template " << endl;

    cout << "\n Int Queue " << endl;

    DynamicQueue<int> intQueue(4);

    cout << "Enqueue 8 integers:" << endl;

    for (int i = 1; i <= 8; i++)

    {
        intQueue.Enqueue(i);
        cout << "Enqueued: " << i
            << "\nSize: " << intQueue.Size()
            << "\n Capacity: " << intQueue.Capacity()<< endl;
    }

    intQueue.Display();
    cout << "\n  String Queue  " << endl;
    DynamicQueue<string> strQueue(3);

    string names[] = { "Zain", "Adullah", "Damian", "Chris", "Adam" };
    for (int i = 0; i < 5; i++)
    {
        strQueue.Enqueue(names[i]);
        cout << "Enqueued: " << names[i]
            << "\nSize: " << strQueue.Size()
                << "\n Capacty: " << strQueue.Capacity()<< endl;

    }

    strQueue.Display();

    cout << "\nDequeue 3 names:" << endl;

    string name;

    for (int i = 0; i < 3; i++)

    {
        strQueue.Dequeue(name);
        cout << "Dequeued: " << name << endl;
    }

    strQueue.Display();
    return 0;
}

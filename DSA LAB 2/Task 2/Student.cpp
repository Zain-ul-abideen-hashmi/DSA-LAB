#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

void student::setData(const char n[], const int g[], int count) {
    strncpy_s(name, n, sizeof(name));
    name[sizeof(name) - 1] = '\0';
    gradeCount = count;
    for (int i = 0; i < count; i++)
        lab[i] = g[i];
}

void student::calculateAverage() {
    int sum = 0;
    for (int i = 0; i < gradeCount; i++)
        sum += lab[i];
    if (gradeCount > 0)
        average = (float)sum / gradeCount;
    else
        average = 0.0f;
}

void student::print() const {
    cout << "Name: " << name << endl;
    cout << "Grades: ";
    for (int i = 0; i < gradeCount; i++)
        cout << lab[i] << " ";
    cout << endl;
    cout << "Average: " << average << endl;
    cout << "------------------------\n";
}

int student::compareName(const char n[]) const {
    return strcmp(name, n) == 0;
}

#pragma once
#ifndef STUDENT_H
#define STUDENT_H

class student {
private:
    char name[50];
    int lab[10];
    float average;
    int gradeCount;

public:
    void setData(const char n[], const int g[], int count);
    void calculateAverage();
    void print() const;
    int compareName(const char n[]) const;
};

#endif

#include <iostream>
#include <fstream>
#include <cstring>
#include "Student.h"
using namespace std;

int main()
{
    char filename[50];
    cout << "Enter filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin)
    {
        cout << " file cant be found ";
        return 0;
    }

    int studentCount, gradeCount;
    fin >> studentCount;
    fin >> gradeCount;
    fin.ignore(); // Move to next line after read numbers because if i do it normally it will just put the entire line into the name and eveeything else is gonna be dummy data

    student* students = new student[studentCount];

    for (int i = 0; i < studentCount; i++)
    {
        char line[100];
        fin.getline(line, 100);

        char name[50] = "";
        int grades[10];
        int gradeIdx = 0;
        int len = strlen(line);
        int pos = 0;

        // Parse name which ic basically all non number untill i hit a number
        while (pos < len) {
            // Skiping space
            while (pos < len && line[pos] == ' ')
                pos++;
            if (pos >= len) break;

           // checking next part if it is number or nahh
            int start = pos;
            while (pos < len && line[pos] != ' ')
                pos++;
            char token[20];
            int tlen = pos - start;
            strncpy_s(token, line + start, tlen);
            token[tlen] = '\0';

            bool isNumber = true;
            for (int k = 0; token[k] != '\0'; k++) {
                if (token[k] < '0' || token[k] > '9') {
                    isNumber = false;
                    break;
                }
            }

            if (isNumber && gradeIdx < gradeCount)
            {
                grades[gradeIdx++] = atoi(token);
            }
            else
            {
                if (name[0] != '\0')
					strcat_s(name, " "); //using strcat_s to add space between first and last name if there is more than one name
                strcat_s(name, token);
            }
        }

        students[i].setData(name, grades, gradeCount);
        students[i].calculateAverage();
    }

    fin.close();

    int choice = 0;
    do {
        cout << "\nmenu\n";
        cout << "1) Display all students\n";
        cout << "2) Find a student\n";
        cout << "3) Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < studentCount; i++)
                students[i].print();
        }
        else if (choice == 2)
        {
            char searchName[50];
            cout << "Enter student name: ";
            cin >> ws;
            cin.getline(searchName, 50);

            int found = 0;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].compareName(searchName))
                {
                    students[i].print();
                    found = 1;
                    break;
                }
            }

            if (!found)
                cout << "Student not found!\n";
        }

    } while (choice != 3);

    delete[] students;

    return 0;
}

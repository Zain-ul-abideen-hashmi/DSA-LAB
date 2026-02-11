#include <iostream>
#include <string>
using namespace std;


class House
{

private:
    string owner;
    string address;
    int bedrooms;
    float price;

public:

    void getHouseinfo();
    void printHouseinfo();
};


void House::getHouseinfo()
{
    cout << "owner name: ";

    getline(cin,owner);
    cout << "adress of location: ";
    getline(cin, address);

    cout << "how many bedroom are inside?: ";
    cin >> bedrooms;

    cout << "cost?: ";
    cin >> price;
}


void House::printHouseinfo()
{
    cout << owner << "\t\t"
         << address << "\t\t"
         << bedrooms << "\t\t"
         << price << endl;
}



int main()
{

    House available[100];
    int count = 0;
    char choice;


    do
    {
        if (count < 100)
        {

            available[count].getHouseinfo();

            count++;

            cout << " Do  You want to see another one ? (y or n): ";
            cin >> choice;


            cin.ignore();
            cout << endl;
        }

        else

        {
            cout <<  "error "<< endl;
            break;
        }

    }

    while (choice == 'y' || choice == 'Y');





    cout << "----------------------------------------------" << endl;




    cout << "Owner\t\tAddress\t\tBedrooms\t\tPrice" << endl;

    for (int i = 0; i < count; i++)
    {

        available[i].printHouseinfo();
    }




    cin.get();

    return 0;



}
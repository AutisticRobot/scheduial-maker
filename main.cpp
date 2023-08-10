// main.cpp
// main file for a schiule making and testing program.
// made by Tyler M. Kormann (tylerkormann.com)

#include <iostream>
using namespace std;

int tDays;
int onDays;
int offDays;

void display();

int main(int argc, char *argv[])
{
    cout << "days in a work week: ";
    cin >> tDays;
    cout << "working days in a work week: ";
    cin >> onDays;
    cout << "non-working days in a work week: ";
    cin >> offDays;

    
}

void display()
{
    cout << "#---#---#---#---#---#---#---#";
    cout << "|Sun|Mon|Tue|Wed|Thr|Fri|Sat|";
    cout << "#---#---#---#---#---#---#---#";
    cout << "|   |   |   |   |   |   |   |";
    cout << "#---#---#---#---#---#---#---#";
    cout << "|   |   |   |   |   |   |   |";
    cout << "#---#---#---#---#---#---#---#";
    cout << "|   |   |   |   |   |   |   |";
    cout << "#---#---#---#---#---#---#---#";
    cout << "|   |   |   |   |   |   |   |";
    cout << "#---#---#---#---#---#---#---#";
}
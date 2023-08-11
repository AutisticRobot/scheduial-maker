// main.cpp
// main file for a schedule making and testing program.
// made by Tyler M. Kormann (tylerkormann.com)

#include <iostream>
using namespace std;

int tDays;
int onDays;
int offDays;

void displayMonth(int offset = 0, int displayDays = 0);// display the curent schedule for a month;
void displayWeek(int offset = 0);//helper function to display a week;

bool getDay(int day);//returns the type of the input day;
//(true=onDay,false=offDay);

int main(int argc, char *argv[])
{
    cout << "days in a work week: ";
    cin >> tDays;
    cout << "working days in a work week: ";
    cin >> onDays;
    cout << "non-working days in a work week: ";
    cin >> offDays;

    displayMonth(1,30);
}

void displayMonth(int offset, int displayDays)// display the curent schedule for a month;
{
    cout << "#---#---#---#---#---#---#---#" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thr|Fri|Sat|" << endl;
    cout << "#---#---#---#---#---#---#---#" << endl;
    displayWeek();
    displayWeek();
    displayWeek();
}

void displayWeek(int offset)//helper function to display a week;
{
    cout << "|   |   |   |   |   |   |   |" << endl;
    cout << "#---#---#---#---#---#---#---#" << endl;
}

bool getDay(int day)//returns the type of the input day;
{
    int dayOfWeek = day % tDays;
    if(dayOfWeek > onDays)
    {
        return false;
    }else{
        return true;
    }
}
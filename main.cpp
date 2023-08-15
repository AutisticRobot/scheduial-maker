// main.cpp
// main file for a schedule making and testing program.
// made by Tyler M. Kormann (tylerkormann.com)

#include <iostream>
using namespace std;

int employeeCount;
int* tDays;
int* onDays;
int* offDays;
int* schOffset;


void displayMonth(int empNum, int offset = 0, int displayDays = 30);// display the curent schedule for a month;
void displayWeek(int empNum, int offset = 0);//helper function to display a week;
void getSced(int empNum); //(Sced = Schedule) get number of on and off days from user;

bool getDay(int empNum, int day);//returns the type of the input day;
//(true=onDay,false=offDay);

int main(int argc, char *argv[])
{
    cout << "number of employees: ";
    cin >> employeeCount;

    tDays     = new int[employeeCount];
    onDays    = new int[employeeCount];
    offDays   = new int[employeeCount];
    schOffset = new int[employeeCount];

    for(int i=0;i<employeeCount;i++)
    {
        getSced(i);
    }
    for(int i=0;i<employeeCount;i++)
    {
        displayMonth(i);
    }
}

void getSced(int empNum) //(Sced = Schedule) get number of on and off days from user;
{
    cout << "------------Employee #" << empNum + 1 << "------------" << endl;
    cout << "working days in a work week: ";
    cin >> onDays[empNum];
    cout << "non-working days in a work week: ";
    cin >> offDays[empNum];
    cout << "-----------------------------------" << endl;

    tDays[empNum] = onDays[empNum] + offDays[empNum];
    if(empNum != 0)
    {
    schOffset[empNum] = schOffset[empNum-1] - onDays[empNum-1];//1st try at schedule offset, and it only works with one shift;
    }else{
        schOffset[0] = 0;
    }
}

void displayMonth(int empNum, int offset, int displayDays)// display the curent schedule for a month;
{
    cout << "/=====#=====#=====#=====#=====#=====#=====\\" << endl;
    cout << "|-Sun-|-Mon-|-Tue-|-Wed-|-Thr-|-Fri-|-Sat-|" << endl;
    cout << "#=====#=====#=====#=====#=====#=====#=====#" << endl;

    displayWeek(empNum, 0+offset);
    displayWeek(empNum, 7+offset);
    displayWeek(empNum, 14+offset);
}

void displayWeek(int empNum, int offset)//helper function to display a week;
{
    offset += schOffset[empNum];

    cout << "|     |     |     |     |     |     |     |" << endl;
    for(int i=0;i<7;i++)
    {
        bool actDay = getDay(empNum, offset++);
        cout << "|  ";
        if(actDay)
        {
            cout << "X  ";
        }else{
            cout << "   ";
        }
    }
    cout << "|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "#-----#-----#-----#-----#-----#-----#-----#" << endl;
}

bool getDay(int empNum, int day)//returns the type of the input day;
{
    int dayOfWeek;
    if(day > 0)
    {
        dayOfWeek = day % tDays[empNum];
    }else{
        dayOfWeek = -day % tDays[empNum];
        dayOfWeek = tDays[empNum] - dayOfWeek;
        dayOfWeek = dayOfWeek % tDays[empNum];
    }
    if(dayOfWeek >= onDays[empNum])
    {
        return false;
    }else{
        return true;
    }
}
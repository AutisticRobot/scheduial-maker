// main.cpp
// main file for a schedule making and testing program.
// made by Tyler M. Kormann (tylerkormann.com)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


const int dspOrder[15] = {7,5,12,1,10,3,8,0,13,2,11,4,9,6,14};
const int dspOrderH[15] = {7,1,8,2,9,5,10,0,11,6,12,3,13,4,14};
// 7, 1, 8, 2, 9
// 5,10, 0,11, 6
//12, 3,13, 4,14

int employeeCount;
int weeks;
int* tDays;
int* onDays;
int* offDays;
int* schOffset;
string* names;
const string color[15] = {"1","2","3","4","5","6","7","8","9","10","11","52","13","93","201"};


void outToTerminal(int argc, char *argv[]);//Main file for CLI mode;
void outToFile(char *argv[]);//Main function for out to file mode;
void displayMonth(int weeks = 3, int offset = 0);// display the curent schedule for a month;
void displayWeek(int offset = 0);//helper function to display a week;
void getSced(int empNum); //(Sced = Schedule) get number of on and off days from user;
void displayLegend();//function to diplay the names for each schedule;

string getDay(int empTmp, int day, int offset);//returns the type of the input day;

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        outToFile(argv);
    }else{
        outToTerminal(argc, argv);
    }
}

void outToTerminal(int argc, char *argv[])//Main file for CLI mode;
{
    cout << "number of employees: ";
    cin >> employeeCount;
    cout << "Weeks to display: ";
    cin >> weeks;

    tDays     = new int[employeeCount];
    onDays    = new int[employeeCount];
    offDays   = new int[employeeCount];
    schOffset = new int[employeeCount];
    names     = new string[employeeCount];

    for(int i=0;i<employeeCount;i++)
    {
        getSced(i);
    }

    displayMonth(weeks);
    displayLegend();
}


void outToFile(char *argv[])
{
    const int argc = 2;
    string curLine = "";

    ifstream inFile;
    inFile.open(argv[1]);

    if(!inFile.is_open())
    {
        exit(EXIT_FAILURE);
    }

    inFile >> employeeCount;
    inFile >> weeks;
    int empNum = 0;
    tDays     = new int[employeeCount];
    onDays    = new int[employeeCount];
    offDays   = new int[employeeCount];
    schOffset = new int[employeeCount];
    names     = new string[employeeCount];
    while(inFile.good())
    {   
        inFile >> onDays[empNum];
        inFile >> offDays[empNum];
        inFile >> names[empNum];

        tDays[empNum] = onDays[empNum] + offDays[empNum];
        if(empNum != 0)
        {
        schOffset[empNum] = schOffset[empNum-1] - onDays[empNum-1];//1st try at schedule offset, and it only works with one shift;
        }else{
            schOffset[0] = 0;
        }

        empNum++;
    }

    displayMonth(weeks);
    displayLegend();
}

void getSced(int empNum) //(Sced = Schedule) get number of on and off days from user;
{
    cout << "------------Employee #" << empNum + 1 << "------------" << endl;
    cout << "working days in a work week: ";
    cin >> onDays[empNum];
    cout << "non-working days in a work week: ";
    cin >> offDays[empNum];
    cout << "Name of the employee: ";
    cin >> names[empNum];
    cout << "-----------------------------------" << endl;

    tDays[empNum] = onDays[empNum] + offDays[empNum];
    if(empNum != 0)
    {
    schOffset[empNum] = schOffset[empNum-1] - onDays[empNum-1];//1st try at schedule offset, and it only works with one shift;
    }else{
        schOffset[0] = 0;
    }
}

void displayMonth(int weeks, int offset)// display the curent schedule for a month;
{
    cout << "/=====#=====#=====#=====#=====#=====#=====\\" << endl;
    cout << "|-Sun-|-Mon-|-Tue-|-Wed-|-Thr-|-Fri-|-Sat-|" << endl;
    cout << "#=====#=====#=====#=====#=====#=====#=====#" << endl;

    for(int i=0;i<weeks;i++)
    {
        displayWeek((i*7)+offset);
    }
}

void displayWeek(int offset)//helper function to display a week;
{
    string line1 = "|";
    string line2 = "|";
    string line3 = "|";

    for(int i=0;i<126;i++)
    {
        string tmp = "";
        if((i % 18) > 14)
        {
            tmp += "\033[38;5;15m\033[48;5;0m|";
        }else{
            int day = (i-(i%18))/18;
            tmp += getDay(i%18, day, offset);
        }

        switch(i%3)
        {
            case 0:
            line1 += tmp;
            break;
            case 1:
            line2 += tmp;
            break;
            case 2:
            line3 += tmp;
            break;
        }
    }

    cout << line1 << endl << line2 << endl << line3 << endl;
    cout << "#-----#-----#-----#-----#-----#-----#-----#" << endl;
}

string getDay(int empTmp, int day, int offset)//returns the type of the input day;
{
    int empNum = dspOrder[empTmp];

    if(empNum >= employeeCount)
    {
        return " ";
    }

    day += offset + schOffset[empNum];

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
        return " ";
    }else{
        return "\033[38;5;" + color[empNum] + "mX";
    }
}

void displayLegend()//function to diplay the names for each schedule;
{
    cout << endl;
    cout << "*-------------------------------------Legend------------------------------------*" << endl;
    for(int i=0;i<15;i++)
    {

        int empNum = dspOrderH[i];

        string output;
        string outName;
        string outColor;
        if(empNum < employeeCount)
        {
            outName = "X " + names[empNum];
            outColor = "\033[38;5;" + color[empNum] + "m";
        }else{
            outName = "";
            outColor = "";
        }
        if(outName.length() < 6)
        {
            outName += "\t";
        }
        outName += "\t";

        output = outColor + "|" + outName + "|\033[38;5;15m";

        
        
        cout << output;
        if(i%5 == 4)
        {
            cout << endl;
        }
    }
}
// main.cpp
// just a tutorial program dump right now
// following a tutorial by Mary Elaine Califf
// made by Tyler M. Kormann

#include <iostream>
using namespace std;
int testFunc(int num1, int num2);


int main(int argc, char *argv[])
{
    int in1;
    int in2;

    cout << "What is your first number? ";
    cin >> in1;
    cout << "What is your second number? ";
    cin >> in2;
    cout << "Your total is " << testFunc(in1, in2) << endl;
}

int testFunc(int num1, int num2)
{
    int out;

    out = num1 + num2;

    return out;
}
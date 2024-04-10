#include <iostream>
#include<iomanip>
//#include<cstdlib>
//#include<ctime>
#include <vector>
#include<string>
#include "MathOperations.h"


// test changes

MathOperations::MathOperations() {
    operand1 = 0;
    operand2 = 0;
    answer = 0;
    theoperator = ' ';

}
// get the current value of the private data member: theoperator

void MathOperations::setOperands(int op1, int op2) {
    operand1 = op1;
    operand2 = op2;
}
// get the current value of the private data member: theoperator
char MathOperations::getOperator() const {
    return theoperator;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const {
    return answer;
}

// set theoperator to '+'
// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition() {
    theoperator = '+';
    answer = operand1 + operand2;

}

// set theoperator to '-'
// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction() {
    theoperator = '-';
    answer = operand1 - operand2;
}

// set theoperator to '*'
// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication() {
    theoperator = '*';
    answer = operand1 * operand2;
}

// set theoperator to const DivisionSymbol, it is ASCII code for obelus
// apply the division operation to operand1 and operand2
// set the answer equal to operand1 � operand2
void MathOperations::Division() {
    theoperator = DivisionSymbol;
    answer = operand1 / operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const {

    if (answer == response) {
        return true;
    }
    else {
        return false;
    }
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const {

    cout << setw(3) << operand1 << endl;
    cout << theoperator << operand2 << endl;
    cout << "___________" << endl;
}

// display the question by calling print() first
// then ask the user for the answer
// it returns the valid user answer collected from the user input
int MathOperations::collectUserAnswer() const {
    bool toQuit = false;
    print();
    do {

        cout << "Enter your answer" << endl;
        int UserAnswer;
        cin >> UserAnswer;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad
            return UserAnswer;
        }
        else {
            cin.clear();
            string invalidOption;
            cin >> invalidOption;
            if (invalidOption == "Q" || invalidOption == "q")
                toQuit = true;

            else
                cout << "Invalid Input!Please try again" << endl;

        }
        cin.ignore(numeric_limits<int>::max(), '\n');

    } while (!toQuit);
    return 0;
}


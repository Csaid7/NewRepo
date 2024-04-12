/* File: MathOperations.cpp
 * Course: CS215-00x
 * Project: Lab 9 (first part of Project 2)
 * Purpose: provide the complete implementation of the class named MathOperations
 * Author: (your name)
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include "MathOperations.h"

 // default constructor    
MathOperations::MathOperations()
{
    operand1 = 0;
    operand2 = 0;
    theoperator = '\0';
    answer = -1;
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2)
{
    operand1 = op1;
    operand2 = op2;
    theoperator = '\0';
    answer = -1;
}

// read the current value of the private data member: current operator
char MathOperations::getOperator() const
{
    return theoperator;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const
{
    return answer;
}

// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition()
{
    theoperator = '+';
    answer = operand1 + operand2;
}

// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction()
{
    theoperator = '-';
    answer = operand1 - operand2;
}

// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication()
{
    theoperator = '*';
    answer = operand1 * operand2;
}

// set theoperator to const DivisionSymbol, it is ASCII code for obelus
// apply the division operation to operand1 and operand2
// set the answer equal to operand1 / operand2
void MathOperations::Division()
{
    theoperator = DivisionSymbol;
    answer = operand1 / operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const
{
    if (response == answer)
        return true;
    else
        return false;
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const
{
    cout << "  " << setw(MAXDIGITS) << operand1 << endl;
    cout << " " << theoperator << setw(MAXDIGITS) << operand2 << endl;
    cout << " " << "-----" << endl;
}

// First display the questions by calling print() member function
// it repeatedly asks the user for the answer until a valid integer has been collected
// it returns the valid user answer collected from the user input
int MathOperations::collectUserAnswer() const
{
    this->print();
    int studentAnswer; // The student's answer
    cout << "Please type your answer: " << endl;
    cin >> studentAnswer;

    // if user-input is not a valid integer, allow the user to try again and again...
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Invalid input! Please try again..." << endl;
        cout << "Please type your answer: " << endl;
        cin >> studentAnswer;
    }

    cin.ignore(numeric_limits<int>::max(), '\n');  //extract any possible leftover in the input stream

    // when the valid integer is collected
    return studentAnswer;
}

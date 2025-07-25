/* File: MathReport.h
 * Course: CS215-00x
 * Project: Lab 10 (as part of Project 2)
 * Purpose: to declare the class named MathReport
 * Author: (your name)
 */

#include <iostream>
#include <vector>
#include <list>
#include "MathOperations.h"

using namespace std;

class MathReport
{
public:
    // default constructor
    MathReport();

    // add a newQuestion into the vector of mathQuestions
    // and the response to check with the correct answer: 
    //    if response is correct, increase numCorrectAnswers
    //    otherwise, increase numWrongAnswers and also insert newQuestion to errorList
    void insert(MathOperations newQuestion, int response);

    // return the value of numCorrectAnswers
    int getNumOfCorrectAnswers() const;

    // return the value of numWrongAnswers
    int getNumOfWrongAnswers() const;

    // generate a brief report
    // if showAnswer is true, display questions solved with correct answers
    //                 otherwise, display questions solved without answers
    void generateReport(bool showAnswer) const;

    // display the questions in errorList for practice again and collect the user answer
    // then check if the answer is correct so that it can be removed from the errorList
    // it returns false if all questions in errorList have been corrected and removed from the errorList
    // otherwise returns true: errorList is not empty yet, need more practice
    bool needMorePractice();

private:
    int numCorrectAnswers;  // number of correctly answered questions
    int numWrongAnswers;  // number of wrong answers
    vector<MathOperations> mathQuestions; // sequence of questions
    list<MathOperations> errorList;  // sequence of questions with wrong answers in first try, need to practice more
};

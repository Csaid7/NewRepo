#include <iostream>
#include<iomanip>
#include <vector>
#include<string>
#include "MathReport.h"

// default constructor
	MathReport::MathReport() {

	}

// add a newQuestion into the vector of mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers and also insert newQuestion to errorList
	void MathReport::insert(MathOperations newQuestion, int response) {
		mathQuestions.push_back(newQuestion);
		if (newQuestion.checkAnswer(response)) {
			numCorrectAnswers++;
		}
		else {
			errorList.push_back(newQuestion);
			numWrongAnswers++;
		}

}

// return the value of numCorrectAnswers
	int MathReport::getNumOfCorrectAnswers() const {
		return numCorrectAnswers;

}

// return the value of numWrongAnswers
	int MathReport::getNumOfWrongAnswers() const {
		return numWrongAnswers;
}

// generate a brief report
// if showAnswer is true, display questions solved with correct answers
//                 otherwise, display questions solved without answers
	void MathReport::generateReport(bool showAnswer) const {
		if showAnswer is true {
			for (int i = 0; i < mathQuestions.size(); i++) {
				cout << "Question " << i + 1 << ": ";
				cout << mathQuestions[i].getOperand1() << " ";
				cout << mathQuestions[i].getOperator() << " ";
				cout << mathQuestions[i].getOperand2() << " = ";
				if (showAnswer) {
					cout << mathQuestions[i].getAnswer() << endl;
				}
				else {
					cout << " " << endl;
				}
			}
		}
		else {
			for (int i = 0; i < errorList.size(); i++) {
				cout << "Question " << i + 1 << ": ";
				cout << errorList[i].getOperand1() << " ";
				cout << errorList[i].getOperator() << " ";
				cout << errorList[i].getOperand2() << " = ";
				if (showAnswer) {
					cout << errorList[i].getAnswer() << endl;
				}
				else {
					cout << " " << endl;
				}
			}
		}

}

// display the questions in errorList for practice again and collect the user answer
// then check if the answer is correct so that it can be removed from the errorList
// it returns false if all questions in errorList have been corrected and removed from the errorList
// otherwise returns true: errorList is not empty yet, need more practice
	bool MathReport::needMorePractice() {
		while (it != errorList.end()) {
			cout << "Question: ";
			cout << it->getOperand1() << " ";
			cout << it->getOperator() << " ";
			cout << it->getOperand2() << " = ";
			int response;
			cin >> response;
			if (it->checkAnswer(response)) {
				it = errorList.erase(it);
			}
			else {
				it++;
			}
		}
		if (errorList.empty()) {
			return false;
		}
		else {
			return true;
		}
}
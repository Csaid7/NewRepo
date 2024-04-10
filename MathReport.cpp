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

}

// return the value of numWrongAnswers
	int MathReport::getNumOfWrongAnswers() const {

}

// generate a brief report
// if showAnswer is true, display questions solved with correct answers
//                 otherwise, display questions solved without answers
	void MathReport::generateReport(bool showAnswer) const {

}

// display the questions in errorList for practice again and collect the user answer
// then check if the answer is correct so that it can be removed from the errorList
// it returns false if all questions in errorList have been corrected and removed from the errorList
// otherwise returns true: errorList is not empty yet, need more practice
	bool MathReport::needMorePractice() {
		while (it != errorList.end()) {
			int answer = it->collectUsesrAnswer();
			//int answer=(*it).collectUserAnswer()
			if (*it.checkAnswer(answer) == true) {
		// remove the current node ; increase numcorrect answers and decrease numwrongasnwer
				it = errorList.erase(it);
				numCorrectAnswers++;
				numWrongAnswers--;

			}//the asnwers the question wrong
			else {
				it++;
			}
			if
		}
		
}

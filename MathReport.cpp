 #include "/Users/eakwa/Documents/GitHub/csaid7/MathReport.h"
 
 // default constructor initializes private variables
//  int numCorrectAnswers;  // number of correctly answered questions
//     int numWrongAnswers;  // number of wrong answers
//     vector<MathOperations> mathQuestions; // sequence of questions
//     list<MathOperations> errorList;  // sequence of questions with wrong answers in first try, need to practice more

MathReport::MathReport()
{
    numCorrectAnswers = 0;
    numWrongAnswers = 0;
    // vector<MathOperations> mathQuestions;
    // list<MathOperations> errorList;
    
    // create empty vector and list
    vector<MathOperations> mathQuestions;
    list<MathOperations> errorList;
}

// add a Question object into the vector of mathQuestions
// and the response to check with the correct answer:
// if response is correct, increase numCorrectAnswers
// otherwise, increase numWrongAnswers
// void insert(MathOperations newQuestions, int response);

void MathReport::insert(MathOperations newQuestion, int response)
{
        mathQuestions.push_back(newQuestion);
		if (newQuestion.checkAnswer(response)) {
			numCorrectAnswers++;
		}
		else {
			errorList.push_back(newQuestion);
			numWrongAnswers++;
		}
}

// return the number of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{
    return numCorrectAnswers;
}

// return the number of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
    return numWrongAnswers;
}

// generate a brief report
// if showAnswer is true, display questions solved with correct answers
// otherwise, display questions without answers
void MathReport::generateReport(bool showAnswer) const
{
    if (showAnswer)
    {
        cout << "Congratulations! " << mathQuestions.back().getAnswer() << " is the right answer." << endl;
        cout << "Excellent! Your answers are all correct! No more practice is needed:)" << endl;
    }
    else
    {
        cout << "You have solved the following " << mathQuestions.size() << " math problems:" << endl;
        for (int i = 0; i < mathQuestions.size(); i++)
        {
            cout << "Question : " << to_string(i + 1) << endl;
            mathQuestions[i].print(); // Prints question
            cout << endl;
            cout << "-----" << endl;
            cout << mathQuestions[i].getAnswer() << endl;
        }
    }
    cout << "----------------------------------" << endl;
    cout << "Your answered " << getNumOfCorrectAnswers() << " questions correctly." << endl;
    cout << "Your made " << getNumOfWrongAnswers() << " mistakes." << endl;
    cout << "Great job!" << endl;
    cout << "Thank you for using Math Tutor." << endl;
}

// display the questions in errorList for practice again and collect the user answer
// and check if the answer is correct so that it can be removed from the errorList
// return false if all questions have been corrected and removed from the errorList
// otherwise return true: errorList is not empty yet, need more practice
bool MathReport::needMorePractice()
{
    if (errorList.empty())
    {
        return false;
    }
    else
    {
        cout << "You have " << errorList.size() << " questions to practice again." << endl;
        cout << "Please solve the following questions:" << endl;
        for (list<MathOperations>::iterator it = errorList.begin(); it != errorList.end(); it++)
        {
            int i;
            for (i = 0; i < mathQuestions.size(); i++)
            {
                cout << "Question : " << to_string(i + 1) << endl;
                mathQuestions[i].print(); // Prints question
                cout << endl;
                cout << "-----" << endl;
                int response;
                cout << "Please enter your answer: ";
                cin >> response;
            if (it->checkAnswer(response))
            {
                cout << "Congratulations! " << response << " is the right answer." << endl;
                errorList.erase(it);
            }
            else
            {
                cout << "Sorry, the answer is wrong. Please try again." << endl;
            }
        }
        return true;
    }
}
}
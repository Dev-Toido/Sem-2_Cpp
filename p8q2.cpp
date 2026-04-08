// Q2 . AI Exam Proctoring System
// Story:
// An AI-based online exam system must protect student scores and prevent tampering.
// Requirements:
// Create class ExamSession.

// Private:
// studentID
// score
// isSubmitted

// Public:
// startExam()
// submitExam(int marks)
// getResult()

// Conditions:
// Score cannot exceed 100
// Score cannot be changed after submission
// Result accessible only after submission

#include <iostream>
using namespace std;

class ExamSession
{
private:
    int studentID;
    int score;
    bool isSubmitted;

public:
    void startExam()
    {
        cout << "Enter the Student ID: ";
        cin >> studentID;
        cout << "The Exam has been started!!" << endl;
        isSubmitted = false;
        score = 0;
    }
    void submitExam(int marks)
    {
        if (marks > 100)
        {
            cout << "The marks is more then 100, please enter the right marks!!" << endl;
            return;
        }
        if (isSubmitted)
        {
            cout << "The exam has already ended!!" << endl;
            return;
        }
        score = marks;
        isSubmitted = true;
        cout << "The exam is completed and the score is submitted!" << endl;
    }
    void getResult()
    {
        if (isSubmitted)
        {
            cout << "The result of the Student with ID " << studentID << " is " << score << endl;
        }
        else
        {
            cout << "Please submit and end the exam first!!" << endl;
        }
    }
};
int main()
{
    ExamSession e1;
    e1.startExam();
    string buf;
    cout << "Press enter to end the exam";
    cin.ignore();
    getline(cin, buf);
    e1.getResult();
    e1.submitExam(170);
    e1.submitExam(70);
    e1.getResult();
    return 0;
}
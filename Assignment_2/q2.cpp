// Q2. Smart Learning Assessment System
// 🧩 Story
// An online learning platform evaluates different types of learners.
// 🧬 Structure
// Learner → QuizLearner, ProjectLearner, ExamLearner

// 📦 Class Design
// 🔹 Learner
// Attributes:
// string name
// Functions:
// void inputLearner()

// 🔹 QuizLearner
// Attributes:
// int quizScore
// Functions:
// void inputQuiz()
// void evaluate()

// 🔹 ProjectLearner
// Attributes:
// int projectScore
// Functions:
// void inputProject()
// void evaluate()

// 🔹 ExamLearner
// Attributes:
// int examScore
// Functions:
// void inputExam()
// void evaluate()

// 🎯 Tasks
// Evaluate each learner differently
// Display performance

#include <iostream>
#include <string>

using namespace std;

// Base Class: Shared attributes for all learners
class Learner {
protected:
    string name;

public:
    void inputLearner() {
        cout << "Enter Learner Name: ";
        cin.ignore(); // Clear any leftover newline in the buffer
        getline(cin, name);
    }
};

// Derived Class 1: Evaluates based on quick quizzes
class QuizLearner : public Learner {
private:
    int quizScore;

public:
    void inputQuiz() {
        cout << "Enter Quiz Score (0-50): ";
        cin >> quizScore;
    }

    void evaluate() {
        cout << "\n[Quiz Assessment for " << name << "]" << endl;
        if (quizScore >= 40) cout << "Performance: Excellent (Fast Recall)" << endl;
        else if (quizScore >= 25) cout << "Performance: Good" << endl;
        else cout << "Performance: Needs Revision" << endl;
        cout << "------------------------------------" << endl;
    }
};

// Derived Class 2: Evaluates based on practical project work
class ProjectLearner : public Learner {
private:
    int projectScore;

public:
    void inputProject() {
        cout << "Enter Project Score (0-100): ";
        cin >> projectScore;
    }

    void evaluate() {
        cout << "\n[Project Assessment for " << name << "]" << endl;
        if (projectScore >= 80) cout << "Performance: Highly Creative & Practical" << endl;
        else if (projectScore >= 50) cout << "Performance: Competent" << endl;
        else cout << "Performance: Incomplete Implementation" << endl;
        cout << "------------------------------------" << endl;
    }
};

// Derived Class 3: Evaluates based on theoretical examinations
class ExamLearner : public Learner {
private:
    int examScore;

public:
    void inputExam() {
        cout << "Enter Final Exam Score (0-100): ";
        cin >> examScore;
    }

    void evaluate() {
        cout << "\n[Exam Assessment for " << name << "]" << endl;
        if (examScore >= 75) cout << "Performance: Distinguished Scholar" << endl;
        else if (examScore >= 40) cout << "Performance: Satisfactory" << endl;
        else cout << "Performance: Unsuccessful" << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    // 1. Quiz Learner
    QuizLearner ql;
    ql.inputLearner();
    ql.inputQuiz();
    ql.evaluate();

    // 2. Project Learner
    ProjectLearner pl;
    pl.inputLearner();
    pl.inputProject();
    pl.evaluate();

    // 3. Exam Learner
    ExamLearner el;
    el.inputLearner();
    el.inputExam();
    el.evaluate();

    return 0;
}
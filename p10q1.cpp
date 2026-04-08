// Q1. AI-Based Resume Screening System
// 🧩 Story
// A recruitment platform uses AI to shortlist candidates by analyzing both their skills profile and project experience.
// 🧬 Structure
// SkillAnalyzer + ProjectEvaluator → CandidateRanking

// 📦 Class Design
// 🔹 Class: SkillAnalyzer
// Attributes:
// int programmingSkill (0–100)
// int communicationSkill (0–100)
// Member Functions:
// void inputSkills()
// int calculateSkillScore()

// 🔹 Class: ProjectEvaluator
// Attributes:
// int projectCount
// int projectQualityScore (0–100)
// Member Functions:
// void inputProjects()
// int calculateProjectScore()

// 🔹 Class: CandidateRanking
// Attributes:
// float finalScore
// string rank
// Member Functions:
// void evaluateCandidate()
// void displayResult()

// 🎯 Tasks
// Combine both scores to calculate the final score
// Assign rank:
// ≥ 80 → Excellent
// 60–79 → Good
// < 60 → Average 
#include <iostream>
#include <string>

using namespace std;

// Base Class 1: Skill Analysis
class SkillAnalyzer {
protected:
    int programmingSkill;
    int communicationSkill;

public:
    void inputSkills() {
        cout << "Enter Programming Skill (0-100): ";
        cin >> programmingSkill;
        cout << "Enter Communication Skill (0-100): ";
        cin >> communicationSkill;
    }

    int calculateSkillScore() {
        // Returns the average of the two skills
        return (programmingSkill + communicationSkill) / 2;
    }
};

// Base Class 2: Project Evaluation
class ProjectEvaluator {
protected:
    int projectCount;
    int projectQualityScore;

public:
    void inputProjects() {
        cout << "Enter Number of Projects: ";
        cin >> projectCount;
        cout << "Enter Project Quality Score (0-100): ";
        cin >> projectQualityScore;
    }

    int calculateProjectScore() {
        // Score is based on quality, weighted slightly by the number of projects
        int score = projectQualityScore + (projectCount * 2); 
        return (score > 100) ? 100 : score; // Cap score at 100
    }
};

// Derived Class: Multiple Inheritance
class CandidateRanking : public SkillAnalyzer, public ProjectEvaluator {
private:
    float finalScore;
    string rank;

public:
    void evaluateCandidate() {
        // Combining scores from both base classes
        int skillScore = calculateSkillScore();
        int projectScore = calculateProjectScore();
        
        finalScore = (skillScore + projectScore) / 2.0;

        // Assigning Rank based on logic
        if (finalScore >= 80) {
            rank = "Excellent";
        } else if (finalScore >= 60) {
            rank = "Good";
        } else {
            rank = "Average";
        }
    }

    void displayResult() {
        cout << "\n========== CANDIDATE EVALUATION REPORT ==========" << endl;
        cout << "Programming Skill   : " << programmingSkill << endl;
        cout << "Communication Skill : " << communicationSkill << endl;
        cout << "Projects Completed  : " << projectCount << endl;
        cout << "Project Quality     : " << projectQualityScore << endl;
        cout << "------------------------------------------------" << endl;
        cout << "FINAL SCORE         : " << finalScore << endl;
        cout << "RANK                : " << rank << endl;
        cout << "=================================================" << endl;
    }
};

int main() {
    CandidateRanking candidate;

    cout << "--- AI Resume Screening Input ---" << endl;
    candidate.inputSkills();
    candidate.inputProjects();

    candidate.evaluateCandidate();
    candidate.displayResult();

    return 0;
}
// Q4. Sports Score Analyzer
// Story:
//  Two teams’ scores are stored privately. A match analyzer function compares them.
// Class: Team
// Attributes (Private):
// teamName
// score
// Friend Function:
// decideWinner(Team t1, Team t2)
// 👉 Task:
// Compare scores
// Display winner or draw
#include <iostream>
#include <string>

using namespace std;

class Team {
private:
    string teamName;
    int score;

public:
    // Constructor to initialize team details
    Team(string name, int s) {
        teamName = name;
        score = s;
    }

    // Declaring friend function to compare two Team objects
    friend void decideWinner(Team t1, Team t2);
};

// Friend function definition
void decideWinner(Team t1, Team t2) {
    cout << "--- Match Result ---" << endl;
    cout << t1.teamName << ": " << t1.score << endl;
    cout << t2.teamName << ": " << t2.score << endl;
    cout << "--------------------" << endl;

    if (t1.score > t2.score) {
        cout << "Winner: " << t1.teamName << "!" << endl;
    } 
    else if (t2.score > t1.score) {
        cout << "Winner: " << t2.teamName << "!" << endl;
    } 
    else {
        cout << "Result: It's a Draw!" << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    // Creating two team objects with private scores
    Team teamA("Lions", 85);
    Team teamB("Tigers", 92);

    // Using the friend function to analyze the match
    decideWinner(teamA, teamB);

    return 0;
}
// Q1. Gaming Scoreboard System
// Story:
// A gaming tournament tracks scores of players.
// Requirements:
// Class Player
// Player Name
// Scores[5 rounds]

// Create array of objects.
// Determine:
// Highest scorer
// Average score per player
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Player
{
private:
    string playerName;
    int scores[5];
    int total;
    float avg;

public:
    Player()
    {
        playerName = "";
        for (int i = 0; i < 5; i++)
        {
            scores[i] = 0;
        }
    }
    void copyobj(Player &ob)
    {
        playerName = ob.playerName;
        for (int i = 0; i < 5; i++)
        {
            scores[i] = ob.scores[i];
        }
    }

    float sumOfScores()
    {
        float sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += scores[i];
        }
        total = sum;
        return sum;
    }
    float averageOfScores()
    {
        avg = sumOfScores() / 5;
        return avg;
    }
    void setScores()
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> scores[i];
        }
        cout << "Scores Updated!!" << endl;
    }
    void setName()
    {
        cin >> playerName;
    }
    string getName()
    {
        return playerName;
    }
    int *getScores()
    {
        return scores;
    }
};

void playerObjectInit(Player &ob)
{
    {
        cout << "Enter the name of the Player name: ";
        ob.setName();
        cout << "Enter the scores of the 5 rounds: ";
        ob.setScores();
    }
}

struct eventHighScore
{
    string name = "";
    int hscore = 0;
};

int main()
{
    int nplayers;
    cout << "Enter the number of players: ";
    cin >> nplayers;
    Player p[nplayers];
    for (int i = 0; i < nplayers; i++)
    {
        playerObjectInit(p[i]);
    }

    Player highscorer(p[0]);
    for (int i = 0; i < nplayers; i++)
    {
        if (p[i].sumOfScores() > highscorer.sumOfScores())
        {
            highscorer.copyobj(p[i]);
        }
    }

    cout << "The highest total scorer is:" << endl;
    cout << left << setw(20) << "Name: " << highscorer.getName() << endl;
    cout << left << setw(20) << "Total Score: " << highscorer.sumOfScores() << endl;

    int *scores;
    struct eventHighScore scoreBoard[5];
    for (int i = 0; i < nplayers; i++)
    {
        scores = p[i].getScores();
        for (int j = 0; j < 5; j++)
        {
            if (scoreBoard[j].hscore < scores[j])
            {
                scoreBoard[j].hscore = scores[j];
                scoreBoard[j].name = p[i].getName();
            }
        }
    }
    cout << "The highest scorer in the individual event:" << endl;

    cout << left << setw(20) << "Event " << setw(10) << 1 << setw(10) << 2 << setw(10) << 3 << setw(10) << 4 << setw(10) << 5 << endl;
    cout << left << setw(20) << "Name: " << setw(10) << scoreBoard[0].name << setw(10) << scoreBoard[1].name << setw(10) << scoreBoard[2].name << setw(10) << scoreBoard[3].name << setw(10) << scoreBoard[4].name << endl;
    cout << left << setw(20) << "Score: " << setw(10) << scoreBoard[0].hscore << setw(10) << scoreBoard[1].hscore << setw(10) << scoreBoard[2].hscore << setw(10) << scoreBoard[3].hscore << setw(10) << scoreBoard[4].hscore << endl;

    cout << "The Average scores of the players are:" << endl;
    for (int i = 0; i < nplayers; i++)
    {
        cout << left << setw(20) << "Name: " << p[i].getName() << endl;
        cout << left << setw(20) << "Average Score: " << p[i].averageOfScores() << endl
             << string(40, '-') << endl;
    }
    return 0;
}
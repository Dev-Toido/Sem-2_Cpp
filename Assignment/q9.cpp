// Q9. Music Streaming Volume Control
// A music streaming app needs to maintain safe audio levels.
// Requirements:
//     Create class MusicPlayer.
//         Private members:
//             volumeLevel
//             isPlaying
//         Public functions:
//             play()
//             pause()
//             increaseVolume()
//             decreaseVolume()
//             getVolume()
//         Conditions:
//             Volume must stay between 0 and 100
#include <iostream>
using namespace std;

class MusicPlayer
{
private:
    int volumeLevel;
    bool isPlaying;

public:
    MusicPlayer():volumeLevel(0),isPlaying(false){}
    void play()
    {
        if (isPlaying)
        {
            cout << "The Music is already playing!" << endl;
        }
        else
        {
            isPlaying = true;
            cout << "The music is playing" << endl;
        }
    }
    void pause()
    {
        if (!isPlaying)
        {
            cout << "The Music is already paused!" << endl;
        }
        else
        {
            isPlaying = false;
            cout << "The music is paused" << endl;
        }
    }
    void increaseVolume()
    {
        int vol;
        cout << "Enter the amount to increase volume(a number representing the amount of volume to be increased):";
        cin >> vol;
        if (vol + volumeLevel > 100)
        {
            cout << "The volume is set to full!" << endl;
            volumeLevel = 100;
        }
        else
        {
            volumeLevel += vol;
            cout << "The volume is increased sucessfully!" << endl;
        }
    }
    void decreaseVolume()
    {
        int vol;
        cout << "Enter the amount to decrease volume(a number representing the amount of volume to be decreased):";
        cin >> vol;
        if (volumeLevel - vol < 0)
        {
            cout << "The volume is muted!" << endl;
            volumeLevel = 0;
        }
        else
        {
            volumeLevel -= vol;
            cout << "The volume is decreased sucessfully!" << endl;
        }
    }
    void getVolume()
    {
        cout << "The current volume is " << volumeLevel << endl;
    }
};
int main()
{
    MusicPlayer m1;
    m1.play();
    m1.play();
    m1.pause();
    m1.pause();
    m1.increaseVolume();
    m1.decreaseVolume();
    m1.getVolume();
    m1.increaseVolume();
    m1.decreaseVolume();
    m1.getVolume();
    
    return 0;
}
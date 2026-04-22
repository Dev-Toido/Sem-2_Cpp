// Q3 . Smart Media Player
// 🧩 Story
// A media player plays different formats.
// 🧬 Structure
// Media → Audio, Video, LiveStream

// 📦 Class Design
// 🔹 Media
// Functions:
// virtual void play()

// 🔹 Derived Classes
// Override play behavior

// 🎯 Tasks
// Call correct method at runtime
// Demonstrate polymorphism
#include <iostream>
#include <string>

using namespace std;

// Base Class
class Media {
public:
    // The 'virtual' keyword is the secret sauce for polymorphism
    virtual void play() {
        cout << "Opening media player..." << endl;
    }

    // Always use a virtual destructor when dealing with polymorphism
    virtual ~Media() {}
};

// Derived Class 1: Audio
class Audio : public Media {
public:
    void play() override {
        cout << "[AUDIO] >>> Playing: 'Midnight_Jazz.mp3'" << endl;
        cout << "Status : Streaming to Speakers (Stereo)" << endl;
        cout << "---------------------------------------" << endl;
    }
};

// Derived Class 2: Video
class Video : public Media {
public:
    void play() override {
        cout << "[VIDEO] >>> Playing: 'Nature_4K.mp4'" << endl;
        cout << "Status : Rendering 2160p at 60fps" << endl;
        cout << "---------------------------------------" << endl;
    }
};

// Derived Class 3: LiveStream
class LiveStream : public Media {
public:
    void play() override {
        cout << "[LIVE]  >>> Connecting to YouTube..." << endl;
        cout << "Status : Buffering real-time data packets" << endl;
        cout << "---------------------------------------" << endl;
    }
};

int main() {
    // To demonstrate TRUE polymorphism, we use pointers of the Base type
    Media* currentMedia;

    cout << "--- Smart Media Player Initialized ---\n" << endl;

    // 1. Playing Audio
    currentMedia = new Audio();
    currentMedia->play(); // Calls Audio's play()
    delete currentMedia;

    // 2. Playing Video
    currentMedia = new Video();
    currentMedia->play(); // Calls Video's play()
    delete currentMedia;

    // 3. Playing Live Stream
    currentMedia = new LiveStream();
    currentMedia->play(); // Calls LiveStream's play()
    delete currentMedia;

    return 0;
}
// Q2 . File Handling System
// Story:
//  Different file types are opened differently in a system.
// Base Class: File
// Member Function:
// virtual void open()
// Derived Classes:
// TextFile
// ImageFile
// VideoFile
// 👉 Task:
// Override open behavior
// Display file-specific operations
#include <iostream>
#include <string>

using namespace std;

// Base Class
class File
{
public:
    // Virtual function to be overridden by specific file types
    virtual void open()
    {
        cout << "Opening a generic file..." << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~File() {}
};

// Derived Class: TextFile
class TextFile : public File
{
public:
    void open() override
    {
        cout << "[Text File] Opening in Notepad..." << endl;
        cout << ">> Reading text buffer and loading fonts." << endl;
        cout << "---------------------------------------" << endl;
    }
};

// Derived Class: ImageFile
class ImageFile : public File
{
public:
    void open() override
    {
        cout << "[Image File] Opening in Photos Gallery..." << endl;
        cout << ">> Rendering pixels and applying color profiles." << endl;
        cout << "---------------------------------------" << endl;
    }
};

// Derived Class: VideoFile
class VideoFile : public File
{
public:
    void open() override
    {
        cout << "[Video File] Opening in Media Player..." << endl;
        cout << ">> Loading codecs, buffering frames, and syncing audio." << endl;
        cout << "---------------------------------------" << endl;
    }
};

int main()
{
    // Creating objects for each file type
    TextFile doc;
    ImageFile photo;
    VideoFile movie;

    // Demonstrating specific operations
    doc.open();
    photo.open();
    movie.open();

    return 0;
}
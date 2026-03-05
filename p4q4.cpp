// Q 4. Student Login System
// Scenario:
//  A school website allows students to log in.
// Task:
// Class: Login
// Private: username, password
// Public:
// setCredentials()
// checkLogin(inputUser, inputPass)

#include <iostream>
using namespace std;

class Login
{
private:
    string username, password;

public:
    bool setCredentials()
    {
        cout << "Please enter credentials of the student:" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "The credentials are being updated sucessfully!" << endl;
    }
    bool checkLogin(string inputUser, string inputPass)
    {
        if (inputUser == username && inputPass == password)
        {
            cout << "Login Sucessful!!" << endl;
            return true;
        }
        else
        {
            cout << "Wrong username or password!!" << endl;
            return false;
        }
    }
};

int main()
{
    Login s1;
    string username, password;
    bool flag = false;

    s1.setCredentials();

    while (!flag)
    {
        cout << "Please enter credentials of the student to login:" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        flag = s1.checkLogin(username, password);
    }
    return 0;
}
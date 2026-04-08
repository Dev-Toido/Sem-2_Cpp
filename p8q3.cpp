// Q3. OTT Streaming Subscription Control
//     Story:
//         An OTT platform wants to control subscription validity.
//         Requirements:
//         Create class Subscription.
//             Private:
//                 userID
//                 expiryDate
//                 isActive
//             Public:
//                 activatePlan(days)
//                 checkValidity()
//                 getStatus()
//             Conditions:
//                 Expiry date updated internally
//                 Status depends on current date
//                 No direct modification allowed
#include <iostream>
#include <sstream>

using namespace std;
class Date
{
private:
    int day, month, year;
    stringstream dformat; // only use for internal work
    bool isValid;
    string monthNames[12] = {"January", "Februay", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string oridinalRepresentation(int n)
    {
        string str;
        if (n % 10 == 1 && (!(n % 100 == 11)))
        {
            return "st";
        }
        else if (n % 10 == 2 && (!(n % 100 == 12)))
        {
            return "nd";
        }
        else if (n % 10 == 3 && (!(n % 100 == 13)))
        {
            return "rd";
        }
        else
        {
            return "th";
        }
    }

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    };
    Date(string d)
    {
        stringstream datestream(d);
        isValid = false;
        char de;
        datestream >> day >> de >> month >> de >> year;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            monthDays[1] = 29;
        }
        dateValidate();
    }
    void setdate(string d)
    {
        stringstream datestream(d);
        isValid = false;
        char de;
        datestream >> day >> de >> month >> de >> year;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            monthDays[1] = 29;
        }
        dateValidate();
    }
    void dateValidate()
    {
        if ((0 < month && month < 13) && (9999 > year && year > 0) && (0 < day && day <= monthDays[month - 1]))
        {
            isValid = true;
        }
        else
        {
            string d;
            char de;
            cout << "Please enter a valid date!!" << endl;
            cout << "Enter the Valid date in this specfic format (DD/MM/YYYY):- ";
            cin >> d;
            stringstream datestream(d);
            datestream >> day >> de >> month >> de >> year;
            dateValidate();
        }
    }
    void listFormats()
    {
        cout << "For example Day:15 Month:March Year:2007" << endl;
        cout << "Format 1: 15/03/2007" << endl;
        cout << "Format 2: 15th March, 2007." << endl;
    }
    string format1()
    {
        dformat.str("");
        dformat.clear();
        dformat << day << '/' << month << '/' << year;
        return dformat.str();
    }
    string format2()
    {
        dformat.str("");
        dformat.clear();
        dformat << day << oridinalRepresentation(day) << " " << monthNames[month - 1] << ", " << year << '.';
        return dformat.str();
    }
    void operator+=(int pdays)
    {
        day += pdays;
        while (day > monthDays[month - 1])
        {
            day -= monthDays[month - 1];
            month += 1;
            while (month > 12)
            {
                year += 1;
                month -= 12;
            }
        }
    }
    Date operator+(int pdays)
    {
        Date d(this->format1());
        d.day += pdays;
        while (d.day > d.monthDays[d.month - 1])
        {
            d.day -= d.monthDays[d.month - 1];
            d.month += 1;
            while (d.month > 12)
            {
                d.year += 1;
                d.month -= 12;
            }
        }
        return d;
    }
    bool operator>(Date &dd)
    {
        if (year > dd.year)
        {
            return true;
        }
        else if (year == dd.year)
        {
            if (month > dd.month)
            {
                return true;
            }
            else if (month == dd.month)
            {
                if (day > dd.day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<(Date &dd)
    {
        if (year < dd.year)
        {
            return true;
        }
        else if (year == dd.year)
        {
            if (month < dd.month)
            {
                return true;
            }
            else if (month == dd.month)
            {
                if (day < dd.day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator==(Date &dd)
    {
        if (year == dd.year && month == dd.month && year == dd.year)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Subscription
{
private:
    int userID;
    Date expiryDate;
    bool isActive;
    Date curdate;

public:
    Subscription(int uid)
    {
        string d;
        userID=uid;
        cout << "Enter the current date in this specfic format (DD/MM/YYYY):- ";
        cin >> d;
        curdate.setdate(d);
        isActive = false;
    }
    void activatePlan(int days)
    {
        expiryDate = curdate + days;
        checkValidity();
        cout << "The Plan is activated and the expiry date is " << expiryDate.format2()<< endl;
    }
    bool checkValidity()
    {
        if (!(curdate > expiryDate))
        {
            isActive = false;
        }
        else
        {
            isActive = true;
        }
        return isActive;
    }
    void getStatus()
    {
        if (isActive)
        {
            cout << "You plan with user ID " << userID << " has expiried!!" << endl;
        }
        else
        {
            cout << "You with user ID " << userID << " have a active plan!!" << endl;
        }
    }
};
int main()
{
    Subscription s1(123);
    s1.getStatus();
    s1.activatePlan(30);
    s1.getStatus();

    return 0;
}
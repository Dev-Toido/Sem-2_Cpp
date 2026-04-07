// Q7. Medicine Dosage Control System
// A hospital system monitors medication dosage to prevent overdosing.
// Requirements:
//     Create class Medicine.
//         Private members:
//             medicineName
//             dosageMg
//             maxSafeDose
//         Public functions:
//             setDosage()
//             increaseDosage()
//             checkSafety()
//         Conditions:
//             Dosage must not exceed maxSafeDose
#include <iostream>
using namespace std;

class Medicine
{
private:
    string medicineName;
    int dosageMg;
    int maxSafeDose;

public:
    Medicine(string name, int maxsdos)
    {
        medicineName = name;
        maxSafeDose = maxsdos;
        dosageMg = 0;
    }
    void setDosage(int mg)
    {
        if (checkSafety(mg))
        {
            dosageMg = mg;
            cout << "The dosage is updated!!" << endl;
            cout << "The dosage is " << dosageMg << "mg" << endl;
        }
        else
        {
            cout << "The dosage exceeds the safe limits!!" << endl;
        }
    }
    void increaseDosage(int mg)
    {
        if (checkSafety(dosageMg + mg))
        {
            dosageMg += mg;
            cout << "The dosage is updated!!" << endl;
            cout << "The dosage is " << dosageMg << "mg" << endl;
        }
        else
        {
            cout << "The dosage exceeds the safe limits!!" << endl;
        }
    }
    bool checkSafety(int mg)
    {
        return mg <= maxSafeDose;
    }
};
int main()
{
    Medicine m1("Paracetemol", 650);
    m1.setDosage(500);
    m1.increaseDosage(800);
    m1.increaseDosage(150);

    return 0;
}
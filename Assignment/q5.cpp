// Q5. Mobile Data Usage Monitoring
// A telecom company tracks mobile data usage for customers. Data usage must not be directly modified to ensure accurate billing.
// Requirements:
// Create class DataUsage.
//     Private members:
//         userID
//         dataUsed (in MB)
//         dataLimit
//     Public functions:
//         useData(int mb)
//         getRemainingData()
//         checkLimitExceeded()
//     Conditions:
//         Data usage cannot exceed limit
//         Data usage must be positive
#include <iostream>
using namespace std;

class DataUsage
{
private:
    int userID;
    int dataUsed;
    int dataLimit;
public:
    DataUsage(int uid, int limit){
        userID=uid;
        dataLimit=limit;
        dataUsed=0;

    }
    void useDate(int mb){
        dataUsed+=mb;
        if(checkLimitExceeded()){
            cout<<"You have used all data, your data speed will be reduced!"<<endl;
            dataUsed=dataLimit;
        }
        else if(getRemainingData()<100){
            cout<<"Alert! Below 100MB data remaining!"<<endl;
        }
        
        cout<<"Data used: "<<dataUsed<<endl;
    }
    int getRemainingData(){
        return dataLimit-dataUsed;
    }
    bool checkLimitExceeded(){
        return dataLimit<dataUsed;
    }
};

int main()
{
    DataUsage cus1(123,2000);
    cus1.getRemainingData();
    cus1.useDate(1500);
    cus1.getRemainingData();
    cus1.useDate(1500);
    cus1.getRemainingData();


    return 0;
}
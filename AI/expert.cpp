#include <string>
#include <iostream>
using namespace std;

int main()
{
    string name;
    int attendance, task, teamwork, quality, punctuality;
    int totalscore;
    float percentage;
    string performance, suggestion;

    cout << "**************EXPERT SYSTEM FOR EMP EVALUATION************\n";

    cout << "Enter employee name: ";
    cin >> name;

    // Attendance
    while (true)
    {
        cout << "\nEnter Attendance score out of 20:\n";
        cin >> attendance;

        if (attendance >= 0 && attendance <= 20)
            break;

        cout << "Invalid Attendance Score! Enter again.\n";
    }

    // Task
    while (true)
    {
        cout << "\nEnter Task completion score out of 25:\n";
        cin >> task;

        if (task >= 0 && task <= 25)
            break;

        cout << "Invalid Task Score! Enter again.\n";
    }

    // Quality
    while (true)
    {
        cout << "\nEnter Work quality score out of 25:\n";
        cin >> quality;

        if (quality >= 0 && quality <= 25)
            break;

        cout << "Invalid Quality Score! Enter again.\n";
    }

    // Teamwork
    while (true)
    {
        cout << "\nEnter Team work score out of 15:\n";
        cin >> teamwork;

        if (teamwork >= 0 && teamwork <= 15)
            break;

        cout << "Invalid Teamwork Score! Enter again.\n";
    }

    // Punctuality
    while (true)
    {
        cout << "\nEnter punctuality score out of 15:\n";
        cin >> punctuality;

        if (punctuality >= 0 && punctuality <= 15)
            break;

        cout << "Invalid Punctuality Score! Enter again.\n";
    }

    totalscore = attendance + task + quality + teamwork + punctuality;

    percentage = totalscore;

    if (totalscore >= 90)
    {
        performance = "Excellent";
        suggestion = "Eligible for reward or bonus";
    }
    else if (totalscore >= 75)
    {
        performance = "Good";
        suggestion = "Good performance. Keep improving.";
    }
    else if (totalscore >= 60)
    {
        performance = "Average";
        suggestion = "Needs improvement in some areas.";
    }
    else if (totalscore >= 40)
    {
        performance = "Poor";
        suggestion = "Training required.";
    }
    else
    {
        performance = "Very Poor";
        suggestion = "Serious improvement required.";
    }

    cout << "\n===== Evaluation Result =====\n";
    cout << "Employee Name : " << name << endl;
    cout << "Total Score : " << totalscore << "/100" << endl;
    cout << "Percentage : " << percentage << "%" << endl;
    cout << "Performance : " << performance << endl;
    cout << "Suggestion : " << suggestion << endl;

    return 0;
}
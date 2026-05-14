#include <iostream>
#include <string>
using namespace std;

int main()
{
string name;
int attendance, task, quality, teamwork, punctuality;
int totalScore;
float percentage;
string performance, suggestion;

cout << "===== Employee Performance Evaluation Expert System =====\n";

cout << "Enter employee name: ";
getline(cin, name);

cout << "Enter attendance score out of 20: ";
cin >> attendance;

cout << "Enter task completion score out of 25: ";
cin >> task;

cout << "Enter work quality score out of 25: ";
cin >> quality;

cout << "Enter teamwork score out of 15: ";
cin >> teamwork;

cout << "Enter punctuality score out of 15: ";
cin >> punctuality;

// Validation
if(attendance < 0 || attendance > 20 ||
task < 0 || task > 25 ||
quality < 0 || quality > 25 ||
teamwork < 0 || teamwork > 15 ||
punctuality < 0 || punctuality > 15)
{
cout << "\nInvalid input entered!";
return 0;
}

totalScore = attendance + task + quality + teamwork + punctuality;
percentage = (static_cast<float>(totalScore) / 100) * 100;

// Expert Rules
if(totalScore >= 90)
{
performance = "Excellent";
suggestion = "Eligible for promotion or reward.";
}
else if(totalScore >= 75)
{
performance = "Good";
suggestion = "Good performance. Keep improving.";
}
else if(totalScore >= 60)
{
performance = "Average";
suggestion = "Needs improvement in some areas.";
}
else if(totalScore >= 40)
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
cout << "Total Score : " << totalScore << "/100" << endl;
cout << "Percentage : " << percentage << "%" << endl;
cout << "Performance : " << performance << endl;
cout << "Suggestion : " << suggestion << endl;

return 0;
}
#ifndef JOBPOSITION_H
#define JOBPOSITION_H

#include <iostream>
using namespace std;

class JobPosition {
private:
    string jobID;
    string title;
    string description;
    vector<string> requiredSkills;
    int seatsAvailable;

public:
    void read() {
        cin.ignore();
        cout << "Enter Job ID: ";
        getline(cin, jobID);

        cout << "Enter Job Title: ";
        getline(cin, title);

        cout << "Enter Job Description: ";
        getline(cin, description);

        cout << "Enter Number of Available Seats: ";
        cin >> seatsAvailable;
        cin.ignore();

        int n;
        cout << "Enter number of required skills: ";
        cin >> n;
        cin.ignore();

        requiredSkills.clear();
        for (int i = 0; i < n; ++i) {
            string skill;
            cout << "Enter Skill #" << i + 1 << ": ";
            getline(cin, skill);

            for (char& ch : skill) {
                if (ch == ' ')
                    ch = '_';
            }

            requiredSkills.push_back(skill);
        }
    }

    string getJobID() const { return jobID; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    vector<string> getRequiredSkills() const { return requiredSkills; }
    int getSeatsAvailable() const { return seatsAvailable; }

    void decreaseSeat() { if (seatsAvailable > 0) seatsAvailable--; }

    JobPosition() {}
    JobPosition(string id, string title, string desc, vector<string> skills, int seats) {
        this->jobID = id;
        this->title = title;
        this->description = desc;
        this->requiredSkills = skills;
        this->seatsAvailable = seats;
    }

    void print() {
        cout << "\nJob ID: " << jobID << "\nTitle: " << title << "\nDescription: " << description << "\nSeats: " << seatsAvailable << "\nSkills: ";
        for (auto& s : requiredSkills) cout << s << ", ";
        cout << endl;
    }
};

#endif
#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
using namespace std;

class Candidate {
private:
    string name;
    string email;
    string cvFilename;

public:
    void read() {
        cin.ignore();
        cout << "Enter Your Name: ";
        getline(cin, name);
        cout << "Enter Your Email: ";
        getline(cin, email);
        cout << "Enter CV File Name (e.g., cv1.txt): ";
        getline(cin, cvFilename);
    }

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getCVFilename() const { return cvFilename; }

    string getCVContent() {
        ifstream file("cvs/" + cvFilename);
        if (!file.is_open()) return "";
        string line, content;
        while (getline(file, line)) content += line + " ";
        return content;
    }

    Candidate() {}
    Candidate(string name, string email, string path) {
        this->name = name;
        this->email = email;
        this->cvFilename = path;
    }

    void print() {
        cout << "Candidate Name: " << name << ", Email: " << email << ", CV: " << cvFilename << endl;
    }
};

#endif

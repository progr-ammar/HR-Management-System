#include <iostream>
#include <Windows.h>
#include "hrSystem.h"
using namespace std;

HRSystem* hr = new HRSystem;
vector<Candidate> recommendedList;
vector<JobPosition> jobList;
void recruitmentHandle();

void employeeHandle()
{
    int ch;
    do
    {
        system("cls");
        system("color 0B");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--  EMPLOYEE INFO. MANAGEMENT ----|\033[0m" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] Add An Employee\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Assign Employee To A Department\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[3] Assign Employee To A Benefit\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[4] Delete An Employee\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[5] Modify An Employee\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[6] Search For An Employee\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[7] Show All Employees\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[8] Recruitment System\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Return To Main Menu\033[0m" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            hr->addEmployee();
            break;
        case 2:
            hr->assignDepart();
            break;
        case 3:
            hr->assignBenefit();
            break;
        case 4:
            hr->deleteEmployee();
            break;
        case 5:
            hr->modifyEmployee();
            break;
        case 6:
            hr->searchEmployee();
            break;
        case 7:
            hr->printemploye();
            system("pause");
            system("cls");
            break;
        case 8:
            recruitmentHandle();
            break;

        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 0);
}

void departHandle()
{
    int ch2;
    do
    {
        system("cls");
        system("color 0C");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--EMPLOYEE DEPARTMENT MANAGEMENT--|\033[0m" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] Add A Department\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Delete A Department\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[3] Modify A Department\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[4] Show Departments\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Return To Main menu\033[0m" << endl;
        cin >> ch2;
        switch (ch2)
        {
        case 1:
            hr->addDepart();
            break;
        case 2:
            hr->deleteDepart();
            break;
        case 3:
            hr->modifyDepart();
            break;
        case 4:
            system("cls");
            hr->showDepart();
            system("pause");
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch2 != 0);
}

void benefitsHandle()
{
    int ch;
    do
    {
        system("cls");
        system("color 0D");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|-- EMPLOYEE BENEFITS MANAGEMENT --|\033[0m" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] Add A Benefit\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Delete A Benefit\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[3] Modify A Benefit\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[4] Show Benefits\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Return To Main menu\033[0m" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            hr->addBenefit();
            break;
        case 2:
            hr->deleteBenefit();
            break;
        case 3:
            hr->modifyBenefit();
            break;
        case 4:
            system("cls");

            hr->showBenefits();
            system("pause");
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 0);
}

void salaryHandle()
{
    int ch;
    do
    {
        system("cls");
        system("color 0E");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--       Salary MANAGEMENT      --|\033[0m" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] Employee Salary\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Total Salary\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Return To Main menu\033[0m" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            hr->employeeSalary();
            break;
        case 2:
            hr->totalSalary();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 0);
}

void searchHandle()
{
    int ch;
    do
    {
        system("cls");
        system("color 0F");
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--  SEARCH SECTION MANAGEMENT   --|\033[0m" << endl;
        cout << "\t\t\t------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] Search For An Employee\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Search For A department\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[3] Search For A Benefit System\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Return To Main menu\033[0m" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            hr->searchEmployee();
            break;
        case 2:
            hr->searchDepart();
            break;
        case 3:
            hr->searchBenefit();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 0);
}

void saveJobsToFile()
{
    ofstream out("jobs.csv");
    for (const auto& job : jobList)
    {
        out << job.getJobID() << ","
            << job.getTitle() << ","
            << job.getDescription() << ","
            << job.getSeatsAvailable();

        vector<string> skills = job.getRequiredSkills();
        for (const auto& skill : skills)
            out << "," << skill;
        out << "\n";
    }
    out.close();
}

void loadJobsFromFile()
{
    ifstream in("jobs.csv");
    if (!in.is_open())
        return;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string id, title, desc, token;
        int seats;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, desc, ',');
        ss >> seats;
        ss.ignore();

        vector<string> skills;
        while (getline(ss, token, ','))
        {
            skills.push_back(token);
        }

        JobPosition job(id, title, desc, skills, seats);
        jobList.push_back(job);
    }
    in.close();
}

void saveRecommendationsToFile()
{
    ofstream out("recommendations.csv");
    for (const auto& cand : recommendedList)
    {
        out << cand.getName() << ","
            << cand.getEmail() << ","
            << cand.getCVFilename() << "\n";
    }
    out.close();
}

void loadRecommendationsFromFile()
{
    ifstream in("recommendations.csv");
    if (!in.is_open())
        return;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string name, email, path;
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, path);

        Candidate c(name, email, path);
        recommendedList.push_back(c);
    }
    in.close();
}

bool doesMatch(JobPosition& job, Candidate& candidate)
{
    string cv = candidate.getCVContent();
    vector<string> skills = job.getRequiredSkills();
    for (string s : skills)
    {
        if (cv.find(s) == string::npos)
            return false;
    }
    return true;
}

void recruitmentHandle()
{
    int ch;
    do
    {
        system("cls");
        system("color 0B");
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--      RECRUITMENT SYSTEM        --|\033[0m" << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t\033[1;33m[1] HR - Post a New Job\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[2] Recruit - Upload CV\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[3] HR - View Recommendations\033[0m" << endl;
        cout << "\t\t\t\033[1;33m[0] Exit Recruitment\033[0m" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        if (ch == 1)
        {
            system("cls");
            cout << "\n\033[1;34m[HR] Post a New Job Position\033[0m\n";
            JobPosition job;
            job.read();
            bool duplicate = false;
            for (auto& existing : jobList) {
                if (existing.getJobID() == job.getJobID()) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) {
                cout << "Duplicate Job ID. Try another.\n";
            }
            else {
                jobList.push_back(job);
                saveJobsToFile();
                cout << "\n\033[1;32m Job posted successfully!\033[0m\n";
            }
        }
        else if (ch == 2) {
            system("cls");
            cout << "\n\033[1;34m[Recruit] Upload Your CV\033[0m\n";
            Candidate cand;
            cand.read();

            for (const auto& c : recommendedList) {
                if (c.getEmail() == cand.getEmail()) {
                    cout << "\n\033[1;31m You have already applied. Duplicate CV not allowed.\033[0m\n";
                    system("pause");
                    return;
                }
            }

            bool matched = false;
            for (auto& job : jobList) {
                if (job.getSeatsAvailable() > 0 && doesMatch(job, cand)) {
                    recommendedList.push_back(cand);
                    job.decreaseSeat();
                    saveRecommendationsToFile();
                    saveJobsToFile();
                    cout << "\n\033[1;32m Your CV matches Job ID: " << job.getJobID() << " - " << job.getTitle() << "\033[0m\n";
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                cout << "\n\033[1;31m Sorry, your CV did not match any current job.\033[0m\n";
            }
            system("pause");
        }

        else if (ch == 3)
        {
            system("cls");
            cout << "\n\033[1;34m[HR] Viewing Recommended Candidates\033[0m\n";
            if (recommendedList.empty())
            {
                cout << "\n\033[1;31m No candidates matched yet.\033[0m\n";
            }
            else
            {
                cout << "\n\033[1;32m Recommended Candidates:\033[0m\n\n";
                for (auto& c : recommendedList)
                {
                    c.print();
                    cout << "-------------------------\n";
                }
            }
        }
        else if (ch != 0)
        {
            cout << "\n\033[1;31mInvalid option. Please try again.\033[0m\n";
        }

        system("pause");
    } while (ch != 0);
}

int main()
{

    loadJobsFromFile();
    loadRecommendationsFromFile();

    int role;
    system("color 0F");
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\033[1;34m|--    HR MANAGEMENT SYSTEM    ----|\033[0m" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\033[1;33m[1] Login as HR\033[0m" << endl;
    cout << "\t\t\t\033[1;33m[2] Login as Recruit (Job Seeker)\033[0m" << endl;
    cout << "\t\t\t\033[1;33m[0] Exit\033[0m" << endl;
    cout << "Enter Your Choice: ";
    cin >> role;

    if (role == 1)
    {
        int choice;
        do
        {
            system("cls");
            system("color 0F");
            cout << "\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\033[1;34m|--    HR MANAGEMENT SYSTEM    ----|\033[0m" << endl;
            cout << "\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\033[1;33m[1] Employee Information Management\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[2] Benefits Management\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[3] Department Management\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[4] Salary Calculation\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[5] Reporting\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[6] Search\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[7] Recruitment System\033[0m" << endl;
            cout << "\t\t\t\033[1;33m[0] Exit\033[0m" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                employeeHandle();
                break;
            case 2:
                benefitsHandle();
                break;
            case 3:
                departHandle();
                break;
            case 4:
                salaryHandle();
                break;
            case 5:
                hr->employeeReporting();
                break;
            case 6:
                searchHandle();
                break;
            case 7:
                recruitmentHandle();
                break;
            case 0:
                break;
            default:
                cout << "Invalid option.\n";
            }
        } while (choice != 0);
    }
    else if (role == 2)
    {
        system("cls");
        system("color 0F");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t\033[1;34m|--     RECRUIT LOGIN     --|\033[0m" << endl;
        cout << "\t\t\t-----------------------------" << endl;

        Candidate cand;
        cand.read();

        bool matched = false;
        for (auto& job : jobList)
        {
            if (job.getSeatsAvailable() > 0 && doesMatch(job, cand))
            {
                recommendedList.push_back(cand);
                job.decreaseSeat();
                saveRecommendationsToFile();
                saveJobsToFile();

                cout << "\n\033[1;32m Your CV matches Job ID: " << job.getJobID() << " - " << job.getTitle() << "\033[0m\n";
                matched = true;
                break;
            }
        }

        if (!matched)
        {
            cout << "\n\033[1;31m Sorry, your CV did not match any current job.\033[0m\n";
        }

        system("pause");
    }

    else if (role == 0)
    {
        cout << "\nThank you for using the HR Management System. Goodbye!\n";
    }
    else
    {
        cout << "Invalid choice. Restart the application.\n";
    }

    delete hr;
    return 0;
}
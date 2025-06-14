#ifndef HRSYSTEM_H
#define HRSYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 
#include "employee.h"
#include "hourlyEmployee.h"
#include "commissionEmployee.h"
#include "salariedEmployee.h"
#include "managerEmployee.h"
#include "benefits.h"
#include "healthBenefit.h"
#include "dentalBenefit.h"
#include "department.h"
#include "jobPosition.h"
#include "candidate.h"

using namespace std;

class HRSystem {
private:
    Employee** employeeList;
    int e_capacity;
    int e_size;
    Department** departList;
    int d_size;
    Benefits** benefitList;
    int b_size;

public:
    HRSystem() : e_capacity(10), e_size(0), d_size(0), b_size(0) {
        employeeList = new Employee * [e_capacity] {nullptr};
        departList = new Department * [6] {nullptr};
        benefitList = new Benefits * [6] {nullptr};
        loadDepartments();
        loadBenefits();
        loadEmployees();
    }

    ~HRSystem() {
        saveDepartments();
        saveBenefits();
        saveEmployees();
        cleanUp();
    }

    void saveDepartments() {
        ofstream outFile("departments.csv", ios::out | ios::trunc);
        if (!outFile.is_open()) {
            cerr << "Failed to open departments.csv for writing." << endl;
            return;
        }
        for (int i = 0; i < d_size; i++) {
            if (departList[i] != nullptr) {
                outFile << departList[i]->getDepartmentID() << "," << departList[i]->getDepartmentName() << "\n";
            }
        }
        outFile.close();
    }


    void loadDepartments() {
        ifstream inFile("departments.csv");
        if (!inFile) {
            cerr << "Error opening departments.csv for reading." << std::endl;
            return;
        }
        string line, id, name;
        while (getline(inFile, line)) {
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, name);
            if (d_size < 6) {
                Department* newDepart = new Department();
                newDepart->setDepartmentID(id);
                newDepart->setDepartmentName(name);
                departList[d_size++] = newDepart;
            }
        }
        inFile.close();
    }

    //void saveEmployees() {
    //    ofstream outFile("employees.csv");
    //    for (int i = 0; i < e_size; i++) {
    //        outFile << employeeList[i]->getType() << "," 
    //            << employeeList[i]->getName() << ","
    //            << employeeList[i]->getPhone() << ","
    //            << employeeList[i]->getEmail() << ","
    //            << employeeList[i]->getEmployeeID() << ","
    //            << employeeList[i]->getJobTitle() << ","
    //            << employeeList[i]->getSalary() << "\n";
    //    }
    //    outFile.close();
    //}

    void saveEmployees() {
        ofstream out("employees.csv", ios::trunc);
        for (int i = 0; i < e_size; i++) {
            Employee* e = employeeList[i];
            out << e->getType() << ','
                << e->getName() << ','
                << e->getPhone() << ','
                << e->getEmail() << ','
                << e->getEmployeeID() << ','
                << e->getJobTitle() << ','
                << e->getDepartID() << ','
                << e->getBenefitID() << ',';

            char t = e->getType();
            if (t == 'h') {
                auto* h = static_cast<HourlyEmployee*>(e);
                out << fixed << setprecision(2)
                    << h->getHoursWorked() << ',' << h->getRate();
            }
            else if (t == 'c') {
                auto* c = static_cast<CommissionEmployee*>(e);
                out << fixed << setprecision(2)
                    << c->getTarget() << ',' << c->getRate();
            }
            else if (t == 's') {
                auto* s = static_cast<SalariedEmployee*>(e);
                out << fixed << setprecision(2)
                    << s->getSalary();
            }
            else if (t == 'm') {
                auto* m = static_cast<ManagerEmployee*>(e);
                out << fixed << setprecision(2)
                    << m->getSalary() << ',' << m->getBonus();
            }
            out << '\n';
        }
    }

    void loadEmployees() {
        ifstream in("employees.csv");
        if (!in.is_open()) return;

        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string type, name, phone, email, id, title, deptID, benID;

            getline(ss, type, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, deptID, ',');
            getline(ss, benID, ',');

            Employee* e = createEmployeeByType(type);
            if (!e) continue;

            e->setName(name);
            e->setPhone(phone);
            e->setEmail(email);
            e->setEmployeeID(id);
            e->setJobTitle(title);

            char t = e->getType();
            if (t == 'h') {
                double hours, rate;
                ss >> hours; ss.ignore();
                ss >> rate;
                auto* h = static_cast<HourlyEmployee*>(e);
                h->setHoursWorked(hours);
                h->setRate(rate);
            }
            else if (t == 'c') {
                double target, rate;
                ss >> target; ss.ignore();
                ss >> rate;
                auto* c = static_cast<CommissionEmployee*>(e);
                c->setTarget(target);
                c->setRate(rate);
            }
            else if (t == 's') {
                double sal; ss >> sal;
                auto* s = static_cast<SalariedEmployee*>(e);
                s->setSalary(sal);
            }
            else if (t == 'm') {
                double sal, bonus;
                ss >> sal; ss.ignore();
                ss >> bonus;
                auto* m = static_cast<ManagerEmployee*>(e);
                m->setSalary(sal);
                m->setBonus(bonus);
            }

            if (!deptID.empty()) {
                for (int j = 0; j < d_size; j++) {
                    if (departList[j]->getDepartmentID() == deptID) {
                        e->setDepart(departList[j]);
                        break;
                    }
                }
            }
            if (!benID.empty()) {
                for (int j = 0; j < b_size; j++) {
                    if (benefitList[j]->getBenefitId() == benID) {
                        e->setBenefit(benefitList[j]);
                        break;
                    }
                }
            }

            if (e_size < e_capacity) {
                employeeList[e_size++] = e;
            }
            else {
                delete e; 
            }
        }
    }



    /*void loadEmployees() {
        ifstream inFile("employees.csv");
        if (!inFile.is_open()) {
            cerr << "Error opening employees.csv for reading." << endl;
            return;
        }
        string line, type, name, phone, email, id, jobTitle;
        int count = 0;

        while (getline(inFile, line)) {
            stringstream ss(line);

            getline(ss, type, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, id, ',');
            getline(ss, jobTitle);

            if (e_size >= e_capacity) {
                cerr << "Reached maximum capacity. No more employees can be added." << endl;
                break;
            }

            Employee* emp = createEmployeeByType(type);
            if (!emp) {
                cerr << "Invalid employee type: '" << type << "' on line " << count + 1 << endl;
                continue;
            }

            emp->setName(name);
            emp->setPhone(phone);
            emp->setEmail(email);
            emp->setEmployeeID(id);
            emp->setJobTitle(jobTitle);
            employeeList[e_size++] = emp;
            count++;
        }
        inFile.close();

        cout << "Total employees loaded: " << count << endl;
    }*/


    void saveBenefits() {
        ofstream outFile("benefits.csv");
        for (int i = 0; i < b_size; i++) {
            outFile << (typeid(*benefitList[i]) == typeid(HealthBenefit) ? "Health" : "Dental") << ","
                << benefitList[i]->getBenefitId() << ","
                << benefitList[i]->getPlanType() << ","
                << benefitList[i]->getAmount() << "\n";
        }
        outFile.close();
    }

    void loadBenefits() {
        ifstream inFile("benefits.csv");
        if (!inFile.is_open()) {
            cerr << "Error opening benefits.csv for reading." << endl;
            return;
        }
        string line, type, id, planType, amountStr;
        while (getline(inFile, line)) {
            stringstream ss(line);
            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, planType, ',');
            getline(ss, amountStr);
            Benefits* benefit = createBenefitByType(type);
            if (benefit && b_size < 6) {
                benefit->setBenefitID(id);
                benefit->setPlanType(planType);
                benefit->setAmount(stod(amountStr));
                benefitList[b_size++] = benefit;
            }
        }
        inFile.close();
    }

    void resize() {
        int new_capacity = e_capacity * 2;
        Employee** new_array = new Employee * [new_capacity] {nullptr};
        for (int i = 0; i < e_size; i++) {
            new_array[i] = employeeList[i];
        }
        delete[] employeeList;
        employeeList = new_array;
        e_capacity = new_capacity;
    }

    void cleanUp() {
        for (int i = 0; i < e_size; i++) {
            delete employeeList[i];
        }
        delete[] employeeList;
        for (int i = 0; i < d_size; i++) {
            delete departList[i];
        }
        delete[] departList;
        for (int i = 0; i < b_size; i++) {
            delete benefitList[i];
        }
        delete[] benefitList;
    }

    Employee* createEmployeeByType(const string& type) {
        if (type == "h") return new HourlyEmployee();
        if (type == "c") return new CommissionEmployee();
        if (type == "s") return new SalariedEmployee();
        if (type == "m") return new ManagerEmployee();
        return nullptr;
    }

    Benefits* createBenefitByType(const string& type) {
        if (type == "Health") return new HealthBenefit();
        if (type == "Dental") return new DentalBenefit();
        return nullptr;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    void addDepart()
    {
        system("cls");
        system("color 7");

        if (d_size >= 6) {
            cout << "Department limit reached (6 max).\n";
            system("pause");
            return;
        }

        Department* newDept = new Department();
        newDept->read();

        for (int i = 0; i < d_size; i++) {
            if (departList[i]->getDepartmentID() == newDept->getDepartmentID() ||
                departList[i]->getDepartmentName() == newDept->getDepartmentName()) {
                cout << "Duplicate Department ID or Name found. Not added.\n";
                delete newDept;
                system("pause");
                return;
            }
        }

        departList[d_size++] = newDept;
        saveDepartments();
        cout << "Department added successfully.\n";
        system("pause");
        system("cls");
    }

    int departSearchHelper()
    {
        string search;
        bool found = false;

        cout << "Enter Depart Name or ID: ";
        getline(cin >> ws, search);

        for (int i = 0; i < d_size; i++)
        {
            if (departList[i]->getDepartmentName() == search || departList[i]->getDepartmentID() == search)
            {
                found = true;
                cout << "\t\tDepartment Found!" << endl;
                return i;
                break;
            }
        }

        if (!found)
        {
            cout << "Department Was Not Found!" << endl;
            return -1;
        }
    }


    void deleteDepart()
    {
        system("cls");
        system("color 7");
        showDepart();
        int index = departSearchHelper();
        if (index != -1)
        {
            for (int j = index; j < d_size; j++)
            {
                departList[j] = departList[j + 1];
            }

            d_size--;
            cout << "\t\tDepartment Deleted Successfully.\n\n" << endl;
            saveDepartments();
        }

        system("pause");
        system("cls");
    }

    void modifyDepart()
    {
        system("cls");
        system("color 7");
        showDepart();
        cout << "\n\n";

        int index = departSearchHelper();

        if (index != -1)
        {


            cout << "\t\tEnter New Informations:-" << endl;
            departList[index]->read();
            cout << "Department Updated Successfully!" << endl;
        }
        saveDepartments();
        system("pause");
        system("cls");
    }

    void searchDepart()
    {
        system("cls");
        system("color 7");

        int index = departSearchHelper();

        if (index != -1)
        {
            departList[index]->print();
        }

        system("pause");
        system("cls");
    }

    void showDepart()
    {

        system("color 0E");

        if (d_size == 0)
        {
            cout << "No Departments Signed!" << endl;
        }
        else
        {

            int maxNameLength = 0;
            int maxIDLength = 0;
            for (int i = 0; i < d_size; i++)
            {
                int nameLength = departList[i]->getDepartmentName().length();
                string id = departList[i]->getDepartmentID();
                int idLength = id.length();
                if (nameLength > maxNameLength)
                    maxNameLength = nameLength;
                if (idLength > maxIDLength)
                    maxIDLength = idLength;
            }


            int nameWidth = maxNameLength + 15;
            int idWidth = maxIDLength + 15;

            cout << setfill('-') << setw(nameWidth + idWidth + 4) << "-" << endl;
            cout << setfill(' ') << "| " << setw(idWidth) << left << "Department ID" << " | " << setw(nameWidth) << "Department Name" << " |" << endl;
            cout << setfill('-') << setw(nameWidth + idWidth + 6) << "-" << endl;

            for (int i = 0; i < d_size; i++)
            {
                cout << setfill(' ') << "| " << setw(idWidth) << left << departList[i]->getDepartmentID() << " | " << setw(nameWidth) << departList[i]->getDepartmentName() << " |" << endl;
                cout << setfill('-') << setw(nameWidth + idWidth + 6) << "-" << endl;
            }
        }

    }

    ///////////////////////////////////////////////////////////////////////////////////
    int benefitSearchHelper()
    {
        string search;
        bool found = false;
        cout << "Enter ID Of The benefit : ";
        getline(cin >> ws, search);

        for (int i = 0; i < b_size; i++)
        {
            if (benefitList[i]->getBenefitId() == search)
            {
                found = true;
                cout << "\t\tBenefit System Found!" << endl;
                return i;
                break;
            }
        }

        if (!found)
        {
            cout << "\t\tBenefit System Not Found!" << endl;
            return -1;
        }
    }

    void addBenefit()
    {
        system("cls");
        system("color 7");

        if (b_size >= 6) {
            cout << "Cannot add more than 6 benefits.\n";
            system("pause");
            return;
        }

        int type;
        bool flag = true;
        cout << "Enter Benefit Type ([1] Health, [2] Dental): ";
        cin >> type;

        switch (type)
        {
        case 1: benefitList[b_size] = new HealthBenefit(); break;
        case 2: benefitList[b_size] = new DentalBenefit(); break;
        default:
            cout << "Invalid input. Try again!\n";
            flag = false;
            break;
        }

        if (flag)
        {
            benefitList[b_size]->read();

            for (int i = 0; i < b_size; i++) {
                if (benefitList[i]->getBenefitId() == benefitList[b_size]->getBenefitId()) {
                    cout << "Duplicate Benefit ID. Not added.\n";
                    delete benefitList[b_size];
                    return;
                }
            }

            b_size++;
            saveBenefits();
            cout << "Benefit added successfully!\n";
        }
        system("pause");
        system("cls");
    }


    void deleteBenefit()
    {
        system("cls");
        system("color 7");
        showBenefits();

        int index = benefitSearchHelper();

        if (index != -1)
        {
            for (int j = index; j < b_size; j++)
            {
                benefitList[j] = benefitList[j + 1];
            }

            b_size--;
            cout << "\t\tBenefit Deleted Successfully!" << endl;
        }
        saveBenefits();
        system("pause");
        system("cls");
    }

    void modifyBenefit()
    {
        system("cls");
        system("color 7");
        showBenefits();
        int index = benefitSearchHelper();

        if (index != -1)
        {
            cout << "\t\tEnter New Informations :-" << endl;
            benefitList[index]->read();
            cout << "\t\tBenefit Edited Successfully!" << endl;
        }
        saveBenefits();
        system("pause");
        system("cls");
    }

    void searchBenefit()
    {
        system("cls");
        system("color 7");

        int index = benefitSearchHelper();

        if (index != -1)
        {
            benefitList[index]->print();
        }

        system("pause");
        system("cls");
    }

    void showBenefits()
    {
        system("color 0E");

        if (b_size == 0)
        {
            cout << "No Benefits Signed!" << endl;
        }

        else
        {
            cout << "[ Benefits ] :- " << endl;
            int maxIDLength = 0;
            int maxPlanTypeLength = 0;
            int maxAmountLength = 0;

            for (int i = 0; i < b_size; i++)
            {
                string id = benefitList[i]->getBenefitId();
                int idLength = id.length();
                int planTypeLength = benefitList[i]->getPlanType().length();
                int amountLength = to_string(benefitList[i]->getAmount()).length();

                if (idLength > maxIDLength)
                    maxIDLength = idLength;
                if (planTypeLength > maxPlanTypeLength)
                    maxPlanTypeLength = planTypeLength;
                if (amountLength > maxAmountLength)
                    maxAmountLength = amountLength;
            }


            int idWidth = maxIDLength + 5;
            int planTypeWidth = maxPlanTypeLength + 5;
            int amountWidth = maxAmountLength + 5;

            cout << setfill('-') << setw(idWidth + planTypeWidth + amountWidth + 15) << "-" << endl;
            cout << setfill(' ') << "| " << setw(idWidth) << left << "ID"
                << " | " << setw(planTypeWidth) << "Plan Type"
                << " | " << setw(amountWidth) << "Amount" << " |" << endl;
            cout << setfill('-') << setw(idWidth + planTypeWidth + amountWidth + 15) << "-" << endl;

            for (int i = 0; i < b_size; i++)
            {
                cout << setfill(' ') << "| " << setw(idWidth) << left << benefitList[i]->getBenefitId()
                    << " | " << setw(planTypeWidth) << benefitList[i]->getPlanType()
                    << " | " << setw(amountWidth) << benefitList[i]->getAmount() << " |" << endl;
                cout << setfill('-') << setw(idWidth + planTypeWidth + amountWidth + 15) << "-" << endl;
            }
        }

    }
    //////////////////////////////////////////////////////////////////////////////////
    int employeeSearchHelper()
    {
        string search;
        bool found = false;

        cout << "Enter Employee's Email OR ID : ";
        getline(cin >> ws, search);

        for (int i = 0; i < e_size; i++)
        {
            if (employeeList[i]->getName() == search || employeeList[i]->getPhone() == search || employeeList[i]->getEmail() == search || employeeList[i]->getEmployeeID() == search)
            {
                found = true;
                cout << "\t\t\nEmployee Found!" << endl;
                return i;
                break;
            }
        }

        if (!found)
        {
            cout << "\t\t\nEmployee Was Not Found!" << endl;
            return -1;
        }

    }


    void addEmployee()
    {
        system("cls");
        system("color 7");

        if (e_size == e_capacity)
            resize();

        int type;
        bool validInput = true;

        cout << "Enter Employee Type ([1] Hourly, [2] Commission, [3] Salaried, [4] Manager): ";
        cin >> type;

        switch (type)
        {
        case 1: employeeList[e_size] = new HourlyEmployee(); break;
        case 2: employeeList[e_size] = new CommissionEmployee(); break;
        case 3: employeeList[e_size] = new SalariedEmployee(); break;
        case 4: employeeList[e_size] = new ManagerEmployee(); break;
        default:
            cout << "Invalid employee type!\n";
            validInput = false;
            break;
        }

        if (validInput)
        {
            employeeList[e_size]->read();

            for (int i = 0; i < e_size; i++) {
                if (employeeList[i]->getEmployeeID() == employeeList[e_size]->getEmployeeID() ||
                    employeeList[i]->getEmail() == employeeList[e_size]->getEmail()) {
                    cout << "Duplicate Employee ID or Email detected. Employee not added.\n";
                    delete employeeList[e_size];
                    return;
                }
            }

            e_size++;
            saveEmployees();
            cout << "Employee added successfully.\n";
        }
        system("pause");
        system("cls");
    }


    void assignDepart()
    {
        system("cls");
        system("color 7");

        printemploye();
        cout << "\n\n";
        int employeeIndex = employeeSearchHelper();
        if (employeeIndex != -1)
        {
            cout << "\nList Of Departments :-\n" << endl;
            /*for (int i = 0; i < d_size; i++)
            {
                cout << "[" << i + 1 << "]. ";
                departList[i]->print();
                cout << "\n";
            }*/
            showDepart();

            int departIndex = departSearchHelper();

            if (departIndex != -1)
            {
                Department* temp = departList[departIndex];
                employeeList[employeeIndex]->setDepart(temp);
                cout << "Department Assigned Successfully!" << endl;
            }
        }

        saveEmployees();
        saveDepartments();

        system("pause");
        system("cls");
    }

    void assignBenefit()
    {
        system("cls");
        system("color 7");
        printemploye();
        cout << "\n\n";
        int employeeIndex = employeeSearchHelper();

        if (employeeIndex != -1)
        {
            showBenefits();

            int benefitIndex = benefitSearchHelper();

            if (benefitIndex != -1)
            {
                Benefits* temp = benefitList[benefitIndex];
                employeeList[employeeIndex]->setBenefit(temp);
                cout << "Benefit Assigned Successfully!" << endl;
            }
        }

        saveEmployees();   
        saveBenefits();

        system("pause");
        system("cls");
    }

    void deleteEmployee()
    {
        system("cls");
        system("color 7");
        printemploye();
        int index = employeeSearchHelper();

        if (index != -1)
        {
            for (int j = index + 1; j < e_size; j++)
            {
                employeeList[j - 1] = employeeList[j];
            }

            e_size--;
            cout << "\t\t\nEmployee deleted successfully.\n\n" << endl;
        }
        saveEmployees();
        system("pause");
        system("cls");
    }

    void modifyEmployee()
    {
        system("cls");
        system("color 7");
        printemploye();

        int index = employeeSearchHelper();
        if (index != -1)
        {
            cout << "Enter New Employee Information:- " << endl;
            employeeList[index]->read();
            cout << "\t\t\nEmployee Updated Successfully!\n\n" << endl;
        }
        saveEmployees();
        system("pause");
        system("cls");
    }

    void searchEmployee()
    {
        system("cls");
        system("color 7");
        int index = employeeSearchHelper();

        if (index != -1)
        {
            employeeList[index]->print();
        }

        system("pause");
        system("cls");
    }

    void employeeSalary()
    {
        system("cls");
        system("color 7");
        printemploye();

        int index = employeeSearchHelper();
        if (index != -1)
        {
            cout << employeeList[index]->getName() << " Has a " << employeeList[index]->getSalary() << " $ as a salary." << endl;
        }
        saveEmployees();
        system("pause");
        system("cls");
    }

    void totalSalary()
    {
        system("cls");
        system("color 7");

        double sum = 0;
        for (int i = 0; i < e_size; i++)
        {
            sum += employeeList[i]->getSalary();
        }
        cout << "The Total Salary Of All Employees Is -> " << sum << " $" << endl;

        system("pause");
        system("cls");
    }

    void employeeReporting()
    {
        system("cls");
        system("color 7");
        printemploye();

        int index = employeeSearchHelper();

        if (index != -1)
        {
            cout << "\t\t\nEmployee Found!\n" << endl;
            cout << "Our loyal Employee " << employeeList[index]->getName() << endl;
            cout << employeeList[index]->getName() << "'s Number is " << employeeList[index]->getPhone() << endl;
            cout << ", His/Her Email is " << employeeList[index]->getEmail() << endl;
            cout << ", Has an The ID of " << employeeList[index]->getEmployeeID() << endl;
            cout << ", Called as " << employeeList[index]->getJobTitle() << endl;
            cout << ", Belongs To Department Which is " << endl;
            employeeList[index]->getDepart();
            cout << "\n, Has a Benefit System Which is ";
            employeeList[index]->getBenefit();
            cout << "\n, Has Total Cash To Earn Equal " << employeeList[index]->getSalary() << " $ as a salary." << endl;

            if (employeeList[index]->getType() == 'h')
            {
                cout << "And As He/She is Hourly Employee , He Has :- " << endl;
                employeeList[index]->printMore();
            }
            else if (employeeList[index]->getType() == 'c')
            {
                cout << "And As He/She is Commission Employee , He Has :- " << endl;
                employeeList[index]->printMore();
            }
            else if (employeeList[index]->getType() == 's')
            {
                cout << "And As He/She is Salaried Employee , He Has :- " << endl;
                employeeList[index]->printMore();
            }
            else if (employeeList[index]->getType() == 'm')
            {
                cout << "And As He/She is Manager Employee , He Has :- " << endl;
                employeeList[index]->printMore();
            }
        }


        system("pause");
        system("cls");
    }

    void printemploye()
    {
        system("cls");
        system("color 0E");

        int maxIDLength = 0;
        int maxNameLength = 0;
        int maxPhoneLength = 0;
        int maxEmailLength = 0;
        int maxJobTitleLength = 0;
        int maxDeptLength = 0;
        int maxEmployeeTypeLength = 0;

        for (int i = 0; i < e_size; i++)
        {
            string id = employeeList[i]->getEmployeeID();
            int idLength = id.length();
            int nameLength = employeeList[i]->getName().length();
            int phoneLength = employeeList[i]->getPhone().length();
            int emailLength = employeeList[i]->getEmail().length();
            int jobTitleLength = employeeList[i]->getJobTitle().length();
            int deptLength = employeeList[i]->getDepartName().length();
            int employeeTypeLength = 1;

            if (idLength > maxIDLength)
                maxIDLength = idLength;
            if (nameLength > maxNameLength)
                maxNameLength = nameLength;
            if (phoneLength > maxPhoneLength)
                maxPhoneLength = phoneLength;
            if (emailLength > maxEmailLength)
                maxEmailLength = emailLength;
            if (jobTitleLength > maxJobTitleLength)
                maxJobTitleLength = jobTitleLength;
            if (deptLength > maxDeptLength)
                maxDeptLength = deptLength;
            if (employeeTypeLength > maxEmployeeTypeLength)
                maxEmployeeTypeLength = employeeTypeLength;
        }


        int idWidth = maxIDLength + 5;
        int nameWidth = maxNameLength + 5;
        int phoneWidth = maxPhoneLength + 5;
        int emailWidth = maxEmailLength + 5;
        int jobTitleWidth = maxJobTitleLength + 5;
        int deptWidth = maxDeptLength + 5;
        int employeeTypeWidth = maxEmployeeTypeLength + 5;

        cout << setfill('-') << setw(idWidth + nameWidth + phoneWidth + emailWidth + jobTitleWidth + deptWidth + employeeTypeWidth + 26) << "-" << endl;
        cout << setfill(' ') << "| " << setw(idWidth) << left << "ID"
            << " | " << setw(nameWidth) << "Name"
            << " | " << setw(phoneWidth) << "Phone"
            << " | " << setw(emailWidth) << "Email"
            << " | " << setw(jobTitleWidth) << "Job Title"
            << " | " << setw(deptWidth) << "Department"
            << " | " << setw(employeeTypeWidth) << "Employee Type" << " |" << endl;
        cout << setfill('-') << setw(idWidth + nameWidth + phoneWidth + emailWidth + jobTitleWidth + deptWidth + employeeTypeWidth + 26) << "-" << endl;

        for (int i = 0; i < e_size; i++)
        {
            cout << setfill(' ') << "| " << setw(idWidth) << left << employeeList[i]->getEmployeeID()
                << " | " << setw(nameWidth) << employeeList[i]->getName()
                << " | " << setw(phoneWidth) << employeeList[i]->getPhone()
                << " | " << setw(emailWidth) << employeeList[i]->getEmail()
                << " | " << setw(jobTitleWidth) << employeeList[i]->getJobTitle()
                << " | " << setw(deptWidth) << employeeList[i]->getDepartName()
                << " | " << setw(employeeTypeWidth) << employeeList[i]->getType() << " |" << endl;
            cout << setfill('-') << setw(idWidth + nameWidth + phoneWidth + emailWidth + jobTitleWidth + deptWidth + employeeTypeWidth + 26) << "-" << endl;
        }

    }


};

#endif 
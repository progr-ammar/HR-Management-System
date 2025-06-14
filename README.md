# 💼 HR Management System with Recruitment & CV Matching

A C++ console-based HR Management System designed using Object-Oriented Programming principles. It helps manage employee records, departments, benefits, salary calculations, and includes an intelligent recruitment system that matches CVs to job postings based on skill requirements.

---

## 📌 Features

### 👨‍💼 Employee Management
- Add, update, delete, and view employees
- Assign employees to departments and benefits
- View detailed reports and salary breakdowns

### 🏢 Department Management
- Add, modify, delete, and list departments
- Assign employees to departments

### 🎁 Benefit Management
- Add and manage Health & Dental benefits
- Assign benefits to employees

### 💰 Salary Management
- Calculate individual and total employee salaries
- Supports Hourly, Commission, Salaried, and Manager types

### 🔍 Search Module
- Search for employees, departments, or benefits by ID or name

---

## 🧠 Recruitment System

### HR (Hiring Team)
- Post new job openings with skill requirements
- View candidates recommended for specific job posts

### Candidate (Job Seeker)
- Submit their CV in `.txt` format
- System auto-matches their skills with job posts and recommends them

> CVs must be saved in the `/cvs/` folder (e.g., `cvs/cv1.txt`) with space-separated or line-separated keywords like:
> ```
> C++
> Teamwork
> Communication
> ```

### ✔️ Matching Logic
- CV is scanned for job-required skills
- If all required skills are found, candidate is saved to `recommendations.csv` and matched with that job

---

## 💾 Persistent Storage

All data is saved to `.csv` files so it survives program restarts:

| Data Type       | File Name             |
|----------------|------------------------|
| Employees       | `employees.csv`        |
| Departments     | `departments.csv`      |
| Benefits        | `benefits.csv`         |
| Job Postings    | `jobs.csv`             |
| Recommendations | `recommendations.csv`  |

---

## 🔧 Project Structure

/cvs/ # Folder for candidate CV text files

main.cpp             # Main application logic and menu
hrsystem.h           # HRSystem class handling all logic
employee.h           # Employee and subclasses (Hourly, Manager, etc.)
department.h         # Department class
benefits.h           # Benefits class
candidate.h          # Candidate class with CV parsing
jobposition.h        # Job posting and skill matching
employees.csv        # Auto-generated
departments.csv      # Auto-generated
benefits.csv         # Auto-generated
jobs.csv             # Auto-generated
recommendations.csv  # Auto-generated


---

## 🖥️ How to Run

1. Clone the repository
2. Open in Visual Studio (or any C++ IDE)
3. Make sure the `/cvs/` folder exists and contains candidate CVs (should be made manually)
   - Example CV file: `cvs/cv1.txt`
   - Format: Each skill on a new line or space-separated
4. Build & Run the project
5. Use the console interface to log in as:
   - **[1] HR** – Manage employees, benefits, and recruitment
   - **[2] Recruit** – Upload CV and apply for jobs

---

## 🧠 Concepts Used

- Object-Oriented Programming (OOP)
- Polymorphism and Inheritance
- File Handling (`ifstream`, `ofstream`)
- Data persistence using CSV
- String parsing and CV text matching
- Console-based UI with styled output (Windows-specific)

---

## 📌 Future Enhancements
- GUI version using Qt or C++
- Proper login system for HR and Recruit users
- Support for partial skill matching
- Export reports to PDF or formatted Excel

---

## 📜 License

This project is for educational purposes only.

---
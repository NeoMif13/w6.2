#include "PersonArray.h"
#include <iostream>

void PersonArray::addPerson() {
    string fullName;
    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "1. Graduate Student\n2. Teacher\n3. Researcher\n4. SupportStaff\n" << endl;
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) 
    {
        int graduationYear;
        long studentID;
        double averageScore;

        cout << "Enter graduation year: ";
        cin >> graduationYear;
        cout << "Enter student ID: ";
        cin >> studentID;
        cout << "Enter average score: ";
        cin >> averageScore;
        cin.ignore();

        persons.push_back(new GraduateStudent(fullName, graduationYear, studentID, averageScore));
    }
    else if (choice == 2) 
    {
        string position, academicDegree;

        cout << "Enter position: ";
        getline(cin, position);
        cout << "Enter academic degree: ";
        getline(cin, academicDegree);

        persons.push_back(new Teacher(fullName, position, academicDegree));
    }
    else if (choice == 3)
    {
        string degree, contractNumber;

        cout << "Enter degree: ";
        getline(cin, degree);
        cout << "Enter contractNumber: ";
        getline(cin, contractNumber);

        persons.push_back(new Researcher(fullName, degree, contractNumber));
    }
    else if (choice == 4)
    {
        string position;
        int labNumber;


        cout << "Enter position: ";
        getline(std::cin, position);
        cout << "Enter labNumber: ";
        cin >> labNumber;
        cin.ignore();

        persons.push_back(new SupportStaff(fullName, position, labNumber));
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}

void PersonArray::removePerson(size_t index) {
    if (index < persons.size()) {
        delete persons[index];
        persons.erase(persons.begin() + index);
    }
    else {
        cout << "Invalid index!" << endl;
    }
}

void PersonArray::printPersons() const {
    for (const auto& person : persons) {
        person->print();
        std::cout << std::endl;
    }
}
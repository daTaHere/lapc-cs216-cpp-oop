#include <iostream>
#include <random>
#include <cmath>

using namespace std;

struct Student {
	int id;
	double gpa;
};

void problem4() {

	// prompt user for input
	int n;
	cout << "Enter number of students to add: ";
	cin >> n;

	// pointer to allocated array of Student obj's ---> in heap
	Student* students = new Student[n];

	// prompt user to < Input id and gpa for each student >
	for (int i = 0; i < n; i++) {
		cout << "Enter Student ID: ";
		cin >> students[i].id;
		cout << "Enter Student GPA: ";
		cin >> students[i].gpa;
	}

	cout << endl;

	// print to console < Display all students >
	for (int i = 0; i < n; i++) {
		cout << "Student " << students[i].id << " GPA: " << students[i].gpa << endl;
	}

	// pointer to address location of first element
	Student* maxGpa = &students[0];

	// search loop < Find and print student with highest GPA >
	for (int i = 1; i < n; i++) {
		if (students[i].gpa > (*maxGpa).gpa) {
			maxGpa = &students[i];
		}
	}
	cout << "Student ID: " << (*maxGpa).id << " GPA: " << (*maxGpa).gpa << endl;

	// free space < Delete memory >
	delete[] students;
}


void promblem5_randomGen() {
	// Random device for seeding
	random_device rd;
	mt19937 gen(rd());  // Mersenne Twister engine

	// Distributions
	uniform_real_distribution<double> double_dist(1.0, 4.0);
	uniform_int_distribution<int> int_dist(1, 100);

	Student* students[3];

	for (int i = 0; i < 3; i++) {
		students[i] = new Student;
		students[i]->id = int_dist(gen);
		students[i]->gpa = round(double_dist(gen) * 100) / 100.0;
	}

	// Print using arrow operator
	for (int i = 0; i < 3; i++) {
		cout << "ID: " << students[i]->id << ", GPA: " << students[i]->gpa << endl;
	}

	// Free memory
	for (int i = 0; i < 3; i++) {
		delete students[i];
	}
}

int main() {

	// ==== call function -> Proplem 4: Dynamic Student Database ============================
	cout << "============= Proplem 4: Dynamic Student Database =================\n" << endl;
	problem4();

	cout << "============= Proplem 5: Array of Pointers to Struct =================\n" << endl;

	promblem5_randomGen();

	
}
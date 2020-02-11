#include<iostream>
#include"ex1.h"
using namespace std;

Instructor::Instructor( string name )
	:instructorName( name ){}

void Instructor::setInstructorName( string name )
{
	instructorName = name;
}

string Instructor::getInstructorName() const
{
	return instructorName;
}

void Instructor::displayMessage() const
{
	cout << "Welcome to the grade book for\n" << "CS101 Introduction to C++ Programming!\n" << "This course is presented by:" << getInstructorName()  << endl;
}

int main()
{
	Instructor instructor1("Sam Smith");
	instructor1.displayMessage();
	instructor1.setInstructorName("Judy Jones");
	instructor1.displayMessage();
}
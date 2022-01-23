#include <iostream>
#include <string>
#include "Student.h"

//STL - Standard Template Library
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

int main() {
	 
	vector<Student> v;
	Student s1("Tomas", 00323151);
	v.push_back(s1);
	v.push_back(Student("IDK", 32312233));
	v.push_back(Student("YKNO", 495434));
	cout << "Vector: " << endl;
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i].name << " " << v[i].studentID<< endl;

	//Create an iterator
	vector<Student>::iterator vIterator = v.begin(); //Points to first position
	vIterator++; //Moves iterator up

	//Insert new student using iterator for position
	v.insert(vIterator, Student("Malcom", 4341));
	//Not safe to use this iterator in its current used state

	//Using iterator to loop through a container, v the vector
	cout << "UPDATED vector of student" << endl;
	for (vector<Student>::iterator i = v.begin(); i != v.end(); i++) {
		//Iterator is a pointer to a position in the container
		cout << (*i).name << (*i).studentID << endl;
	}
	v.pop_back(); //To delete something at the back
	
	//To remove elements that are not at the back
	vIterator = v.begin();
	vIterator++;
	v.erase(vIterator);

	cout << "UPDATED vector of student" << endl;
	for (vector<Student>::iterator i = v.begin(); i != v.end(); i++) {
		//Iterator is a pointer to a position in the container
		cout << (*i).name << (*i).studentID << endl;
	}

	//List
	list<Student> l;
	l.push_back(Student("Other", 439032));
	l.push_back(Student("ANdasaber", 4344));
	l.push_back(Student("Yeia", 434444));

	//Push to front
	l.push_front(Student("Front", 1000));

	cout << "List: " << endl;
	for (list<Student>::iterator i = l.begin(); i != l.end(); i++)
		cout << i->name << " " << i->studentID << endl;

	system("pause");
	return 0;
}
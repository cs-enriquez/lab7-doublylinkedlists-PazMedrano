	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {
		numStudents = 0; 
		head = nullptr; 
		tail = nullptr; 
	}

	// return the number of students currently in the list
	int StudentList::listSize() {
		numStudents = 0; 
		Node* current = head; 

		while (current != nullptr){ 
		numStudents++; 
		current = current->next; 
		}
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		Node* newNode = new Node(s); 
		newNode->data = s; 
		newNode->next = head; 
		head = newNode; 
	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		Node* newNode = new Node(s); 
		newNode->data = s; 
		newNode->next = nullptr; 

		if(head == nullptr){ 
			head = tail = newNode;
		}
		else{ 
			tail->next= newNode; 
			tail = newNode; 
		}
	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		while(head!= nullptr){
			cout << head->next << "";
			head = head->next; 
		}
	}


	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		if(head == nullptr){ 
			cout << "Error, list is empty" << endl;
			return; 
		}
	Node* current = head; 
	Node* previous = nullptr; 

	while(current->next != nullptr){ 
		previous = current; 
		current = current->next; 
	}

	if(previous == nullptr){ 
		head = tail = nullptr; 
	}
	else{ 
		previous->next = nullptr; 
		tail = previous; 
	}

	delete current; 

	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		if(head == nullptr){ 
			cout << "Error, the list is empty" << endl;
			return; 
		}

		Node* temp = head; 
		head = head->next; 
		delete temp; 

		if(head == nullptr){ 
			tail = nullptr; 
		}
	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		if(index <= 0){ 
			addFront(s); 
			return; 
		}

		Node* newstudent = new Node(s); 
		newstudent->data = s; 

		Node* current = head; 
		Node* previous = nullptr; 
		int currentIndex = 0; 

		while (current != nullptr && currentIndex < index){ 
			previous = current; 
			current = current->next; 
			currentIndex++; 
		}

		if(current == nullptr){ 
			tail->next = newstudent; 
			tail = newstudent; 
		}
		else{ 
			previous->next = newstudent; 
			newstudent->next = current;
		}
	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Node* current = head; 

		while(current != nullptr){ 
			if(current->data.id == idNum){ 
				return current->data; 
			}
			else{ 
				current = current->next;
			}
		}

		Student dummyStudent{"nobody", -1, 0.0}; 
		cout << "Student with an ID" << idNum << " not found. Return a dummy student." << endl;
		
		return dummyStudent;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {
		Node* current = head; 
		Node* previous = nullptr; 

		while (current != nullptr){ 
			if(current-> data.id == idNum){ 
				if(previous != nullptr){ 
					previous-> next = current->next; 

				}
				else{ 
					head = current->next; 
				}

				if(current == tail){ 
					tail = previous; 
				}
				
				delete current; 
				cout << "Student ID " << idNum << "has been removed" << endl;
				return; 
			}
			previous = current; 
			current = current->next; 
		}
		cout << "Student with ID" << idNum << "not found." << endl;
	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {
		Node* current = head; 

		while(current != nullptr){ 
			if(current->data.id == idNum){ 
				current->data.GPA = newGPA; 
				cout << "ID " << idNum << " has been updated with a new GPA." << endl;
				return;
			}
			current = current->next; 
		}
		cout << "Student with ID: " << idNum << " is not found. GPA can not be updated." << endl;
	}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {
		if(otherList.head == nullptr){ 
			return; 
		}

		if(head == nullptr){ 
			head = otherList.head; 
			tail = otherList.tail;
		}
		else{
			 tail->next = otherList.head; 
			 tail = otherList.tail;
		}

		otherList.head = otherList.tail = nullptr;
	}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList studentminGPA;

		Node* current = head; 

		while(current != nullptr){ 
			if(current->data.GPA >= minGPA){ 
				Student student = current->data; 
				studentminGPA.addFront(student);
			}
			current = current->next;
		}
		return studentminGPA;
	}

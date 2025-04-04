#include <iostream>
#include <string>
#include <vector>

// Person class
class Person {
	
	// Encapsulation - Granting accessto private data only through controlled public interfaces;
	private:
		std::string first;
		std::string last;

	public:
		// Constructor (modern way -> destructuring);
		Person(std::string first, std::string last): first(first), last(last) {};
		
		// If you want to instantiate the class without the required variables on default;
		Person() = default;

		// Constructor (classic way)
		// Person(std::string first, std::string last) {
		//	this->fist = first;
		//	this->last = last;
		// }

		void setFirstName(std::string first) {this->first = first; }
		void setLastName(std::string last) {this->last = last; }
		void printFullName(){ std::cout << first << " " << last << '\n'; }
		
		std::string getName() {
			return first + " " + last;
		}

		// A 'virtual' method can be overrided on inherited classes;
		// Inside Person, it will print only the name, inside Employee it will print the department and the name;
		virtual void printInfo() {
			std::cout << this-> getName() << '\n';
		}

		// Static method that receives a list of persons and print it.
		static void printPeople(std::vector<Person*> people) {
			for (auto person : people) {
				person->printInfo();
			}
		}
};


// Inheritance - Create derived classes that inherit properties from their parent classes;
class Employee : public Person {
	private:
		std::string department;
	
	public:
		// Constructor, inheriting the first and last name from the base class and 
		Employee(std::string first, std::string last, std::string department): Person(first, last), department(department) {}; 
		
		std::string getDepartment() {
			return department;
		}

		void setDepartment(std::string department) { this->department = department; };

		// An 'override' method declares an alternative function from a base class;
		// Inside Person, it will print only the name, inside Employee it will print the department and the name; 
		void printInfo() override {
			std::cout << this->department << " - " << this-> getName() << '\n';
		}
};

int main() {
	// Instantiating the first person.
	Person luis("Luis", "Zimermann");
	luis.printFullName();

	// Instantiating the second person.
	Person amanda("Amanda", "Zimermann");
	std::cout << amanda.getName() << '\n';	// Returning it through reference.

	Employee sarah("Sarah", "Lima", "Databases");
	sarah.setDepartment("Development");
	sarah.printInfo();
	
	std::cout << '\n';

	// Polymorphism - Treat multiple different objects as their base object type;
	std::vector<Person*> people;
	
	people.push_back(&luis);	// Luis is a person	-> Prints the name
	people.push_back(&amanda);	// Amanda is a person   -> Prints the name
	people.push_back(&sarah);	// Sarah is an employee -> Prints the name and the department
	
	// Using the static method without instantiating any Person object.
	// Passing the people vector and printing all of them.
	Person::printPeople(people);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent a Person
struct Person {
    string name;
    int age;
    double height;

    // Default constructor
    Person() : name("Unknown"), age(0), height(0.0) {}

    // Parameterized constructor
    Person(string n, int a, double h) : name(n), age(a), height(h) {}

    // Member function to display the information
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", Height: " << height << " m" << '\n';
    }
};

int main() {
    // Create an object of the Person struct
    Person p1;
    p1.name = "Alice";
    p1.age = 25;
    p1.height = 1.60;
    
    Person p2("Fernanda", 30, 1.64);
    Person p3("Ana Livia", 12, 1.72);
    Person p4("Paguso", 53, 1.75);
    
    // Call the member function to display the person's details
    p1.display();
    p2.display();
    p3.display();
    p4.display();

    return 0;
}

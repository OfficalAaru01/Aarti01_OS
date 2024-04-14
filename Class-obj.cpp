//Problem 1
#include<iostream>
#include<string>
using namespace std;

class book{
    public:
    int b_id;
    string b_name;
};
int main(){
    book b1;
    b1.b_id=01;
    b1.b_name="Harry Potter";
    cout<<"Book id : "<<b1.b_id<<endl;
    cout<<"Book name : "<<b1.b_name<<endl;
    return 0;
}



//Problem 2
#include<iostream>
#include<string>
using namespace std;
class book{
    public:
    int b_id;
    string b_name;
};
int main(){
    book b1, b2, b3;
    b1.b_id=01;
    b1.b_name="Harry Potter";

    b2.b_id=02;
    b2.b_name="The Alchemist";

    b3.b_id=03;
    b3.b_name="The Monk who sold his ferrari";

    cout<<"Book id : "<<b1.b_id<<endl;
    cout<<"Book name : "<<b1.b_name<<endl;

    cout<<"Book id : "<<b2.b_id<<endl;
    cout<<"Book name : "<<b2.b_name<<endl;

    cout<<"Book id : "<<b3.b_id<<endl;
    cout<<"Book name : "<<b3.b_name<<endl;

    return 0;
}



//Problem 3
#include<iostream>
#include<string>
using namespace std;
class book{
    private:
    int b_id;
    string b_name;
    public:
    void setdata(){
        cout<<"Enter book id : ";
        cin>>b_id;
        cout<<"Enter book name : ";
        cin>>b_name;
    }
    void getdata(){
        cout<<"Book id : "<<b_id<<endl;
        cout<<"Book name : "<<b_name<<endl;
    }
};
int main(){
    book b1, b2, b;
    b1.setdata();
    b2.setdata();
    b1.getdata();
    b2.getdata();
    return 0;
}


//Problem 4
#include <iostream>
#include <string>

class Car {
public:

    std::string make;
    std::string model;
    int year;

    Car(std::string cMake, std::string cModel, int cYear) {
        make = cMake;
        model = cModel;
        year = cYear;
    }

    void displayInfo() {
        std::cout << "Car Make: " << make << std::endl;
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Car Year: " << year << std::endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2021);
    myCar.displayInfo();

    return 0;
}



//Problem 5
#include <iostream>
#include <string>

class Person {
private:
    std::string name;  
    int age;           

public:
    Person(std::string pName, int pAge) {
        name = pName;
        age = pAge;
    }

    void setName(std::string newName) {
        name = newName;
    }

    std::string getName() const {
        return name;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    int getAge() const {
        return age;
    }

    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    Person person1("Alice", 30);
    person1.displayInfo();
    person1.setName("Alice Johnson");
    person1.setAge(31);

    std::cout << "\nAfter updates:" << std::endl;
    person1.displayInfo();

    return 0;
}

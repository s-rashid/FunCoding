#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Forward declarations
class Course;
class Grade;
class Student;
class Transcript;

// Base class for all system users
class User {
protected:
    std::string name;
    std::string address;
public:
    User(const std::string& n, const std::string& a) : name(n), address(a) {}
    virtual ~User() {}

    // Getters
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

// Course class
class Course {
private:
    std::string name;
    std::string instructor;
    int creditHours;
    std::vector<Student*> students;
    std::vector<Grade*> grades;
public:
    Course(const std::string& n, const std::string& i, int ch) : 
           name(n), instructor(i), creditHours(ch) {}

    // Getters
    std::string getName() const { return name; }
    std::string getInstructor() const { return instructor; }
    int getCreditHours() const { return creditHours; }

    // Course management methods
    void addStudent(Student* s) {
        students.push_back(s);
    }

    void removeStudent(Student* s) {
        students.erase(std::remove(students.begin(), students.end(), s), students.end());
    }

    void addGrade(Grade* g) {
        grades.push_back(g);
    }

    float calculateAverageGrade() {
        float sum = 0.0f;
        for (Grade* g : grades) {
            sum += g->getGrade();
        }
        return sum / grades.size();
    }
};

// Grade class
class Grade {
private:
    std::string studentID;
    std::string courseName;
    float grade;
public:
    Grade(const std::string& sid, const std::string& cn, float g) : 
          studentID(sid), courseName(cn), grade(g) {}

    // Getters
    std::string getStudentID() const { return studentID; }
    std::string getCourseName() const { return courseName; }
    float getGrade() const { return grade; }

    // Setter
    void setGrade(float g) { grade = g; }
};

// Student class
class Student : public User {
private:
    std::string ID;
    std::vector<Course*> courses;
    std::vector<Grade*> grades;
public:
    Student(const std::string& n, const std::string& a, const std::string& id) : 
            User(n, a), ID(id) {}

    // Getters
    std::string getID() const { return ID; }

    // Student methods
    void registerCourse(Course* c) {
        courses.push_back(c);
        c->addStudent(this);
    }

    void dropCourse(Course* c) {
        courses.erase(std::remove(courses.begin(), courses.end(), c), courses.end());
        c->removeStudent(this);
    }

    void addGrade(Grade* g) {
        grades.push_back(g);
    }

    float calculateGPA() {
        float totalCreditHours = 0.0f;
        float weightedGradePoints = 0.0f;
        for (Grade* g : grades) {
            Course* c = nullptr;
            for (Course* course : courses) {
                if (course->getName() == g->getCourseName()) {
                    c = course;
                    break;
                }
            }
            if (c

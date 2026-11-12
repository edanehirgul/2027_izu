
// Example:

/* -Contents:
1.Classes and Objects
2.Encapsulation
3.Constructors
4.Deconstructor
5.Pointers
6.C-Style Strings with char*
7.String Manipulation
8.Dynamic Memory Allocation
*/

#include <iostream>
#include <cstring> //strlen() ve strcpy)()
#include <cctype>  //karakter türü kontrolü

using namespace std;

class Student
{
private:
    char *name;    // değişkenin adresini tutar
    char *surname; // ihtiyaç duyulan bellek alanı kadar depolama için lazım olacak
    // adresten başlayarak birden fazla karakter okuyabilir
    int age;

    double *grades;
    int numberOfGrades;

public:
    // Constructor

    Student(const char *studentName, const char *studentSurname,
            int studentAge, int gradeCount)
    {
        // Allocate the memory for the name
        name = new char[strlen(studentName) + 1];
        /*
        strlen(studentName) -> studentName'in uzunluğunu ölçer
        + 1 -> for the NULL '\0'
        new char[] -> bellekte dinamik olarak belirtilen uzunluğu ayırır.
        name = dönen adresi name'e eşitler
        */

        // Copy the name strcpy():Adreslerdeki değişkenleri kopyalar
        strcpy(name, studentName);

        // Allocate the memory fot the surname
        surname = new char[strlen(studentSurname) + 1];

        // Copy the surname
        strcpy(surname, studentSurname);

        age = studentAge;
        numberOfGrades = gradeCount;

        // int'in bellek boyutu değişmez 4 bit zaten
        // char *name: pointer adres tutar; metin için gereken bellek değişebilir
        // double* grades: pointer adres tutar; dizi boyutu not sayısına bağlıdır.

        // Allocate the dynamic array for grades.
        grades = new double[numberOfGrades];

        // Inıtialize grades to 0
        for (int i = 0; i < numberOfGrades; i++)
        {
            grades[i] = 0.0;
        }
    }

    // Set a grade
    void setGrade(int index, double grade)
    {
        if (index >= 0 && index < numberOfGrades)
        {
            grades[index] = grade;
        }
    }

    // Calculate the average grade.
    double calculateAverage()
    {
        double sum = 0;

        for (int i = 0; i < numberOfGrades; i++)
        {
            sum += grades[i];
        }
        return (sum / numberOfGrades);
    }

    // Create the students e-mail adress
    /*
        Example:
        Name: Eda
        Surname: Gül
        Email: eda.nehir@izu.edu.tr
    */

    char *createEmail()
    {
        int emailLength = strlen(name) + 1 + strlen(surname) + strlen("@izu.edu.tr") + 1;
        //                               '.'        '\0'

        // Allocate the memory for email
        char *email = new char[emailLength];

        // Copy the name
        strcpy(email, name);

        // Add the dot
        strcat(email, ".");

        // Add the surname
        strcat(email, surname);

        // Add the university domain
        strcat(email, "@izu.edu.tr");

        // Convert the entire email to lowecase
        for (int i = 0; email[i] != '\0'; i++)
        { // elemanları dolaş
            email[i] = tolower(email[i]);
        }

        return email;
    }
    /*
    strcat(destination, source); // Source'u destination'ın sonuna ekler.
    strcpy(destination, source); // Source'u destination'a kopyalar.
    */

    // Display student information
    void displayInfo()
    {
        cout << "Name: " << name << " " << surname << endl;
        cout << "Age " << age << endl;

        cout << "Grades ";

        for (int i = 0; i < numberOfGrades; i++)
        {
            cout << grades[i] << " ";
        }
        cout << endl;

        cout << "Average: " << calculateAverage() << endl;

        // Create and display the email
        char *email = createEmail();

        cout << "Email: " << email << endl;

        // Realese the memory allocated for the email
        delete[] email;
    }

    // Destructor

    ~Student()
    {
        cout << "Memory realesed for " << name << " " << surname << endl;

        // Realese dynamicallyallocated memory
        delete[] name;
        delete[] surname;
        delete[] grades;
    }
};

int main()
{
    // Create the student

    Student student1("Eda", "Gül", 20, 3);

    // Set Eda's Grades
    student1.setGrade(0, 85);
    student1.setGrade(1, 90);
    student1.setGrade(2, 95);

    // Display the information
    cout << "----Student Information----" << endl;

    student1.displayInfo();

    return 0;
}
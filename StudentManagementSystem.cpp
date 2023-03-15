#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class student
{
    int admissionNo;
    int std;
    int percentage;
    char sname[20];
    float smarks;
    char sgender;

public:
    void getdata();
    void showdata();
    int getAdmissionNo()
    {
        return admissionNo;
    }
} s;
void student ::getdata()
{
    cout << "\n\n*****************************************\n\n";
    cout << "Admission No.";
    cin >> admissionNo;
    cout << "Full Name\n";
    cin.ignore();
    cin.getline(sname, 20);
    cout << "Gender\n";
    cin >> sgender;
    cout << "Class : ";
    cin >> std;
    cout << "Total Marks out of 500 : ";
    cin >> smarks;
    percentage = smarks / 5;
}
void student ::showdata()
{
    cout << "\n\n***************************************\n\n";
    cout << "Admission number : " << admissionNo << endl;
    cout << "Name : " << sname << endl;
    cout << "Class : " << std << endl;
    cout << "Gender : " << sgender << endl;
    cout << "Marks : " << smarks << "/500" << endl;
    cout << "Percentage : " << percentage << endl;
}
void adddata()
{
    ofstream fout;
    fout.open("stu.txt", ios::out | ios::app);
    s.getdata();
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\n\nData Saved Successfully\n\n";
}
void displaydata()
{
    ifstream fin;
    fin.open("stu.txt", ios::in);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.showdata();
    }
    fin.close();
    cout << "\n\nData successfully Read from file\n\n";
}
void deletedata()
{
    int n, flag = 0;
    ifstream fin;
    ofstream fout, tout;
    cout << "Enter admission number\n";
    cin >> n;
    fin.open("Stu.txt", ios::in ); // open Stu.txt in input mode

    fout.open("Temp.txt", ios::out | ios::app ); // open Temp.txt in append mode

    tout.open("Trash.txt", ios::out | ios::app ); // open Trash.txt in append mode
    if (n == s.getAdmissionNo())
    {
        cout << "Data of id " << n << "has been sent to Trash\n";
        s.showdata();
        tout.write((char *)&s, sizeof(s));
        flag++;
    }
    else
    {
        fout.write((char *)&s, sizeof(s));
    }
    fout.close();
    fin.close();
    tout.close();
    if (flag == 0)
    {
        cout << "No record found for id : " << n << endl;
        remove("stu.txt");
        rename("tmp.txt", "stu.txt");
    }
}
void gettrash()
{
    ifstream fin;
    fin.open("trash.txt", ios::in );
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.showdata();
    }
    fin.close();
    cout << "\n\n********Data Reading from trash file done successfully**********\n\n";
}
void project();
int main()
{
    project();
    return 0;
}
void project()
{
    int choice;
    system("cls");
    do
    {
        cout << "\n\n******************Welcome to Student Management System****************\n\n";
        cout << "Enter 1 to add data\n";
        cout << "Enter 2 to display data\n";
        cout << "Enter 3 to delete data\n";
        cout << "Enter 4 to display trash data\n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            adddata();
            break;
        case 2:
            displaydata();
            break;
        case 3:
            deletedata();
            break;
        case 4:
            gettrash();
            break;
        case 5:
            cout << "\n*****************Exit successfully done***********\n";
            break;
        default:
            cout << "\n*****************Incorrect choice***********\n";
        }
        system("pause");
    } while (choice != 5);
}
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


class faculty
{
protected:
    string faculty_id[10][2];
    string teach_data[10][7];
    string student_data[10][7];
    int acc[3];

    int student_count;
    int teach_count;
    int faculty_count;

public:
    faculty();
    void write();
    int login();

    void write_announcement();
    void read_announcement();

    void diplay_teach();
    void read_teach();
    void add_teach();
    void update_teach();

    void display_stud();
    void read_stud();
    void add_stud();
    void update_stud();
    void add_feechalan();
};


class teacher : public faculty
{
private:
    string my_id;

public:
    teacher();

    string login();
    void show_profile(string id);
    void view_courses(string id);
    void upload_marks();

    void write_announcement();
    void read_announcement();
};


class student : public faculty
{
private:
    string enroll;

public:
    student();

    string login();
    void show_profile(string enroll);
    void view_marks(string enroll);
    void read_announcement();
};

#endif

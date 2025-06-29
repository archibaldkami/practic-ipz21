#ifndef MYLIB
#define MYLIB

#include <string>
#include <vector>
#include <json/json.h>

// Task 1

struct Student_1 {
    std::string surname;
    int english;
    int GREAT_MATH;
    int physics;
    int programming;
};

class StudentGroup {
private:
    std::vector<Student_1> students;
    std::string filename;

public:
    StudentGroup(const std::string& file);
    void load_from_json();
    void print_grade_counts() const;
    void print_high_avg_students() const;
    void print_students_with_three() const;
    void print_students_no_five() const;
    void print_group_with_subject_averages() const;
    void print_students_with_avg() const;
    void print_math_grades() const;
    void print_extreme_avg_students() const;
    void print_low_avg_students() const;
    void bubble_sort();
    void quick_sort();
};

void BoobleSort(Student_1 Tab[], int kl);
void QSort(Student_1 Tab[], int kl);
void display_menu_1(int &result_);

// Task 2

struct ABONENT {
    std::string Name;
    std::string Init;
    std::string Nomer;
    std::string Adress;
};

void inputTelefonData(std::vector<ABONENT>& telefon, int n);
void sortTelefonByName(std::vector<ABONENT>& telefon);
void searchByPhoneNumber(const std::vector<ABONENT>& telefon, const std::string& nomer);

void display_task_2();

// Task 3
struct Student_2 {
    std::string faculty;
    int course;
    std::string group;
    std::string surname;
    std::vector<int> grades;
};

class StudentDatabase {
private:
    std::vector<Student_2> students;
    std::string db_filename;
    std::string top_faculty_course_file;
    std::string honor_students_file;
    std::string no_failing_group_file;

public:
    StudentDatabase(const std::string& db_file, const std::string& top_file, const std::string& honor_file, const std::string& no_fail_file);

    void sort_students();
    void add_student();
    void edit_student();
    void display_database() const;
    void save_to_file() const;
    void load_from_file();
    void find_top_faculty_course() const;
    void list_honor_students() const;
    void find_no_failing_group() const;
    int count_file_lines(const std::string& filename) const;
    void set_file_read_only(const std::string& filename) const;
    void search_student() const;
    void delete_student();
};

void display_menu_3(int &return_);
void init();

#endif
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sys/stat.h>
#include <json/json.h>
#include <vector>
#include "mylib.hpp"

using namespace std;

// Завдання 1. 1-9
StudentGroup::StudentGroup(const string& file) : filename(file) {}

void StudentGroup::load_from_json() {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No file found, starting with empty group.\n";
        return;
    }

    Json::Value root;
    file >> root;
    file.close();

    students.clear();
    for (const auto& student_json : root["students"]) {
        Student_1 student;
        student.surname = student_json["surname"].asString();
        student.english = student_json["english"].asInt();
        student.GREAT_MATH = student_json["GREAT_MATH"].asInt();
        student.physics = student_json["physics"].asInt();
        student.programming = student_json["programming"].asInt();
        students.push_back(student);
    }
    cout << "Group loaded from " << filename << "\n";
}

void StudentGroup::print_grade_counts() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    int total_5 = 0, total_4 = 0, total_3 = 0, total_2 = 0;
    cout << "\nGrade Counts:\n";
    cout << "No | Surname | 5 | 4 | 3 | 2\n";
    cout << "--------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        int count_5 = 0, count_4 = 0, count_3 = 0, count_2 = 0;
        for (int grade : {students[i].english, students[i].GREAT_MATH, 
                         students[i].physics, students[i].programming}) {
            if (grade == 5) count_5++;
            else if (grade == 4) count_4++;
            else if (grade == 3) count_3++;
            else if (grade == 2) count_2++;
        }
        cout << setw(2) << i + 1 << " | "  << setw(8) << students[i].surname << " | " << count_5 << " | " << count_4 << " | "  << count_3 << " | " << count_2 << "\n";
        total_5 += count_5;
        total_4 += count_4;
        total_3 += count_3;
        total_2 += count_2;
    }
    cout << "--------------------------------\n";
    cout << "Total:      | " << total_5 << " | " << total_4 << " | "  << total_3 << " | " << total_2 << "\n";
}

void StudentGroup::print_high_avg_students() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    int count = 0;
    cout << "\nStudents with average > 4:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog | Avg\n";
    cout << "---------------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        double avg = (students[i].english + students[i].GREAT_MATH + 
                     students[i].physics + students[i].programming) / 4.0;
        if (avg > 4.0) {
            cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << " | " << fixed << setprecision(2) << avg << "\n";
            count++;
        }
    }
    cout << "---------------------------------------------\n";
    cout << "Total students: " << count << "\n";
}

void StudentGroup::print_students_with_three() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    int count = 0;
    cout << "\nStudents with at least one 3:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog\n";
    cout << "---------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].english == 3 || students[i].GREAT_MATH == 3 || 
            students[i].physics == 3 || students[i].programming == 3) {
            cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << "\n";
            count++;
        }
    }
    cout << "---------------------------------------\n";
    cout << "Total students: " << count << "\n";
}

void StudentGroup::print_students_no_five() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    int count = 0;
    cout << "\nStudents with no 5:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog\n";
    cout << "---------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].english != 5 && students[i].GREAT_MATH != 5 && 
            students[i].physics != 5 && students[i].programming != 5) {
            cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << "\n";
            count++;
        }
    }
    cout << "---------------------------------------\n";
    cout << "Total students: " << count << "\n";
}

void StudentGroup::print_group_with_subject_averages() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    double avg_eng = 0, avg_math = 0, avg_phys = 0, avg_prog = 0;
    cout << "\nGroup with subject averages:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog\n";
    cout << "---------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << "\n";
        avg_eng += students[i].english;
        avg_math += students[i].GREAT_MATH;
        avg_phys += students[i].physics;
        avg_prog += students[i].programming;
    }
    cout << "---------------------------------------\n";
    cout << "Subject averages: | " << fixed << setprecision(2) << avg_eng / students.size() << " | " << avg_math / students.size() << " | " << avg_phys / students.size() << " | " << avg_prog / students.size() << "\n";
}

void StudentGroup::print_students_with_avg() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    cout << "\nStudents with average grades:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog | Avg\n";
    cout << "---------------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        double avg = (students[i].english + students[i].GREAT_MATH + students[i].physics + students[i].programming) / 4.0;
        cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << " | " << fixed << setprecision(2) << avg << "\n";
    }
    cout << "---------------------------------------------\n";
}

void StudentGroup::print_math_grades() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    double avg_math = 0;
    cout << "\nMath grades:\n";
    cout << "No | Surname | Math\n";
    cout << "--------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].GREAT_MATH << "\n";
        avg_math += students[i].GREAT_MATH;
    }
    cout << "--------------------\n";
    cout << "Average math grade: " << fixed << setprecision(2) << avg_math / students.size() << "\n";
}

void StudentGroup::print_extreme_avg_students() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    double min_avg = 6.0, max_avg = 0.0;
    vector<size_t> min_indices, max_indices;
    
    for (size_t i = 0; i < students.size(); ++i) {
        double avg = (students[i].english + students[i].GREAT_MATH + students[i].physics + students[i].programming) / 4.0;
        if (avg < min_avg) {
            min_avg = avg;
            min_indices.clear();
            min_indices.push_back(i);
        } else if (avg == min_avg) {
            min_indices.push_back(i);
        }
        if (avg > max_avg) {
            max_avg = avg;
            max_indices.clear();
            max_indices.push_back(i);
        } else if (avg == max_avg) {
            max_indices.push_back(i);
        }
    }

    cout << "\nStudents with highest/lowest average:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog | Avg\n";
    cout << "---------------------------------------------\n";
    
    for (size_t i : max_indices) {
        double avg = (students[i].english + students[i].GREAT_MATH + students[i].physics + students[i].programming) / 4.0;
        cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << " | " << fixed << setprecision(2) << avg << "\n";
    }
    for (size_t i : min_indices) {
        double avg = (students[i].english + students[i].GREAT_MATH + students[i].physics + students[i].programming) / 4.0;
        cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << " | " << fixed << setprecision(2) << avg << "\n";
    }
    cout << "---------------------------------------------\n";
}

void StudentGroup::print_low_avg_students() const {
    if (students.empty()) {
        cout << "No students in group!\n";
        return;
    }

    int count = 0;
    cout << "\nStudents with average < 4:\n";
    cout << "No | Surname | Eng | Math | Phys | Prog | Avg\n";
    cout << "---------------------------------------------\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        double avg = (students[i].english + students[i].GREAT_MATH + students[i].physics + students[i].programming) / 4.0;
        if (avg < 4.0) {
            cout << setw(2) << i + 1 << " | " << setw(8) << students[i].surname << " | " << students[i].english << " | " << students[i].GREAT_MATH << " | " << students[i].physics << " | " << students[i].programming << " | " << fixed << setprecision(2) << avg << "\n";
            count++;
        }
    }
    cout << "---------------------------------------------\n";
    cout << "Total students: " << count << "\n";
}

void StudentGroup::bubble_sort() {
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = 0; j < students.size() - i - 1; ++j) {
            if (students[j].surname > students[j + 1].surname) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Students sorted by surname (Bubble Sort)!\n";
}

void StudentGroup::quick_sort() {
    sort(students.begin(), students.end(),
        [](const Student_1& a, const Student_1& b) {
            return a.surname < b.surname;
        });
    cout << "Students sorted by surname (Quick Sort)!\n";
}

// Вставити рядок
int InsertRow(Student_1 Tab[], int kl, int n) {
    if (n < 0 || n > kl) return kl;
    for (int i = kl; i > n; --i) {
        Tab[i] = Tab[i - 1];
    }
    cout << "Enter new student data at position " << n << ":\n";
    cout << "Surname: "; cin >> Tab[n].surname; 
    cout << "English: "; cin >> Tab[n].english;
    cout << "Higher mathematics: "; cin >> Tab[n].GREAT_MATH;
    cout << "Physics: "; cin >> Tab[n].physics;
    cout << "Programming: "; cin >> Tab[n].programming;
    return kl + 1;
}

// Видалити стрічку
int DelRow(Student_1 Tab[], int kl, int n) {
    if (n < 0 || n >= kl) return kl;
    for (int i = n; i < kl - 1; ++i) {
        Tab[i] = Tab[i + 1];
    }
    return kl - 1;
}

// Редагувати стрічку
void EditRow(Student_1 Tab[], int kl, int n) {
    if (n < 0 || n >= kl) return;
    cout << "Enter new data for student at position " << n << ":\n";
    cout << "Surname: "; cin >> Tab[n].surname;
    cout << "English: "; cin >> Tab[n].english;
    cout << "Higher mathematics: "; cin >> Tab[n].GREAT_MATH;
    cout << "Physics: "; cin >> Tab[n].physics;
    cout << "Programming: "; cin >> Tab[n].programming;
}

// Сортування бульбашкою
void BoobleSort(Student_1 Tab[], int kl) {
    for (int i = 0; i < kl - 1; ++i) {
        for (int j = 0; j < kl - i - 1; ++j) {
            if (Tab[j].surname > Tab[j + 1].surname) {
                swap(Tab[j], Tab[j + 1]);
            }
        }
    }
}

// Швидке сортування
void QSort(Student_1 Tab[], int kl) {
    if (kl <= 1) return;
    Student_1 pivot = Tab[kl / 2];
    int i = 0, j = kl - 1;
    while (i <= j) {
        while (Tab[i].surname < pivot.surname) ++i;
        while (Tab[j].surname > pivot.surname) --j;
        if (i <= j) swap(Tab[i++], Tab[j--]);
    }
    QSort(Tab, j + 1);
    QSort(Tab + i, kl - i);
}

// Послідовний пошук
int SequentialSearch(Student_1 Tab[], int kl, const string& zrazok) {
    int count = 0;
    for (int i = 0; i < kl; ++i) {
        if (Tab[i].surname == zrazok) ++count;
    }
    return count;
}

// Швидкий пошук
int QuickSearch(Student_1 Tab[], int kl, const string& zrazok) {
    int left = 0, right = kl - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (Tab[mid].surname == zrazok) {
            int count = 1;
            int i = mid - 1;
            while (i >= 0 && Tab[i].surname == zrazok) { --i; ++count; }
            i = mid + 1;
            while (i < kl && Tab[i].surname == zrazok) { ++i; ++count; }
            return count;
        }
        if (Tab[mid].surname < zrazok) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

void display_menu_1(int &return_) {
    StudentGroup group("group.json");

    while (true) {
        system("clear");
        cout << "\nStudent Group Analysis System\n";
        cout << "1. Print grade counts\n";
        cout << "2. Print students with average > 4\n";
        cout << "3. Print students with at least one 3\n";
        cout << "4. Print students with no 5\n";
        cout << "5. Print group with subject averages\n";
        cout << "6. Print students with individual averages\n";
        cout << "7. Print math grades and average\n";
        cout << "8. Print students with highest/lowest average\n";
        cout << "9. Print students with average < 4\n";
        cout << "10. Load group from JSON\n";
        cout << "11. Bubble Sort students\n";
        cout << "12. Quick Sort students\n";
        cout << "13. Return\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice; cin >> choice;
        
        switch (choice) {
            case 1: group.print_grade_counts(); break;
            case 2: group.print_high_avg_students(); break;
            case 3: group.print_students_with_three(); break;
            case 4: group.print_students_no_five(); break;
            case 5: group.print_group_with_subject_averages(); break;
            case 6: group.print_students_with_avg(); break;
            case 7: group.print_math_grades(); break;
            case 8: group.print_extreme_avg_students(); break;
            case 9: group.print_low_avg_students(); break;
            case 10: group.load_from_json(); break;
            case 11: group.bubble_sort(); break;
            case 12: group.quick_sort(); break;
            case 13: return;
            case 0: return_ = 0; return;
            default: cout << "Invalid choice!\n";
        }
        cout << "Press Enter to continue...";
        cin.get();
        cin.get();
    }
    cout << "Press Enter to continue...";
    cin.get();

}

// Завдання 2. 4
// Введення даних про абонентів
void inputTelefonData(vector<ABONENT>& telefon, int n) {
    telefon.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter data for abonent " << i + 1 << ":\n";
        cout << "Name: "; cin >> telefon[i].Name;
        cout << "Initials: "; cin >> telefon[i].Init;
        cout << "Phone number: "; cin >> telefon[i].Nomer;
        cout << "Address: ";
        cin.ignore();
        getline(cin, telefon[i].Adress);
    }
}

// Сортування за ім'ям
void sortTelefonByName(vector<ABONENT>& telefon) {
    sort(telefon.begin(), telefon.end(), [](const ABONENT& a, const ABONENT& b) { return a.Name < b.Name; });
    cout << "\nSorted telefon list by Name:\n";
    for (const auto& abonent : telefon) {
        cout << "Name: " << abonent.Name << ", Initials: " << abonent.Init << ", Phone: " << abonent.Nomer << ", Address: " << abonent.Adress << "\n";
    }
}

// Пошук за номером
void searchByPhoneNumber(const vector<ABONENT>& telefon, const string& nomer) {
    auto it = find_if(telefon.begin(), telefon.end(), [&nomer](const ABONENT& a) { return a.Nomer == nomer; });
    
    if (it != telefon.end()) {
        cout << "\nFound abonent:\n";
        cout << "Name: " << it->Name << ", Initials: " << it->Init << ", Address: " << it->Adress << "\n";
    } else {
        cout << "\nNo abonent found with phone number: " << nomer << "\n";
    }
}

// Тут мала бути менюшка
void display_task_2() {
    system("clear");
    int n;
    cout << "Enter number of abonents: ";
    cin >> n;
    
    vector<ABONENT> telefon;
    inputTelefonData(telefon, n);
    sortTelefonByName(telefon);
    
    string search_nomer;
    cout << "\nEnter phone number to search: ";
    cin >> search_nomer;
    searchByPhoneNumber(telefon, search_nomer);
}

// Завдання 3. 4
// Конструктор класу
StudentDatabase::StudentDatabase(const string& db_file, const string& top_file, const string& honor_file, const string& no_fail_file) : 
    db_filename(db_file), top_faculty_course_file(top_file), honor_students_file(honor_file), no_failing_group_file(no_fail_file) {}

// Видалити студента
void StudentDatabase::delete_student() {
    string surname;
    cout << "Enter surname of student to delete: ";
    cin >> surname;
    
    auto it = find_if(students.begin(), students.end(),
        [&surname](const Student_2& s) { return s.surname == surname; });
    
    if (it == students.end()) {
        cout << "Student not found!\n";
        return;
    }
    
    students.erase(it);
    cout << "Student deleted successfully!\n";
}

// Пошук студента
void StudentDatabase::search_student() const {
    string surname;
    cout << "Enter surname to search: ";
    cin >> surname;
    
    auto it = find_if(students.begin(), students.end(),
        [&surname](const Student_2& s) { return s.surname == surname; });
    
    if (it == students.end()) {
        cout << "Student not found!\n";
        return;
    }
    
    cout << "\nFound Student:\n";
    cout << "Faculty: " << it->faculty << "\n";
    cout << "Course: " << it->course << "\n";
    cout << "Group: " << it->group << "\n";
    cout << "Surname: " << it->surname << "\n";
    cout << "Grades: ";
    for (int grade : it->grades) {
        cout << grade << " ";
    }
}

// Сортування студентів
void StudentDatabase::sort_students() {
    sort(students.begin(), students.end(),
        [](const Student_2& a, const Student_2& b) {
            if (a.faculty != b.faculty) return a.faculty < b.faculty;
            if (a.course != b.course) return a.course < b.course;
            return a.surname < b.surname;
        });
    cout << "Students sorted by faculty, course, and surname!\n";
}

// Функція додавання студента
void StudentDatabase::add_student() {
    Student_2 student;
    cout << "Enter faculty: "; cin >> student.faculty;
    cout << "Enter course (1-5): "; cin >> student.course;
    cout << "Enter group: "; cin >> student.group;
    cout << "Enter surname: "; cin >> student.surname;
    
    int grade_count;
    cout << "Enter number of grades: ";
    cin >> grade_count;
    student.grades.resize(grade_count);
    for (int i = 0; i < grade_count; ++i) {
        cout << "Enter grade " << i + 1 << " (1-5): ";
        cin >> student.grades[i];
    }
    
    students.push_back(student);
    cout << "Student added successfully!\n";
}

// Фукнція редагування студента за іменем
void StudentDatabase::edit_student() {
    string surname;
    cout << "Enter surname of student to edit: "; cin >> surname;
    
    auto it = find_if(students.begin(), students.end(), [&surname](const Student_2& s) { return s.surname == surname; });
    
    if (it == students.end()) {
        cout << "Student not found!\n";
        return;
    }
    
    cout << "Enter new faculty: "; cin >> it->faculty;
    cout << "Enter new course (1-5): "; cin >> it->course;
    cout << "Enter new group: "; cin >> it->group;
    
    int grade_count;
    cout << "Enter new number of grades: "; cin >> grade_count;
    it->grades.resize(grade_count);
    for (int i = 0; i < grade_count; ++i) {
        cout << "Enter new grade " << i + 1 << " (1-5): ";
        cin >> it->grades[i];
    }
    
    cout << "Student updated successfully!\n";
}

// Відобразити базу даних студентів
void StudentDatabase::display_database() const {
    if (students.empty()) {
        cout << "Database is empty!\n";
        return;
    }
    
    cout << "\nStudent Database:\n";
    cout << "Faculty\t\tCourse\tGroup\tSurname\t\tGrades\n";
    for (const auto& student : students) {
        cout << student.faculty << ((student.faculty.size() < 8) ? "\t\t" : "\t");
        cout << student.course << "\t";
        cout << student.group << "\t";
        cout << student.surname << ((student.surname.size() < 16) ? "\t\t" : "\t"); // Українські літери вважаються за кілька символів :P
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

// Зберегти базу даних у json файл
void StudentDatabase::save_to_file() const {
    Json::Value root;
    for (const auto& student : students) {
        Json::Value student_json;
        student_json["faculty"] = student.faculty;
        student_json["course"] = student.course;
        student_json["group"] = student.group;
        student_json["surname"] = student.surname;
        for (int grade : student.grades) {
            student_json["grades"].append(grade);
        }
        root["students"].append(student_json);
    }
    
    ofstream file(db_filename);
    if (file.is_open()) {
        file << root;
        file.close();
        cout << "Database saved to " << db_filename << "\n";
    } else {
        cout << "Error saving to file!\n";
    }
}

// Завантажити базу даних з json файлу
void StudentDatabase::load_from_file() {
    ifstream file(db_filename);
    if (!file.is_open()) {
        cout << "No database file found, starting with empty database.\n";
        return;
    }
    
    Json::Value root;
    file >> root;
    file.close();
    
    students.clear();
    for (const auto& student_json : root["students"]) {
        Student_2 student;
        student.faculty = student_json["faculty"].asString();
        student.course = student_json["course"].asInt();
        student.group = student_json["group"].asString();
        student.surname = student_json["surname"].asString();
        for (const auto& grade : student_json["grades"]) {
            student.grades.push_back(grade.asInt());
        }
        students.push_back(student);
    }
    cout << "Database loaded from " << db_filename << "\n";
}

// Знайти факультет і курс студента з найкращими оцінками
void StudentDatabase::find_top_faculty_course() const {
    map<pair<string, int>, int> honor_count;
    for (const auto& student : students) {
        int honor_grades = count_if(student.grades.begin(), student.grades.end(), [](int grade) { return grade == 5; });
        honor_count[{student.faculty, student.course}] += honor_grades;
    }
    
    filesystem::remove(top_faculty_course_file);
    auto max_it = max_element(honor_count.begin(), honor_count.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
    ofstream file(top_faculty_course_file);
    if (file.is_open()) {
        if (max_it != honor_count.end()) {
            file << "Faculty with most honor students: " << max_it->first.first << ", Course: " << max_it->first.second << ", Honor grades: " << max_it->second << "\n";
            cout << "Faculty with most honor students: " << max_it->first.first << ", Course: " << max_it->first.second << ", Honor grades: " << max_it->second << "\n";
        } else {
            file << "No data available\n";
            cout << "No data available\n";
        }
        file.close();
        set_file_read_only(top_faculty_course_file);
        cout << "Top faculty/course written to " << top_faculty_course_file << "\n";
    }
}

// Знайти відмінників
void StudentDatabase::list_honor_students() const {
    filesystem::remove(honor_students_file);
    ofstream file(honor_students_file);
    int honor_count = 0;
    
    if (file.is_open()) {
        for (const auto& student : students) {
            bool is_honor = all_of(student.grades.begin(), student.grades.end(),
                [](int grade) { return grade == 5; });
            if (is_honor) {
                cout << student.surname << " (" << student.faculty << ", " << student.group << ")\n";
                file << student.surname << " (" << student.faculty << ", " << student.group << ")\n";
                honor_count++;
            }
        }
        file.close();
        
        if (honor_count == 0) {
            ofstream file(honor_students_file);
            if (file.is_open()) {
                file << "No honor students found.\n";
                cout << "No honor students found.\n";
                file.close();
                set_file_read_only(honor_students_file);
            }
        } else {
            set_file_read_only(honor_students_file);
        }
        
        cout << "Honor students written to " << honor_students_file << ", Lines: " << count_file_lines(honor_students_file) << "\n";
    }
}

// Групи групи без поганих оцінок
void StudentDatabase::find_no_failing_group() const {
    int count = 0;
    map<string, bool> group_no_fail;
    for (const auto& student : students) {
        if (!group_no_fail.count(student.group)) {
            group_no_fail[student.group] = true;
        }
        bool has_fail = any_of(student.grades.begin(), student.grades.end(), [](int grade) { return grade <= 2; });
        if (has_fail) {
            group_no_fail[student.group] = false;
        }
    }

    filesystem::remove(no_failing_group_file);
    ofstream file(no_failing_group_file);
    if (file.is_open()) {
        for (const auto& [group, no_fail] : group_no_fail) {
            if (no_fail) {
                file << "Group with no failing grades: " << group << "\n";
                cout << "Group with no failing grades: " << group << "\n";
                count++;
            }
        }
        file.close();
        set_file_read_only(no_failing_group_file);
        if (!count) cout << "No droups with failing grades";
        cout << "No failing groups written to " << no_failing_group_file << ", Lines: " << count_file_lines(no_failing_group_file) << "\n";
    }
}

// Функція повернення кількості стрічок у файлі
int StudentDatabase::count_file_lines(const string& filename) const {
    ifstream file(filename);
    int lines = 0;
    string line;
    while (getline(file, line)) {
        lines++;
    }
    file.close();
    return lines;
}

// Функція встановлення прав "тільки для читання" ( зроблено для зручності )
void StudentDatabase::set_file_read_only(const string& filename) const {
    chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH);
}

// Ініціювати вікно вибору
void display_menu_3(int &return_) {   
    StudentDatabase db("students.json", "top_faculty_course.txt", "honor_students.txt", "no_failing_group.txt"); 
    while (true) {
        system("clear");
        cout << "Student Database Management System\n";
        cout << "1. Add new student\n";
        cout << "2. Edit student\n";
        cout << "3. Delete student\n";
        cout << "4. Search student\n";
        cout << "5. Display database\n";
        cout << "6. Find faculty/course with most honor students\n";
        cout << "7. List honor students\n";
        cout << "8. Find group with no failing grades\n";
        cout << "9. Sort students\n";
        cout << "10. Save to file\n";
        cout << "11. Load from file\n";
        
        cout << "12. Return\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: db.add_student(); break;
            case 2: db.edit_student(); break;
            case 3: db.delete_student(); break;
            case 4: db.search_student(); break;
            case 5: db.display_database(); break;
            case 6: db.find_top_faculty_course(); break;
            case 7: db.list_honor_students(); break;
            case 8: db.find_no_failing_group(); break;

            case 9: db.sort_students(); break;
            case 10: db.save_to_file(); break;
            case 11: db.load_from_file(); break;

            case 12: return;
            case 0: return_ = 0; return;
            default: cout << "Invalid choice!\n";
        }
        cout << "Press Enter to continue...";
        cin.get();
        cin.get();
    }
    
}

void init() {
    int choice;
    while (true) {
        system("clear");
        cout << "Student Practic IPZ-21, 4. Theme 4:\n";
        cout << "1. Task 1\n";
        cout << "2. Task 2\n";
        cout << "3. Task 3\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice)
        {
        case 1: display_menu_1(choice); break;
        case 2: display_task_2(); break;
        case 3: display_menu_3(choice); break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
        if (!choice) return;
    }
}
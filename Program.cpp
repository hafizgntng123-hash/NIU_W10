//Program ini mengelola data nilai siswa menggunakan struct dan array
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi struktur data
struct studentType {
    string studentFName; //Menyimpan nama depan siswa
    string studentLName; //Menyimpan nama belakang siswa
    int testScore; //Menyimpan nilai ujian (0-100)
    char grade; //Menyimpan huruf grade (A, B, C, D, F)
};

// Deklarasi fungsi
void readStudentData(studentType students[], int size); //Membaca input data dari user untuk semua siswa
void assignGrades(studentType students[], int size); /*Menghitung grade berdasarkan test score
90-100: A
80-89: B
70-79: C
60-69: D
<60: F */
int findHighestScore(studentType students[], int size); //Mencari nilai tertinggi dari semua siswa
void printHighestScoringStudents(studentType students[], int size, int highestScore); //Menampilkan siswa yang memiliki nilai tertinggi

const int CLASS_SIZE = 20; // Jumlah siswa dalam kelas

int main() {
    studentType students[CLASS_SIZE]; // Membuat array berisi data 20 siswa
    
    readStudentData(students, CLASS_SIZE); // Membaca data dari pengguna
    assignGrades(students, CLASS_SIZE); // Menentukan huruf grade berdasarkan skor
    int highestScore = findHighestScore(students, CLASS_SIZE); // Mencari nilai tertinggi dari seluruh siswa
    
    // Menampilkan seluruh data siswa
    cout << "\n=== ALL STUDENTS' RESULTS ===" << endl;
    cout << left << setw(25) << "NAME" << setw(12) << "TEST SCORE" << "GRADE" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < CLASS_SIZE; i++) {
        cout << left << setw(25) << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(12) << students[i].testScore << students[i].grade << endl;
    }
    
    // Menampilkan siswa dengan nilai tertinggi
    cout << "\n=== HIGHEST SCORING STUDENTS ===" << endl;
    printHighestScoringStudents(students, CLASS_SIZE, highestScore);
    
    return 0;
}

// a. Fungsi untuk membaca data siswa ke dalam array
void readStudentData(studentType students[], int size) {
    cout << "Enter data for " << size << " students:\n" << endl;
    for (int i = 0; i < size; i++) {
        cout << "STUDENT " << (i + 1) << ":" << endl;
        cout << "First Name: ";
        cin >> students[i].studentFName;
        cout << "Last Name: ";
        cin >> students[i].studentLName;
        cout << "Test Score (0-100): ";
        cin >> students[i].testScore;
        
        // Validasi agar nilai tetap dalam rentang 0–100
        while (students[i].testScore < 0 || students[i].testScore > 100) {
            cout << "Invalid score! Enter test score (0-100): ";
            cin >> students[i].testScore;
        }
        cout << endl;
    }
}

// b.  Fungsi untuk menentukan grade setiap siswa
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90)
            students[i].grade = 'A';
        else if (students[i].testScore >= 80)
            students[i].grade = 'B';
        else if (students[i].testScore >= 70)
            students[i].grade = 'C';
        else if (students[i].testScore >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// c. Fungsi untuk mencari nilai ujian tertinggi
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
}

// d. Fungsi untuk menampilkan nama siswa dengan nilai tertinggi
void printHighestScoringStudents(studentType students[], int size, int highestScore) {
    cout << "Highest Test Score: " << highestScore << endl;
    cout << "Students with highest score:" << endl;
    
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << "- " << students[i].studentLName << ", " << students[i].studentFName << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No students found with the highest score." << endl;
    }
}
/* Cara kerja progam :
1 Program membaca data siswa (nama depan, nama belakang, nilai ujian) sebanyak 20 orang menggunakan fungsi readStudentData().
Jika nilai di luar 0–100, pengguna diminta menginput ulang.
2. Setelah data dimasukkan, program memanggil assignGrades() untuk memberi huruf nilai (A–F) berdasarkan skor ujian.
3. Fungsi findHighestScore() mencari nilai ujian tertinggi dari seluruh siswa dan mengembalikannya ke main().
4. Selanjutnya, seluruh data siswa ditampilkan dalam bentuk tabel menggunakan setw() agar rapi dan mudah dibaca.
5. Terakhir, program memanggil printHighestScoringStudents() untuk menampilkan nama siswa yang memperoleh nilai tertinggi beserta nilainya.*/
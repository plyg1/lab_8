#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;

// Завдання 1: Дублювання парних чисел у масиві
void duplicate_even_values(vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        result.push_back(num);
        if (num % 2 == 0) {
            result.push_back(num);
        }
    }
    arr = result;
}

// Завдання 2: Знайти рядок з найбільшою сумою елементів
void find_max_sum_row(const vector<vector<int>>& matrix, int& max_row, int& max_sum) {
    max_row = 0;
    max_sum = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        int sum = 0;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            sum += matrix[i][j];
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_row = i;
        }
    }
}

// Завдання 3: Сортування методом вставок (зменшення)
void insertion_sort_descending(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void read_array(const string& filename, vector<int>& arr) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    size_t n;
    infile >> n;
    arr.resize(n);
    for (size_t i = 0; i < n; ++i) {
        infile >> arr[i];
    }
    infile.close();
}

void write_array(const string& filename, const vector<int>& arr) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    for (const int& elem : arr) {
        outfile << elem << " ";
    }
    outfile.close();
}

void read_matrix(const string& filename, vector<vector<int>>& matrix, size_t& m, size_t& n) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    infile >> m >> n;
    matrix.resize(m, vector<int>(n));
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            infile >> matrix[i][j];
        }
    }
    infile.close();
}

void write_matrix_result(const string& filename, int max_row, int max_sum) {
    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    outfile << "Рядок з найбільшою сумою: " << max_row + 1 << endl;
    outfile << "Максимальна сума: " << max_sum << endl;
    outfile.close();
}

void menu() {
    cout << "Оберіть завдання:" << endl;
    cout << "1. Продублювати парні числа у масиві" << endl;
    cout << "2. Знайти рядок з найбільшою сумою елементів у матриці" << endl;
    cout << "3. Сортування масиву методом вставок (зменшення)" << endl;
    cout << "0. Вихід" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        menu();
        cin >> choice;

        if (choice == 1) {
            string input_file, output_file;
            cout << "Введіть ім'я вхідного файлу: ";
            cin >> input_file;
            cout << "Введіть ім'я вихідного файлу: ";
            cin >> output_file;

            vector<int> arr;
            read_array(input_file, arr);
            duplicate_even_values(arr);
            write_array(output_file, arr);
            cout << "Результат збережено у " << output_file << endl;

        }
        else if (choice == 2) {
            string input_file, output_file;
            cout << "Введіть ім'я вхідного файлу: ";
            cin >> input_file;
            cout << "Введіть ім'я вихідного файлу: ";
            cin >> output_file;

            vector<vector<int>> matrix;
            size_t m, n;
            read_matrix(input_file, matrix, m, n);
            int max_row, max_sum;
            find_max_sum_row(matrix, max_row, max_sum);
            write_matrix_result(output_file, max_row, max_sum);
            cout << "Результат збережено у " << output_file << endl;

        }
        else if (choice == 3) {
            string input_file;
            cout << "Введіть ім'я вхідного файлу: ";
            cin >> input_file;

            vector<int> arr;
            read_array(input_file, arr);
            insertion_sort_descending(arr);

            cout << "Відсортований масив: ";
            for (const int& elem : arr) {
                cout << elem << " ";
            }
            cout << endl;
        }

    } while (choice != 0);

    return 0;
}

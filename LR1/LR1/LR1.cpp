#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    string nameS;
    double rating;
    double height;

    void print() {
        cout << "Имя та Фамилию : " << nameS << endl;
        cout << "Рейтинг : " << rating << endl;
        cout << "Рост" << height << endl;
    }

    void input() {
        cout << "Введите имя и Фамилию студента : ";
        cin >> nameS;
        cout << "Рейтинг : ";
        cin >> rating;
        cout << "Рост : ";
        cin >> height;

    }
};

void print_interface();
void qSort(vector<Student>& student, int& swap_count, int& comprasions_count, int l, int r);

int main()
{
    setlocale(LC_ALL, "ru");
    int x;
    cout << "Введите количество студентов : ";
    cin >> x;

    int a = 1;
    vector<Student> student(x);

    while (a != x + 5) {
        print_interface();
        cin >> a;

        switch (a) {
        case 1: {
            cout << endl;
            for (int i = 0; i < x; i++) {
                student[i].input();
                cout << endl;
            }
            break;
        }
        case 2: {
            int swap_count = 0;
            int comprasions_count = 0;
            double start_time = clock();

            cout << "Bubble sort" << endl;
            for (int i = 0; i < x; i++)
                for (int j = i + 1; j < x; j++) {
                    if (student[i].rating > student[j].rating) {
                        swap(student[i], student[j]);
                        swap_count++;
                    }
                    comprasions_count++;
                }
            double end_time = clock();
            double search_time = end_time - start_time;

            cout << "Час роботи : " << search_time << endl;
            cout << "Кiлькiсть операцiй обмiну : " << swap_count << endl;
            cout << "Кiлькiсть операцiй порiвняння : " << comprasions_count << "\n\n";
            break;


        }
        case 3: {
            int swap_count = 0;
            int comprasions_count = 0;
            double start_time = clock();

            cout << "Quick sort" << endl;

            qSort(student, swap_count, comprasions_count, 0, student.size() - 1);

            double end_time = clock();
            double search_time = end_time - start_time;

            cout << "Час роботи : " << search_time << endl;
            cout << "Кiлькiсть операцiй обмiну : " << swap_count << endl;
            cout << "Кiлькiсть операцiй порiвняння : " << comprasions_count << "\n\n";

            break;
        }
        case 4: {
            for (int i = 0; i < x; i++) {
                student[i].print();
                cout << endl;
            }
            break;
        }
        case 5: {
            system("cls");
            break;
        }
        case 6: {
            return 0;
        }
        }
    }
}

void print_interface() {
    cout << "1.Внесение данных" << endl;
    cout << "2.Пузырьковая сортировка" << endl;
    cout << "3.Быстрая сортировка" << endl;
    cout << "4.Вывод данных" << endl;
    cout << "5.Очисктка екрана" << endl;
    cout << "6.Выход" << endl;
}
void qSort(vector<Student>& student, int& swap_count, int& comprasions_count, int l, int r) {
    int i = l, j = r;
    int pivot = student[(l + r) / 2].rating;    
    int pivot_static = pivot;

    while (i <= j) {
        comprasions_count++;

        while (student[i].rating < pivot_static) i++;
        while (student[j].rating > pivot_static) j--;

        if (i <= j) {
            swap(student[i], student[j]);
            i++; j--;
            swap_count++;
        }
    }

    if (l < j) qSort(student, swap_count, comprasions_count, l, j);
    if (i < r) qSort(student, swap_count, comprasions_count, i, r);
}
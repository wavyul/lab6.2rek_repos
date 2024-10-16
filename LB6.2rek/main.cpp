#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

double FindingTheArithmetic(int* arr, int SIZE, int i, double sum, int count) {
    if (i < SIZE) {
        if (i % 2 == 0) {
            sum += arr[i];
            count++;
        }
        return FindingTheArithmetic(arr, SIZE, i + 1, sum, count);
    }
    else {
        if (count == 0) {
            return 0;
        }
        else {
            return sum / count;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX, 0);


    Print(arr, SIZE, 0);
    cout << "\n\n";
    cout << "Середнє арифметичне елементів з парними індексами: "
        << FindingTheArithmetic(arr, SIZE, 0, 0.0, 0) << endl;

    delete[] arr;

    return 0;
}

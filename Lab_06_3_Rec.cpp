#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Рекурсивне формування масиву
void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    if (i >= size) return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(const int* a, const int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    Print(a, size, i + 1);
}

// 1. Звичайна рекурсивна функція
int MinOddElement(const int* a, const int size, int i = 0, int currentMin = INT_MAX) {
    if (i >= size) {
        return (currentMin == INT_MAX) ? 0 : currentMin;
    }

    if (a[i] % 2 != 0 && a[i] < currentMin) {
        currentMin = a[i];
    }

    return MinOddElement(a, size, i + 1, currentMin);
}

// 2. Шаблонна рекурсивна функція
template <typename T>
T MinOddElement(const T* a, const int size, int i = 0, T currentMin = INT_MAX) {
    if (i >= size) {
        return (currentMin == INT_MAX) ? 0 : currentMin;
    }

    if (static_cast<long long>(a[i]) % 2 != 0 && a[i] < currentMin) {
        currentMin = a[i];
    }

    return MinOddElement<T>(a, size, i + 1, currentMin);
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 10;
    const int LOW = -20;
    const int HIGH = 50;

    int a[SIZE];

    Create(a, SIZE, LOW, HIGH);

    cout << "Initial array:" << endl;
    Print(a, SIZE);

    // Виклик звичайної рекурсивної функції
    int minOdd1 = MinOddElement(a, SIZE);

    // Виклик шаблонної рекурсивної функції
    int minOdd2 = MinOddElement<int>(a, SIZE);

    cout << endl;
    if (minOdd1 != 0) {
        cout << "Min odd element (ordinary recursive): " << minOdd1 << endl;
        cout << "Min odd element (template recursive): " << minOdd2 << endl;
    }
    else {
        cout << "There are no odd elements in the array." << endl;
    }

    return 0;
}
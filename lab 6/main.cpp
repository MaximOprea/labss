#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Функция для выделения динамического буфера и заполнения его случайными числами
std::vector<int> generateRandomArray(size_t size) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 1000);

    for (size_t i = 0; i < size; ++i) {
        array[i] = distribution(generator);
    }

    return array;
}

// Функция для измерения времени выполнения переданной функции
template <typename Function>
std::chrono::microseconds measureExecutionTime(Function&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

// Алгоритмы сортировки и поиска

// Selection Sort
void selectionSort(std::vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(std::vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        for (size_t j = 0; j < array.size() - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// Linear Search
size_t linearSearch(const std::vector<int>& array, int target) {
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return array.size(); // Возвращаем размер массива, если элемент не найден
}

// Binary Search
size_t binarySearch(const std::vector<int>& array, int target) {
    size_t left = 0;
    size_t right = array.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return array.size(); // Возвращаем размер массива, если элемент не найден
}

int main() {
    const size_t arraySize = 10000;
    const size_t numTests = 5;

    // Генерация случайного массива
    std::vector<int> randomArray = generateRandomArray(arraySize);

    // Тестирование алгоритмов сортировки
    auto selectionSortTime = measureExecutionTime([&]() {
        for (size_t i = 0; i < numTests; ++i) {
            std::vector<int> copyArray = randomArray;
            selectionSort(copyArray);
        }
    });

    auto bubbleSortTime = measureExecutionTime([&]() {
        for (size_t i = 0; i < numTests; ++i) {
            std::vector<int> copyArray = randomArray;
            bubbleSort(copyArray);
        }
    });

    // Тестирование алгоритмов поиска
    auto linearSearchTime = measureExecutionTime([&]() {
        for (size_t i = 0; i < numTests; ++i) {
            linearSearch(randomArray, randomArray[arraySize / 2]);
        }
    });

    auto binarySearchTime = measureExecutionTime([&]() {
        for (size_t i = 0; i < numTests; ++i) {
            std::vector<int> copyArray = randomArray;
            std::sort(copyArray.begin(), copyArray.end());
            binarySearch(copyArray, copyArray[arraySize / 2]);
        }
    });

    // Вывод результатов
    std::cout << "Selection Sort Time: " << selectionSortTime.count() / numTests << " microseconds\n";
    std::cout << "Bubble Sort Time: " << bubbleSortTime.count() / numTests << " microseconds\n";
    std::cout << "Linear Search Time: " << linearSearchTime.count() / numTests << " microseconds\n";
    std::cout << "Binary Search Time: " << binarySearchTime.count() / numTests << " microseconds\n";

    return 0;
}
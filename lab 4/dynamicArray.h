#pragma once /* директива препроцессора в языке C++ для предотвращения 
многократного включения одного и того же файла заголовка в течение одной компиляции. */

#include <span>

// Структура для представления динамического массива
struct DynamicArray
{
    int* buffer;   // Указатель на массив элементов
    size_t capacity;  // Общая ёмкость массива (размер выделенной памяти)
    size_t length;    // Текущее количество элементов в массиве
};

// Создает динамический массив с указанной начальной ёмкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity);

// Создает динамический массив с дефолтной начальной ёмкостью
DynamicArray createDynamicArray();

// Добавляет элемент в конец массива
void addElementToArray(DynamicArray* arr, int element);

// Получает элемент массива по указанному индексу
int getElementAtIndex(const DynamicArray* arr, size_t index);

// Возвращает std::span, представляющий текущий кусок массива
std::span<int> getCurrentSpan(const DynamicArray* arr);

// Освобождает выделенную память для динамического массива
void destroyDynamicArray(DynamicArray* arr);

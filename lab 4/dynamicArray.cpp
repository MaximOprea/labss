#include "dynamicArray.h"
#include <cassert>
#include <span>

// Создает динамический массив с указанной начальной ёмкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity)
{
    DynamicArray arr;
    arr.buffer = new int[capacity];
    arr.capacity = capacity;
    arr.length = 0;
    return arr;
}

// Создает динамический массив с дефолтной начальной ёмкостью
DynamicArray createDynamicArray()
{
    // Используем дефолтный capacity (например, 4)
    return createDynamicArrayWithCapacity(4);
}

// Добавляет элемент в конец массива
void addElementToArray(DynamicArray* arr, int element)
{
    if (arr->length == arr->capacity)
    {
        // Если массив полный, удваиваем его размер
        size_t newCapacity = arr->capacity * 2;
        int* newBuffer = new int[newCapacity];

        // Копируем элементы из старого массива в новый
        for (size_t i = 0; i < arr->length; ++i)
        {
            newBuffer[i] = arr->buffer[i];
        }

        // Освобождаем память старого массива и обновляем указатель
        delete[] arr->buffer;
        arr->buffer = newBuffer;
        arr->capacity = newCapacity;
    }

    // Добавляем новый элемент в конец массива
    arr->buffer[arr->length++] = element;
}

// Получает элемент массива по указанному индексу
int getElementAtIndex(const DynamicArray* arr, size_t index)
{
    // Проверка валидности индекса
    assert(index < arr->length);
    return arr->buffer[index];
}

// Возвращает std::span, представляющий текущий кусок массива
std::span<int> getCurrentSpan(const DynamicArray* arr)
{
    return {arr->buffer, arr->length};
}

// Освобождает выделенную память для динамического массива
void destroyDynamicArray(DynamicArray* arr)
{
    delete[] arr->buffer;
    arr->buffer = nullptr;
    arr->capacity = 0;
    arr->length = 0;
}
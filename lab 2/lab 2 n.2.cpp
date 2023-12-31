#include <stdlib.h>
#include <iostream>

// Определение структуры TwoInts с двумя целыми числами
struct TwoInts
{
    int a;
    int b;
};

// Определение структуры StructWithArray с массивом и указателем
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Инициализация структуры TwoInts, a и b устанавливаются в 0
    TwoInts i2 = { };

    // Присвоение значения полям a и b структуры TwoInts
    i2.a = 5;
    i2.b = 7;

    // Вывод значений a и b на экран
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Инициализация структуры StructWithArray, массив arr устанавливается в 0
    StructWithArray s = { };

    // Присвоение значения первому элементу массива arr в структуре s
    s.arr[0] = 10;

    // Инициализация еще одной структуры StructWithArray
    StructWithArray s1 = { };

    // Присвоение значения первому элементу массива arr в структуре s1
    s1.arr[0] = 15;

    // Создание указателя на структуру StructWithArray и присвоение значения первому элементу массива
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;

    // Вывод значения первого элемента массива arr в структуре s
    std::cout << s.arr[0] << std::endl;

    // Присвоение нового значения первому элементу массива arr в структуре s
    s.arr[0] = 25;

    // Вывод нового значения первого элемента массива arr в структуре s
    std::cout << s.arr[0] << std::endl;

    // Присвоение значения первому элементу массива arr через указатель
    sPointer->arr[0] = 30;

    // Вывод значения первого элемента массива arr в структуре s
    std::cout << s.arr[0] << std::endl;

    // Изменение указателя на структуру s1
    sPointer = &s1;

    // Присвоение значения первому элементу массива arr через указатель
    sPointer->arr[0] = 35;

    // Вывод значения первого элемента массива arr в структуре s
    std::cout << s.arr[0] << std::endl;

    // Вывод значения первого элемента массива arr в структуре s1
    std::cout << s1.arr[0] << std::endl;

    // Инициализация массива структур StructWithArray
    StructWithArray structArray[2] = { };

    // Присвоение значения четвертому элементу массива arr в первой структуре
    structArray[0].arr[3] = 77;

    // Присвоение указателю someNumber второй структуры адреса четвертого элемента массива arr
    structArray[1].someNumber = &structArray[0].arr[3];

    // Изменение указателя на структуру s
    sPointer = &s;

    // Создание указателя на четвертый элемент массива arr в структуре s через указатель
    int* pointer = &sPointer->arr[3];

    // Присвоение нового значения четвертому элементу массива arr в структуре s
    s.arr[3] = 72;

    // Вывод значения, на которое указывает указатель
    std::cout << *pointer;

    // Создание структуры StructWithArray в стеке и заполнение ее нулями
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
@echo off
g++ -c dynamicArray.cpp -o dynamicArray.o
g++ -c main.cpp -o main.o
g++ dynamicArray.o main.o -o dynamicArrayTest
:: В файле dynamicArray.h содержатся объявления функций и структуры.
:: Файл dynamicArray.cpp содержит реализации этих функций.
:: Файл main.cpp используется для тестирования функциональности динамического массива.
:: Файл compile.bat содержит команды для компиляции программы.
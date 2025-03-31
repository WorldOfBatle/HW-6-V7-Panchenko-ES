#include <iostream>
#include <cmath>
#include <fstream>    // для работы с файловыми потоками
#include <vector>     // для std::vector

void task1()
{
    // Одномерный массив заготовка
    {
        std::cout << "[Одномерный массив]\n";

        // Открываем файл с данными
        std::ifstream input1D("task1_input_1d.txt");
        if (!input1D.is_open())
        {
            std::cerr << "Не удалось открыть файл task1_input_1d.txt\n";
        }
        else
        {
            int n;
            input1D >> n; // считываем размер массива
            if (!input1D || n <= 0)
            {
                std::cerr << "Некорректные данные для n в файле task1_input_1d.txt\n";
            }
            else
            {
                // Считываем n целых чисел в массив
                std::vector<int> arr(n);
                for (int i = 0; i < n; i++)
                {
                    input1D >> arr[i];
                }

                // Считаем среднее отрицательных
                int negativeCount = 0;
                long long sumNeg = 0;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] < 0)
                    {
                        sumNeg += arr[i];
                        negativeCount++;
                    }
                }

                if (negativeCount == 0)
                {
                    std::cout << "Нет отрицательных элементов.\n";
                }
                else
                {
                    double average = static_cast<double>(sumNeg) / negativeCount;
                    std::cout << "Среднее отрицательных (1D) = " << average << std::endl;
                }
            }
        }
    }

    // Двумерный массив заготовка
    {
        std::cout << "[Двумерный массив]\n";

        std::ifstream input2D("task1_input_2d.txt");
        if (!input2D.is_open())
        {
            std::cerr << "Не удалось открыть файл task1_input_2d.txt\n";
        }
        else
        {
            int rows, cols;
            input2D >> rows >> cols;
            if (!input2D || rows <= 0 || cols <= 0)
            {
                std::cerr << "Некорректные данные для rows/cols в task1_input_2d.txt\n";
            }
            else
            {
                // Создаем двумерный массив
                std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

                // Считываем элементы
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        input2D >> matrix[i][j];
                    }
                }

                // Считаем среднее отрицательных по всей матрице (как одна последовательность)
                int negCount = 0;
                long long sumNeg = 0;

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        if (matrix[i][j] < 0)
                        {
                            sumNeg += matrix[i][j];
                            negCount++;
                        }
                    }
                }

                if (negCount == 0)
                {
                    std::cout << "Нет отрицательных элементов (2D).\n";
                }
                else
                {
                    double average2D = static_cast<double>(sumNeg) / negCount;
                    std::cout << "Среднее отрицательных (2D) = " << average2D << std::endl;
                }
            }
        }
    }
}
void task2()
{
    // Заготовка для считывания массива
    {
        std::ifstream input("task2_input.txt");
        if (!input.is_open())
        {
            std::cerr << "Не удалось открыть файл task2_input.txt\n";
            return;
        }

        // Считываем n
        int n;
        input >> n;
        if (!input || n <= 0)
        {
            std::cerr << "Некорректное значение n в task2_input.txt\n";
            return;
        }

        // Считываем n действительных чисел
        std::vector<double> arr(n);
        for (int i = 0; i < n; i++)
        {
            input >> arr[i];
            if (!input)
            {
                std::cerr << "Ошибка чтения числа №" << (i + 1) << " из файла\n";
                return;
            }
        }

        // Ищем первый минимальный
        // Инициализируем minValue и minIndex начальными значениями
        double minValue = arr[0];
        int minIndex = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
                minIndex = i;
            }
        }

        // Выводим индекс (1-базный)
        std::cout << "Первый минимальный элемент = " << minValue
            << ", индекс = " << (minIndex) << std::endl;
    }
}

void task3()
{
}

void task4()
{
}

void task5()
{
}

void task6()
{
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}

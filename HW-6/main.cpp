#include <iostream>
#include <cmath>
#include <fstream>    // для работы с файловыми потоками
#include <vector>     // для std::vector

void task1()
{
    std::cout << "\n--- Task 1: Среднее отрицательных (1D и 2D) ---\n";

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
    std::cout << "\n--- Task 2: Индекс первого минимального элемента (1D) ---\n";

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

        // Выводим индекc
        std::cout << "Первый минимальный элемент = " << minValue
            << ", индекс = " << (minIndex) << std::endl;
    }
}

void task3()
{
    std::cout << "\n--- Task 3: Перестановка средних строк (2D) ---\n";

    std::ifstream input("task3_input.txt");
    if (!input.is_open())
    {
        std::cerr << "Не удалось открыть файл task3_input.txt\n";
        return;
    }

    int n, m;
    input >> n >> m;
    if (!input || n <= 0 || m <= 0)
    {
        std::cerr << "Некорректные n или m\n";
        return;
    }

    // Считываем матрицу
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input >> matrix[i][j];
        }
    }

    // Выводим матрицу для проверки
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Логика перестановки
    if (n % 2 == 0)
    {
        // Чётное число строк
        int row1 = (n / 2) - 1;  // "левая" средняя
        int row2 = (n / 2);      // "правая" средняя

        // Меняем строки row1 и row2
        std::swap(matrix[row1], matrix[row2]);
        std::cout << "\nЧётное n=" << n << ". Поменяли строки "
            << row1 << " и " << row2 << "\n";
    }
    else
    {
        // Нечётное число строк
        int rowMid = n / 2; // целочисленное деление
        // Меняем строку 0 и rowMid
        std::swap(matrix[0], matrix[rowMid]);
        std::cout << "\nНечётное n=" << n << ". Поменяли строку 0 и "
            << rowMid << "\n";
    }

    // Выводим результат
    std::cout << "\nМатрица после перестановки:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void task4()
{
    std::cout << "\n--- Task 4: Сумма отрицательных по столбцам (2D) ---\n";

    std::ifstream input("task4_input.txt");
    if (!input.is_open())
    {
        std::cerr << "Не удалось открыть файл task4_input.txt\n";
        return;
    }

    int n, l;
    input >> n >> l;
    if (!input || n <= 0 || l <= 0)
    {
        std::cerr << "Некорректные размеры n и l\n";
        return;
    }

    // Создаем двумерный массив (vector)
    std::vector<std::vector<int>> matrix(n, std::vector<int>(l));

    // Считываем элементы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            input >> matrix[i][j];
        }
    }

    // Выводим матрицу для проверки
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Создаем массив (vector) для сумм отрицательных по каждому столбцу
    std::vector<long long> colSum(l, 0LL);

    // Для каждого столбца, суммируем отрицательные
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (matrix[i][j] < 0)
            {
                colSum[j] += matrix[i][j];
            }
        }
    }

    // Выводим результат
    std::cout << "\nСумма отрицательных по столбцам:\n";
    for (int j = 0; j < l; j++)
    {
        std::cout << colSum[j] << " ";
    }
    std::cout << std::endl;
}

void task5()
{
    std::cout << "\n--- Task 5: Вставить элемент после последнего положительного (1D) ---\n";

    std::ifstream input("task5_input.txt");
    if (!input.is_open())
    {
        std::cerr << "Не удалось открыть файл task5_input.txt\n";
        return;
    }

    int n;
    input >> n;
    if (!input || n < 0)
    {
        std::cerr << "Некорректное n\n";
        return;
    }

    // Считываем массив
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        input >> arr[i];
    }

    // Считаем, что следующий элемент в файле — это "newElem"
    int newElem;
    input >> newElem; // не проверяем особо, что файл содержит, для упрощения

    // Находим индекс последнего положительного
    int posIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            posIndex = i;
        }
    }

    // Вставляем элемент после posIndex (или в конец, если posIndex = -1)
    if (posIndex == -1)
    {
        // Нет положительных, вставляем в конец
        arr.push_back(newElem);
        std::cout << "Положительных элементов нет. Вставляем в конец.\n";
    }
    else
    {
        // Вставляем после posIndex
        // posIndex + 1 — позиция для вставки
        arr.insert(arr.begin() + (posIndex + 1), newElem);
        std::cout << "Вставляем после индекса " << posIndex << "\n";
    }

    // Выводим результат
    std::cout << "Результирующий массив: ";
    for (int i = 0; i < (int)arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
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

#include <iostream>
#include <cmath>
#include <fstream>

// Максимальные размеры для статических массивов
constexpr size_t MAX1D = 1000;
constexpr size_t MAX2D_ROWS = 100;
constexpr size_t MAX2D_COLS = 100;

void task1()
{
    std::cout << "\n--- Task 1: Среднее отрицательных (1D и 2D) ---\n";

    // Одномерный массив
    {
        std::cout << "[Одномерный массив]\n";

        std::ifstream input1D("task1_input_1d.txt");
        if (!input1D.is_open())
        {
            std::cerr << "Не удалось открыть файл task1_input_1d.txt\n";
        }
        else
        {
            int n;
            input1D >> n;
            if (!input1D || n <= 0 || static_cast<size_t>(n) > MAX1D)
            {
                std::cerr << "Некорректные данные для n в task1_input_1d.txt\n";
            }
            else
            {
                int arr[MAX1D];
                for (int i = 0; i < n; i++)
                {
                    input1D >> arr[i];
                }

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
                    std::cout << "Среднее отрицательных (1D) = " << average << "\n";
                }
            }
        }
    }

    // Двумерный массив
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
            if (!input2D
                || rows <= 0 || cols <= 0
                || static_cast<size_t>(rows) > MAX2D_ROWS
                || static_cast<size_t>(cols) > MAX2D_COLS)
            {
                std::cerr << "Некорректные размеры матрицы в task1_input_2d.txt\n";
            }
            else
            {
                int matrix[MAX2D_ROWS][MAX2D_COLS];
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        input2D >> matrix[i][j];
                    }
                }

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
                    std::cout << "Среднее отрицательных (2D) = " << average2D << "\n";
                }
            }
        }
    }
}

void task2()
{
    std::cout << "\n--- Task 2: Индекс первого минимального элемента (1D) ---\n";

    std::ifstream input("task2_input.txt");
    if (!input.is_open())
    {
        std::cerr << "Не удалось открыть файл task2_input.txt\n";
        return;
    }

    int n;
    input >> n;
    if (!input || n <= 0 || static_cast<size_t>(n) > MAX1D)
    {
        std::cerr << "Некорректное значение n в task2_input.txt\n";
        return;
    }

    double arr[MAX1D];
    for (int i = 0; i < n; i++)
    {
        input >> arr[i];
        if (!input)
        {
            std::cerr << "Ошибка чтения числа №" << (i + 1) << "\n";
            return;
        }
    }

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

    std::cout << "Первый минимальный элемент = " << minValue
        << ", индекс = " << minIndex << "\n";
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
    if (!input
        || n <= 0 || m <= 0
        || static_cast<size_t>(n) > MAX2D_ROWS
        || static_cast<size_t>(m) > MAX2D_COLS)
    {
        std::cerr << "Некорректные размеры матрицы в task3_input.txt\n";
        return;
    }

    int matrix[MAX2D_ROWS][MAX2D_COLS];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input >> matrix[i][j];
        }
    }

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    if (n % 2 == 0)
    {
        int r1 = n / 2 - 1, r2 = n / 2;
        for (int j = 0; j < m; j++)
        {
            std::swap(matrix[r1][j], matrix[r2][j]);
        }
        std::cout << "\nЧётное n=" << n << ": поменяли строки "
            << r1 << " и " << r2 << "\n";
    }
    else
    {
        int r0 = 0, rm = n / 2;
        for (int j = 0; j < m; j++)
        {
            std::swap(matrix[r0][j], matrix[rm][j]);
        }
        std::cout << "\nНечётное n=" << n << ": поменяли строки 0 и "
            << rm << "\n";
    }

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
    if (!input
        || n <= 0 || l <= 0
        || static_cast<size_t>(n) > MAX2D_ROWS
        || static_cast<size_t>(l) > MAX2D_COLS)
    {
        std::cerr << "Некорректные размеры матрицы в task4_input.txt\n";
        return;
    }

    int matrix[MAX2D_ROWS][MAX2D_COLS];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            input >> matrix[i][j];
        }
    }

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    long long colSum[MAX2D_COLS] = { 0 };
    // обойдём СНАЧАЛА столбцы, затем строки
    for (int j = 0; j < l; j++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] < 0)
                sum += matrix[i][j];
        }
        colSum[j] = sum;
    }

    std::cout << "\nСумма отрицательных по столбцам:\n";
    for (int j = 0; j < l; j++)
    {
        std::cout << colSum[j] << " ";
    }
    std::cout << "\n";
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
    if (!input || n < 0 || static_cast<size_t>(n) > MAX1D)
    {
        std::cerr << "Некорректное значение n в task5_input.txt\n";
        return;
    }

    int arr[MAX1D + 1];
    for (int i = 0; i < n; i++)
    {
        input >> arr[i];
    }
    int newElem;
    input >> newElem;

    int posIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            posIndex = i;
    }

    if (n + 1 > static_cast<int>(MAX1D + 1))
    {
        std::cerr << "Переполнение массива при вставке\n";
        return;
    }

    if (posIndex < 0)
    {
        // вставляем в конец
        arr[n++] = newElem;
        std::cout << "Положительных нет — вставляем в конец\n";
    }
    else
    {
        // сдвигаем всё вправо
        for (int i = n; i > posIndex + 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[posIndex + 1] = newElem;
        ++n;
        std::cout << "Вставляем после индекса " << posIndex << "\n";
    }

    std::cout << "Результат: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void task6()
{
    std::cout << "\n--- Task 6: Удалить столбцы, где первый элемент > последнего (2D) ---\n";

    std::ifstream input("task6_input.txt");
    if (!input.is_open())
    {
        std::cerr << "Не удалось открыть файл task6_input.txt\n";
        return;
    }

    int n, m;
    input >> n >> m;
    if (!input
        || n <= 0 || m <= 0
        || static_cast<size_t>(n) > MAX2D_ROWS
        || static_cast<size_t>(m) > MAX2D_COLS)
    {
        std::cerr << "Некорректные размеры матрицы в task6_input.txt\n";
        return;
    }

    int matrix[MAX2D_ROWS][MAX2D_COLS];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input >> matrix[i][j];
        }
    }

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    int newMatrix[MAX2D_ROWS][MAX2D_COLS];
    int newM = 0;

    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] <= matrix[n - 1][j])
        {
            // копируем столбец j
            for (int i = 0; i < n; i++)
            {
                newMatrix[i][newM] = matrix[i][j];
            }
            ++newM;
        }
    }

    std::cout << "\nМатрица после удаления столбцов:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < newM; j++)
        {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
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

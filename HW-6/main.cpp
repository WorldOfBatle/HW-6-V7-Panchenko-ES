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
    }
}
void task2()
{
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

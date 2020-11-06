#include <iostream>
#include <chrono>

void quick_sort(int *arr, int start, int finish)
{
    int arr_s = start;
    int arr_f = finish;
    short int t;
    int mid = arr[(arr_s + arr_f) / 2];
    while (arr_s < arr_f)
    {
        while (arr[arr_s] < mid)
        {
            arr_s++;
        }
        while (arr[arr_f] > mid)
        {
            arr_f--;
        }
        if (arr_s <= arr_f)
        {
            t = arr[arr_s];
            arr[arr_s] = arr[arr_f];
            arr[arr_f] = t;
            arr_s++;
            arr_f--;
        }
    }
    if (start < arr_f)
    {
        quick_sort(arr, start, arr_f);
    }
    if (arr_s < finish)
    {
        quick_sort(arr, arr_s, finish);
    }
}

int left_binary(int* arr, int number)
{
    int left = 0;
    int right = 99;
    int mid = (left + right) / 2;
    while (left != mid)
    {
        if (number <= arr[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid;
            mid = (left + right) / 2;
        }
    }
    if (number <= arr[0])
    {
        left--;
    }
    if (number > arr[99])
    {
        left++;
    }
    return left + 1;
}

int right_binary(int* arr, int number)
{
    int left = 0;
    int right = 99;
    int mid = (left + right) / 2;
    while (left != mid)
    {
        if (number < arr[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid;
            mid = (left + right) / 2;
        }
    }
    if (number < arr[0])
    {
        right--;
    }
    if (number >= arr[99])
    {
        right++;
    }
    return right;
}

int brute_force(int* arr, int check, int number)
{
    int cnt = 0;
    if (check == 1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] < number)
            {
                cnt += 1;
            }
        }
    }
    if (check == 2)
    {
        std::cout << "Индексы:";
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] == number)
            {
                cnt += 1;
                std::cout << ' ' << i;
            }
        }
        std::cout << '\n';
    }
    if (check == 3)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] > number)
            {
                cnt += 1;
            }
        }
    }
    if (check == 4)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] == number)
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}

void fill_array(int* first_arr, int* second_arr)
{
    bool sign_number;
    for (int i = 0; i < 100; i++)
    {
        sign_number = rand() % 2;
        if (sign_number)
        {
            first_arr[i] = rand() % 100;
        }
        else
        {
            first_arr[i] = (rand() % 100) * (-1);
        }
        second_arr[i] = first_arr[i];
    }
}

int max_min(int* arr, bool check = 0)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < 100; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    if (!check)
    {
        std::cout << "min: " << min << ", max: " << max;
    }
    return (min + max) / 2;
}

void show_array(int* arr)
{
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        cnt++;
        std::cout << arr[i] << " ";
        if (cnt % 10 == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void dop_task(int* arr, int* s_arr)
{
    int i;
    for (i = 0; i < 99; i++)
    {
        arr[i] += arr[i + 1];
        s_arr[i] = arr[i];
    }
    arr[99] += arr[0];
    s_arr[99] = arr[99];
    show_array(arr);
    short int check = 100;
    int random_index;
    i = 0;
    while (i < 100)
    {
        random_index = (rand()) % 100;
        if (s_arr[random_index] != 1000)
        {
            arr[i] = s_arr[random_index];
            s_arr[random_index] = 1000;
            i++;
        }
    }
    for (i = 0; i < 100; i++)
    {
        s_arr[i] = arr[i];
    }
    show_array(arr);
    int cnt;
    for (i = 1; i < 10; i++)
    {
        cnt = 0;
        for (int j = 0; j < 100; j++)
        {
            if (arr[j] < 0)
            {
                if ((arr[j] * (-1)) % i == 0)
                {
                    cnt += 1;
                }
            }
            else
            {
                if (arr[j] % i == 0)
                {
                    cnt += 1;
                }
            }
        }
        std::cout << "Элементов, делящихся нацело на " << i << ": " << cnt << '\n';
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Привет!\n";
    int number = 9;
    std::cout << "\n1) Создать целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.\n";
    std::cout << "2) Отсортировать заданные в пункте 1 элементы массива quick sort сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono.\n";
    std::cout << "3) Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.\n";
    std::cout << "4) Вывести среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. Вывести индексы всех элементов, которые равны этому значению, и их количество.\n";
    std::cout << "5) Вывести количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.\n";
    std::cout << "6) Вывести количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.\n";
    std::cout << "7) Вывести информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравнить скорость его работы с обычным перебором. (*)\n";
    std::cout << "8) Поменять местами элементы массива, индексы которых вводит пользователь. Вывести скорость обмена, используя библиотеку chrono.\n";
    std::cout << "9) Заменить каждый элемент массива суммой значений текущего и следующего элемента. Присвоить каждому элементу случайный номер в массиве. Вывести количество элементов, которые нацело делятся на 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
    std::cout << "0) Закончить программу.\n";
    bool if_arr = 0;
    short int if_sort = 0;
    int arr[100];
    int mid, a, b, cnt, temp;
    int s_arr[100];
    srand(static_cast<unsigned int>(time(0)));
    try {
        while (number != 0)
        {
            std::cout << "\nВыбери номер: ";
            std::cin >> number;
            if (!std::cin)
            {
                throw "ex";
            }
            std::cout << '\n';
            switch (number)
            {
            case 1: std::cout << "\nВы выбрали первое задание!\nСоздать целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.\n";
                fill_array(arr, s_arr);
                show_array(arr);
                if_arr = 1;
                if_sort = 0;
                break;
            case 2:
            {
                std::cout << "\nВы выбрали второе задание!\n";
                std::cout << "Отсортировать заданные в пункте 1 элементы массива quick sort сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if_sort = 1;
                auto t_start = std::chrono::high_resolution_clock::now();
                quick_sort(arr, 0, 99);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                show_array(arr);
                std::cout << "\nНа сортировку ушло " << std::fixed << t_cnt.count() << " секунд\n";
                break;
            }
            case 3:
            {
                std::cout << "\nВы выбрали третье задание!\n";
                std::cout << "Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    if_sort = 1;
                }
                auto t_start = std::chrono::high_resolution_clock::now();
                max_min(s_arr);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                std::cout << "\nНа нахождение минимума и максимума в неотстортированном массиве ушло " << std::fixed << t_cnt.count() << " секунд\n";
                t_start = std::chrono::high_resolution_clock::now();
                int min = arr[0];
                int max = arr[99];
                t_end = std::chrono::high_resolution_clock::now();
                t_cnt = t_end - t_start;
                std::cout << "На нахождение минимума и максимума в отстортированном массиве ушло " << std::fixed << t_cnt.count() << " секунд\n";
                break;
            }
            case 4:
                std::cout << "\nВы выбрали четвёртое задание!\n";
                std::cout << "Вывести среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. Выводит индексы всех элементов, которые равны этому значению, и их количество.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                mid = max_min(arr, 1);
                std::cout << "Среднее минимального и максимального элементов равно " << mid << ". Чисел, равных ему, " << brute_force(arr, 2, mid) << ".\n";
                break;
            case 5:
                std::cout << "\nВы выбрали пятое задание!\n";
                std::cout << "Вывести количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Введите число: ";
                std::cin >> a;
                if (!std::cin)
                {
                    throw "ex";
                }
                std::cout << "Количество элементов меньше числа " << a << " равно " << left_binary(arr, a) << ".\n";
                break;
            case 6:
                std::cout << "\nВы выбрали шестое задание!\n";
                std::cout << "Вывести количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Введите число: ";
                std::cin >> b;
                if (!std::cin)
                {
                    throw "ex";
                }
                std::cout << "Количество элементов больше числа " << b << " равно " << 100 - right_binary(arr, b) << ".\n";
                break;
            case 7:
            {
                std::cout << "\nВы выбрали седьмое задание!\n";
                std::cout << "Вывести информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализовать алгоритм бинарного поиска. Сравнить скорость его работы с обычным перебором. (*)\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Введите число: ";
                std::cin >> a;
                if (!std::cin)
                {
                    throw "ex";
                }
                auto t_start = std::chrono::high_resolution_clock::now();
                cnt = right_binary(arr, a) - left_binary(arr, a);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                std::cout << "Количество элементов равных " << a << " равно " << cnt << ".\n";
                std::cout << "В отсортированном массиве на бинарный поиск уходит " << std::fixed << t_cnt.count() << " секунд\n";
                t_start = std::chrono::high_resolution_clock::now();
                brute_force(s_arr, 4, a);
                t_end = std::chrono::high_resolution_clock::now();
                t_cnt = t_end - t_start;
                std::cout << "В неотсортированном массиве на перебор уходит " << std::fixed << t_cnt.count() << " секунд\n";
                break;
            }
            case 8:
            {
                std::cout << "\nВы выбрали восьмое задание!\n";
                std::cout << "Поменять местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                std::cout << "Введите два числа - индексы массива: ";
                std::cin >> a >> b;
                if ((a < 0) or (a > 99) or (b < 0) or (b > 99))
                {
                    std::cout << "Индексы введены некорректно. Это должны быть целые числа в диапазоне от 0 до 99";
                }
                else
                {
                    auto t_start = std::chrono::high_resolution_clock::now();
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                    auto t_end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration< double > t_cnt = t_end - t_start;
                    show_array(arr);
                    temp = s_arr[a];
                    s_arr[a] = s_arr[b];
                    s_arr[b] = temp;
                    std::cout << "На замену переменных уходит " << std::fixed << t_cnt.count() << " секунд\n";
                }
                break;
            }
            case 9:
            {
                std::cout << "\nВы выбрали девятое задание!\n";
                std::cout << "Заменить каждый элемент массива суммой значений текущего и следующего элемента. Присвоить каждому элементу случайный номер в массиве. Вывести количество элементов, которые нацело делятся на 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                dop_task(arr, s_arr);
            }
            }
        }
    }
    catch (...)
    {
        std::cout << "\nНекорректные данные!\n";
    }
}

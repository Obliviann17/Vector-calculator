#include <iostream> // підключає стандартний бібліотечний заголовочний файл для роботи з потоками введення/виведення
#include <vector> // заголовочний файл для використання std::vector
#include <sstream> // заголовочний файл із класами та функціями для роботи з рядками
#include <stdexcept> // включає заголовок для викорстання класів, пов'язаних з обробкою винятків
#include <cmath> // заголовочний файл для роботи з математичними функціями

namespace VectorCalculator {
    // Об'явлкння простору імен VectorCalculator
  
    class Calculator {
    public:
        // Оголошення класу Calculator, який надає функціонал для обчислення векторних операцій

        std::vector<double> sumArrays(const std::vector<double>& arr1, const std::vector<double>& arr2) // Створення функції sumArrays 
        {
            std::vector<double> result;
            if (arr1.size() != arr2.size()) // Якщо вектори мають різну довжину
            {
                throw std::invalid_argument("The vectors must have the same size."); // Виклик винятка і повернення в початок програми
            }

            for (size_t i = 0; i < arr1.size(); i++) // Цикл перебирає кожен елемент веторів
            {
                result.push_back(arr1[i] + arr2[i]); // Результат додавання відповідних елементів векторів записується в result 
            }

            return result; // Певертає вектор resul
        }

        std::vector<double> subtractArrays(const std::vector<double>& arr1, const std::vector<double>& arr2) // Створення функції subtractArrays 
        {
            std::vector<double> result;
            if (arr1.size() != arr2.size()) // Якщо вектори мають різну довжину, викликається виняток
            {
                throw std::invalid_argument("The vectors must have the same size."); // Виклик винятка і повернення в початок програми
            }

            for (size_t i = 0; i < arr1.size(); i++) // Цикл перебирає кожен елемент веторів
            {
                result.push_back(arr1[i] - arr2[i]); // Результат віднімання відповідних елементів векторів записується в result 
            }

            return result; // Певертає вектор resul
        }

        std::vector<double> multiplyArrays(const std::vector<double>& arr1, const std::vector<double>& arr2) // Створення функції multiplyArrays
        {
            std::vector<double> result;
            if (arr1.size() != arr2.size()) // Якщо вектори мають різну довжину, викликається виняток
            {
                throw std::invalid_argument("The vectors must have the same size."); // Виклик винятка і повернення в початок програми
            }

            for (size_t i = 0; i < arr1.size(); i++) // Цикл перебирає кожен елемент веторів
            {
                result.push_back(arr1[i] * arr2[i]); // Результат множення відповідних елементів векторів записується в result 
            }

            return result; // Певертає вектор resul
        }

        std::vector<double> divideArrays(const std::vector<double>& arr1, const std::vector<double>& arr2) // Створення функції divideArrays
        {
            std::vector<double> result;
            if (arr1.size() != arr2.size()) // Якщо вектори мають різну довжину, викликається виняток
            {
                throw std::invalid_argument("The vectors must have the same size."); // Виклик винятка і повернення в початок програми
            }

            for (size_t i = 0; i < arr1.size(); i++) // Цикл перебирає кожен елемент веторів
            {
                if (arr2[i] == 0) // Якщо один з елементів ветора arr2 дорінює 0 - викликаєтьсявиключення, бо на нуль ділити не можна
                {
                    throw std::invalid_argument("Division by zero is not allowed."); // Виклик винятка і повернення в початок програми
                }
                result.push_back(arr1[i] / arr2[i]); // Результат множення відповідних елементів векторів записується в result 
            }

            return result; // Певертає вектор resul
        }

        std::vector<double> log2Arrays(const std::vector<double>& arr1) // Створення функції log2Arrays
        {
            std::vector<double> result;
            for (double num : arr1) // Цикл перебирає кожен елемент вектора
            {
                if (num <= 0) // Якщо число менше або дорівнює 0, то викликається виняток
                {
                    throw std::invalid_argument("Logarithm of a non-positive number is undefined."); // Виклик винятка і повернення в початок програми
                }
                result.push_back(log2(num)); // Результат обчислення log2 відповідних елементів вектора записується в result 
            }
            return result; // Певертає вектор resul
        }

        std::vector<double> log10Arrays(const std::vector<double>& arr1) // Створення функції log10Arrays
        {
            std::vector<double> result;
            for (double num : arr1) // Цикл перебирає кожен елемент вектора
            {
                if (num <= 0) // Якщо число менше або дорівнює 0, то викликається виняток
                {
                    throw std::invalid_argument("Logarithm of a non-positive number is undefined."); // Виклик винятка і повернення в початок програми
                }
                result.push_back(log10(num)); // Результат обчислення log10 відповідних елементів вектора записується в result 
            }
            return result; // Певертає вектор result
        }

        std::vector<double> sqrtArrays(const std::vector<double>& arr1) // Створення функції sqrtArrays
        {
            std::vector<double> result;
            for (double num : arr1) // Цикл перебирає кожен елемент вектора
            {
                if (num < 0) // Якщо число менше 0, то викликається вийняток
                {
                    throw std::invalid_argument("Square root of a negative number is undefined."); // Виклик винятка і повернення в початок програми
                }
                result.push_back(sqrt(num)); // Результат обчислення квадратного кореня(sqrt) відповідних елементів вектора записується в result 
            }
            return result; // Певертає вектор result
        }

        std::vector<double> powerArrays(const std::vector<double>& arr1, const double& exponent) // Створення функції powerArrays
        {
            std::vector<double> result;
            for (double num : arr1) // Цикл перебирає кожен елемент вектора
            {
                result.push_back(pow(num, exponent)); // Результат обчислення піднесеня до ступеня відповідних елементів вектора записується в result 
            }
            return result; // Певертає вектор result
        }

    };
}

int main() {
    using namespace VectorCalculator; // Використання простору імен VectorCalculator
    Calculator calculator; // Створення об'єкту класу Calculator

    std::string input_line;
    double num;
    double exponent;

    while (true) {
        // Незкінченний цикл для введення користувачем даних та виконання операцій

        std::vector<double> arr1;
        std::vector<double> arr2;

        std::cout << "Choose an operation: +, -, *, /, log2, log10, sqrt, ^ or type 'q' to quit: "; // Вивід повідомлення з вибором операції
        std::string operation;
        std::cin >> operation; // зчитування вибраної операції

        if (operation == "q") {
            break;
            // Вихід з циклу, якщо користувач вводить 'q'
        }

        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
            // Якщо обрана одна з операцій: +, -, *, /

            std::cout << "Enter the first array (separate elements with spaces, press Enter to finish): "; // Вивід повідомлення для введення першого вектора
            std::cin.ignore(); // Ігновування попереднього символу "\n"
            std::getline(std::cin, input_line); // Зчитування рядка у змінну input_line
            std::istringstream stream(input_line); // Створює поток stream для зчитування числе з рядка
            

            while (stream >> num) // Цикл розбиває stream на числа
            {
                arr1.push_back(num); // Додавання чисел до першого вектора
            }  

            std::cout << "Enter the second array (separate elements with spaces, press Enter to finish): "; // Вивід повідослення для введення другого вектора
            std::getline(std::cin, input_line); // Зчитування рядка у змінну input_line
            std::istringstream stream2(input_line); // Створює поток stream2 для зчитування числе з рядка

            while (stream2 >> num) // Цикл розбиває stream2 на числа
            {
                arr2.push_back(num); // Додавання чисел до другого вектора
            }
        }
        else {
            // Якщо обрана одна з операцій: log2, log10, sqrt, ^

            std::cout << "Enter the vector (separate elements with spaces, press Enter to finish): "; // Виведенн повідомлення про введення вектора
            std::cin.ignore(); // Ігновування попереднього символу "\n"
            std::getline(std::cin, input_line); // Зчитування рядка у змінну input_line
            std::istringstream stream(input_line); // Створює поток stream для зчитування числе з рядка
            

            while (stream >> num) // Цикл розбиває stream на числа 
            {
                arr1.push_back(num); // Додавання числа до вектора
            }
        }

        if (operation == "^") // Якщо обрана операція ^ 
        {
            std::cout << "Enter the exponent: "; // Повідомлення про введення ступеня
            std::cin >> exponent; // Зчитування значення в exponent
            
        }

        try {
            std::vector<double> result;

            if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
                // Виведення результату операцій: +, -, *, /

                switch (operation[0]) {
                case '+':
                    result = calculator.sumArrays(arr1, arr2); // Якщо операція + - виклик функції sumArrays і вихід з циклу
                    std::cout << "Sum of arrays: ";
                    break;
                case '-':
                    result = calculator.subtractArrays(arr1, arr2); // Якщо операція -, виклик функції subtractArrays і вихід з циклу
                    std::cout << "Subtraction of arrays: ";
                    break;
                case '*':
                    result = calculator.multiplyArrays(arr1, arr2); // Якщо операція * - виклик функції multiplyArrays і вихід з циклу
                    std::cout << "Multiply of arrays: ";
                    break;
                case '/':
                    result = calculator.divideArrays(arr1, arr2); // Якщо операція / - виклик функції divideArrays і вихід з циклу
                    std::cout << "Division of arrays: ";
                    break;
                default:
                    throw std::invalid_argument("Invalid operation."); // Обробка вийнятків, якщо користувач ввів невірну операцію
                }
            }
            else {
                // Обчислення операцій: log2, log10, sqrt, ^, якщо попередня умова не спрацювала

                switch (operation[0]) {
                case 'l': // Якщо назва операції почанається з l
                    if (operation == "log2") {
                        result = calculator.log2Arrays(arr1); // Якщо операція log10 - виклик функції log10Arrays 
                        std::cout << "Log2 of array: ";
                    }
                    else if (operation == "log10") {
                        result = calculator.log10Arrays(arr1); // Якщо перша умова не вірна, операція log10 - виклик функції log10Arrays 
                        std::cout << "Log10 of array: ";
                    }
                    break; 
                case 's': // Якщо назва операції почанається з s 
                    if (operation == "sqrt") {
                        result = calculator.sqrtArrays(arr1); // Якщо операція sqrt - виклик функції sqrtArrays і вихід з циклу
                        std::cout << "Sqrt of array: ";
                    }
                    break;
                case '^':
                    result = calculator.powerArrays(arr1, exponent); // Якщо операція ^ - виклик функції powerArrays і вихід з циклу
                    std::cout << "Power of array: ";
                    break;
                default:
                    throw std::invalid_argument("Invalid operation."); // Обробка вийнятків, якщо користувач ввів невірну операцію
                }
            }

            for (double num : result) // Зчитує кожний елемент з result 
            {
                std::cout << num << " "; 
            }
            std::cout << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl; // Виведення повідомленя про помилку
        }
    }

    return 0;
}


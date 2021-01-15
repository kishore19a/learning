#include <iostream>

int factorial(int number)
{
    if(number >= 0)
    {
        int temp{1};
        for(int i = 1; i <= number; i++)
            temp *= i;

        return temp;
    }
    else
    {
        throw std::runtime_error("Factorial of negative number is undefined");
    }
}

int factorialRec(int number)
{
    if(number < 0)
        throw std::runtime_error("Factorial of negative number is undefined");
    
    if(number == 0)
        return 1;
    else
        return number * factorialRec(number - 1);
}

int main(int argc, char const *argv[])
{
    int number;

    std::cout << "Enter number to find factorial of : ";
    std::cin >> number;

    try
    {
        std::cout << number << "! (recurrsion) = " << factorialRec(number) << std::endl;
        std::cout << number << "! (iterative) = " << factorial(number) << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

// g++ -std=c++11 factorial.cpp -o factorial
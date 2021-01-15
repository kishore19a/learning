#include <iostream>
#include <cmath>

int countDigitsDiv(int number)
{
    int count{0};
    while(number != 0)
    {
        count++;
        number = number / 10;
    }

    return count;
}

int countDigitsRec(int number)
{
    if(number == 0)
        return 0;
    else
        return (1 + countDigitsRec(number/10));
}

int countDigitsLog(int number)
{
    return std::floor(std::log10(number) + 1);
}

int main(int argc, char const *argv[])
{
    int number;

    std::cout << "Enter number to count digits: ";
    std::cin >> number;

    std::cout << "Number of digits using divison method = " << countDigitsDiv(number) << std::endl;
    std::cout << "Number of digits using recurrsion method = " << countDigitsRec(number) << std::endl;
    std::cout << "Number of digits using log method = " << countDigitsLog(number) << std::endl;
    return 0;
}
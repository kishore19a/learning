#include <iostream>

bool isPalindrome(int number)
{
    if(number > 0)
    {
        int temp{number}, reversed{0};
        while(temp != 0)
        {
            int rem = temp % 10;
            reversed = reversed * 10 + rem;
            temp = temp / 10;
        }

        if(reversed == number)
            return true;
        else
            return false;
    }
    else
    {
        std::cout << "Invalid input; number should be positive" << std::endl;
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int number;

    std::cout << "Enter a number to check for palindrome : ";
    std::cin >> number;

    if(isPalindrome(number))
        std::cout << number << " is palindrome" << std::endl;
    else
        std::cout << number << " is not palindrome" << std::endl;

    return 0;
}

// g++ -std=c++11 palindromeNumber.cpp -o palindromeNumber
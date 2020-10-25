#include <iostream>

int solution(int number);

int main()
{
    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int answer = solution(n);

    std::cout << std::endl << "The sum of all the multiples of 3 or 5 until the number ";
    std::cout << n << " is: " << answer << std::endl;

    return 0;
}

int solution(int number)
{
    if(number < 0){return 0;}
    int c,sum_multiples = 0;
    c = 1;
    //std::cout << c << std::endl;
    for(int i = 1; i<=number; i++){
        std::cout << "Is c = " << c << " multiple of 3 or 5?: " << std::endl;
        if(c % 3 == 0 || c % 5 == 0){
            sum_multiples += c;
            std::cout << " Yes!, sum_multiples = " << sum_multiples << std::endl;
        }
        c++;
        //std::cout << c << std::endl;
    }

    return sum_multiples;
}

#include <vector>
#include <string>
#include <iostream>

/***************************************************************
This code uses the fact that conversion of digits in decimal
representation to roman numerals doesn't depend on other digits.
Each decimal digit can be represented using 3 symbols:
___________________ a b c_________________________________
1-9                 I V X
1(0) - 9(0)         X L C
1(00) - 9(00)       C D M
1(000) - 3(000)     M

1 - a       4 - ab      7 - baa
2 - aa      5 - b       8 - baaa
3 - aaa     6 - ba      9 - ac

****************************************************************/

const std::vector<std::string> romanSymbols = {"I", "V", "X", "L", "C", "D", "M"};

std::string digitToRoman(int digit, int depth){
    switch(digit){
        case 0:
            return ""; break;
        case 1:
        case 2:
        case 3:
            return std::string(digit, static_cast<char>(romanSymbols[2*depth][0]) ); break;
        case 4:
            return (romanSymbols[2*depth] + romanSymbols[2*depth + 1]); break;
        case 5:
            return romanSymbols[2*depth + 1]; break;
        case 6:
        case 7:
        case 8:
            return (romanSymbols[2*depth+1] + std::string(digit - 5, static_cast<char>(romanSymbols[2*depth][0]) ) );
            break;
        case 9:
            return (romanSymbols[2*depth] + (romanSymbols[2*depth + 2]) ); break;       
    }
}

std::string numberToRoman(int number){
    int num = number;
    std::string romanStr = "";
    int depth = 0;
    while(num > 0){
        int lastDigit = (num % 10);
        num = num/10;
        romanStr.insert(0, digitToRoman(lastDigit, depth) );
        depth += 1;
    }
    
    return romanStr;
}

int main(int argc, char* argv[]){
    if(argc == 1)
        std::cout << "No argument given.\n";
    
    else
        std::cout << numberToRoman(std::stoi(argv[1]) );

    return 0;
}
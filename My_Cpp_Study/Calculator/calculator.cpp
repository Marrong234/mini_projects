#include <iostream>
#include <cmath>

double addNumber(double result, double y);
double subNumber(double result, double y);
double mulNumber(double result, double y);
double divNumber(double result, double y);
double sqrtNumber(double result);
double powNumber(double result, double powerNum);
double roundNumber(double result);
double absNumber(double result);

int main() {
    while (true) {
        double result;

        std::cout << "==Welcome to calculator==\n";
        std::cout << "Enter a starting number: ";
        std::cin >> result;

        char again = 'y';

        // Unified operation loop — pick unary or binary each time
        while (again == 'y' || again == 'Y') {
            char operationChoose;
            std::cout << "\nCurrent result: " << result << "\n";
            std::cout << "===Unary or Binary operation? (u/b)===\n";
            std::cin >> operationChoose;

            if (operationChoose == 'u') {
                std::string unaryOperator;
                std::cout << "Enter an operator (sqrt, abs, power, round): ";
                std::cin >> unaryOperator;

                if (unaryOperator == "sqrt") {
                    result = sqrtNumber(result);
                } else if (unaryOperator == "power") {
                    double powerNum;
                    std::cout << "Enter exponent: ";
                    std::cin >> powerNum;
                    result = powNumber(result, powerNum);
                } else if (unaryOperator == "round") {
                    result = roundNumber(result);
                } else if (unaryOperator == "abs") {
                    result = absNumber(result);
                } else {
                    std::cout << "===Invalid operator===\n";
                }

            } else if (operationChoose == 'b') {
                char userOperator;
                double y;

                std::cout << "Enter an operator (+, -, *, /): ";
                std::cin >> userOperator;
                std::cout << "Enter the next number: ";
                std::cin >> y;

                if (userOperator == '+') {
                    result = addNumber(result, y);
                } else if (userOperator == '-') {
                    result = subNumber(result, y);
                } else if (userOperator == '*') {
                    result = mulNumber(result, y);
                } else if (userOperator == '/') {
                    result = divNumber(result, y);
                } else {
                    std::cout << "===Invalid operator===\n";
                }

            } else {
                std::cout << "===Invalid choice, enter 'u' or 'b'===\n";
            }

            std::cout << "Result: " << result << "\n";
            std::cout << "===Continue? (y/n)===\n";
            std::cin >> again;
        }

        char restart;
        std::cout << "===Restart calculator? (y/n)===\n";
        std::cin >> restart;

        if (restart != 'y' && restart != 'Y') {
            break;
        }
    }

    std::cout << "===System ended===\n";
    return 0;
}

double addNumber(double result, double y) { return result + y; }
double subNumber(double result, double y) { return result - y; }
double mulNumber(double result, double y) { return result * y; }

double divNumber(double result, double y) {
    if (y == 0) {
        std::cout << "===Error: Cannot divide by 0 — result unchanged===\n";
        return result; // Fixed: preserve result instead of returning 0
    }
    return result / y;
}

double sqrtNumber(double result) {
    if (result < 0) {
        std::cout << "===Error: Cannot sqrt a negative number — result unchanged===\n";
        return result; // Fixed: preserve result instead of returning 0
    }
    return sqrt(result);
}

double powNumber(double result, double powerNum) { return pow(result, powerNum); }
double roundNumber(double result) { return round(result); }
double absNumber(double result) { return std::abs(result); } // Fixed: use std::abs
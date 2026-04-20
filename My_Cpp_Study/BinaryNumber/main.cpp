#include <iostream>
#include <algorithm>

std::string convertBinary(int x);
std::string make32Bit(int x);
std::string myAnd(int x, int y);
std::string myOr(int x, int y);
std::string myXor(int x, int y);
std::string myNot(int x);
std::string myLeftShift(int x, int y);
std::string myRightShift(int x, int y);


int main(){

    int x;
    int y;
    char choice;
    std::string result;

    do{
        std::cout << "X: ";
        std::cin >> x;

        if(x < 0){
            std::cout << "Only positive number\n";
            continue;
        }

        std::cout << "& for AND\n";
        std::cout << "| for OR\n";
        std::cout << "^ for XOR\n";
        std::cout << "~ for NOT\n";
        std::cout << "< for left shift\n";
        std::cout << "> for right shift\n";
        std::cout << "B for binary converter\n";
        std::cout << "E for Exit\n";
        std::cout << "Operator: ";
        std::cin >> choice;

        if(choice == 'E'){
            return 0;
        }
        if(choice == '&' || choice == '|' || choice == '^' || choice == '<' || choice == '>'){
            std::cout << "Y: ";
            std::cin >> y;
            if(y < 0){
                std::cout << "Only Positive Number\n";
                continue;
            }
        }

        switch(choice){
            case 'E': break;
            case '&': result = myAnd(x, y);
            break;
            case '|': result = myOr(x, y);
            break;
            case '^': result = myXor(x, y);
            break;
            case '~': result = myNot(x);
            break;
            case '<': result = myLeftShift(x, y);
            break;
            case '>': result = myRightShift(x, y);
            break;
            case 'B': result = convertBinary(x);
            break;
            default: std::cout << "Invalid Operator\n";
            continue;
        }

        std::cout << "Result: " << result << "\n";


    }while(choice != 'E');
    

    return 0;
}

std::string convertBinary(int x){
    std::string result;

    if(x == 0){
        return "0";
    }

    while(x > 0){
        int remainder = x % 2;
        result += '0' + remainder;
        x /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}
std::string make32Bit(int x){
    std::string binaryX = convertBinary(x);
    std::string result;

    while(binaryX.length() < 32){
        binaryX = '0' + binaryX;
    }

    return binaryX;
}
std::string myAnd(int x, int y){
    std::string binaryX = convertBinary(x);
    std::string binaryY = convertBinary(y);
    std::string result;

    binaryX = make32Bit(x);
    binaryY = make32Bit(y);

    for(int i = 0; i < 32; i++){
        if(binaryX[i] == '1' && binaryY[i] == '1'){
            result += '1';
        }
        else{
            result += '0';
        }
    }

    return result;
}
std::string myOr(int x, int y){
    std::string binaryX = convertBinary(x);
    std::string binaryY = convertBinary(y);
    std::string result;

    binaryX = make32Bit(x);
    binaryY = make32Bit(y);

    for(int i = 0; i < 32; i++){
        if(binaryX[i] == '0' && binaryY[i] == '0'){
            result += '0';
        }
        else{
            result += '1';
        }
    }
    return result;
}
std::string myXor(int x, int y){
    std::string binaryX = convertBinary(x);
    std::string binaryY = convertBinary(y);
    std::string result;

    binaryX = make32Bit(x);
    binaryY = make32Bit(y);

    for(int i = 0; i < 32; i++){
        if(binaryX[i] == binaryY[i]){
            result += '0';
        }
        else{
            result += '1';
        }
    }
    return result;
}
std::string myNot(int x){
    std::string binaryX = convertBinary(x);
    std::string result;

    binaryX = make32Bit(x);

    for(int i = 0; i < 32; i++){
        if(binaryX[i] == '0'){
            result += '1';
        }
        else{
            result += '0';
        }
    }
    return result;
}
std::string myLeftShift(int x, int y){
    std::string binaryX = convertBinary(x);
    binaryX = make32Bit(x);

    for(int i = 0; i < y; i++){ 
        binaryX = binaryX.substr(1) + '0';
    }
    
    return binaryX;
}
std::string myRightShift(int x, int y){
    std::string binaryX = convertBinary(x);
    binaryX = make32Bit(x);
    
    for(int i = 0; i < y; i++){
        binaryX = '0' + binaryX.substr(0, 31);
    }

    return binaryX;
}
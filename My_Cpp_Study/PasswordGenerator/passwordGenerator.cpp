#include <iostream>
#include <random>
#include <string>

static const std::string DIGITS = "0123456789";
static const std::string SPECIAL = "!@#$%^&*";
static const std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string LOWER = "abcdefghijklmnopqrstuvwxyz";

int passwordLength(int minLength, int maxLength);
std::string buildPool(bool useSpecial, bool useUppercase, bool useLowercase, bool useDigits);
std::string passwordGenerator(int randomLength, std::string pool);
bool hasSpecial(const std::string &password);
bool hasUpper(const std::string &password);
bool hasLower(const std::string &password);
bool hasDigits(const std::string &password);
bool checkPassword(bool useSpecial, bool useUppercase, bool useLowercase, bool useDigits, const std::string &password);


int main(){

    int maxLength;
    int minLength;
    char specialCharacterChoice;
    char uppercaseChoice;
    char lowercaseChoice;
    char digitsChoice;

    do{
        std::cout << "What is the minimum length of password?: ";
        std::cin >> minLength;
    }while(minLength < 4);

    std::cout << "What is the maximum length of password?: ";
    std::cin >> maxLength;

    if(minLength > maxLength){
        std::cout << "Maximum length must be greater than or equal to minimum length.\n";
        return 1;
    }

    bool useSpecial;
    bool useUppercase;
    bool useLowercase;
    bool useDigits;

    std::cout << "Is there special character requirement?(y/n): ";
    std::cin >> specialCharacterChoice;
    if(specialCharacterChoice == 'y' || specialCharacterChoice == 'Y'){
        useSpecial = true;
    }
    else if(specialCharacterChoice == 'n' || specialCharacterChoice == 'N'){
        useSpecial = false;
    }
    else{
        std::cout << "Invalid Input\n";
        useSpecial = false;
    }

    std::cout << "Is there uppercase character requirement?(y/n): ";
    std::cin >> uppercaseChoice;
    if(uppercaseChoice == 'y' || uppercaseChoice == 'Y'){
        useUppercase = true;
    }
    else if(uppercaseChoice == 'n' || uppercaseChoice == 'N'){
        useUppercase = false;
    }
    else{
        std::cout << "Invalid Input\n";
        useUppercase = false;
    }

    std::cout << "Is there lowercase character requirement?(y/n): ";
    std::cin >> lowercaseChoice;
    if(lowercaseChoice == 'y' || lowercaseChoice == 'Y'){
        useLowercase = true;
    }
    else if(lowercaseChoice == 'n' || lowercaseChoice == 'N'){
        useLowercase = false;
    }
    else{
        std::cout << "Invalid Input\n";
        useLowercase = false;
    }

    std::cout << "Include digits?(y/n): ";
    std::cin >> digitsChoice;
    if(digitsChoice == 'y' || digitsChoice == 'Y'){
        useDigits = true;
    }
    else if(digitsChoice == 'n' || digitsChoice == 'N'){
        useDigits = false;
    }
    else{
        std::cout << "Invalid Input\n";
        useDigits = false;
    }

    int randomLength = passwordLength(minLength, maxLength);
    std::string pool = buildPool(useSpecial, useUppercase, useLowercase, useDigits);
    if(pool.empty()){
        std::cout << "You must select at least character types\n";
        return 1;
    }

    std::string password;

    do{
        password = passwordGenerator(randomLength, pool);
    }while(!checkPassword(useSpecial, useUppercase, useLowercase, useDigits, password));

    std::cout << "====Generated password: " << password << " ===";
    

    return 0;
}


int passwordLength(int minLength, int maxLength){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(minLength, maxLength);

    int randomLength = dist(gen);
    return randomLength;
}
std::string buildPool(bool useSpecial, bool useUppercase, bool useLowercase, bool useDigits){
    std::string pool = "";

    if(useSpecial){
        pool += SPECIAL;
    }
    if(useUppercase){
        pool += UPPER;
    }
    if(useLowercase){
        pool += LOWER;
    }
    if(useDigits){
        pool += DIGITS;
    }

    return pool;
}
std::string passwordGenerator(int randomLength, std::string pool){
    std::string password = "";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, pool.size()-1);

    for(int i = 0; i < randomLength; i++){
        password += pool[dist(gen)];
    }

    return password;
}
bool hasSpecial(const std::string &password){
    for(char ch : password){
        if(SPECIAL.find(ch) != std::string::npos){
            return true;
        }
    }
    return false;
}
bool hasUpper(const std::string &password){
    for(char ch : password){
        if(UPPER.find(ch) != std::string::npos){
            return true;
        }
    }
    return false;
}
bool hasLower(const std::string &password){
    for(char ch : password){
        if(LOWER.find(ch) != std::string::npos){
            return true;
        }
    }
    return false;
}
bool hasDigits(const std::string &password){
    for(char ch : password){
        if(DIGITS.find(ch) != std::string::npos){
            return true;
        }
    }
    return false;
}
bool checkPassword(bool useSpecial, bool useUppercase, bool useLowercase, bool useDigits, const std::string &password){

    if(useSpecial){
        if(!hasSpecial(password)){
            return false;
        }
    }
    if(useUppercase){
        if(!hasUpper(password)){
            return false;
        }
    }
    if(useLowercase){
        if(!hasLower(password)){
            return false;
        }
    }
    if(useDigits){
        if(!hasDigits(password)){
            return false;
        }
    }

    return true;
}
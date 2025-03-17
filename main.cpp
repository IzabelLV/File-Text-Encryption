#include <iostream>
#include <fstream>
#include <string>

std::string xorEncryptDecrypt(const std::string& text, char key) 
{
    std::string result = text;
    for (char& c : result) 
    {
        c ^= key; 
    }
    return result;
}

std::string readFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Could not open the file!" << std::endl;
        exit(1);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeFile(const std::string& filename, const std::string& content) 
{
    std::ofstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Could not open the file to write." << std::endl;
        exit(1);
    }
    file << content;
    file.close();
}


int main() {
    std::string inputFile = "My_Top_Secret.txt";
    std::string encryptedFile = "encrypted.txt";
    std::string decryptedFile = "decrypted.txt";
    char key = 'k'; 

    std::string originalText = readFile(inputFile);
    
    std::string encryptedText = xorEncryptDecrypt(originalText, key);
    writeFile(encryptedFile, encryptedText);
    std::cout << "Encryption completed." << std::endl;

    std::string decryptedText = xorEncryptDecrypt(encryptedText, key);
    writeFile(decryptedFile, decryptedText);
    std::cout << "Decryption completed." << std::endl;

    return 0;
}

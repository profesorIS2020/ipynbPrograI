#include <iostream>
#include <iomanip> // Required for std::setprecision

int main() {
    // Integer types
    int int_var = 10;
    short short_var = 5;
    long long_var = 1000000;
    long long long_long_var = 1234567890123456789;
    unsigned int unsigned_int_var = 20u;

    // Floating-point types
    float float_var = 3.14f;
    double double_var = 2.71828;
    long double long_double_var = 1.6180339887;

    // Character types
    char char_var = 'A';
    wchar_t wchar_var = L'B';
    char16_t char16_var = u'C';
    char32_t char32_var = U'D';

    // Boolean type
    bool bool_var = true;


    // Outputting the values and types
    std::cout << "Integer types:\n";
    std::cout << "int: " << int_var << "\n";
    std::cout << "short: " << short_var << "\n";
    std::cout << "long: " << long_var << "\n";
    std::cout << "long long: " << long_long_var << "\n";
    std::cout << "unsigned int: " << unsigned_int_var << "\n\n";

    std::cout << "Floating-point types:\n";
    std::cout << "float: " << float_var << "\n";
    std::cout << "double: " << double_var << "\n";
    std::cout << "long double: " << std::setprecision(17) << long_double_var << "\n\n"; // Increased precision

    std::cout << "Character types:\n";
    std::cout << "char: " << char_var << "\n";
    std::cout << "wchar_t: " << wchar_var << "\n";
    std::cout << "char16_t: " << char16_var << "\n";
    std::cout << "char32_t: " << char32_var << "\n\n";


    std::cout << "Boolean type:\n";
    std::cout << "bool: " << bool_var << "\n";


    return 0;
}

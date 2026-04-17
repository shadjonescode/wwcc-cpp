# include <iostream>
# include <cstdio>
using namespace std;

int main(){
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");


    printf("Integer formats:\n");
    printf("%s %d\n", "Decimal:", integer_value);
    printf("%s %x\n", "Hexadecimal:", integer_value);
    printf("%s %o\n", "Octal:", integer_value);
    printf("%s [%5d]\n", "With width (5):", integer_value);
    printf("%s [%-5d]\n", "Left alligned:", integer_value);

    printf("\nFloat formats:\n");
    printf("%s %f\n", "Default:", float_value);
    printf("%s %.2f\n", "With precision:", float_value);
    printf("%s %e\n", "Scientific:", double_value);
    printf("%s %.4f\n", "Fixed with precision (4):", double_value);
    
    printf("\nCharacter and String formats\n");
    printf("%s %c\n", "Character:", char_value);
    printf("%s %s\n", "String:", string_value);
    printf("%s %20s\n", "String with width (20):", string_value);

    return 0;
}
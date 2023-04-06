#include <stdio.h>
#include <stdlib.h>

// Define the struct
struct Data {
    int num1;
    int num2;
    char letter;
};

// Declare the add function
void add(struct Data data);

// Main function
int main() {
    // Declare a Data struct
    struct Data myData;
    
    // Call the add function and pass a pointer to the struct
    add(myData);
    
    // Print the values of the struct
    printf("num1: %d\n", myData.num1);
    printf("num2: %d\n", myData.num2);
    printf("letter: %c\n", myData.letter);
    
    return 0;
}

// Define the add function
void add(struct Data *data) {
    // Get input from the user and store it in the struct
    printf("Enter a number: ");
    scanf("%d", &(data->num1));
    
    printf("Enter another number: ");
    scanf("%d", &(data->num2));
    
    printf("Enter a letter: ");
    scanf(" %c", &(data->letter));
}

/*
Write a C program that generates multiplication tables for positive integers read from
keyboard, one at a time. For each number read, the program generates and prints the multiplication table.
After showing the multiplication table of the read number, the program should ask the user if they want to enter
another number. If they answer Y (yes), the program repeats the number reading and shows the multiplication table. If
they answer N (no), the program shows how many numbers the user entered and what is the largest number
among those informed by the user.
*/

#include <stdio.h>


void printMultiplicationTable(int number) {
    printf("Multiplication table of %d:\n", number);
    for (int i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", number, i, number * i);
    }
}

int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int number, count = 0, max = 0;
    char choice;

    do {
        printf("Enter a number to see its multiplication table: ");
        scanf("%d", &number);

        if (number > 0) {
            count++;
            max = (number > max) ? number : max;

            printMultiplicationTable(number);
            printf("Do you want to enter another number? (Y/N): ");
            scanf(" %c", &choice);
            
        } else {
            printf("Please enter a positive number.\n");
            printf("Do you want to enter another number? (Y/N): ");
            scanf(" %c", &choice);
        }

    } while (choice == 'Y' || choice == 'y');

    if (count > 0) {
        printf("You entered %d number(s).\n", count);
        printf("The largest number was: %d\n", max);
    } else {
        printf("No positive number was entered.\n");
    }

    return 0;
}


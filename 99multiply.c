#include <stdio.h>

/**
 * 99 Multiplication Table (Upper Triangle Format)
 * 
 * This program prints the 99 multiplication table in an upper triangular format:
 * Row 1: 1*1=1
 * Row 2: 1*2=2  2*2=4
 * Row 3: 1*3=3  2*3=6  3*3=9
 * ...and so on up to Row 9
 */
int main() {
    // Print header
    printf("99 Multiplication Table (Upper Triangle):\n\n");
    
    // Outer loop controls the rows (1 to 9)
    for (int i = 1; i <= 9; i++) {
        // Inner loop controls the elements in each row, printing only from 1 to i
        for (int j = 1; j <= i; j++) {
            // Using %-3d to ensure consistent spacing (3 spaces for each result)
            printf("%d*%d=%-3d ", j, i, i * j);
        }
        // Line break after each row
        printf("\n");
    }
    
    // Wait for user input before exiting
    printf("\nPress Enter to exit...");
    getchar();
    
    return 0;
}
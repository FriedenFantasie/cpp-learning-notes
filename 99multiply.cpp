#include <iostream>
#include <iomanip>

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
    // Using C++ style I/O
    // Print header
    std::cout << "99 Multiplication Table (Upper Triangle):" << std::endl << std::endl;
    
    // Outer loop controls the rows (1 to 9)
    for (int i = 1; i <= 9; i++) {
        // Inner loop controls the elements in each row, printing only from 1 to i
        for (int j = 1; j <= i; j++) {
            // Using std::setw to ensure consistent spacing
            std::cout << j << "*" << i << "=" << std::left << std::setw(3) << i * j << " ";
        }
        // Line break after each row
        std::cout << std::endl;
    }
    
    // Wait for user input before exiting
    std::cout << std::endl << "Press Enter to exit...";
    std::cin.get();
    
    return 0;
}

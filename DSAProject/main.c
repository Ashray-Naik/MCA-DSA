#include <stdio.h>
#include <stdlib.h>
#include "finance_management.h"

int main() {
    FinanceManagement fm;
    initializeDivision(&fm); // Initialize the division
    int choice;
    
    while (1) {
        // Check if the budget is exceeded
        if (fm.budgetAmount < 0) {
            printf("-- You are over budget! Remaining budget: %d\n", fm.budgetAmount);
        }
        
        printf("\n| Enter your choice |\n");
        printf("--------------------------------------------------------------\n");
        printf("1. To set budget\n");
        printf("2. To add expense details\n");
        printf("3. To display all expenses\n");
        printf("4. To display GST Imposed\n");
        printf("0. To exit\n");
        printf("> Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        printf("--------------------------------------------------------------\n");
        
        switch (choice) {
            case 1:
                setBudget(&fm); // Set budget
                break;
            case 2:
                setDetails(&fm); // Add expense details
                break;
            case 3:
                display(&fm); // Display all expenses
                break;
                
            case 4:
                calculateTaxes(&fm); // Calculate taxes
                break;
                
            case 0:
                freeFinanceList(fm.head); // Free allocated memory
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Not a proper choice\n");
                break;
        }
    }
    return 0;
}

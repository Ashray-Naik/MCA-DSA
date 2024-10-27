#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finance_management.h"

// Initialize Finance Management
void initializeDivision(FinanceManagement *fm) {
    fm->budgetAmount = 0;
    fm->head = NULL;
}

// Set budget
void setBudget(FinanceManagement *fm) {
    printf("Enter budget: ");
    while (scanf("%d", &fm->budgetAmount) != 1) {
        printf("Invalid input! Please enter a valid integer for the budget.\n");
        while (getchar() != '\n'); // Clear invalid input
    }
    printf("Budget set to: %d\n", fm->budgetAmount);
}

// Add a new expense record
void setDetails(FinanceManagement *fm) {
    Finance *newFinance = (Finance *)malloc(sizeof(Finance)); // Allocate memory for a new finance record
    
    printf("> Enter Date: ");
    scanf("%s", newFinance->date);
    
    printf("> Enter Expense: ");
    while (scanf("%d", &newFinance->expenseAmount) != 1) {
        printf("Invalid input! Please enter a valid integer for the expense.\n");
        while (getchar() != '\n'); // Clear invalid input
    }
    
    printf("> Enter Expense Reason: ");
    scanf("%s", newFinance->expenseReason);
    
    // Update budget and total expenses
    fm->budgetAmount -= newFinance->expenseAmount;
    fm->totalExpenses += newFinance->expenseAmount; // Update total expenses
    newFinance->budgetAmount = fm->budgetAmount;
    newFinance->next = fm->head; // Insert at the head of the list
    fm->head = newFinance; // Update head pointer

    printf("Expense recorded. Remaining budget: %d\n", fm->budgetAmount);
}


// Display all expense details
void display(const FinanceManagement *fm) {
    if(fm->head == NULL){
        printf("\n> The expense list is empty.\n");
        return;
    }


    Finance *current = fm->head;
    printf("| List of Expenses |");
    printf("\n--------------------------------------------------------------\n");
    while (current != NULL) {
        printf("- Date: %s\n", current->date);
        printf("- Expense: %d\n", current->expenseAmount);
        printf("- Expense Reason: %s\n", current->expenseReason);
        printf("- Remaining budget: %d\n", current->budgetAmount);
        printf("--------------------------------------------------------------\n");
        current = current->next;
    }
}


void calculateTaxes(const FinanceManagement *fm) {
    const float taxRate = 0.18; // GST rate of 18%
    float taxes = fm->totalExpenses * taxRate;
    printf("Total expenses: %d\n", fm->totalExpenses);
    printf("Calculated GST (18%%): %.2f\n", taxes);
    
    printf("Maximize savings by claiming input tax credits on eligible purchases!");
    
}



// Free all allocated nodes in the linked list
void freeFinanceList(Finance *head) {
    Finance *current = head;
    while (current != NULL) {
        Finance *temp = current;
        current = current->next;
        free(temp); // Free each node
    }
}

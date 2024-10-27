#ifndef FINANCE_MANAGEMENT_H
#define FINANCE_MANAGEMENT_H

// Structure for Finance record (Linked list node)
typedef struct Finance {
    char date[20];           
    int budgetAmount;        
    int expenseAmount;       
    char expenseReason[100]; 
    struct Finance *next;    
} Finance;

// Structure for Finance Management
typedef struct {
    int budgetAmount;  
    int totalExpenses; // Ensure this is included
    Finance *head;     
} FinanceManagement;

// Function declarations
void initializeDivision(FinanceManagement *fm);
void setBudget(FinanceManagement *fm);
void setDetails(FinanceManagement *fm);
void display(const FinanceManagement *fm);
void calculateTaxes(const FinanceManagement *fm);
void freeFinanceList(Finance *head);

#endif // FINANCE_MANAGEMENT_H


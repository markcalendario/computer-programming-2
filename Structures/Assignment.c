// Mark Kenneth Calendario
// BSCS 1-1
// Computer Programming 2

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Structure initialization consisting 5 records.
struct BankData
{
   float balance;
   char firstName[80];
   char lastName[80];
} bankAccount[5] = {
    {25000.00, "Danessa Mae", "Calendario"},
    {25000.00, "Mark Kenneth", "Calendario"},
    {25000.00, "Danilo", "Calendario"},
    {25000.00, "Delisa", "Calendario"},
    {25000.00, "Jaime", "Salinas"},
};

void balanceInquiry(int acntNo) // Function for balance inquiry
{
   printf("\n\n======= Balance Inquiry =======\n");
   printf("Account Number:\t %d\n", acntNo);
   printf("Full Name:\t %s %s\n", bankAccount[acntNo].firstName, bankAccount[acntNo].lastName);
   printf("Balance:\t %.2f\n", bankAccount[acntNo].balance);
   printf("===============================\n");
   printf("Press any key to continue.\n");
   getch();
}

void deposit(int acntNo) // Function for deposit transaction
{
   float amount = 0;
   printf("\n\n======== Cash Deposit ========\n");

AmountInputPoint:;
   printf("Amount: \033[0;32m");
   scanf("%f", &amount);
   printf("\033[0;37m");
   if (amount <= 0) // Prevent depositing amount that is less than to zero.
   {
      printf("\033[0;31mInvalid Amount!\033[0;37m\n");
      goto AmountInputPoint;
   }

   printf("You have successfully deposited %.2f to %s %s\n", amount, bankAccount[acntNo].firstName, bankAccount[acntNo].lastName);
   printf("Previous Balance: %.2f\n", bankAccount[acntNo].balance);
   bankAccount[acntNo].balance += amount; // Add amount to current balance
   printf("New Balance: %.2f\n", bankAccount[acntNo].balance);
   printf("==============================\n");
   printf("Press any key to continue.\n");
   getch();
}

void withdraw(int acntNo) // Function for withdrawal transaction
{
   float amount = 0;
   printf("\n\n======= Cash Withdrawal ======\n");

AmountInputPoint:;
   printf("Current Balance: %.2f\n", bankAccount[acntNo].balance);
   printf("Amount: \033[0;32m");
   scanf("%f", &amount);
   printf("\033[0;37m");

   // Prevent withdrawing amount that is less than to 0 and greater than to the current balance.
   if (amount <= 0 || amount > bankAccount[acntNo].balance)
   {
      printf("\033[0;31mInvalid Amount!\033[0;37m\n");
      goto AmountInputPoint;
   }

   printf("You have successfully withdrawn %.2f from %s %s\n", amount, bankAccount[acntNo].firstName, bankAccount[acntNo].lastName);
   printf("Previous Balance: %.2f\n", bankAccount[acntNo].balance);
   bankAccount[acntNo].balance -= amount;
   printf("New Balance: %.2f\n", bankAccount[acntNo].balance);
   printf("==============================\n");
   printf("Press any key to continue.\n");
   getch();
}

void displayAllAccounts() // Displaying all records
{
   printf("\n============================================================================\n");
   printf("Showing all records.[5/5]\n");
   printf("============================================================================\n");
   printf("Account #\tFirst Name\t\tLast Name\t\tBalance\n");
   for (int i = 0; i < 5; i++)
   {
      // Format records into a tabular form.
      printf("%-12d\t%-12s\t\t%-12s\t\t%-12.2f\n", i, bankAccount[i].firstName, bankAccount[i].lastName, bankAccount[i].balance);
   }
   printf("============================================================================\n");
}

void displayMenu() // Transaction Menu
{
   printf("===============================\n");
   printf("A. Balance Inquiry\nB. Deposit\nC. Withdraw\n");
   printf("===============================\n");
}

int main()
{
   int acntNo;
   char operation = 0;
   printf("Banking Portal\n");
   printf("Good day!\n");

SignOut:;
Start:;
   printf("\nPlease enter your account number: \033[0;32m");
   scanf("%d", &acntNo);
   printf("\033[0;37m");

   if (acntNo > 4 || acntNo < 0) // Prevent user entering non-existent account number.
   {
      printf("\033[0;31mNo records found for %d account number!\033[0;37m", acntNo);
      goto Start;
   }

   printf("\nSuccess!\nWelcome Mr./Ms. %s %s\n", bankAccount[acntNo].firstName, bankAccount[acntNo].lastName);

OperationSelect:;

   displayMenu();
   printf("Please select an operation: \033[0;32m");
   operation = getche();
   printf("\033[0;37m");

SuccessPoint:;
   if (operation == 'A' || operation == 'a')
   {
      balanceInquiry(acntNo);
   }
   else if (operation == 'B' || operation == 'b')
   {
      deposit(acntNo);
   }
   else if (operation == 'C' || operation == 'c')
   {
      withdraw(acntNo);
   }
   else
   {
      printf("\n\033[0;31mUnknown operation! Please try again.\033[0;37m\n");
      goto OperationSelect;
   }

   displayAllAccounts(); // Display all records
   printf("\n=============================================\n[Y] - Yes\n[S] - Sign Out\n[Any Key] - Exit\n");
   printf("Do you want to continue another transaction for this account: \033[0;32m");
   char again = getche();
   printf("\033[0;37m\n");
   if (again == 'S' || again == 'S')
   {
      goto SignOut;
   }
   else if (again == 'Y' || again == 'y')
   {
      goto OperationSelect;
   }

   printf("Thank you, have a nice day.\n");
   return 0;
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

// =================================
// Declaration of Global Entities
// =================================

// Functions
void getUserInput();
void flushSudokuData();
void flushInsertedValues();

// Variables
int sudokuData[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int insertedValues[3] = {-1, -1, -1}; // use for coloring

// Colors
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define DEFAULT "\033[0;37m"

// =================================
// Functions from the other file
// =================================

#include "./functions/tablefiller.c"
#include "./functions/tabledisplayer.c"

// =================================
// Beginning of the Program
// =================================

int main()
{
   char name[80];
   printf("Welcome to Mini Sudoku Game!\n", DEFAULT);
   printf("Please state your name: ");
   gets(name);

StartPoint:;
   flushSudokuData();
   flushInsertedValues();
   int tryAgain = -1; // -1 default value

   system("cls");
   printf("Ok %s, let's start!\n", name);

   // Start getting inputs from user
   displayTable();
   getUserInput();

   // After a success inputs
   printf("Please press any key to see complete table.");
   getch();

   // Finalize results
   // Fill out table with a unique randomized numbers
   system("cls");
   fillTable();

   // Show results
   printf("Result: \n");
   printf("%sYou\n", GREEN);
   printf("%sComputer%s\n", BLUE, DEFAULT);
   displayTable();

   while (tryAgain == -1)
   {
      printf("Do you want to try again? [1-Yes | 0-No]: ");
      tryAgain = getche();

      if (tryAgain - 48 != 0 && tryAgain - 48 != 1)
      {
         printf("\n%sInvalid option. Please select [0 for No] and [1 for Yes] only.%s\n", RED, DEFAULT);
         tryAgain = -1;
      }
   }

   // 0 = false
   // 1 = true
   if (tryAgain - 48)
   {
      system("cls");
      goto StartPoint;
   }

   printf("\nThank you %s, have a nice day!", name);
   getch();
   return 0;
}

void getUserInput()
{
   // Important Note:
   // Rows and columns data types are shifted from int into char.
   // So, we are dealing with ASCII.
   // Reason: The SCANF function returns infinite loop if user entered alpha values.
   // Action: We will use ASCII.
   int selectedRow = 0, selectedCol = 0, value = 0;

   printf("To change a value of a 3 cells please provide the following.\n");
   // Selecting row, columns, and values will be repeated 3 times.

   for (int i = 0; i < 3; i++)
   {

   ValueSelectionArea:;
      // ===== Row Selection Area ===== //
      // Prevent users inputing values other than 1-3
      while (selectedRow == 0)
      {
         printf("\nPlease select a row [1-3]: ");
         selectedRow = getche();

         if (selectedRow - 48 > 3 || selectedRow - 48 < 1)
         {
            printf("\n%sInvalid row number. Please select 1-3 only.%s", RED, DEFAULT);
            selectedRow = 0;
         }
         else
         {
            printf(" %sOK%s", GREEN, DEFAULT);
         }
      }

      // ===== Column Selection Area ===== //
      // Prevent users inputing values other than 1-3

      while (selectedCol == 0)
      {
         printf("\nPlease select a column [1-3]: ");
         selectedCol = getche();

         if (selectedCol - 48 > 3 || selectedCol - 48 < 1)
         {
            printf("\n%sInvalid column number. Please select 1-3 only.%s", RED, DEFAULT);
            selectedCol = 0;
         }
         else
         {
            printf("%s OK%s", GREEN, DEFAULT);
         }
      }

      // ===== Cell Checker ===== //
      // Check if the cell is empty.
      // If not empty, force user to select another row and column from users.
      if (*(*(sudokuData + (selectedRow - 48 - 1)) + (selectedCol - 48 - 1)) != 0)
      {
         printf("\n%sSelected cell is not empty. Try to select another cell.%s", RED, DEFAULT);
         selectedRow = 0;
         selectedCol = 0;
         value = 0;
         goto ValueSelectionArea;
      }

   // ===== Value Setting Area ===== //
   // Prevent users from inserting value other than 1 - 9
   SetValuePoint:;
      while (value == 0)
      {
         printf("\nEnter a value for this cell [1-9 only]: ");
         value = getche();

         if (value - 48 > 9 || value - 48 < 1)
         {
            printf("\n%sInvalid value for this cell. Please select 1-9 only.%s", RED, DEFAULT);
            value = 0;
         }
         else
         {
            printf(" %sOK%s", GREEN, DEFAULT);
         }
      }
      printf("\n");

      // ===== Value Checker ===== //
      // Check if value entered is unique.
      // If not, go back to set value point.
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            if (*(*(sudokuData + i) + j) == value - 48)
            {
               printf("%s%d is already in a table. Please enter another value.%s", RED, value - 48, DEFAULT);
               value = 0;
               goto SetValuePoint;
            }
         }
      }

      // Save value on selected cell
      *(*(sudokuData + (selectedRow - 48 - 1)) + (selectedCol - 48 - 1)) = value - 48;
      insertedValues[i] = value - 48;
      system("cls");
      displayTable();

      // Reset and continue loop.
      selectedRow = 0;
      selectedCol = 0;
      value = 0;
   }
}

void flushSudokuData()
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         *(*(sudokuData + i) + j) = 0;
      }
   }
}

void flushInsertedValues()
{
   for (int i = 0; i < 3; i++)
   {
      insertedValues[i] = -1;
   }
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Functions Declarations
int play(int sudokuData[3][3]);
void fillOutTable(int sudokuData[3][3]);
void displayTable(int sudokuData[3][3]);

// Start
int main() {
   char name[80];
   int tryAgain = -1;

   printf("Hello there.\n");
   printf("Welcome to Mini Sudoku!\n");
   printf("Please state your name: ");
   gets(name);

   StartPoint:
   tryAgain = -1;
   int sudokuData[3][3] = {0};
   play(sudokuData);
   
   while (tryAgain != 0 && tryAgain != 1)
   {
      printf("Do you want to try again? [1-Yes | 0-No]: ");
      scanf("%d", &tryAgain);
   }
   
   if (tryAgain)
   {
      system("cls");
      goto StartPoint;
   }

   printf("\nThank you %s, have a nice day!", name);
   getch();
   return 0;

}

int play(int sudokuData[3][3]) {
   int selectedRow = 0, selectedCol = 0, value = 0;

   displayTable(sudokuData);

   printf("To change a value of a 3 cells please provide the following.\n\n");

      for (int i = 0; i < 3; i++)
      {
         RestartPoint:

            // Prevent users inputing values other than 1-3
            while (selectedRow > 3 || selectedRow < 1)
            {
               printf("Please select a row [1-3]: ");   
               scanf("%d", &selectedRow);
            }
            
            while (selectedCol > 3 || selectedCol < 1)
            {
               printf("Please select a column [1-3]: ");   
               scanf("%d", &selectedCol);
            }

            // Check if the cell is empty.
            // If not empty, retry getting row and column input from users.
            if (sudokuData[selectedRow - 1][selectedCol - 1] != 0)
            {
               printf("Selected cell is not empty. Try to select another cell. \n\n");
               selectedRow = 0;
               selectedCol = 0;
               value = 0;
               goto RestartPoint;
            }
            
            SetValuePoint:
            while (value > 9 || value < 1)
            {
               printf("Enter a value for this cell [1-9 only]: ");
               scanf("%d", &value);
            }
            printf("\n");

            // Check if value entered is unique.
            // If not, go back to set value point.
            for (int i = 0; i < 3; i++)
            {
               for (int j = 0; j < 3; j++)
               {
                  if (sudokuData[i][j] == value)
                  {
                     printf("%d is already in a table. Please enter another value.\n", value);
                     value = 0;
                     goto SetValuePoint;
                  }
                  
               }
               
            }
         
            // Save value on selected cell
            sudokuData[selectedRow - 1][selectedCol - 1] = value; 
            system("cls");
            displayTable(sudokuData);
            // Reset 
            selectedRow = 0;
            selectedCol = 0;  
            value = 0;
      }

      printf("Please press enter to see complete table.");
      getch();
      system("cls");
      printf("Your input:\n");
      displayTable(sudokuData);
      printf("Computer's output:\n");
      fillOutTable(sudokuData);
      displayTable(sudokuData);
}

void fillOutTable(int sudokuData[3][3]) {
   int targetValue = 1;

   // check if targetValue is on the table
   // if it exists on the table, increment it

   CheckAgainPoint:
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (sudokuData[i][j] == targetValue)
         {
            targetValue++;
            goto CheckAgainPoint;
         }
         
      }
      
   }

   // Find empty cell to insert targetValue.
   // After inserting, check if table is empty.
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (sudokuData[i][j] == 0)
         {
            sudokuData[i][j] = targetValue;
            goto CheckEmptyTable;
         }
         
      }  
   }

   CheckEmptyTable:
   // Check if table has empty cell
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (sudokuData[i][j] == 0)
         {

            goto CheckAgainPoint;
         }
         
      }  
   }
}

void displayTable(int sudokuData[3][3]) {
   printf("-------------------------------------------------\n");
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         printf("|\t%d\t|", sudokuData[i][j]);  
      }
      printf("\n");
      printf("-------------------------------------------------\n");
   }
}
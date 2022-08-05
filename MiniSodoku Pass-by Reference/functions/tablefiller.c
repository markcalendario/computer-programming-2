#include <time.h> // for random number

int getRandomAvailableNum(int sudokuData[][3])
{
   srand(time(NULL));
   RegenerateAvailableNumber:;
      // Generates 1 - 9
      int randomNum = rand() % 9 + 1; 

      // Search for random number duplication/conflict from user-defined values in the table.
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            if (sudokuData[i][j] == randomNum)
            {
               goto RegenerateAvailableNumber;
            }
         }
   }

   // Throw randomized number if that number does not have...
   // ...a duplication in the table.
   return randomNum;
}

int fillTable(int sudokuData[][3])
{
   EmptyCellSearch:;

   // Search for an empty cell.
   // If a cell is empty then generate a value for that cell.
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (sudokuData[i][j] == 0)
         {
            int randomValue = getRandomAvailableNum(sudokuData);
            sudokuData[i][j] = randomValue;
         }  
      }  
   }

   system("cls");
}


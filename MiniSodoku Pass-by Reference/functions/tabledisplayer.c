void displayTable(int sudokuData[3][3], int insertedValues[3]) {
   printf("-------------------------------------------------\n");
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         // Check if data being scanned is same with the inserted value.
         // Print text green if true.
         if (
            sudokuData[i][j] == insertedValues[0] ||
            sudokuData[i][j] == insertedValues[1] ||
            sudokuData[i][j] == insertedValues[2]
            )
            {
               printf("|\t");
               printf("%s%d%s", GREEN, sudokuData[i][j], DEFAULT);
               printf("\t|");
         }
         // Check if data being scanned has no value yet.
         // Print text white if true. 
         else if (sudokuData[i][j] == 0) {
            printf("|\t%d\t|", sudokuData[i][j]);
         }
         // Check if data being scanned is not the same with the inserted data by the users.
         // Print text blue if true.
         else {
            printf("|\t");
            printf("%s%d%s", BLUE, sudokuData[i][j], DEFAULT);
            printf("\t|");
         }
         
      }
      printf("\n");
      printf("-------------------------------------------------\n");
   }
}
#include <stdio.h>
#include <string.h>

struct students
{
   int Idno;
   char fname[80];
   char lname[80];
} stud[3];

int main()
{
   // Welcomer
   printf("Hello, Welcome to Student Information System.\n");

   for (int i = 0; i < 3; i++)
   {
      printf("\n[Enter the information for student %d]\n", (i + 1));

      printf("Enter the ID:");
      scanf("%d", &stud[i].Idno);
      printf("Enter the first name:");
      scanf("%s", &stud[i].fname);
      printf("Enter the last name: ");
      scanf("%s", &stud[i].lname);
   }

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (strcmp(stud[i].lname, stud[j].lname) < 0)
         {

            stud[3] = stud[i];
            stud[i] = stud[j];
            stud[j] = stud[3];
         }
      }
   }

   printf("ID\t\tFirst Name\t\tLast Name\n");
   for (int i = 0; i < 3; i++)
   {
      printf("%d\t\t%s\t\t%s\n", stud[i].Idno, stud[i].fname, stud[i].lname);
   }
}

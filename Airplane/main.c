// HEADER FILES
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// =================================
// Structure
// =================================

struct AirplaneSeatData
{
   char seat[4];
} seatData[5] = { // Structure Variable = seatData
    "ABCD",
    "ABCD",
    "ABCD",
    "ABCD",
    "ABCD"};

struct AirplaneSeatData *ptr = seatData; // Pointer

// =================================
// COLORS
// =================================

char RED[80] = "\033[0;31m";
char WHITE[80] = "\033[0;37m";
char GREEN[80] = "\033[0;32m";
char YELLOW[80] = "\033[0;33m";

// =================================
// Prototypes
// =================================

void displaySeats();
int getColumnCharAsIndex(char colLetter);
void checkAirplaneCapacity();
void displayWelcomer();
void displayGoodbye();
int getTotalPassengers();

// =================================
// START
// =================================

int main()
{

   system("cls");
   displayWelcomer();
   system("cls");
   int rowNumber;
   char colLetter;

   printf("Here's our available seats:");

startPoint:; // Starting Point
   displaySeats();

rowInputArea:; // Get user input for row (numeric 1-5)
   printf("\nEnter row [1-5]: %s", GREEN);
   rowNumber = getche();

   if (rowNumber > '5' || rowNumber < '1')
   {
      printf("%s\nInvalid row, please select 1-5 only.\n%s", RED, WHITE);
      goto rowInputArea;
   }

colInputArea:; // Get user input for column (A-D)

   printf("\n%sEnter column [A-D]: %s", WHITE, GREEN);
   colLetter = getche(); // GETCHE RETURNS ASCII VALUE

   if ((colLetter > 'D' || colLetter < 'A') && (colLetter > 'd' || colLetter < 'a'))
   {
      printf("%s\nInvalid column, please select A-D only\n", RED);
      goto colInputArea;
   }
   system("cls");

   // Set selected row and column to occupied (char X)
   int convertedColChar = getColumnCharAsIndex(colLetter);

   // Check if the selected seat is already occupied
   // Prevent user selecting a seat that is already occupied
   if ((ptr + rowNumber - 48 - 1)->seat[convertedColChar] == 'X')
   {
      printf("\n%sSorry, this seat is already occupied!\n%s", RED, WHITE);
      goto startPoint;
   }

   // seatData[rowNumber-48-1].seat[convertedColChar] = 'X'; // Normal way of accessing structure

   (ptr + rowNumber - 48 - 1)->seat[convertedColChar] = 'X'; // We use this because we are using pointer

   displaySeats();
   checkAirplaneCapacity();

getUserChoiceArea:;
   char choice = 0;
   printf("Do you want to book another seat? [(Y)Yes | (X)Exit]: %s", GREEN);
   choice = getche();
   printf("%s", WHITE);
   if (choice == 'Y' || choice == 'y')
   {
      system("cls");
      goto startPoint;
   }
   else if (choice == 'X' || choice == 'x')
   {

      displayGoodbye();
      exit(0);
   }
   else
   {
      printf("\n%sInvalid choice!\n%s", RED, WHITE);
      goto getUserChoiceArea;
   }
}

// =================================
// USER DEFINED FUNCTIONS
// =================================

void checkAirplaneCapacity()
{
   int currentPassengerCount = 0;
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         if ((ptr + i)->seat[j] == 'X')
         {
            ++currentPassengerCount;
         }
      }
   }

   if (currentPassengerCount == 20)
   {
      printf("%sHello captain, all seats are taken. The airplane is ready to take off.\n", YELLOW);
      getch();
      getch();
      displayGoodbye();
   }
}

int getColumnCharAsIndex(char colLetter)
{
   // This function converts A,B,C,D to 0,1,2,3 that serves as an index
   // of an array
   switch (colLetter)
   {
   case 'A':
   case 'a':
      return 0;
      break;
   case 'B':
   case 'b':
      return 1;
      break;
   case 'C':
   case 'c':
      return 2;
      break;
   case 'D':
   case 'd':
      return 3;
      break;
   }
}

void displaySeats()
{
   printf("\n%s=========== PASSENGER SEATS ===========", WHITE);
   for (int i = 0; i < 5; i++)
   {
      printf("\n[%d]   |", i + 1);
      for (int j = 0; j < 4; j++)
      {
         if ((ptr + i)->seat[j] == 'X')
         {
            printf("   %s%c%s   |", RED, (ptr + i)->seat[j], WHITE);
         }
         else
         {
            printf("   %s%c%s   |", GREEN, (ptr + i)->seat[j], WHITE);
         }
      }
   }
   printf("\n=======================================\n");
}

void displayGoodbye()
{
   system("cls");
   printf("%sTotal passengers onboard: %d", YELLOW, getTotalPassengers());

   printf("\nThank you and have a safe travel.");
   printf("\n              .------, \n");
   printf("              =\\      \\  \n");
   printf(" .---.         =\\      \\  \n");
   printf(" | C~ \\         =\\      \\  \n");
   printf(" |     `----------'------'----------,  \n");
   printf(".'     LI.-.LI LI LI LI LI LI LI.-.LI`-. \n");
   printf("\\ _/.____|_|______.------,______|_|_____)  \n");
   printf("                 /      / \n");
   printf("               =/      / \n");
   printf("              =/      / \n");
   printf("             =/      / \n");
   printf("             /_____,' \n%s", WHITE);
   exit(0);
}

int getTotalPassengers()
{
   int total = 0;

   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         if ((ptr + i)->seat[j] == 'X')
         {
            total++;
         }
      }
   }

   return total;
}

void displayWelcomer()
{
   printf("%s   SSSSSSSSSSSSSSS MMMMMMMM               MMMMMMMMPPPPPPPPPPPPPPPPP        AAA               \n", YELLOW);
   printf("S:::::SSSSSS::::::SM::::::::M           M::::::::MP::::::PPPPPP:::::P    A:::::A             \n");
   printf("S:::::S     SSSSSSSM:::::::::M         M:::::::::MPP:::::P     P:::::P  A:::::::A            \n");
   printf("S:::::S            M::::::::::M       M::::::::::M  P::::P     P:::::P A:::::::::A           \n");
   printf("S:::::S            M:::::::::::M     M:::::::::::M  P::::P     P:::::PA:::::A:::::A          \n");
   printf("  SS::::::SSSSS    M::::::M M::::M M::::M M::::::M  P:::::::::::::PPA:::::A   A:::::A        \n");
   printf("    SSS::::::::SS  M::::::M  M::::M::::M  M::::::M  P::::PPPPPPPPP A:::::A     A:::::A       \n");
   printf("       SSSSSS::::S M::::::M   M:::::::M   M::::::M  P::::P        A:::::AAAAAAAAA:::::A      \n");
   printf("            S:::::SM::::::M    M:::::M    M::::::M  P::::P       A:::::::::::::::::::::A     \n");
   printf("            S:::::SM::::::M     MMMMM     M::::::M  P::::P      A:::::AAAAAAAAAAAAA:::::A    \n");
   printf("SSSSSSS     S:::::SM::::::M               M::::::MPP::::::PP   A:::::A             A:::::A   \n");
   printf("S::::::SSSSSS:::::SM::::::M               M::::::MP::::::::P  A:::::A               A:::::A  \n");
   printf("S:::::::::::::::SS M::::::M               M::::::MP::::::::P A:::::A                 A:::::A \n");
   printf(" SSSSSSSSSSSSSSS   MMMMMMMM               MMMMMMMMPPPPPPPPPPAAAAAAA                   AAAAAAA%s\n", WHITE);
   printf("\nWelcome to Sta. Mesa Pacific Airlines\n\n");
   printf("Please press any key to continue...");
   getch();
}
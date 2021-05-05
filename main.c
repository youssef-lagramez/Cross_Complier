#include <stdio.h>
#include <stdlib.h>
#include "Student_Management.h"

int main()
{

    char choice = 0;
    do {
    system("clear");
    printf("*********************************************\n");
    printf(" _______________Main Menu:________________ \n");
    printf("|                                         |\n");
    printf("| 1. Add Student                          |\n");
    printf("| 2. Delete Student                	      |\n");
    printf("| 3. List of Student                      |\n");
    printf("| 4. Exit                                 |\n");
    printf("|_________________________________________|\n");
    printf("*********************************************\n");
    printf("**  ==> ");

    scanf("%c", &choice);

        switch(choice)
        {
            case '3':
                system("clear");
                lecture();
                getchar();
                getchar();
                break;
            case '1':
                system("clear");
                add_Etudiant();
		getchar();
                break;
            case '2':
                system("clear");
                remove_Etudiant();
                getchar();
                break;
            case '4':
                return 0;
            default:
                printf("you should enter number from [1-4]!!");
                getchar();
                getchar();
                break;
        }
    }while(1);
}

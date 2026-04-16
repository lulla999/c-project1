#include <stdio.h>
#include <conio.h>

/* Structure must be identical to the others */
struct Member {
    char name[50];
    int age;
    char plan[20];
    int y, m, d;
};

void main() {
    struct Member mem[24];
    FILE *fp;
    int count = 0;

    clrscr();
    printf("--- Members Joined After 2025-01-01 ---\n\n");

    fp = fopen("gym1.txt", "r");

    if (fp == NULL) {
        printf("Error: gym.txt not found!\n");
    } else {
        /* Reading the file */
        for (int i = 0; i < 24; i++) {
            if (fscanf(fp, "%s %d %s %d-%d-%d", mem[i].name, &mem[i].age, mem[i].plan, &mem[i].y, &mem[i].m, &mem[i].d) == EOF) {
                break;
            }

            /* The Logic: Check if Year > 2025 
               OR if Year is 2025 and Month/Day is after Jan 1st */
            if (mem[i].y > 2025 || (mem[i].y == 2025 && (mem[i].m > 1 || (mem[i].m == 1 && mem[i].d > 1)))) {
                printf("Name: %-15s | Joined: %d-%02d-%02d\n", mem[i].name, mem[i].y, mem[i].m, mem[i].d);
                count++;
            }
        }
        
        if (count == 0) {
            printf("No members found who joined after 2025-01-01.\n");
        } else {
            printf("\nTotal found: %d", count);
        }
        
        fclose(fp);
    }

    printf("\n\nPress any key to exit...");
    getch();
}
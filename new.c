#include <stdio.h>
#include <string.h>

/* The structure must be defined here so the compiler knows what 'Member' is */
struct Member {
    char name[50];
    int age;
    char plan[20];
    int y, m, d;
};

int main() {
    FILE *fp;
    int i,n = 24, found=0; // Assuming a maximum of 24 members
    struct Member mem[n];
    printf("--- Premium Plan Members ---\n\n");

    /* Open the file created by the first partner */
    fp = fopen("gym1.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open gym.txt. Make sure Partner 1 ran their code first!\n");
    }
    else {
        /* Reading the file line by line */
        for(i = 0; i < n; i++) {
        fscanf(fp, "%s %d %s %d %d %d", mem[i].name, &mem[i].age, mem[i].plan, &mem[i].y, &mem[i].m, &mem[i].d);
    }
        /* The Logic: Compare the member's plan with the word "Premium" */
        printf("\nName\t\t Age\t\t Plan\t\t Date\n");
        for(i=0;i<n;i++)
        {
            if (strcmp(mem[i].plan, "Premium") == 0) {
                found=1;
                printf("%s\t\t",mem[i].name);
                printf("%d\t\t",mem[i].age);
                printf("%s\t\t",mem[i].plan);
                printf("%d-%d-%d\n",mem[i].y,mem[i].m,mem[i].d);    
            }
        }
        
        if (found==0) {
            printf("\nNo members found with a Premium plan.\n");
        }
        
    fclose(fp);
    }

    printf("\nPress any key to exit...");
    return 0;
}
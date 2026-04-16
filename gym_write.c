#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Member {
    char name[50];
    int age;
    char plan[20];
    int y, m, d;
};

void main() {
    FILE *fp;
    int n, i;
    fp = fopen("gym.txt", "w");
    printf("--- GYM ENTRY SYSTEM ---\n");
    printf("Enter number of members: ");
    scanf("%d", &n);
    struct Member mem[n];
    for(i = 0; i < n; i++) {
        printf("\nFor Member %d \nName: ", i+1);
        scanf("%s", mem[i].name);
        printf("Age: ");
        scanf("%d", &mem.age);
        printf("Plan: ");
        scanf("%s", mem[i].plan);
        printf("Date (YYYY-MM-DD): ");
        scanf("%d-%d-%d", &mem[i].y, &mem[i].m, &mem[i].d);
        fprintf(fp, "%s %d %s %d-%d-%d\n", mem[i].name, mem[i].age, mem[i].plan, mem[i].y, mem[i].m, mem[i].d);
    }
    fclose(fp);
    fp = fopen("gym.txt", "r");
    for(i = 0; i < n; i++) {
        fscanf(fp, "%s %d %s %d %d %d", mem[i].name, &mem[i].age, mem[i].plan, &mem[i].y, &mem[i].m, &mem[i].d);
    }
    int yng=mem[0].age, old=mem[0].age;
    for(i=0;i<n;i++)
    {
        if(yng>mem[i].age)
        {
            yng=mem[i].age;
        }
        if(old<mem[i].age)
        {
            old=mem[i].age;
        }
    }
    for(i=0;i<n;i++)
    {
        if(yng==mem[i].age)
        {
            printf("\nDetails of youngest member : \n");
            printf("\nName=%s",mem[i].name);
            printf("\nAge=%d",mem[i].age);
            printf("\nPlan=%s",mem[i].plan);
            printf("\nDate (YYYY-MM-DD)=%d-%d-%d\n",mem[i].y,mem[i].m,mem[i].d);
        }
         if(old==mem[i].age)
        {
            printf("\nDetails of oldest member : \n");
            printf("\nName=%s",mem[i].name);
            printf("\nAge=%d",mem[i].age);
            printf("\nPlan=%s",mem[i].plan);
            printf("\nDate (YYYY-MM-DD)=%d-%d-%d\n",mem[i].y,mem[i].m,mem[i].d);
        }
    }
    fclose(fp);

    printf("\n Analysis Complete!");
    getch();
}
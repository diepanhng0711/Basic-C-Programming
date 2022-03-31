#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500

typedef struct student{
        int no;
        int id;
        char name[50];
        long int phone;
        float score;
} Student;

void Std_Info(Student s[], FILE *fin, FILE *fout){
    int i = 0;
    while (fscanf(fin, "%d  %d  %s  %ld",&s[i].no,&s[i].id,s[i].name,&s[i].phone) != EOF)
    {
        fflush(stdin);
        do {
            printf("Nhap diem sinh vien thu %d = ",i+1); 
            scanf("%f",&s[i].score);
        } while (s[i].score < 0 || s[i].score > 10);
        fprintf(fout, "%d  %d  %s  0%ld  %.2f\n",s[i].no,s[i].id,s[i].name,s[i].phone,s[i].score);
        i++;
    }    
}

int main(int argc, char *argv[])
{
    int i = 0;
    Student s[MAX];
    FILE *fptr1, *fptr2;

    if (argc != 3){
        printf("Wrong arguments!\n");
    return 1;
    }

    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    } else if ((fptr2 = fopen(argv[2], "w")) == NULL){
        printf("Cannot open %s.\n", argv[2]);
        return 1;
    } else {
            Std_Info(s,fptr1,fptr2);
            fclose(fptr2);
            fclose(fptr1);
            return 0;
    }
}
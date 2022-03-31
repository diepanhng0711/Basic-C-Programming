#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 80

void CharReadWrite(FILE *fin, FILE *fout){
    rewind(fin);
    int c;
    while ((c=fgetc(fin)) != EOF){
        fputc(c, fout);
    }
}
void LineReadWrite(FILE *fin, FILE *fout, int f, int n){
    rewind(fin);
    int j,i;

    char s[MAX];

    while(f != i) {
            fgets(s, MAX, fin);
        i++;
    }

    for(i = f; i < n; i++) {
        fgets(s, MAX, fin);
        fprintf(fout,"%s",s);
    }
}

void BinaryReadWrite(FILE *fin, FILE *fout, int n){
    int block;
    char line[MAX + 1];
    rewind(fin);
    while (!feof(fin)){
	    block = fread(line, sizeof(char), n, fin);
	    fwrite(line, sizeof(char), block, fout);
	}
}

int main(int argc, char *argv[])
{
    int key,n,x,first;
    FILE *fptr1, *fptr2;
    clock_t start, end;
    double time_use;

    
    //MENUUUUU nè
    while(true){
        printf("---Chuong trinh sao chep ky tu!---\n\n");
        printf("1. Sao chep tung ky tu\n");
        printf("2. Sao chep theo dong\n");
        printf("3. Sao chep theo block\n");
        printf("4. Thoat chuong trinh!\n\n");
        printf("------------------------------------\n");
        printf("Moi ban lua chon yeu cau: ");

        scanf("%d",&key);
        printf("\n\n");
        switch (key){
            case 1:
            if ((fptr1 = fopen(argv[1], "r")) == NULL){
                printf("Cannot open %s.\n", argv[1]);
                return 1;
            } else if ((fptr2 = fopen(argv[2], "w")) == NULL){
                printf("Cannot open %s.\n", argv[2]);
                return 1;
            }
                start = clock();
                CharReadWrite(fptr1,fptr2);
                end = clock();
                fclose(fptr2);
                fclose(fptr1);
                time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Qua trinh nay duoc thuc hien trong %lf giay!\n", time_use);
                printf("Ban vua lua chon yeu cau 1 thanh cong!\n\n");
                break;
            case 2:
            if ((fptr1 = fopen(argv[1], "r")) == NULL){
                printf("Cannot open %s.\n", argv[1]);
                return 1;
            } else if ((fptr2 = fopen(argv[2], "w")) == NULL){
                printf("Cannot open %s.\n", argv[2]);
                return 1;
            }
                printf("Bat dau sao chep tu dong: ");
                scanf("%d",&first);
                printf("Nhap so dong can sao chep: ");
                scanf("%d",&n);
                start = clock();
                LineReadWrite(fptr1,fptr2,first,n);
                end = clock();
                fclose(fptr2);
                fclose(fptr1);
                time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Qua trinh nay duoc thuc hien trong %lf giay!\n", time_use);
                printf("Ban vua lua chon yeu cau 2 thanh cong!\n\n");
                break;
            case 3:
            if ((fptr1 = fopen(argv[1], "r")) == NULL){
                printf("Cannot open %s.\n", argv[1]);
                return 1;
            } else if ((fptr2 = fopen(argv[2], "w")) == NULL){
                printf("Cannot open %s.\n", argv[2]);
                return 1;
            }
            printf("Nhap so bytes theo moi block sao chep: ");
            scanf("%d",&n);
                start = clock();
                BinaryReadWrite(fptr1,fptr2,n);
                end = clock();
                fclose(fptr2);
                fclose(fptr1);
                time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Qua trinh nay duoc thuc hien trong %lf giay!\n", time_use);
                printf("Ban vua lua chon yeu cau 3 thanh cong!\n\n");
                break;
            case 4:
                printf("Ban da thoat chuong trinh!");
                return 0;
            default:
                printf("Ban da nhap sai yeu cau! Moi nhap lai!\n");
                break;

        }
    }
    
}
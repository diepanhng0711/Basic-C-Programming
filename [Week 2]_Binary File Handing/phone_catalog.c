#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define MAX 500

enum {SUCCESS, FAIL};

typedef struct phoneinfo {
    char model[45];
    char memory[5];
    char size[6];
    char price[10];
} phoneinfo;

int main(int argc, char * argv[])
{
    FILE *fptr1, *fptr2;
    int i = 0;
    int count = 0;
    int key, irc, j;
    phoneinfo *p_inf, *tmp_p_inf; 

    //Check the validity of argc
    if (argc != 3) {
        printf("Syntax error!\n");
        return 1;
    }

    //MENUUU
    while (true)
    {
        printf("-----  Phone Catalog  -----\n\n");
        printf("1. Convert from file.txt to file.dat\n");
        printf("2. Read from file.dat into memory\n");
        printf("3. Print All Database\n");
        printf("4. Search by phone by Phone Model\n");
        printf("5. Exit the program!\n\n");
        printf("------------------------------------\n");
        printf("Please choose your selection: ");

        scanf("%d",&key);
        printf("\n\n");
        switch (key){
            case 1:
            printf("1. Convert from file.txt to file.dat\n");
            if ((fptr1 = fopen(argv[1], "r")) == NULL){
                printf("Cannot open %s.\n", argv[1]);
                return 1;
            } else if ((fptr2 = fopen(argv[2], "w+b")) == NULL){
                printf("Cannot open %s.\n", argv[2]);
                return 1;
            }

            count = 0;
            tmp_p_inf = (phoneinfo *) malloc(sizeof(phoneinfo));
            while (fscanf(fptr1, "%s  %s  %s  %s",tmp_p_inf[i].model,tmp_p_inf[i].memory,tmp_p_inf[i].size,tmp_p_inf[i].price) != EOF){
                count++;
                tmp_p_inf = (phoneinfo *) realloc (tmp_p_inf, (count + 1) * sizeof(phoneinfo));
            }
                printf("\n%d\n", count);
                free(tmp_p_inf);
                rewind(fptr1);

            p_inf = (phoneinfo *) malloc(count * sizeof(phoneinfo));
                
            i = 0;
            while (i < count) {
                fscanf(fptr1, "%s  %s  %s  %s",p_inf[i].model,p_inf[i].memory,p_inf[i].size,p_inf[i].price);
                i++;
            }

                fwrite(p_inf, sizeof(phoneinfo), count, fptr2);
                fclose(fptr1);
                fclose(fptr2);
                free(p_inf);
                printf("Ban vua lua chon yeu cau 1 thanh cong!\n\n");
                break;
            case 2:
            if ((fptr2 = fopen(argv[2], "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", argv[2]);
                break;
            }
                count= 0;
                tmp_p_inf = (phoneinfo *) malloc(sizeof(phoneinfo));
                while (irc = fread(tmp_p_inf, sizeof(phoneinfo), 1, fptr2) != 0){
                    count++;
                }

                free(tmp_p_inf);
                rewind(fptr2);
                

                p_inf = (phoneinfo*) malloc (count * sizeof(phoneinfo));
                fread(p_inf, sizeof(phoneinfo), count, fptr2);
                for (i = 0; i < count; i++) {
                    printf("%s  -  ",p_inf[i].model);
                    printf("%s  -  ",p_inf[i].memory);
                    printf("%s  -  ",p_inf[i].size);
                    printf("%s\n",p_inf[i].price);
                }
                fclose(fptr2);
                free(p_inf);
                printf("Ban vua lua chon yeu cau 2 thanh cong!\n\n");
                break;
            case 3:
            if ((fptr2 = fopen(argv[2], "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", argv[2]);
                break;
            }
                count= 0;
                tmp_p_inf = (phoneinfo *) malloc(sizeof(phoneinfo));
                while (irc = fread(tmp_p_inf, sizeof(phoneinfo), 1, fptr2) != 0){
                    count++;
                }

                free(tmp_p_inf);
                rewind(fptr2);
                
                p_inf = (phoneinfo*) malloc (count * sizeof(phoneinfo));
                fread(p_inf, sizeof(phoneinfo), count, fptr2);
                if (count <= 36) for (i = 0; i < count; i++) {
                    printf("%s  -  ",p_inf[i].model);
                    printf("%s  -  ",p_inf[i].memory);
                    printf("%s  -  ",p_inf[i].size);
                    printf("%s\n",p_inf[i].price);
                } else {
                    int page = (count / 36) + 1;
                    int last_page_count = count - (36 * page);
                    for (j = 0; j < page; j++) {
                        printf("Page no. %d\n\n", j + 1);
                        for (i = j * 36; i < (j * 36) + 36; i++) {
                            printf("%s  -  ",p_inf[i].model);
                            printf("%s  -  ",p_inf[i].memory);
                            printf("%s  -  ",p_inf[i].size);
                            printf("%s\n",p_inf[i].price);
                        }
                        printf("\n");
                    }
                }
                fclose(fptr2);
                free(p_inf);
                printf("Ban vua lua chon yeu cau 3 thanh cong!\n\n");
                break;
            case 4:
                if ((fptr2 = fopen(argv[2], "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", argv[2]);
                break;
            }
                char name[100];
                printf("Model: ");
                scanf("%s%*c", name);

                count= 0;
                tmp_p_inf = (phoneinfo *) malloc(sizeof(phoneinfo));
                while (irc = fread(tmp_p_inf, sizeof(phoneinfo), 1, fptr2) != 0){
                    count++;
                }

                free(tmp_p_inf);
                rewind(fptr2);
                

                p_inf = (phoneinfo*) malloc (count * sizeof(phoneinfo));
                fread(p_inf, sizeof(phoneinfo), count, fptr2);
                int find_count = 0;
                for (i = 0; i < count; i++) {
                    if (strcmp(name, p_inf[i].model) == 0) {
                        printf("%s  -  ",p_inf[i].model);
                        printf("%s  -  ",p_inf[i].memory);
                        printf("%s  -  ",p_inf[i].size);
                        printf("%s\n\n",p_inf[i].price);
                        find_count++;
                    }
                }
                if (find_count == 0) printf("Cannot find model <%s>\n", name);
                fclose(fptr2);
                free(p_inf);
                printf("Ban vua lua chon yeu cau 4 thanh cong!\n\n");
                break;
            case 5:
                printf("Ban da thoat chuong trinh!");
                return 0;
            default:
                printf("Ban da nhap sai yeu cau! Moi nhap lai!\n");
                break;

        }
    }   
}
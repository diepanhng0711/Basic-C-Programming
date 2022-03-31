#include"BST_student.h"
#define MAX 500

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
    int count;
    Student s[MAX];
    FILE *fptr1, *fptr2;
    TreeType Tree;

    if (argc != 2){
        printf("Wrong arguments!\n");
    return 1;
    }

    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    //} else if ((fptr2 = fopen(argv[2], "w")) == NULL){
    //    printf("Cannot open %s.\n", argv[2]);
    //    return 1;
    } else {
        count = 0;
        Student *tmp_p = (Student *) malloc(sizeof(Student));
        while (fscanf(fptr1, "%d  %d  %s  %ld  %f", &tmp_p->no, &tmp_p->id, tmp_p->name, &tmp_p->phone, &tmp_p->score) != EOF){
            count++;
        }
        printf("The number of students = %d\n", count);
        free(tmp_p);
        rewind(fptr1);

        for(i = 0; i < count; i++) {
            fscanf(fptr1, "%d  %d  %s  %ld  %f",&s[i].no,&s[i].id,s[i].name,&s[i].phone,&s[i].score);
            fflush(stdin);
            Insert_Node(s[i],&Tree);
        }

        //Display the tree
        post_Order_Print(Tree);

        int key_search = 1;
        do {
            char name[50];
            printf("Enter the student's name: ");
            scanf("%s%*c",name);
            TreeType inf = Search(name, Tree);
            if (inf == NULL) printf("The student's not found!\n");
            else {
                printf("The student found:\n");
                printf("%d  %d  %s  0%ld  %.2f\n", inf->key.no, inf->key.id, inf->key.name, inf->key.phone, inf->key.score);
            }
            printf("Do you want to continue searching student's information? (y = 1 / n = 0): ");
            scanf("%d",&key_search);
        } while (key_search == 1);
        
        fclose(fptr1);
        return 0;
    }
}
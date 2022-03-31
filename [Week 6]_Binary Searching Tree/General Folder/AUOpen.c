#include"BST_TournamentTree.h"
#include<time.h>

//Random the result of a Tennis's set
int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

//Define Player Type
typedef struct AUOpen {
   char name[30];
    int game[5];
} player;

int main() 
{
    TreeType winner;
    FILE *fptr1, *fptr2;
    int i;
    int x = 1;
    int count = 0;
    player *p;

    srand(time(NULL));
    
    //Open AUOpen.txt
    if ((fptr1 = fopen("AUOpen.txt","r")) == NULL) {
        printf("Cannot open AUOpen.txt!\nPlease check whether that file is availabe!\n");
        return 1;
    }
    //Open treegame.txt
    if ((fptr2 = fopen("treegame.txt","w")) == NULL) {
        printf("Cannot open treegame.txt!\nPlease check whether that file is availabe!\n");
        return 1;
    }

    //Count the number of players in the Australia Open Tournament's bracket
    count = 0;
    player *tmp_p = (player *) malloc(sizeof(player));
    while (fscanf(fptr1, "%s", tmp_p->name) != EOF){
        count++;
    }
    printf("The number of players in this bracket = %d\n", count);
    free(tmp_p);
    rewind(fptr1);

    p = (player *) malloc (sizeof(player) * count);

    int d;
    while (i < count)
    {
        if (fscanf(fptr1, "%s", p[i].name) != EOF) {
            if (fscanf(fptr1, "%s", p[i+1].name) != EOF) {
                int j, m;
                for (j = 0; j < 5; j++) {
                    p[i].game[j] = 0;
                    p[i+1].game[j] = 0;
                }
                int p1_count = 0, p2_count = 0;
                for (m = 0; (p1_count == 3 || p2_count == 3); m++) {
                    d = rand() % 2;
                    if (d == 0) {
                        p[i].game[m] = 6;
                        p[i+1].game[m] = rand() % 6;
                        p1_count++;
                    } else {
                        p[i].game[m] = rand() % 6;
                        p[i+1].game[m] = 6;
                        p2_count++;
                    }
                }
            }
        }
        fprintf(fptr2, "%s  %d  %d  %d  %d  %d\n",p[i].name, p[i].game[0], p[i].game[1], p[i].game[2], p[i].game[3], p[i].game[4]);
        fprintf(fptr2, "%s  %d  %d  %d  %d  %d\n",p[i+1].name, p[i+1].game[0], p[i+1].game[1], p[i+1].game[2], p[i+1].game[3], p[i+1].game[4]);
        fprintf(fptr2,"----------\n");
        i = i + 2;
    }
    

    fclose(fptr1);
    fclose(fptr2);


    //while (x == 1) {
    //    for (i = 0; i < 1; i++) {
    //        if(fscanf(fptr,"%s", p[count]))
    //    }
    //}
}
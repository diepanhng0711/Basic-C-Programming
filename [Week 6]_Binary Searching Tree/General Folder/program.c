#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"BST_VNEdict.h"

int main()
{
	int ch;
	TreeType Tree, inf;
	char name[100];
	while (1)
	{
		printf("================\n");
		printf(">>>>> MENU <<<<<\n");
		printf("================\n");
		printf("1. get data from file .txt\n"
			   "2. display data\n"
			   "3. search\n"
			   "4. update\n"
			   "5. delete\n"
			   "6. exit\n"
			   "---> Select: ");
		scanf("%d%*c", &ch);

		switch (ch)
		{
		case 1:
			printf("===================\n");
			printf(">>> INSERT DATA >>>\n");
			printf("===================\n");
			FILE *f = fopen("vnedict.txt", "r");
			if (f == NULL)
			{
				printf("Khong the mo file\n");
				return;
			}

			vnedict tmp;

			//int dkx = 0;
			while (!feof(f)) {	
				/* if (dkx == 0) {
					fscanf(f, "%[^:]:%[^\n]%*c", tmp->vie, tmp->eng);
					dkx = 1;
					continue;
				} */
			//tmp = (vnedict *)malloc(sizeof(vnedict));
			fscanf(f, "%[^:]:%[^\n]%*c", tmp.vie, tmp.eng);
			Insert_Node_Vie(tmp, &Tree);
			//free(tmp);
			}

			fclose(f);
			break;
		case 3:
			printf("==============================\n");
			printf(">>> SEARCH >>>\n");
			printf("==============================\n");
			 printf("Word: ");
            scanf("%s", name);
            
            inf = Search_Vie(name, Tree);
            if (inf == NULL) printf("Cannot find word <%s>\n\n", name);
            else {
                printf("The word found:\n");
                printf("%s  :  %s  -  %s  -  %s\n", inf->key.vie, inf->key.eng);
			}
			break;
		case 4:
			printf("===================\n");
			printf(">>> UPDATE >>>\n");
			printf("===================\n");
			 printf("Word: ");
            scanf("%s", name);
            
            inf = Search_Vie(name, Tree);
            if (inf == NULL) printf("Cannot find word <%s>\n\n", name);
            else {
                printf("The word found:\n");
                printf("%s  :  %s  -  %s  -  %s\n", inf->key.vie, inf->key.eng);
				printf("\nUpdate : \n");
			        printf("Vietnamese meaning: ");	gets(inf->key.vie);
			        printf("English: "); gets(inf->key.eng);
			}
			break;
		case 5:
			printf("===================\n");
			printf(">>> DELETE >>>\n");
			printf("===================\n");
			break;
		case 6:
			printf("===================\n");
			printf(">>> EXIT >>>\n");
			printf("===================\n");
			exit(0);
			break;
		default:
			printf("Error Key\n");
			break;
		}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char vie[100];
	char eng[280];
} vnedict;

void Text2Dat()
{
	FILE *f = fopen("vnedict.txt", "r"), *f1 = fopen("vnedict.dat", "wb");
	if (f == NULL || f1 == NULL)
	{
		printf("Khong the mo file\n");
		return;
	}

	vnedict *tmp;

	while (!feof(f))
	{
		tmp = (vnedict *)malloc(sizeof(vnedict));
		fscanf(f, "%[^:]:%[^\n]%*c", tmp->vie, tmp->eng);
		fwrite(tmp, sizeof(vnedict), 1, f1);
		free(tmp);
	}

	fclose(f);
	fclose(f1);
}

void getData()
{
	int first, end;

	vnedict *tmp;

	FILE *f = fopen("vnedict.dat", "rb");
	if (f == NULL)
	{
		printf("Khong the mo file vnedict.dat\n");
		return;
	}

	printf("++++++++++++++++++++++++++++++++++\n"
		   ">>>>> Get data from position <<<<<\n"
		   "First: ");
	scanf("%d", &first);
	printf("End: ");
	scanf("%d", &end);
	printf("++++++++++++++++++++++++++++++++++\n");

	fseek(f, (first - 1) * sizeof(vnedict), SEEK_SET);
	for (int i = first; i <= end; i++)
	{
		tmp = (vnedict *)malloc(sizeof(vnedict));
		fread(tmp, sizeof(vnedict), 1, f);
		printf("%s:%s\n", tmp->vie, tmp->eng);
		free(tmp);
	}

	fclose(f);
}

int main()
{
	int ch;

	printf("%d\n\n", strlen("dep"));
	while (1)
	{
		printf("================\n");
		printf(">>>>> MENU <<<<<\n");
		printf("================\n");
		printf("1. convert vnedict.txt to vnedict.dat\n"
			   "2. get data by number line from file .dat\n"
			   "3. Exit\n"
			   "---> Select: ");
		scanf("%d%*c", &ch);

		switch (ch)
		{
		case 1:
			printf("===================\n");
			printf(">>> TEXT TO DAT >>>\n");
			printf("===================\n");
			Text2Dat();
			break;
		case 2:
			printf("==============================\n");
			printf(">>> GET DATA FROM FILE DAT >>>\n");
			printf("==============================\n");
			getData();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Error Key\n");
			break;
		}
	}
}
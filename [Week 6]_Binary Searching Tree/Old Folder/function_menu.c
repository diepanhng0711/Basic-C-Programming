#include"GenSLL.h"
int numElement = 0;

void import()
{
	int n;
	FILE *f = fopen("PhoneDB.dat", "rb");
	if ((f = fopen("PhoneDB.dat", "rb")) == NULL)
	{
		printf("Cannot open PhoneDB.dat!\n");
		return;
	}

	fseek(f, 0, SEEK_END);
	n = ftell(f) / sizeof(elementType);
	rewind(f);
	elementType tmp;
	for (int i = 0; i < n; i++)
	{
		fread(&tmp, sizeof(elementType), 1, f);
		numElement++;
		insert_After_Current_Position(tmp);
	}

	printf("Imported from PhoneDB.dat!\n");
	fclose(f);
}

void display()
{
	traverse_List();
}

void addNew()
{
	int p;
	printf("-------------------------\n"
		   "\t ADD NEW PHONE \n"
		   "Before or After Current Pointer? (Before: 0, After: 1 [Default: 1]): ");
	scanf("%d%*c", &p);
	if (p == 0)
	{
		printf("\t INSERT BEFORE CURRENT POINTER \n");
		insert_Before_Current_Position(get_Data());
		numElement++;
	}
	else
	{
		printf("\t INSERT AFTER CURRENT POINTER \n");
		insert_After_Current_Position(get_Data());
		numElement++;
	}
	printf("\t ADDED! \n");
}

void insertAtPos()
{
	printf("\t Insert At Position \n");
	int n;
	char str[10];
	do
	{
		printf("Them o vi tri (>= 0): ");
		scanf("%d%*c", &n);
	} while (n < 0);

	insert_At_Position(root, get_Data(), n);
	numElement++;
	if (n == 0)
	{
		strcpy(str, "head");
	}
	else
	{
		sprintf(str, "%d", n);
	}
	printf("\t Da them sau vi tri %s thanh cong!\n", str);
}

void delAtPos()
{
	if (root == NULL)
	{
		printf("Con tro ROOT NULL\n");
		return;
	}

	printf("\t Delete at Position \n");
	int n;
	char str[10];
	do
	{
		printf("Xoa o vi tri (>= 0): ");
		scanf("%d%*c", &n);
	} while (n < 0 || n > numElement);

	root = delete_At_Position(root, n);
	numElement--;
	if (n == 0)
	{
		strcpy(str, "head");
	}
	else
	{
		sprintf(str, "%d", n);
	}
	printf("\t Xoa phan tu o vi tri %s thanh cong!\n", str);
}

void delCurrent()
{
	printf("\t Delete Current \n");
	Node *tmp;
	int i = 0;
	printf("Address Current Pointer: %p\n", cur);
	printf("Dia chi cua cac Node trong List: \n");
	for (tmp = root; tmp != NULL; tmp = tmp->next, i++)
	{
		printf("%d. %p\n", i, tmp);
	}

	delete_Current_Element();
	cur = prev;
	prev = root;
	while (prev->next != cur)
	{
		prev = prev->next;
	}
	numElement--;
	printf("\t Xoa thanh cong Element o vi tri hien tai!\n");
}

void delFirst()
{
	printf("\t Delete First \n");
	delete_First_Element();
	numElement--;
	printf("\t Xoa thanh cong First\n");
}

void search_Normal_And_Update()
{
    elementType new;
	printf("\t SEARCH AND UPDATE \n");
	char model[20];
	int i = 0;
	printf("Search by Model: ");
	scanf("%s%*c", model);
	Node *curr;
	for (curr = root; curr != NULL; curr = curr->next)
	{
		i++;
		if (strcmp((curr->inf).model, model) == 0)
		{
			printf(">>> UPDATE ELEMENT thu %d <<<\n", i);
			printf("Model: ");
	        scanf("%s%*c", new.model);
	        printf("Space: ");
	        scanf("%s%*c", new.space);
	        printf("Screen size: ");
	        scanf("%s%*c", new.size);
	        printf("Price: ");
	        scanf("%s%*c", new.price);
		}
	}
	printf("\t DONE! \n");
}

void search_Move_To_Front()
{
	printf("\t SEARCH MOVE TO FRONT \n");
	char model[20];
	int i = 0;
	printf("Search by Model: ");
	scanf("%s%*c", model);
	Node *curr, *found, *pre;
	elementType tmp;
	for (curr = root; curr != NULL; curr = curr->next)
	{
		if (strcmp((curr->inf).model, model) == 0)
		{
			break;
		}
	}
	if (curr == NULL)
	{
		printf("Not found!\n");
		return;
	}
	printf("Founded!\n");

	tmp = curr->inf;
	found = curr;
	if (found == root)
	{
		printf("In root!\n");
		return;
	}
	for (pre = root; curr != root;)
	{
		while (pre->next != curr)
		{
			pre = pre->next;
		}

		curr->inf = pre->inf;
		curr = pre;
		pre = root;
	}
	root->inf = tmp;
	printf("Searched Moved to Front!\n");
}

void search_Transpose()
{
	printf("\t SEARCH TRANSPOSE \n");
	char model[20];
	int i = 0;
	printf("Search by Model: ");
	scanf("%s%*c", model);
	Node *curr, *found, *pre;
	elementType tmp;
	for (curr = root; curr != NULL; curr = curr->next)
	{
		if (strcmp((curr->inf).model, model) == 0)
		{
			break;
		}
	}

	if (curr == NULL)
	{
		printf("Not found!\n");
		return;
	}
	printf("Founded!\n");
	if (curr == root)
	{
		printf("In Root!\n");
		return;
	}

	for (pre = root; curr != root;)
	{
		while (pre->next != curr)
		{
			pre = pre->next;
		}
		tmp = curr->inf;
		curr->inf = pre->inf;
		pre->inf = tmp;
		curr = pre;
		pre = root;
	}
	printf("Searched Transpose!\n");
}

void select8()
{
	int choose;
	printf("----- Select 8-----!\n"
		   "1. Search Normal and Update\n"
		   "2. Search move to front\n"
		   "3. Search transpose\n"
		   "---> Choose: ");
	scanf("%d%*c", &choose);

	switch (choose)
	{
	case 1:
		search_Normal_And_Update();
		break;
	case 2:
		search_Move_To_Front();
		break;
	case 3:
		search_Transpose();
		break;
	default:
		printf("error!\n");
		break;
	}
}

void divideAndExtract()
{
	printf("\t DIVIDE AND EXTRACT \n");
	Node *rootList1 = NULL, *rootList2 = root;
	if (root == NULL)
	{
		printf("Root NULL\n");
		return;
	}
	int n1, n2;
	printf("Divide List to List1 and List2\n");

	do
	{
		printf("Chu y: Nhap dung!!!\n");
		printf("Chia tu vi tri: ");
		scanf("%d%*c", &n1);
		printf("Lay so phan tu: ");
		scanf("%d%*c", &n2);
	} while (n1 > numElement || n1 + n2 - 1 > numElement);

	rootList1 = spilt(root, n1, n2);
	rootList2 = root;

	printf("-----List 1-----\n");
	save_to_Text(rootList1, "PhoneDB_List1.txt");
	printf("-----List 2-----\n");
	traverse_List();
	printf("\t DIVIDE AND EXTRACT \n");
}

void reverse()
{
	printf("\t REVERSE \n");
	root = list_Reverse(root);
}

void saveListToDat(char *filename)
{
	printf("\t SAVE TO DAT \n");
	FILE *f = fopen(filename, "wb");
	if (f == NULL)
	{
		printf("Khong the mo file nen khong the luu file.\n");
		return;
	}

	for (cur = root; cur != NULL; cur = cur->next)
	{
		fwrite(&(cur->inf), sizeof(elementType), 1, f);
	}
	printf("Da luu file thanh cong!\n");
	fclose(f);
}

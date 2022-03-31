#include"DLL_PhoneDB.h"

int main()
{
    node_phoneinfo *root = NULL, *cur = NULL, *tail = NULL;
    int key, d, i, irc;
    int n, n1, n2;
    int count = 0;
    phoneinfo *tmp_p_inf, *p_inf;
    while (true) 
    {
        printf("------- MENU -------\n");
        printf("1. Import from PhoneDB.dat\n");
        printf("2. Display List\n");
        printf("3. Add new phone (Before or After Current Pointer)\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Position\n");
        printf("6. Delete current\n");
        printf("7. Delete first\n");
        printf("8. Delete last\n");
        printf("9. Search and Update\n");
        printf("10. Reverse List\n");
        printf("11. Save to file\n");
        printf("12. Quit\n");
        printf("Please choose your selection: ");

        scanf("%d",&key);
        printf("\n\n");
        switch (key)
        {
        case 1:
            printf("1. Import from PhoneDB.dat\n\n");
	        FILE *f = fopen("PhoneDB.dat", "rb");
	        if ((f = fopen("PhoneDB.dat", "rb")) == NULL) {
		        printf("Khong the mo file PhoneDB.dat!\n");
		        return;
	        }

            n = 0;
	        tmp_p_inf = (phoneinfo *) malloc(sizeof(phoneinfo));
                while (irc = fread(tmp_p_inf, sizeof(phoneinfo), 1, f) != 0){
                    n++;
                }

                free(tmp_p_inf);
                rewind(f);
                
            phoneinfo tmp;
	        for (i = 0; i < n; i++) {
		        fread(&tmp, sizeof(phoneinfo), 1, f);
		        count++;
		        insert_After_Current_Position(tmp, &root, &tail, &cur);
	        }
	        fclose(f);
            printf("Selection 1 succeeded!\n\n");
            break;
        case 2:
            printf("2. Display List\n\n");
            travesing_A_List(&root);
            printf("Selection 2 succeeded!\n\n");
            break;
        case 3:
            printf("3. Add new phone (Before or After Current Pointer)\n");
            printf("Select: 1 - [Before] / 2 - [After] : ");
            do {
                scanf("%d%*c",&d);
            }
            while (d != 1 && d != 2);
            fflush(stdin);
            if (d == 1) {
                phoneinfo add_inf = read_Node();
                insert_Before_Currrent_Position(add_inf, &root, &tail, &cur);
                count++;
            } else {
                phoneinfo add_inf = read_Node();
                insert_After_Current_Position(add_inf, &root, &tail, &cur);
                count++;
            }
            printf("Selection 3 succeeded!\n\n");
            break;
        case 4:
            printf("4. Insert at Position\n");
            do {
		        printf("Insert at the position : ");
		        scanf("%d", &n);
	        } while (n < 0);
            phoneinfo tmp_inf = read_Node();
            insert_At_Position(tmp_inf, n, &root, &tail, &cur);
            count++;
            printf("Selection 4 succeeded!\n\n");
            break;
        case 5:
            printf("5. Delete at Position\n");
            do {
		        printf("Insert at the position : ");
		        scanf("%d", &n);
	        } while (n < 0);
            delete_At_Element(n, &root, &tail, &cur);
            count--;
            printf("Selection 5 succeeded!\n\n");
            break;
        case 6:
            printf("6. Delete current\n");
            delete_Current_Element(&root, &tail, &cur);
            count--;
            printf("Selection 6 succeeded!\n\n");
            break;
        case 7:
            printf("7. Delete first\n");
            delete_First_Element(&root, &tail, &cur);
            printf("Selection 7 succeeded!\n\n");
            break;
        case 8:
            printf("8. Delete last\n");
            delete_Last_Element(&root, &tail, &cur);
            printf("Selection 8 succeeded!\n\n");
            break;
        case 9: 
            printf("9. Search and Update\n");
            if ((f = fopen("phoneDB.dat", "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", "phoneDB.dat");
                break;
            }
            search_And_Update(&root, &tail, &cur);
            printf("Selection 9 succeeded!\n\n");
            break;
        case 10: 
            printf("10. Reverse List\n");
            list_Reverse(&root, &tail, &cur);
            travesing_A_List(&root);
            printf("Selection 10 succeeded!\n\n");
            break;
        case 11:
            printf("11. Save to file\n");
            save_to_Text(root, "PhoneDB_DLL.txt");
            printf("Selection 11 succeeded!\n\n");
            break;
        case 12:
            freeing_A_List(&root);
            printf("Exit the program!\n");
            return 0;
        default:
            printf("Wrong selection! Please enter the correct number!\n");
            break;
        }
    }
}




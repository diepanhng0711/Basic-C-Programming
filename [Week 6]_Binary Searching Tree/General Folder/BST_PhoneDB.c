#include"BST_PhoneDB.h"
#define MAX 500

int main()
{
    int key, d, i, irc;
    int n, n1, n2;
    int count = 0;
    phoneinfo *tmp_p_inf, p_inf[MAX];
    TreeType Tree, inf;
    char name[100];
    while (true) 
    {
        printf("------- MENU -------\n");
        printf("1. Import from PhoneDB.txt\n");
        printf("2. Display List\n");
        printf("3. Add new phone\n");
        printf("4. Delete\n");  
        printf("5. Search and Update\n");
        printf("6. Save to file\n");
        printf("7. Quit\n");
        printf("Please choose your selection: ");

        scanf("%d",&key);
        printf("\n\n");
        
        switch (key)
        {
        case 1:
            printf("1. Import from PhoneDB.txt\n");
	        FILE *f = fopen("PhoneDB.txt", "r");
	        if ((f = fopen("PhoneDB.txt", "r")) == NULL) {
		        printf("Khong the mo file PhoneDB.txt!\n");
		        return;
	        }

            count = 0;
            phoneinfo *tmp_p = (phoneinfo *) malloc(sizeof(phoneinfo));
            while (fscanf(f, "%s %s %s %s", tmp_p->model, tmp_p->memory, tmp_p->size, tmp_p->price) != EOF){
                count++;
            }
            printf("The number of phones = %d\n", count);
            free(tmp_p);
            rewind(f);

            for(i = 0; i < count; i++) {
                fscanf(f, "%s %s %s %s", p_inf[i].model, p_inf[i].memory, p_inf[i].size, p_inf[i].price);
                fflush(stdin);
                Insert_Node(p_inf[i],&Tree);
            }
            printf("Selection 1 succeeded!\n\n");
            break;
        case 2:
            printf("2. Display List\n");
            int dis;
            printf("Please enter your Order (Pre = 1 / Post = 2 / In = 3): ");
            scanf("%d", &dis);

            switch (dis) {
                case 1:
                    pre_Order_Print(Tree);
                    break;
                case 2:
                    post_Order_Print(Tree);
                    break;
                case 3:
                    in_Order_Print(Tree);
                    break;
                default:
                    printf("Wrong selection!\n");
                    break;
            }
            printf("Selection 2 succeeded!\n\n");
            break;
        case 3:
            printf("3. Add new phone\n");
            fflush(stdin);

            printf("Enter the new phone: \n");
            phoneinfo add_inf = read_Node();
            Insert_Node(add_inf, &Tree);
            count++;
            printf("Selection 3 succeeded!\n\n");
            break;
        case 4:
            printf("4. Delete\n");
            if ((f = fopen("phoneDB.dat", "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", "phoneDB.dat");
                break;
            }
            printf("Enter the phone you want to delete: \n");
                printf("Model: ");
                scanf("%s", name);

            inf = Search(name, Tree);
            if (inf == NULL) printf("Cannot find model <%s>\n\n", name);
            else {
                printf("The phone found:\n");
                printf("%s  -  %s  -  %s  -  %s\n", inf->key.model, inf->key.memory, inf->key.size, inf->key.price);
                KeyType del = inf->key;
                Delete_Node(del, &Tree);
            }
                
            printf("Selection 4 succeeded!\n\n");
            break;
        case 5:
            printf("5. Search and Update\n");
            if ((f = fopen("phoneDB.dat", "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", "phoneDB.dat");
                break;
            }
            printf("Model: ");
            scanf("%s", name);
            
            inf = Search(name, Tree);
            if (inf == NULL) printf("Cannot find model <%s>\n\n", name);
            else {
                printf("The phone found:\n");
                printf("%s  -  %s  -  %s  -  %s\n", inf->key.model, inf->key.memory, inf->key.size, inf->key.price);
                printf("\nUpdate : \n");
			        printf("Model: ");scanf("%s%*c", inf->key.model);
			        printf("Memory: ");scanf("%s%*c", inf->key.memory);
			        printf("Screen size: ");scanf("%s%*c", inf->key.size);
			        printf("Price: ");scanf("%s%*c", inf->key.price);
                    printf("\n\n");
                    printf("The phone catalog after updating (Post):\n");
                    post_Order_Print(Tree);
                    printf("\nUpdate succeeded! \n");
            }
            printf("Selection 5 succeeded!\n\n");
            break;
        case 6:
            printf("6. Save to file\n");
            FILE *fptr = fopen("PhoneDB_out.txt", "w");
                if (fptr == NULL) {
                printf("Cannot open %s\n", "PhoneDB_out.txt");
                return;
            }
            fclose(fptr);
            int dis1;
            printf("Please enter your Order (Pre = 1 / Post = 2 / In = 3): ");
            scanf("%d", &dis1);

            switch (dis1) {
                case 1:
                    pre_Order_Save(Tree);
                    break;
                case 2:
                    post_Order_Save(Tree);
                    break;
                case 3:
                    in_Order_Save(Tree);
                    break;
                default:
                    printf("Wrong selection!\n");
                    break;
            }
            printf("Selection 6 succeeded!\n\n");
            break;
        case 7:
            fclose(f);
            printf("Exit the program\n");
            return 0;
        default:
            printf("Wrong selection! Please enter the correct number!\n\n");
            break;
        }
    }
}


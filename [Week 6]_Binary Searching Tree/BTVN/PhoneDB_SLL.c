#include"SLL_PhoneDB.h"

int main()
{
    int key, d, i, irc;
    int n, n1, n2;
    int count = 0;
    phoneinfo *tmp_p_inf, *p_inf;
    phoneinfo tmp;
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
        printf("8. Search and Update\n");
        printf("9. Divide and Extract (split)\n");
        printf("10. Reverse List\n");
        printf("11. Save to file\n");
        printf("12. Quit\n");
        printf("Please choose your selection: ");

        scanf("%d",&key);
        printf("\n\n");
        
        switch (key)
        {
        case 1:
            printf("1. Import from PhoneDB.dat\n");
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
                
	        for (i = 0; i < n; i++) {
		        fread(&tmp, sizeof(phoneinfo), 1, f);
		        count++;
		        insert_After_Current_Position(tmp);
	        }
	        fclose(f);
            printf("Selection 1 succeeded!\n\n");
            break;
        case 2:
            printf("2. Display List\n");
            travesing_A_List();
            printf("Selection 2 succeeded\n\n");
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
                insert_Before_Current_Position(add_inf);
                count++;
            } else {
                phoneinfo add_inf = read_Node();
                insert_After_Current_Position(add_inf);
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
            insert_At_Position(root, read_Node(), n);
            count++;
            printf("Selection 4 succeeded!\n\n");
            break;
        case 5:
            printf("5. Delete at Position\n");
            do {
		        printf("Insert at the position : ");
		        scanf("%d", &n);
	        } while (n < 0);
            delete_At_Element(n);
            count--;
            printf("Selection 5 succeeded!\n\n");
            break;
        case 6:
            printf("6. Delete current\n");
            delete_Current_Element();
            count--;
            printf("Selection 6 succeeded!\n\n");
            break;
        case 7:
            printf("7. Delete first\n");
            delete_First_Element();
            printf("Selection 7 succeeded!\n\n");
            break;
        case 8:
            printf("8. Search and Update\n");
            if ((f = fopen("phoneDB.dat", "r+b")) == NULL){
                printf("Cannot open %s.\n! Please do the first step before!", "phoneDB.dat");
                break;
            }

            node_phoneinfo *curr, *found, *pre;
            char name[100];
            int select_8;
            printf("What type of searching and updating?\n");
            printf("1. Search and Update\n");
            printf("2. Move to Front\n");
            printf("3. Transpose\n");
            printf("Enter your selection: ");
            scanf("%d%*c", &select_8);
            switch(select_8) {
        case 1:
                printf("Model: ");
                scanf("%s", name);

                int find_count = 0;

            node_phoneinfo *ptr;
            for (ptr = root; ptr != NULL; ptr = ptr -> next) {
                if (strcmp(name, (ptr -> inf).model) == 0) {
                    display_Node(ptr);
                    printf("\nUpdate : \n");
			        printf("Model: ");scanf("%s%*c", ptr -> inf.model);
			        printf("Memory: ");scanf("%s%*c", ptr -> inf.memory);
			        printf("Screen size: ");scanf("%s%*c", ptr -> inf.size);
			        printf("Price: ");scanf("%s%*c", ptr -> inf.price);
                    printf("\n\n");
                    display_Node(ptr);
                    printf("\nUpdate succeeded! \n");
                    find_count++;
                }
            }
            if (find_count == 0) printf("Cannot find model <%s>\n\n", name);
            printf("Selection 8 succeeded!\n\n");
            break;
        case 2:
            printf("Move To Front \n");
	        int i = 0;
	        printf("Search by Model: ");
	        scanf("%s%*c", name);
	        for (curr = root; curr != NULL; curr = curr->next)
	        {
		        if (strcmp((curr->inf).model, name) == 0)
		        {
			        break;
		        }
	        }
	        if (curr == NULL)
	        {
		        printf("Khong tim thay model <%s>!\n", name);
		        return;
	        }
	        printf("Model <%s>\n",name);

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
            break;
        case 3:
            printf("Transpose \n");
	        i = 0;
	        printf("Search by Model: ");
	        scanf("%s%*c", name);
	        
	        for (curr = root; curr != NULL; curr = curr->next)
	        {
		        if (strcmp((curr->inf).model, name) == 0)
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
        break;
    }
        break;
        case 9:
            printf("9. Divide and Extract (split)\n");
	        node_phoneinfo *rootList1 = NULL, *rootList2 = root;
	        if(root == NULL){
		        printf("Root NULL\n");
		        return;
	        }
	        printf("Divide List into List1 and List2\n");

	        do
	        {
		        printf("Chu y: Nhap dung!!!\n");
		        printf("Chia tu vi tri: ");scanf("%d%*c", &n1);
		        printf("Lay so phan tu: ");scanf("%d%*c", &n2);
	        } while (n1 > count || n1 + n2 - 1 > count);
	
	        rootList1 = spilt(root, n1, n2);
	        rootList2 = root;

	        printf("-----List 1-----\n");
	        save_to_Text("PhoneDB_List1.txt");
	        printf("-----List 2-----\n");
	        travesing_A_List();
	        printf("\t DIVIDE AND EXTRACT \n");
            printf("Selection 9 succeeded!\n\n");
            break;
        case 10: 
            printf("10. Reverse List\n");
            list_reverse(root);
            travesing_A_List();
            printf("Selection 10 succeeded!\n\n");
            break;
        case 11:
            printf("11. Save to file\n");
            save_to_Text("PhoneDB_out.txt");
            printf("Selection 11 succeeded!\n\n");
            break;
        case 12:
            freeing_A_List();
            printf("Exit the program!\n\n");
            return 0;
        default:
            printf("Wrong selection! Please enter the correct number!\n\n");
            break;
        }
    }
}
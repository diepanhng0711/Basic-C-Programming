#include"GenSLL.h"
#include"function_menu.c"

int main()
{
    int ch;
    while (1)
    {
        printf("--------------\n"
               ">>>> MENU <<<<<\n"
               "1. Import from PhoneDB.dat\n"
               "2. Display List\n"
               "3. Add new phone (Before or After Current Pointer)\n"
               "4. Insert at Position\n"
               "5. Delete at Position\n"
               "6. Delete current\n"
               "7. Delete first\n"
               "8. Search and Update\n"
               "9. Divide and Extract (split)\n"
               "10. Reverse List\n"
               "11. Save to file\n"
               "12. Quit\n"
               "->> Select: ");
        scanf("%d%*c", &ch);
        switch (ch)
        {
        case 1:
            import();
            break;
        case 2:
            display();
            break;
        case 3:
            addNew();
            break;
        case 4:
            insertAtPos();
            break;
        case 5:
            delAtPos();
            break;
        case 6:
            delCurrent();
            break;
        case 7:
            delFirst();
            break;
        case 8:
            select8();
            break;
        case 9:
            divideAndExtract();
            break;
        case 10:
            reverse();
            break;
        case 11:
            saveListToDat("PhoneDB.dat");
            break;
        case 12:
            printf("\tBye! Bye!\n");
            Free();
            exit(0);
            break;
        default:
            perror("Error Key!\n");
            break;
        }
    }
}
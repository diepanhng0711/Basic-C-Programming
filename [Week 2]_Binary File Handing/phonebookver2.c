#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

// the phone book structure
typedef struct phoneaddress {
      char name[20];
      char tel[11];
      char email[25];
} phoneaddress;

int main(void)
{
    FILE *fp;
    phoneaddress *phonearr;


    int i,n,irc,x,y;
    int reval = SUCCESS;
    printf("Nhap x va y:\n");
    scanf("%d %d",&x,&y);
    printf("Read from data number %d to data number %d\n",x ,y );
   
    if ((fp = fopen("phonebook.dat","r+b")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	 } 
    
    phonearr = (phoneaddress *)malloc((y-x+1) * sizeof(phoneaddress));
    if (phonearr == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    if (fseek(fp,1*sizeof(phoneaddress),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), (y-x+1), fp);
    for (i=0; i<(y-x+1); i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].tel);
        printf("%s\n",phonearr[i].email);
    }
 
    strcpy(phonearr[3].name,"Lan Hoa");
    strcpy(phonearr[6].tel,"0923456");
    strcpy(phonearr[7].email,"anhlaido9x@yahoo.com");


    fseek(fp,x*sizeof(phoneaddress),SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress), (y-x+1), fp);
    printf(" fwrite return code = %d\n", irc);
    fclose(fp); 
    free(phonearr);

    return reval;
}

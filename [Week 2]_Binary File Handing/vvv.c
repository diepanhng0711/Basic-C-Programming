#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("baitapc.txt","w+");
   fputs("Hoc C co ban va nang cao tai VietJack !!!", fp);
  
   fseek( fp, 1, SEEK_SET );
   fputs("lap trinh C", fp);
   fclose(fp);
   
   return(0);
}
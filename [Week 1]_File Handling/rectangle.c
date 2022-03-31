#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    double height, width;
    height = atof(argv[1]);
    width  = atof(argv[2]);

    if (argc != 3) {
        printf("Wrong Syntax!\nMust be: .\\rectangle <height> <width>!\n");
        return 1;
    }

    if (height <= 0 || width <= 0) {
        printf("Invalid value!");
        return 1;
    }

    printf("Perimeter = %.2lf\n", (height + width) * 2);
    printf("Area = %.2lf\n", height * width);
    return 0;
}
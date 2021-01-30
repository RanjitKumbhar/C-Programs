// Swapping of 2 Numbers
#include<stdio.h>
#include<conio.h>

int main()
{
                    int  Num1 = 0, Num2 = 0, Num3 = 0, Temp = 0;

                    printf("\n Enter 3 Numbers for Swapping = ");
                    scanf("%d%d%d",&Num1, &Num2,&Num3);

                    printf("\n Before Swap 1st Number = %d.", Num1);
                    printf("\n Before Swap 2nd Number = %d.",Num2);
                    printf("\n Before Swap 3rd Number = %d.",Num3);

                    Temp = Num1;
                    Num1 = Num3;
                    Num3 = Num2;
                    Num2 = Temp;

                    printf("\n=================================\n");

                    printf("\n\n After Swap 1st Number = %d.", Num1);
                    printf("\n After Swap 2nd Number = %d.",Num2);
                    printf("\n After Swap 3rd Number = %d.",Num3);

                    printf("\n\n Thanks");

                    getch();
                    return 0;
}

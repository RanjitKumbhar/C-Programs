#include<stdio.h>
#include<conio.h>

int main()
{
            int No = 0,  Temp = 0, RevNum = 0;

            printf(" Enter +ve Integer Number  To Get its Reverse Number : ");
            scanf("%d",&No);

            Temp = No;

            if(No < 0)
            {
                    printf("Invalid Number"); return -1;
            }

            while( Temp > 0 )
            {
                        RevNum = (RevNum * 10) + (Temp % 10);
                        Temp /= 10;
            }

            printf("\n Reverse Of Given Number %d is = %d.", No, RevNum);

            getch();
            return 0;
}

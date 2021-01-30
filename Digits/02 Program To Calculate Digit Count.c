#include<stdio.h>
#include<conio.h>

int main()
{
            int No = 0, dCnt = 0, Temp = 0;

            printf(" Enter +ve Integer Number  To Calculate its Digits Count : ");
            scanf("%d",&No);

            Temp = No;

            if(No < 0)
            {
                    printf("Invalid Number"); return -1;
            }

            while( Temp > 0 )
            {
                        dCnt++;
                        Temp = Temp / 10;
            }

            printf("\n Count of Digits in Given Number %d is = %d.", No, dCnt);

            getch();
            return 0;
}

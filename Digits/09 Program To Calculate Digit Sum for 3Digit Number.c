#include<stdio.h>
#include<conio.h>

int main()
{
            int No = 0, Dig = 0, dSum = 0, Temp = 0, dCnt = 0;

            printf(" Enter +ve Integer Number  To Calculate its Digits Sum : ");
            scanf("%d",&No);

            Temp = No;

            if(No < 0)
            {
                    printf("Invalid Number"); return -1;
            }

            while(Temp > 0)      // Loop To Calculate Digits Count in Given Number
            {
                    dCnt++;
                    Temp = Temp / 10;
            }
            // After Above Loop Execution Our Temp Becomes Zero

            if(dCnt == 3)           // To Check Whether That Given Number is 3 Digit or Not
            {
                            Temp = No;                      // Reset Our Temp Variable to Given No

                            while( Temp > 0 )          // To Calculate Sum Of Digits in Given 3 Digit Number
                            {
                                        Dig = Temp % 10;
                                        printf("\n Sum => %d + %d = %d. ",dSum, Dig, dSum + Dig);
                                        dSum = dSum + Dig;
                                        Temp = Temp / 10;
                            }

                            printf("\n Sum of Digits in Given Number %d is = %d.", No, dSum);
            }
            else
            {
                            printf("\n Given Number is not 3 Digit Number!!!");
            }

            getch();
            return 0;
}

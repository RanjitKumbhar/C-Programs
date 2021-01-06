
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Customer
{
        long Cust_Acc_No;
        char Cust_Name[10];
        long Cust_Mob_no;
        struct Customer *next;
};

void Long_To_String(char *str, long Num)
{
    /*
        long dig = 0;
        char ch;

        while(Num != 0)
        {
                dig = parse(int)(Num % 10);
                 ch = dig + 48;
                 *str = ch;
                 str++;
                 Num = Num / 10;
        }
        */

        printf("\nHIiiiii%s\n",str);
}

long String_To_Long(char str[])
{
        int len = strlen(str);

        int i = 0;
        long num = 0;

        while (i < len )
        {
                num =  num * 10;
                num =  num + (str[i] - 48);
                i++;
        }
        return num;
}

void Open_Bank(struct Customer **First)
{
       char ch;

        FILE *f1;

        f1 = fopen("CustomerDetails.txt","r+");

        while(1)
        {
                ch = fgetc(f1);
                if(ch == EOF)
                {
                        break;
                }
                while(ch != '\n')
                {
                        int Flg = 0;
                        char AccNo[10] ;

                        char MobNo[10];

                        struct Customer  *newnode = NULL;

                        newnode = (struct Customer*)malloc(sizeof(struct Customer));

                        if(NULL == newnode)
                        {
                            return;
                        }

                        while(ch != ' ' )
                        {
                                AccNo[Flg] = ch;
                                Flg++;
                                ch = fgetc(f1);
                        }
                        AccNo[Flg] = '\0';

                        //printf("\n %s \n",AccNo);
                        Flg = 0;

                        ch = fgetc(f1);

                        //printf("%c\n",ch);

                         while(ch != ' ' )
                        {
                                newnode ->Cust_Name[Flg] = ch;
                                Flg++;
                                //printf("%c\n",ch);
                                ch = fgetc(f1);
                        }
                        newnode ->Cust_Name[Flg] = '\0';

                        Flg = 0;

                        ch = fgetc(f1);

                         while(ch != 10)
                        {
                                MobNo[Flg] = ch;
                                Flg++;
                               //printf("%c\n",ch);
                                 ch = fgetc(f1);
                        }
                        MobNo[Flg] = '\0';

                        //printf("\n %s \n",MobNo);

                        Flg = 0;

                        newnode -> Cust_Acc_No = String_To_Long(AccNo);

                        newnode ->Cust_Mob_no = String_To_Long(MobNo);

                        newnode -> next = NULL;

                        if(*First == NULL)
                        {
                            *First = newnode;
                        }
                        else
                        {
                            struct Customer *temp = *First;

                            while( temp -> next != NULL)
                            {
                                temp = temp -> next;
                            }
                            temp -> next = newnode;
                        }
                }
        }
        fclose(f1);
        return;
}

void Display_All_Customers(struct Customer **First)
{
       char ch;

        FILE *f1;

        f1 = fopen("CustomerDetails.txt","r+");

        while(1)
        {
                ch = fgetc(f1);
                if(ch == EOF)
                {
                        break;
                }
                while(ch != '\n')
                {
                        int Flg = 0;
                        char AccNo[10] ;

                        char MobNo[10];

                        struct Customer  *newnode = NULL;

                        newnode = (struct Customer*)malloc(sizeof(struct Customer));

                        if(NULL == newnode)
                        {
                            return;
                        }

                        while(ch != ' ' )
                        {
                                AccNo[Flg] = ch;
                                Flg++;
                                ch = fgetc(f1);
                        }
                        AccNo[Flg] = '\0';

                        Flg = 0;

                        ch = fgetc(f1);

                         while(ch != ' ' )
                        {
                                newnode ->Cust_Name[Flg] = ch;
                                Flg++;
                                ch = fgetc(f1);
                        }
                        newnode ->Cust_Name[Flg] = '\0';

                        Flg = 0;

                        ch = fgetc(f1);

                         while(ch != 10)
                        {
                                MobNo[Flg] = ch;
                                Flg++;
                                 ch = fgetc(f1);
                        }
                        MobNo[Flg] = '\0';

                        Flg = 0;

                        newnode -> Cust_Acc_No = String_To_Long(AccNo);

                        newnode ->Cust_Mob_no = String_To_Long(MobNo);

                        newnode -> next = NULL;

                        printf("-----------------------------------------------------\n");
                        printf("Customer Account Number  :  %li.\n",newnode -> Cust_Acc_No);
                        printf("Customer Name  :  %s.\n",newnode ->Cust_Name );
                        printf("Customer Mobile Number  :  %li.\n",newnode ->Cust_Mob_no );
                        printf("-----------------------------------------------------\n");

                        if(*First == NULL)
                        {
                            *First = newnode;
                        }
                        else
                        {
                            struct Customer *temp = *First;

                            while( temp -> next != NULL)
                            {
                                temp = temp -> next;
                            }
                            temp -> next = newnode;
                        }
                }
        }
        fclose(f1);
        return;
}

void Add_New_Customer(struct Customer **First)
{
        FILE *f1;

        f1 = fopen("CustomerDetails.txt","a+");

        lseek(f1, feof,0);

        struct Customer *temp = *First;

        while( temp -> next != NULL)
        {
            temp = temp -> next;
        }
        //temp -> next = newnode;

        char CustNm[10] ;
        long MobNo;
        char AccNo[10];
        char cMobNo[10];
        long Flg;
        int i = 0;

        struct Customer  *newnode = NULL;

        newnode = (struct Customer*)malloc(sizeof(struct Customer));

        if(NULL == newnode)
        {
            return;
        }

        Flg = newnode -> Cust_Acc_No =  (temp -> Cust_Acc_No) + 1;

        printf("\n Account Number For New Customer Is : %ld",Flg);

        printf("\n Enter Customer Name : ");
        scanf("%s",&CustNm);

        while(CustNm [i] != '\0')
        {
                newnode ->Cust_Name[i] = CustNm[i];
                i++;
        }
        newnode ->Cust_Name[i] =  '\0';


        printf("\n Enter Customer Mobile Number : ");
        scanf("%ld",&MobNo);
        newnode->Cust_Mob_no = MobNo;

         //Long_To_String(&AccNo, Flg);
         sprintf(AccNo,"%li",Flg);
        fwrite(AccNo,11,1,f1);
        fputc(' ',f1);

        fwrite(CustNm,11,1,f1);
        fputc(' ',f1);

        //Long_To_String(&cMobNo, MobNo);
        sprintf(cMobNo,"%li",MobNo);
        fwrite(cMobNo,11,1,f1);
        fputc('\n',f1);

        fclose(f1);
        return;
}

int main()
{
        struct Customer *Head = NULL;
        char ch;
        Open_Bank(&Head);

        printf("\n Please Select the Choice: \n");
        printf("\n ============================================================== \n");
        printf("\n 1. Add New Customer \n");
        printf("\n 2. Credit Amount to Customers Account \n");
        printf("\n 3. Debit Amount From Customers Account \n");
        printf("\n 4. Delete Customer\n");
        printf("\n 5. Display Customer Details \n");
        printf("\n 6. Display All Customer Details \n");
        printf("\n 7. Display No. of Customers \n");
        printf("\n 8. Exit \n");
        printf("\n ============================================================== \n");

        for(;;)
        {
            printf("\n Enter Your Choice :");
            scanf(" %c",&ch);
            //ch = getche();

            switch(ch)
            {
                case '1':
                    Add_New_Customer(&Head);
                    break;

                case '2':

                    break;

                case '3':

                    break;

                case '4':


                    break;

                case '5':

                    break;

                case '6':
                    Display_All_Customers(&Head);
                    break;

                case '7':

                    break;

                case '8':
                    return 0;

                default:
                    printf("\n Enter Valid value\n");
                    break;
            }
        }
}

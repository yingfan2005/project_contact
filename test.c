#include"contact.h"
#include<stdio.h>
void menu()
{
    printf("1.Add\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.Modify\n");
    printf("5.Show\n");
    printf("6.Sort\n");
    printf("0.Exit\n");
}
int main()
{
    int input=0;
    //criar
    struct Contact con;
    //iniciar
    InitContact(&con);
    do
    {
        menu();
        printf("Choose:->");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:
            AddContact(&con);
            break;
            case DELETE:
            DeleteContact(&con);
            break;
            case SEARCH:
            SearchContact(&con);
            break;
            case MODIFY:
            ModifyContact(&con);
            break;
            case SHOW:
            ShowContact(&con);
            break;
            case SORT:
            SortContact(&con);
            break;
            case EXIT:
            printf("Out\n");
            break;
            default:
            printf("Error\n");
            break;
        }
    }while(input);
    return 0;
}

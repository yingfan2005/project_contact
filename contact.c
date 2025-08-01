#include "contact.h"

void InitContact(struct Contact *ps)
{
    ps->data=(struct PeoInfo *)malloc(MIN_CAP*sizeof(struct PeoInfo));
    if(ps->data==NULL)
    {
        return ;
    }
    ps->size=0;
    ps->capacity=MIN_CAP;
     
    LoadContact(ps);

}

void CheckCap(struct Contact *ps)
{
    if(ps->size==ps->capacity)
    {
        struct PeoInfo *p=(struct PeoInfo *)realloc(ps->data,(ps->capacity+2)*(sizeof(struct PeoInfo)));
        if(p!=NULL)
        {
            ps->data=p;
            ps->capacity+=2;
            printf("Expand capacity with success\n");
        }
        else
        {
            printf("Expand failed\n");
        }
    }
}

void LoadContact(struct Contact *ps)
{
    struct PeoInfo tmp={0};
    FILE *pfRead=fopen("contact.dat","rb");
    if(pfRead==NULL)
    {
        printf("LoadContact::%s\n",strerror(errno));
        return ;
    }
    while(fread(&tmp,sizeof(struct PeoInfo),1,pfRead))
    {
        CheckCap(ps);
        ps->data[ps->size]=tmp;
        ps->size++;
    }



    fclose(pfRead);
    pfRead=NULL;

}
static int FindByName(const struct Contact *ps,char name[MAX_NAME])
{
    int i=0;
    for(i=0;i<ps->size;i++)
    {
        if(0==strcmp(ps->data[i].name,name))
        {
            return i;
        }
    }
   return -1;
}//é uma fncao para implementar outra funcao declarada no header

/*void SortByName(struct Contact *ps)
{
    int i=0;
    int j=0;
    struct Contact tmp;
    for(i=0;i<ps->size-1;i++)
    {
        for(j=i+1;j<ps->size;j++)
        {
            if(strcmp(ps->data[i].name,ps->data[j].name)>0)
            {
                //For name
                strcpy(tmp.data->name,ps->data[i].name);
                strcpy(ps->data[i].name,ps->data[j].name);
                strcpy(ps->data[j].name,tmp.data->name);
                //For age
                tmp.data->age=ps->data[i].age;
                ps->data[i].age=ps->data[j].age;
                ps->data[j].age=tmp.data->age;
                //For sex
                strcpy(tmp.data->sex,ps->data[i].sex);
                strcpy(ps->data[i].sex,ps->data[j].sex);
                strcpy(ps->data[j].sex,tmp.data->sex);
                ///For tele
                strcpy(tmp.data->tele,ps->data[i].tele);
                strcpy(ps->data[i].tele,ps->data[j].tele);
                strcpy(ps->data[j].tele,tmp.data->tele);
                //For addr
                strcpy(tmp.data->addr,ps->data[i].addr);
                strcpy(ps->data[i].addr,ps->data[j].addr);
                strcpy(ps->data[j].addr,tmp.data->addr);
            }
        }
    }
}*/



void AddContact(struct Contact *ps)
{
    CheckCap(ps);
    printf("Name:->");
    getchar();
    scanf("%[^\n]%*c",ps->data[ps->size].name);
    printf("Age:->");
    scanf("%d",&(ps->data[ps->size].age));
    printf("Sex:->");
    getchar();
    scanf("%[^\n]%*c",ps->data[ps->size].sex);
    printf("Tel:->");
    scanf("%s",ps->data[ps->size].tele);
    printf("Address:->");
    getchar();
    scanf("%[^\n]%*c",ps->data[ps->size].addr);
    (ps->size)+=1;
    printf("Added with success\n");
     /*if(ps->size==MAX)
     {
        printf("Can't add more contact due to maximum memory configured\n");
     }
     else
     {
        printf("Name:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[ps->size].name);
        printf("Age:->");
        scanf("%d",&(ps->data[ps->size].age));
        printf("Sex:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[ps->size].sex);
        printf("Tel:->");
        scanf("%s",ps->data[ps->size].tele);
        printf("Address:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[ps->size].addr);
        (ps->size)+=1;
        printf("Added with success\n");
     }*/
}

void ShowContact(const struct Contact *ps)
{
    if(ps->size==0)
    {
        printf("Zero contact saved\n");
    }
    else
    {
        int i=0;
        printf("%-30s\t%-4s\t%-10s\t%-15s\t%-30s\n","Name:","Age:","Sex:","Tel:","Address:");
        for(i=0;i<(ps->size);i++)
        {
            printf("%-30s\t%-4d\t%-10s\t%-15s\t%-30s\n",ps->data[i].name,ps->data[i].age,ps->data[i].sex,ps->data[i].tele,ps->data[i].addr);
        }
    }
}

void  DeleteContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("Enter the name of person that you want to delete from your contact:->");
    getchar();
    scanf("%[^\n]%*c",name);
    //1.Found the index
    int pos=FindByName(ps,name);
    //2.Delete
    if(pos==-1)
    {
        printf("Contact don't saved\n");
    }
    else
    {
        int j=0;
        for(j=pos;j<(ps->size)-1;j++)
        {
            ps->data[j]=ps->data[j+1];
        }
        (ps->size)--;
        printf("Delete with success\n");
    }
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    int i=0;
    printf("Enter the name of the person that yout want to find;->");
    getchar();
    scanf("%[^\n]%*c",name);
    int pos=FindByName(ps,name);
    if(pos==-1)
    {
        printf("Contact don't saved\n");
    }
    else
    {
        printf("%-30s\t%-4s\t%-10s\t%-15s\t%-30s\n","Name:","Age:","Sex:","Tel:","Address:");
        printf("%-30s\t%-4d\t%-10s\t%-15s\t%-30s\n",ps->data[pos].name,ps->data[pos].age,ps->data[pos].sex,ps->data[pos].tele,ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("Enter the name of the person that you want to modify;->");
    getchar();
    scanf("%[^\n]%*c",name);
    int pos=FindByName(ps,name);
    if(pos==-1)
    {
        printf("Contact not saved\n");
    }
    else
    {
        printf("Name:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[pos].name);
        printf("Age:->");
        scanf("%d",&(ps->data[pos].age));
        printf("Sex:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[pos].sex);
        printf("Tel:->");
        scanf("%s",ps->data[pos].tele);
        printf("Address:->");
        getchar();
        scanf("%[^\n]%*c",ps->data[pos].addr);
        printf("Modified withc success\n");
    }
}

/*void SortContact(struct Contact *ps)
{
    SortByName(ps);
}*/

void DestroyContact(struct Contact *ps)
{
    free(ps->data);
    ps->data=NULL;
}

void SaveContact(struct Contact *ps)
{
    FILE *pfWrite=fopen("contact.dat","wb");
    if(pfWrite==NULL)
    {
        printf("SaveContact::%s\n",strerror(errno));
        return ;
    }
    int i;
    for(i=0;i<ps->size;i++)
    {
        fwrite(&(ps->data[i]),sizeof(struct PeoInfo),1,pfWrite);

    }


    fclose(pfWrite);
    pfWrite=NULL;
}

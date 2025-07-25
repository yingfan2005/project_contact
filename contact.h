#ifndef CONTACT_H
#define CONTACT_H
#define MAX 1000

#define MAX_NAME 30
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
 
enum Option
{
    EXIT,
    ADD,
    DELETE,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};
struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct Contact
{
    struct PeoInfo data[MAX];
    int size;//quantidade de contatos existentes
};
void InitContact(struct Contact *ps);
void AddContact(struct Contact *ps);
void ShowContact(const struct Contact *ps);
void  DeleteContact(struct Contact *ps);
void SearchContact(const struct Contact *ps);
void ModifyContact(struct Contact *ps);
void SortContact(struct Contact *ps);
#endif

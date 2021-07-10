#include <stdio.h>
#include <accctrl.h>
#include <time.h>
#include <assert.h>

typedef struct Node Node;
typedef struct student student;
typedef struct data_birth data_birth;
struct data_birth{
    int day;
    int month;
    int year;
};

struct student{
    char name[15];
    int id;
    data_birth data;
    int last_year_score;

};
struct Node{
    student item;
    Node *next;

};
Node* head = NULL;
Node* tail = NULL;

int counter=0;


void insert_First_linked_list( student element)
{
    Node *newNode; // declare a node
    newNode = (Node *)malloc(sizeof( Node));
    newNode->item = element;

    if (counter == 0)
    {
        head = tail = newNode;//
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    counter++;
}

void insert_End_linked_list(student element)
{
    Node *newNode; // declare a node
    newNode = (Node *)malloc(sizeof( Node));
    newNode->item= element;
    if (counter == 0) {
        head = tail = newNode;
        newNode->next = NULL;
    }
    else {
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
    counter++;
}


void insert_Atloc_linked_list(int loc, student element)
{
    if (loc < 0 || loc > counter)
        printf("out of range\n\n");
    else
    {
        Node *newNode; // declare a node
        newNode = (Node *)malloc(sizeof( Node));
        newNode->item = element;
        if (loc == 0) //insert at the begining
            insert_First_linked_list(element);
        else if (loc == counter) //insert at the end;
            insert_End_linked_list(element);
        else
        {
            Node *curr = head;
            for (int i = 1; i < loc; i++)
                curr = curr->next;

            newNode->next = curr->next;
            curr->next = newNode;
            counter++;
        }

    }
}
void print_Linked_list()
{
    Node *curr = head;

    int index=1;
    while (curr != NULL)

    {
        printf("The Name of Student (%d) : %s \n",index,curr->item.name);
        printf("The Id of Student (%d) : %d \n",index,curr->item.id);
        printf("The Birth day of Student (%d) : %d\\%d\\%d \n",index,curr->item.data.year,curr->item.data.month,curr->item.data.day);
        printf("The Last Year Score of Student (%d) :  %d \n",index,curr->item.last_year_score);
        printf("=================================\n");
        curr = curr->next;
        index++;
    }

}


int main (){

return 0 ;
}
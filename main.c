#include <stdio.h>
#include <accctrl.h>
#include <time.h>
#include <assert.h>
typedef struct Node Node;
typedef struct student student;
typedef struct data_birth data_birth;


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



student *arr;   //array to hold the arr elements
int length= 0;    //to store the length of the arr
int maxSize;    //to store the maximum size of the arr

void creat_arr (int size)
{

    if(size <= 0)
    {
        printf("wrong size\n");
        maxSize = 100;
    }
    else
        maxSize = size;


    arr = (student *) calloc(maxSize,sizeof(student ));
    assert(arr != NULL); //terminate if unable to allocate memory space
}

void reallocation(){
    maxSize++;
    arr = (student *) realloc(arr,maxSize*sizeof(student ));

}
boolean Is_Full()
{
    return (length == maxSize);
}


void Insert_At_array(int loc,  student element)
{
    if (Is_Full())
    {
        printf("your array is full , \n Do you want to expand size ? y/n \n");
        char chosed;
        while(1){
            scanf("%c", &chosed);
            if (chosed == 'Y' || chosed == 'y'){
                reallocation();
                break;
            }
            else if (chosed == 'n' || chosed == 'N')
            {
                printf("thank you\n");
                break;
            }
            else
                printf("pleas enter y or n  \n");

        }
        if (chosed == 'Y' || chosed == 'y')
        {
            for(int i = length; i > loc; i--)
                arr[i] = arr[i - 1];  //shift right

            arr[loc] = element;  //insert the item at the specified position
            length++;  //increment the length
        }
    }

    else if(loc < 0 || loc > length)
        printf("out of range\n\n");
    else
    {
        for(int i = length; i > loc; i--)
            arr[i] = arr[i - 1];  //shift right

        arr[loc] = element;  //insert the item at the specified position
        length++;  //increment the length
    }
}

void Insert_first_array( student element)
{
    if (Is_Full())
    {
        printf("your array is full , \n Do you want to expand size ? y/n \n");
        char chosed;
        while(1){
            scanf("%c", &chosed);
            if (chosed == 'Y' || chosed == 'y'){
                reallocation();
                break;
            }
            else if (chosed == 'n' || chosed == 'N')
            {
                printf("thank you\n");
                break;
            }
            else
                printf("pleas enter y or n  \n");

        }
        if (chosed == 'Y' || chosed == 'y')
            Insert_At_array(0, element );
    }
    else
        Insert_At_array(0, element );
}

void insert_End_Array(student element) {
    if (Is_Full())
    {
        printf("your array is full , \n Do you want to expand size ? y/n \n"); ///عايزين نعمل تزين  اوفر جدا
        char chosed;
        while(1){
            scanf("%c", &chosed);
            if (chosed == 'Y' || chosed == 'y'){
                reallocation();
                break;
            }
            else if (chosed == 'n' || chosed == 'N')
            {
                printf("thank you\n");
                break;
            }
            else
                printf("pleas enter y or n  \n");

        }
        if (chosed == 'Y' || chosed == 'y')
            arr[length++] = element;
    }
    else
        arr[length++] = element;


}
void print_Array()
{

    for(int i = 0; i < length; i++) {
        printf("The Name of Student (%d) : %s \n",i+1,arr[i].name);
        printf("The Id of Student (%d) : %d \n",i+1,arr[i].id);
        printf("The Birth day of Student (%d) : %d\\%d\\%d \n",i+1,arr[i].data.year,arr[i].data.month,arr[i].data.day);
        printf("The Last Year Score of Student (%d) :  %d \n",i+1,arr[i].last_year_score);
        printf("=================================\n");
    }
}



int main() {

    /// Test Time  Execution
    
    /// Test Time  Execution At First
/*
    student tS={"hassan",555,9,4,2000,3211};
    int start = clock();
    for (int i=0;i<1000;i++){
        insert_First_linked_list(tS);
    }
    int stop = clock();
    printf("Time To insert at first linked list in ms: %f\n",   (double)(stop - start)/ CLOCKS_PER_SEC);
    creat_arr(1000);
     start = clock();
    for (int i=0;i<1000;i++){
        Insert_first_array(tS);
    }
     stop = clock();
    printf("Time To insert at first Araay in ms: %f\n",   (double)(stop - start)/ CLOCKS_PER_SEC);


*/
///Test Time  Execution At End
/*
    student tS={"hassan",555,9,4,2000,3211};
    int start = clock();
    for (int i=0;i<1000;i++){
        insert_End_linked_list(tS);
    }
    int stop = clock();
    printf("Time To insert at End linked list in ms: %f\n",   (double)(stop - start)/ CLOCKS_PER_SEC);
    creat_arr(1000);
    start = clock();
    for (int i=0;i<1000;i++){
        insert_End_Array(tS);
    }
    stop = clock();
    printf("Time To insert at End Array in ms: %f\n",   (double)(stop - start)/ CLOCKS_PER_SEC);
*/
/// Test Time  Execution Al loc

/*
    student tS={"hassan",555,9,4,2000,3211};
    for (int i=0;i<1000;i++){
        insert_First_linked_list(tS);
    }

    creat_arr(2000);
    for (int i=0;i<1000;i++){
        Insert_first_array(tS);
    }

    int start = clock();
    for (int i=0;i<1000;i++){
        insert_Atloc_linked_list(500+i,tS);
    }

    int stop = clock();
    printf("Time To insert at End linked list in ms: %f\n", (double)(stop - start)/ CLOCKS_PER_SEC);
    start = clock();
    for (int i=0;i<1000;i++){
        Insert_At_array(500+i,tS);
    }
    stop = clock();
    printf("Time To insert at End Array in ms: %f\n",   (double)(stop - start)/ CLOCKS_PER_SEC);
*/


    printf("\nHello Embadded !\n");

    int N;
    printf("enter the number of students\n");
    scanf("%d", &N);


    printf("\nwill you use linked list or dynamic array ? !\n");
    printf("\npress A for dynamic array\n");
    printf("\npress L for linked list \n");

    char chosed_methode;
    scanf("%c", &chosed_methode);
    scanf("%c", &chosed_methode);

    if (chosed_methode == 'l' || chosed_methode == 'L') {
        for (int m = 0; m < N; m++) {
            student s;
            printf("if you want to add in First press F \n");
            printf("if you want to add in End press E \n");
            printf("if you want to add in Mid press M \n");

            char x;
            scanf("%c", &x);
            scanf("%c", &x);
            if (x == 'F' || x == 'f') {
                printf("enter the name of student\n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth \n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score \n");
                scanf("%d", &s.last_year_score);


                insert_First_linked_list(s);


            } else if
                    (x == 'E' || x == 'e') {
                printf("enter the name of student \n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth\n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score \n");
                scanf("%d", &s.last_year_score);

                insert_End_linked_list(s);
            } else if(x == 'M' || x == 'm') {

                printf("enter the name of student \n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth \n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score \n");
                scanf("%d", &s.last_year_score);
                printf("\nenter the loc in linked_list \n");
                int p;
                scanf("%d", &p);

                insert_Atloc_linked_list(p, s);
            }


        }


        print_Linked_list();
    }

    else if (chosed_methode == 'a' || chosed_methode == 'A')
    {
        creat_arr(N);
        for (int m = 0; m < N; m++) {
            student s;
            printf("if you want to add in First press F \n");
            printf("if you want to add in End press E \n");
            printf("if you want to add in Mid press M \n");

            char x;
            scanf("%c", &x);
            scanf("%c", &x);

            if (x == 'F' || x == 'f') {
                printf("enter the name of student \n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth \n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score \n");
                scanf("%d", &s.last_year_score);

                Insert_first_array(s);
            } else if
                    (x == 'E' || x == 'e') {
                printf("enter the name of student \n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth \n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score\n ");
                scanf("%d", &s.last_year_score);

                insert_End_Array(s);

            } else if
                    (x == 'M' || x == 'm') {

                printf("enter the name of student \n");
                scanf("%s", &s.name);
                printf("enter the id of student \n");
                scanf("%d", &s.id);
                printf("enter the day of birth \n");
                scanf("%d", &s.data.day);
                printf("enter the month of birth \n");
                scanf("%d", &s.data.month);
                printf("enter the year of birth \n");
                scanf("%d", &s.data.year);
                printf("enter last_year_score \n");
                scanf("%d", &s.last_year_score);

                printf("\n enter the loc in linked_list \n");
                int p;
                scanf("%d", &p);

                Insert_At_array(p, s);

            }

        }
        print_Array();
    }
    else {
        printf("\ninvalid choice \n");
    }

    return 0;

}
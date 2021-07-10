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
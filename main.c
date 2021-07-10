#include <stdio.h>

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

int main (){

return 0 ;
}
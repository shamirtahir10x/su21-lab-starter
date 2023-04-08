#include <stdio.h>

struct Student {
    char name[50];
    int id;
    int age;
};

int main() {
    struct Student student1;
    
    printf("Name of student: ");
    scanf("%s", student1.name);
    
    printf("ID of student: ");
    scanf("%d", &student1.id);
    
    printf("Age of student: ");
    scanf("%d", &student1.age);
    
    printf("Name: %s\n", student1.name);
    printf("ID: %d\n", student1.id);
    printf("Age: %d\n", student1.age);
    
    return 0;
}
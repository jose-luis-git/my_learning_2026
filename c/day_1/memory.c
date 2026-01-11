#include<stdio.h>
#include<stdlib.h>

void change(int*, int*);
void average_array(int*,int);

int main(){
    int a, b;

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("\n\t.:Before the fucntion:.\n");
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("\t.:After the function:.\n");
    change(&a, &b);
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);

    int size;
    printf("Enter the array size: ");
    scanf("%d", &size);

    int *array = malloc(sizeof(int) * size);


    for(int i=0;i<size;i++){
        printf("Enter a number: ");
        scanf("%d", array + i);
    }


    printf("\nArrangement numbers\n");
    for(int i=0;i<size;i++){
        printf("Number: %d\n", *(array + i));
    }

    average_array(array, size);

    free(array);

    return 0;
}
void change(int*a, int*b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
void average_array(int*array,int size){
    float average = 0;
    int sum=0;

    for(int i=0;i<size;i++){
        sum += *(array + i);
    }
    average = (float)sum / size;
    printf("The average of the array is: %.2f\n", average);
}

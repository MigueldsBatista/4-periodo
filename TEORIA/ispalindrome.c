#include <stdio.h>


int is_palindrome(char *arr, int size){
    char foward_symbol;
    char backwards_symbol;

    for (int i = 0, j = size; i < size && j > 0; i++, j--){
        foward_symbol = arr[i];
        backwards_symbol = arr[j];
        if(foward_symbol != backwards_symbol){
            return 0;
        }
    }
    return 1;
}
// char* reverse(char *arr, int size){
//     char reversed[size];
//     char backwards_symbol;

//     for (int i = 0, j = size; i < size && j > 0; i++, j--){
//         backwards_symbol = arr[j];
//         reversed[i]=backwards_symbol;
//     }
//     return reversed;
// }

void display(int is_pal){
    switch (is_pal)
    {
    case 1:
        printf("True\n");
        break;
    case 0:
    printf("False\n");
    break;
    default:
        break;
    }
}

int len(char *arr){
    int size = 0;
    while(arr[size] != '\0') {
        size++;
    }
    return size-1;
}

int main(){

    char arr[100];

    scanf("%s", arr);

    int is_pal = is_palindrome(arr, len(arr));
    // char *reversed = reverse(arr, len(arr));
    // printf("%s", reversed);
    display(is_pal);

    return 0;
}
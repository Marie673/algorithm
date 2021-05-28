#include <stdio.h>
#include <stdlib.h>

int num;

unsigned int func(unsigned int n){
    unsigned int result = 1;
    if(n > 0){
        result = func(n-1) * 10;
    }

    return result;
}

char* plus(int n, char a[]) {
    char *result;
    result = (char *) malloc(sizeof(char) * num);

    if(a[n] == '9') {
        a[n] = '0';
        return plus(n-1, a);
    }
    else {
        a[n]++;
        result = a;
    }
    return result;
}

int main(){
    char *a;
    unsigned int time;

    scanf("%d", &num);
    time = func(num);

    a = (char*)malloc(sizeof(char)*(num+1));
    for(int i = 0; i < num; i++) {
        a[i] = '0';
    }
    a[num] = '\0';

    for(int i = 0; i < time; i++){
        /*
        for(int j = 0; j < num; j++) {
            printf("%c", a[j]);
        }
         */
        printf("%s", a);
        a = plus(num-1, a);
        printf("\n");
    }


    return 0;
}

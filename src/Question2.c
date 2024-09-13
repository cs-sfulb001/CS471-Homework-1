#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int sumton(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
int sumtoncubed(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+(i*i*i);
    }
    return sum;
    }


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int x = 0;
    if(n==0){
        printf("Input an integer greater than 0\n");
        return 0;
    }
    printf("n = %d\n", n);
    pid_t Child_1 = fork();
    pid_t Child_2;
    if(Child_1!=0) //Stop Child_1 from making a fork
        Child_2 = fork();
    if(Child_1==0){
        printf("The sum of the first %d natrual numbers is %d\n", n, sumton(n));
    }
    else if(Child_2==0){
        printf("The sum of the first %d natrual numbers cubed is %d\n", n, sumtoncubed(n));

    }
    else{
        wait(NULL);
        wait(NULL);
        printf("The end of the program\n");
    }
    return 0;
}
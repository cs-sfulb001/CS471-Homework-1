#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int elements[]={20, 18, 16, 14, 12, 10, 8, 6, 4, 2, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2};
    int n=0;
    pid_t p=getppid();
    for(int i=0;i<5;i++){
        if(p!=0) {
            p=fork();
            n++;
        }
    }
    if(p==0)n--;
    printf("line\n");
    printf("%d\n", n);
    int sum=0;
    if(p==0){
        for(int i=n*4; i<((n+1)*4);i++){
            sum+=elements[i];
        }
        return sum;
    }
    else{
        for(int i=0;i<5;i++){
            int status;
            wait(&status);
            sum+=WEXITSTATUS(status);
        }
    }
    printf("The sum is %d", sum);
}
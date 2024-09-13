#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int elements[]={20, 18, 16, 14, 12, 10, 8, 6, 4, 2, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2};
    int n=0;
    int p[2];
    if(pipe(p)==-1){
        printf("Pipe Failed");
        return 1;
    }
    pid_t pid=getppid();
    for(int i=0;i<5;i++){
        if(pid!=0) {
            pid=fork();
            n++;
        }
    }
    if(pid==0)n--;
    printf("line\n");
    printf("%d\n", n);
    int sum=0;
    if(pid==0){
        close(p[0]);
        for(int i=n*4; i<((n+1)*4);i++){
            sum+=elements[i];
        }
        printf("%d thread pushing %d into pipe\n", n, sum);
        char pinput[3];
        if(sum>0){
            sprintf(pinput, "+%d", sum);
        }
        else{
            sprintf(pinput, "%d", sum);
        }
        write(p[1], pinput, strlen(pinput));
        close(p[1]);
        return 0;
    }
    else{
        close(p[1]);
        while(wait(NULL)!=-1){}
        printf("Reading from pipe\n");
        for(int i=0;i<5;i++){
            char value[3];
            read(p[0], value, 3);
            printf("%s\n", value);
            sum+=atoi(value);
        }
        printf("Done reading\n");
        close(p[0]);
    }
    printf("The sum is %d\n", sum);
}
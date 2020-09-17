#include<stdio.h>
#include<climits>

int main(){
    int t=3,N;
    int ss=-1%100;
    printf("%d",ss);

    while(t--){
        long long S=0;
        int overflow=0;
        scanf("%d",&N); //data 개수
        while(N--){
                 //overflow counter
            //+ 오버플로우나면 무조건 +고, - 오버플로우나면 무조건 -인가??
            long long temp;
            scanf("%lld",&temp);    //longlong최댓값 부여
            if(S>0 && temp>LLONG_MAX-S && temp>0){    //+overflow occured
                overflow++;
                S+=temp;
            }  
            else if(S<0 && temp<LLONG_MIN-S && temp<0){ //-overflow occured
                overflow--;
                S+=temp;
            }
            else S+=temp;
            
        }
        if(overflow>0)  printf("+\n");
        else if(overflow<0) printf("-\n");
        else{
            if(S>0) printf("+\n");
            else if(S<0)   printf("-\n");
            else    printf("0\n");
        }
        
    }
    return 0;
}
#include<iostream>
#define MAX_COST 1000*20
using namespace std;


int main(){

    int caseNum;
    cin>>caseNum;

    while(caseNum--){
        int num_of_bricks;
        cin>>num_of_bricks;

        int dp[num_of_bricks+1][num_of_bricks*1000+1];
        int w[num_of_bricks],c[num_of_bricks];
        int sum=0;
        for(int i=0;i<num_of_bricks;i++){
            cin>>w[i]>>c[i];
            sum+=w[i];
        }

        for(int i=0;i<num_of_bricks+1;i++){
            for(int j=0;j<num_of_bricks*1000+1;j++){
                dp[i][j] = MAX_COST;
            }
        }
        dp[0][0]=0;
        dp[1][w[0]] = c[0];

        for(int n=1;n<num_of_bricks;n++)
            for(int i=num_of_bricks;i>0;i--)
                for(int j=w[n];j<=sum;j++)
                    dp[i][j] = min(dp[i][j],dp[i-1][j-w[n]]+c[n]);

        int request_num;
        cin>>request_num;

        while(request_num--){
            int M,C_min,C_max;

            cin>>M>>C_min>>C_max;
            if(C_min>C_max){
                cout<<"impossible"<<endl;
                continue;
            }

            C_min*=M;
            C_max*=M;
            int min_cost=MAX_COST;
            for(int i=C_min;i<=C_max&&i<=sum;i++){
                min_cost = min(min_cost,dp[M][i]);
            }


            if(min_cost == MAX_COST)
                cout<<"impossible"<<endl;
            else
                cout<<min_cost<<endl;
        }
        if(caseNum)
            cout<<endl;
    }
    return 0;
}

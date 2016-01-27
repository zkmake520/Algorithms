#include<iostream>

#include<string>

#include <algorithm>

#include<stdlib.h>

#include<math.h>

#include<fstream>
#include<cmath>
using namespace std;


int main(){
    
    //Initialize
    
    double Smax = 100; //maximum stock price
    
    int M =20;
    
    int N =10;
    
    double dS = Smax/M; // increment of stock price
    
    double T=5.0/12; //maturity date
    
    double dT = T/N; //time step
    
    double K = 50; //strike price
    
    double r = 0.10;
    
    double Sigma = 0.4;
    
    double S0 = 50;
    
    
    
    
    
    double a[M+1]; double b[M+1]; double c[M+1];double tmp[M+1];
    
    for (int j = 1; j <= M-1; j++) {
        
        a[j] = 0.5*r*dT*j - 0.5*Sigma*Sigma*dT*j*j;
        
        c[j] = -0.5*r*dT*j - 0.5*Sigma*Sigma*dT*j*j;
        
        b[j]= 1+Sigma*Sigma*j*j*dT + r*dT;
        
    }
    
    float put[N+1][M+1];
    
    for (int j=0;j<=M;j++){
        
        put[N][j]=std::max((K-j*dS),0.0);
        
    }
    
    for (int i=0;i<=N;i++){
        
        put[i][0]=K;
        
        put[i][M]=0;
        
    }
    
    
    
    double B[M+1][M+1];
    
    for (int i=1;i<=M-1;i++){
        
        for (int j=1;j<=M-1;j++){
            
            B[i][j]=0;
            
        }
        
    }
    
    B[1][1]=b[1]; B[1][2]=c[1];
    
    B[M-1][M-2]=a[M-1];B[M-1][M-1]=b[M-1];
    
    for (int j=2; j<M-1;j++) {
        
        B[j][j-1]=a[j];B[j][j]=b[j];B[j][j+1]=c[j];
        
    }
    
    double aa[M][2*M];
    
    double BI[M][M];
    
    for (int i=1;i<=M-1;i++){
        
        for (int j=1;j<=M-1;j++)
            
            aa[i][j]=B[i][j];
        
    }
    
    for(int i=1;i<=M-1;i++)
        
    {
        
        for(int j=M-1+1;j<=(M-1)*2;j++){ aa[i][j]=(j-i==M-1)?(1.0):(0.0);}
        
    }
    
    for(int i=1;i<=M-1;i++)
        
    {
        
        if(aa[i][i]!=1.0)
            
        {
            
            double temp=aa[i][i];
            
            aa[i][i]=1.0;
            
            for(int j=i+1;j<=(M-1)*2;j++)
                
                aa[i][j]/=temp;
            
        }
        
        for(int k=1;k<=M-1;k++)
            
        {
            
            if(i!=k)
                
            {
                
                double temp=aa[k][i];
                
                for(int j=1;j<=(M-1)*2;j++)
                    
                    aa[k][j]-=(temp*aa[i][j]);
                
            }
            
            else continue;
            
        }
        
    }
    
    for(int i=1;i<=M-1;i++)
        
    {
        
        for(int j=M-1+1;j<=(M-1)*2;j++){
            
            BI[i][j-M+1]=aa[i][j];
            
        }
        
    }
    
    double x;
    
    for (int i=N-1;i>=0;i--){
        
        for (int j=1;j<=M;j++){
            
            tmp[j]=put[i+1][j];
            
        }
        
        tmp[1]=tmp[1]-a[1]*K;
        
        
        
        for (int k=1;k<=M-1;k++)	 {
            
            x=0;
            
            for (int j=1;j<=M-1;j++){
                
                x=x+BI[k][j]*tmp[j];
                
            }
            
            //  put[i][k]=std::max(x,K-dS*k);
            
            put[i][k]=x;
            
        }
        
    }
    
    int l=S0/dS;
    
    double Euro = put[0][l];
    double d1 = (log(S0/K)/log(10) + (r+Sigma*Sigma/2)*T)*(1.0/(Sigma*sqrt(T)));
    double d2 = d1 - Sigma*sqrt(T);
    double Euro2 = K*exp(-r*T)*cdf(-d2,0,1)-S0*cdf(-d1,0,1);
    cout<<Euro<<endl;
    cout<<Euro2<<endl;
    return 0;
    
}



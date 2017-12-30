#include<iostream>
#include<cstring>
using namespace std;
#define M  100    
int Work[M],Finish[M],Max[M][M],Allocation[M][M],Need[M][M]; 

/*
原始数据：

3

4

3 2 2
6 1 3
3 1 4
4 2 2

1 0 0 
5 1 1
2 1 1
0 0 2

1 1 2

安全


3

4

3 2 2
6 1 3
3 1 4
4 2 2

2 0 1 
5 1 1
2 1 1
0 0 2

0 1 1

不安全 

*/

int main(){
	
	memset(Work,0,sizeof(Work));
	memset(Finish,0,sizeof(Finish));
	
	int m,n;
	int i;
	
	cout<<"请输入m:";
	cin>>m;
	
	cout<<"请输入n:";
	cin>>n;
	
	cout<<"请输入Max矩阵:"<<endl;
	for(i=0;i<n;i++) 
	  for(int j=0;j<m;j++)
	    cin>>Max[i][j];
	    
	cout<<"请输入Allocation矩阵:"<<endl;
	for(i=0;i<n;i++) 
	  for(int j=0;j<m;j++)
	    cin>>Allocation[i][j];
	    
	for(i=0;i<n;i++)
	  for(int j=0;j<m;j++)    
	    Need[i][j]=Max[i][j]-Allocation[i][j];
	
	int Available[M];
	cout<<"请输入Available向量:"<<endl;
	for(i=0;i<m;i++) cin>>Available[i];
	for(i=0;i<m;i++) Work[i]=Available[i];
	
	int count=1;
	int count2=0;
	
	cout<<"    Work       Need     Allocation    Work+Allocation "<<endl; 
	
	int flag3;
	while( count>0 ){
	 count=0;
	 count2=0;
	 i=0;
	 flag3=1;
	 
	 //打印表格 
	 cout<<"   ";
	 for(int uu=0;uu<m;uu++) cout<<Work[uu]<<" ";
	   cout<<"      "; 
	 
	 while( i<n ){
		
		int flag=1;
		for(int j=0;j<m;j++){
			if( Need[i][j] >Work[j] ){
				flag=0;
				break;
			}
		}
		
		if( Finish[i]==0 && flag==1 && flag3==1 ){
		  flag3=0;
		  count++;
		  
		  for(int uu=0;uu<m;uu++) cout<<Need[i][uu]<<" ";
		  
		  cout<<"      ";
		  
		  for(int uu=0;uu<m;uu++) cout<<Allocation[i][uu]<<" ";
		  
		  cout<<"      ";
		  
		  for(int j=0;j<m;j++){
		  	Work[j]+=Allocation[i][j];
		  }
		  Finish[i]=1;	
		}
		if( Finish[i]==1 ) count2++;//统计未结束的机器数量 
		i++;
	 }
	 
	 //打印结果
	 if(!count)  cout<<"                        ";
	 for(int uu=0;uu<m;uu++) cout<<Work[uu]<<" ";
	 cout<<endl;
	 
    }
    
	if(count2==n){
		cout<<"系统处于安全状态."<<endl; 
	}else{
		cout<<"系统不处于安全状态."<<endl;
	}
	
	return 0;
} 

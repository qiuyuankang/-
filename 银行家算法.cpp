#include<iostream>
#include<cstring>
using namespace std;
#define M  100    
int Work[M],Finish[M],Max[M][M],Allocation[M][M],Need[M][M]; 

/*
ԭʼ���ݣ�

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

��ȫ


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

����ȫ 

*/

int main(){
	
	memset(Work,0,sizeof(Work));
	memset(Finish,0,sizeof(Finish));
	
	int m,n;
	int i;
	
	cout<<"������m:";
	cin>>m;
	
	cout<<"������n:";
	cin>>n;
	
	cout<<"������Max����:"<<endl;
	for(i=0;i<n;i++) 
	  for(int j=0;j<m;j++)
	    cin>>Max[i][j];
	    
	cout<<"������Allocation����:"<<endl;
	for(i=0;i<n;i++) 
	  for(int j=0;j<m;j++)
	    cin>>Allocation[i][j];
	    
	for(i=0;i<n;i++)
	  for(int j=0;j<m;j++)    
	    Need[i][j]=Max[i][j]-Allocation[i][j];
	
	int Available[M];
	cout<<"������Available����:"<<endl;
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
	 
	 //��ӡ��� 
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
		if( Finish[i]==1 ) count2++;//ͳ��δ�����Ļ������� 
		i++;
	 }
	 
	 //��ӡ���
	 if(!count)  cout<<"                        ";
	 for(int uu=0;uu<m;uu++) cout<<Work[uu]<<" ";
	 cout<<endl;
	 
    }
    
	if(count2==n){
		cout<<"ϵͳ���ڰ�ȫ״̬."<<endl; 
	}else{
		cout<<"ϵͳ�����ڰ�ȫ״̬."<<endl;
	}
	
	return 0;
} 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){

// int data[32];
int data[10]={1,1,1,0,1,1,0,1};
int r=4,m=8,j=0,k=0,i;
int a[m+r+1];
// char s[32];
// printf("enter the data\n");
// scanf("%d",s);


// for(i=0;i<strlen(s);i++){
// 	data[i]=s[i]-48;
// }

// for(i=0;i<strlen(s);i++){
// 	printf("%d \n",data[i] );
// }

for ( int i=1 ; i<m+r+1 ; ++i ){
	if(i== (int)pow(2,j)){
		a[i]=2;
		j++;
	}else{
		a[i]=data[k];
		k++;
	}	
}
k=1;
for(i=1;i<m+r+1 ;i++){
	
	if(a[i]==2 ){
		int count=0;
		int flag=0;

		printf("for i=%d\n",i );
		for(j=i ; j<m+r+1 ; j++){
			
			if(j%(int)(pow(2,k-1))==0)
				flag++;

			if(i!=j){
				if(flag%2==1){
					printf("%d ",j);
					if(a[j]==1)
					count++;
				}
			}

		}

		k++;
		if(count%2==0)
			a[i]=0;
		else
			a[i]=1;

		printf("\n");
	}

}


for(i=1;i< m+r+1 ;i++){
	printf("%d ",a[i]);

}




}

 

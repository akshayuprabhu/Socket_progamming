//remote procedure call program:fileclient.cc
#include <math.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#define SERV_PORT 5576
main(int argc,char **argv)
{
int i,j;
ssize_t n;
char filename[180],recvline[180];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

printf("The data to be sent is 1 1 1 0 1 1 0 1\n");

int data[10]={1,1,1,0,1,1,0,1};
int r=4,m=8,k=0;
j=0;
int a[m+r+1];
char s[32];
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

printf("the data after converting\n");
for(i=1;i< m+r+1 ;i++){
	printf("%d ",a[i]);
	if(a[i]==0)
		filename[i]='0';
	else
		filename[i]='1';
}

write(sockfd,filename,1000);

close(sockfd);

}
 

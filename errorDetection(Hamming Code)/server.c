#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#define SERV_PORT 5576

int main(int argc,char **argv){

	int i,j;
	ssize_t n;
	FILE *fp;
	int m=8,r=4,k=0;
	char s[180],f[180];
	int a[m+r+1];
	int error[10];
	int z=0;

	struct sockaddr_in servaddr,cliaddr;

	int listenfd,connfd,clilen;

	listenfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,1);

	clilen=sizeof(cliaddr);
	connfd=accept(listenfd,(struct sockaddr*) &cliaddr,&clilen);

	printf("client connected \n");
	read(connfd,f,90);
	// strcat(f,"> fileStorage");
	// system(f);
	printf("\n The data recieved from the client is:\n");

	// add this to detect error
	// f[4]='0';

	for(i=1;i<=12;i++){
		printf("%c ",f[i]);
	}

	a[0]=0;
	for ( int i=1 ; i<m+r+1; ++i ){

		if(i== (int)pow(2,j)){
			a[i]=2;
			j++;
		}else{
			a[i]=0;
		}	
	}

	printf("the array a is \n");
	for (int i = 1; i < m+r+1; ++i)
		printf("%d ",a[i] );

	for(int i=1;i<=12;i++){
		
		if(a[i]==2 ){
			int count=0;
			int flag=0;

			printf("\nthe first error bit is ");
			
			for(j=i ; j<m+r+1 ; j++){	
				if((j % (int)pow(2,k)) == 0)
					flag++;
					if(flag%2==1){
						if(f[j]=='1')
						count++;
						// printf("%d f[j]=%c count=%d ",j,f[j],count);

					}
			}

			k++;
			if(count%2==0){
				error[z]=0;
				z++;
				printf("no error");
			}else{
				error[z]=1;
				z++;
				printf("error");
			}
			// printf("error[%d]=%d ",z,error[z]);
			

		printf("\n");
	}

	}
	printf("hi4\n");

	// printf("the error bits are\n");
	// for(i=0;i<4;i++){
	// 	printf("%d ",error[i]);
	// }

	close(listenfd);
	fclose(fp);
} 
 

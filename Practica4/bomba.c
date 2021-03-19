// gcc -m32 bomba.c -o bomba


#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

char cifrada[]="durnadcpaus\n";	// burladapass
int  passcode  = 67645;		// 35291

void boom(){
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	exit(-1);
}

void defused(){
	printf("*************************\n");
	printf("*** bomba desactivada ***\n");
	printf("*************************\n");
	exit(0);
}

void cifrar( char palabra[] ){
	for( int i=0; i<strlen(cifrada)-1; i++ ){
		if( i % 3 == 0 )
			palabra[i] = palabra[i]+2;
	} 	
}

int cifrar_numero( int pasv ){
	return pasv + 32354;
}



int main(){
#define SIZE 100
	char password[SIZE];
	int  passvalue;
#define TLIM 5
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1,NULL);

	printf("Introduce la contraseña: ");
	fgets(password,SIZE,stdin);
	cifrar(password);
	


	if (strncmp(password,cifrada,strlen(cifrada)))
	    boom();

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    boom();

	printf("Introduce el código: ");
	scanf("%i",&passvalue);

	passvalue = cifrar_numero(passvalue);	
	
	if (passvalue!=passcode){
 		boom();
	}


	gettimeofday(&tv1,NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
	    boom();

	defused();

	
}

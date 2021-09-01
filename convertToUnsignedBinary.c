#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void iToB(long int n, int bit){
	int b[bit];
	int counter = bit -1;


	for(int i = 0; i < bit; i++){
		b[i] = 0;
	}
	
	
	while(n != 0){
		b[counter]  = n%2;
		n= n/2;
		counter--;
	}
	

	for(int i = 0;i<bit;i++){
		printf("%d",b[i]);

	}
	printf("\n");

}


int main(int argc, char* argv[argc+1]){
	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}
	
	FILE* fp = fopen(argv[1],"r");
	unsigned long int decimal;
	int bit;

	while(fscanf(fp, "%ld %d\n",&decimal,&bit) != EOF){
						
			iToB(decimal,bit);	

	}
	fclose(fp);
	return EXIT_SUCCESS;
}

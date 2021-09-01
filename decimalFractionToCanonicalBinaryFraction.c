#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void toBinary(double n,int bit){
	n = n-1;
	int count = 0;
	printf("1.");
	while(n!=0){	
		
		n = n*2;
		if(n>=1){
			n = n-1;
			printf("1");
		}else{
			printf("0");
		}
		count++;
		if(count == bit){
			break;
		}
	}
	while(count < bit){
		printf("0");
		count++;	
	}
	

	
	printf(" ");
	return;

}
int main(int argc, char* argv[argc+1]){
	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}
	
	FILE* fp = fopen(argv[1],"r");

	double num;
	int bit;
	
	while(fscanf(fp,"%lf %d\n",&num, &bit) != EOF){

		int expo = 0;
		if(num>1){
			while(num > 2){
				num = num / 2;
				expo++;
			}			
		}else{
			while(num < 1){ //might need to make one inclusive
				num = num * 2;
				expo--;
			}
		}
	
		toBinary(num,bit);
		printf("%d\n", expo);

	}
	
	fclose(fp);
	//toBinary(0.25,3);
}

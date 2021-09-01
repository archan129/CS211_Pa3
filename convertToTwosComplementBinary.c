#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int bits(long int n){
	if(n < 0){
		n = n * -1;
	}
	int count = 0;
	while(n!=0){
		n = n / 2;
		count++;
	}
	
	return count;	
}

void iToB(long int n, int bit){
	int b[bit];
	int counter = bit - 1;
	long int temp = n;

	if(n < 0){
		n = n * -1;
	}
	for(int i = 0; i < bit; i++){
		b[i] = 0;
	}
	if(n == 0){
	
		for(int i = 0;i<bit;i++){
			printf("%d",b[i]);

		}
		printf("\n");
		return;
	
	}else if(n == 1){
		for(int i = 0;i<bit-1;i++){
			printf("%d",b[i]);
		}
		
		printf("1\n");
		return;
	}
	
	
	while(n != 0){
		b[counter]  = n % 2;
		n= n/2;
		counter--;
	}

	
	
	if(temp >= 0 && bits(temp) < bit){   //if positive and required bits is less that given, then its just 
		for(int i = 0;i<bit;i++){ //unsigned binary
			printf("%d",b[i]);
		}
		printf("\n");
		return;
	}
	if(bits(temp) >= bit){ //if required bits > given bits, first bit is sign and rest are ones
		if(temp < 0){
			b[0] = 1;
			for(int i = 1; i<bit;i++){
				b[i] = 0;	
			}	
		}else{
			b[0] = 0;
			for(int i = 1; i<bit;i++){
				b[i] = 1;	
			}
		}
		
		for(int i = 0;i<bit;i++){
			printf("%d",b[i]);

		}
		printf("\n");
		return;
	}
	
	if(temp < 0){
		b[0] = 1;
		for(int i = 1; i < bit; i++){
			if(b[i] == 1){
				b[i] = 0;			
			}else{
				b[i] = 1;
			}
		}
		
	
		for(int i = bit-1; i>0;i--){
			if(b[i] == 0){
				b[i] = 1;
				break;	
			}else{
				b[i] = 0;
				
			}
		}
		for(int i = 0;i<bit;i++){
			printf("%d",b[i]);

		}
		printf("\n");
		return;
	}
	
	

	

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

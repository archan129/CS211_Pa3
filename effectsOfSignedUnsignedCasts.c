#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void unsignedToSigned(long int n, int bit){
	int b[bit];
	int counter = bit -1;


	for(int i = 0; i < bit; i++){ //convert to unsigned binary
		b[i] = 0;
	}
	
	
	while(n != 0){
		b[counter]  = n%2;
		n= n/2;
		counter--;
	}
	

	
	long int decimal = 0; //converting back to decimal
	long int t = 0;
	for(int i = bit-1;i>0;i--){
		if(b[i] == 1){
			t = 1;
			for(int j = 0; j<bit-(i+1); j++){
				t = t * 2;
			}	
			decimal+=t;
		}
	}

	if(b[0] == 1){
		int x = 1;
		for(int i = 0; i < bit-1; i++){
			x = x * 2;	
		}
		decimal-=x;
	}
	
	printf("%ld\n", decimal); 
}

void signedToUnsigned(long int n, int bit){
	int b[bit];
	int counter = bit -1;
	if(n>=0){
		printf("%ld\n",n);
		return;
	}
	if(n<0){ //make it positive
		n = n*-1;
	}
	

	for(int i = 0; i < bit; i++){ //convert to unsigned binary
		b[i] = 0;
	}
	
	
	while(n != 0){
		b[counter]  = n%2;
		n= n/2;
		counter--;
	}
 
	//b[0] = 1;       		
	for(int i = 1; i < bit; i++){	//inverting all bits
		if(b[i] == 1){
			b[i] = 0;			
		}else{
			b[i] = 1;
		}
	}
	
	
	for(int i = bit-1; i>0;i--){ //adding one to the binary
		if(b[i] == 0){
			b[i] = 1;
			break;	
		}else{
			b[i] = 0;
			
		}
	}
	
	
	long int decimal = 0;  //converting back to decimal
	long int t = 0;
	for(int i = bit-1;i>=0;i--){ //	for(int i = bit-1;i>=ptr;i--){
		if(b[i] == 1){
			t = 1;
			for(int j = 0; j<bit-(i+1); j++){
				t = t * 2;
			}	
			decimal+=t;
		}
	}

	printf("%ld\n", decimal);
	
	
}


int main(int argc, char* argv[argc+1]){
	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}
	
	FILE* fp = fopen(argv[1],"r");
	unsigned long int decimal;
	int bit;
	char src;
	char dest;

	while(fscanf(fp, "%ld %d %c %c\n",&decimal,&bit,&src,&dest) != EOF){
		if(dest == 's'){
			unsignedToSigned(decimal,bit);	
		}else{
			signedToUnsigned(decimal,bit+1);
		}				
			

	}
	fclose(fp);
	return EXIT_SUCCESS;
}

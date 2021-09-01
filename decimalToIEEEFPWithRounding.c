#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int arr[100];

int toBinary(float n,int eBits,int bit){
	n = n-1;
	int count = 0;
	int b[bit+3];
	for(int i = 0; i<bit+3;i++){
		b[i] = 0;
	}
	int u = 1;
	while(n!=0){	
		
		n = n*2;
		if(n>=1){
			n = n-1;
			b[count] = 1;
		}else{
			b[count] = 0;
		}
		count++;
		
		if(count == bit+3){
			break;			
		}
	}

	while(count < bit+3){
		b[count] = 0;
		count++;	
	}
	
	
	
	if(b[bit] == 1 && (b[bit+1] != 0 || b[bit+2] != 0)){
		for(int i = bit-1; i>=0;i--){
			if(b[i] == 1){
				b[i] = 0;		
			}else if(b[i] == 0){
				b[i] = 1;
				break;	
			}
		}
	}else if(b[bit] == 1 && b[bit-1] == 1 && (b[bit] != 0 || b[bit+1] != 0)){
		u = 0;
		for(int i = bit-1; i>=0;i--){
			if(b[i] == 1){
				b[i] = 0;		
			}else if(b[i] == 0){
				b[i] = 1;
				u = 1;
				break;	
			}
		}
	}
		

		
	
	
	for(int i = 0; i<bit;i++){
		arr[1+i+eBits] = b[i]; 
		
	}
	

	

	return u;

}



void iToB(long int n, int bit){
	int b[bit];
	int counter = bit - 1;


	for(int i = 0; i < bit; i++){
		b[i] = 0;
	}
	
	
	while(n != 0){
		b[counter]  = n%2;
		n= n/2;
		counter--;
	}
	

	for(int i = 0;i<bit;i++){
		//printf("%d",b[i]);
		arr[i+1] = b[i];

	}


}
int main(int argc, char* argv[argc+1]){

	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}

	FILE* fp = fopen(argv[1],"r");

	double num;
	int bit;
	int exponent;
	int mantissa;
	
	


	while(fscanf(fp,"%lf %d %d %d\n",&num, &bit, &exponent, &mantissa) != EOF){
		//int ar[bit];
		//arr = ar;
		if(num < 0){
			arr[0] = 1;
			num = num*-1;
		}else{
			arr[0] = 0;
		}
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
		int t =1;
		for(int i = 0;i<(exponent-1);i++){
			t = t * 2;
		}
		
		expo = expo + (t-1); //2 to the power of (exponent bits - 1) - 1

		int u = toBinary(num,exponent,mantissa);
		if(u == 0){
			expo++;
		}
		iToB(expo,exponent);

		
		for(int i = 0;i<bit;i++){
			printf("%d",arr[i]);

		}
		printf("\n");
		
	
		

	}
	
	fclose(fp);

	return EXIT_SUCCESS;
}

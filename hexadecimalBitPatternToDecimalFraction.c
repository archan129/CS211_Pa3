#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



void denormal(int tBits,int eBits,int binary[tBits],int prec){
	double bias = pow(2,eBits-1)-1;
	double ans = 0;
	int sign  = 1;
	int f = -1;
	if(binary[0] == 1){
		sign*=-1;
	}
	//for(int i = eBits+1;i<tBits;i++){
	//	printf("%d", binary[i]);
	//}
	//printf("\n");
	for(int i = eBits+1;i<tBits;i++){
		if(binary[i] == 1){
			ans = ans + pow(2,f);
		}
		f--;
	}
	//printf("%f\n", ans);
	ans = ans * pow(2,1-bias);
	ans = ans * sign;
	
	
	printf("%.*lf\n",prec,ans);
	
	
}
void binaryToDecimal(char hex[],int tBits,int eBits, int mBits, int prec){

	int size = strlen(hex) - 2;
	char h[size];
	for(int i = 0;i<size; i++){
		h[i] = hex[i+2];
	}
	int b[size*4];
	for(int i = 0; i<size*4;i++){
		b[i] = 0;
	}

	//for(int i = 0; i< strlen(h);i++){
	//	printf("%c", h[i]);	
	//}
	//printf("\n");
	//printf("%d\n", size);
	//printf("%ld\n", strlen(h));
	
	int k = 0;
	int j = 0;
	while(j<strlen(h)){   //take each hexadecimal letter and organize into 4 bit binary
		if(h[j] == '0'){
			b[k] = 0;
			b[k+1] = 0;
			b[k+2] = 0;
			b[k+3] = 0;
		}else if(h[j] == '1'){
			b[k] = 0;
			b[k+1] = 0;
			b[k+2] = 0;
			b[k+3] = 1;
			
		}else if(h[j] == '2'){
			b[k] = 0;
			b[k+1] = 0;
			b[k+2] = 1;
			b[k+3] = 0;

		}else if(h[j] == '3'){
			b[k] = 0;
			b[k+1] = 0;
			b[k+2] = 1;
			b[k+3] = 1;

		}else if(h[j] == '4'){
			b[k] = 0;
			b[k+1] = 1;
			b[k+2] = 0;
			b[k+3] = 0;

		}else if(h[j] == '5'){
			b[k] = 0;
			b[k+1] = 1;
			b[k+2] = 0;
			b[k+3] = 1;

		}else if(h[j] == '6'){
			b[k] = 0;
			b[k+1] = 1;
			b[k+2] = 1;
			b[k+3] = 0;

		}else if(h[j] == '7'){
			b[k] = 0;
			b[k+1] = 1;
			b[k+2] = 1;
			b[k+3] = 1;

		}else if(h[j] == '8'){
			b[k] = 1;
			b[k+1] = 0;
			b[k+2] = 0;
			b[k+3] = 0;

		}else if(h[j] == '9'){
			b[k] = 1;
			b[k+1] = 0;
			b[k+2] = 0;
			b[k+3] = 1;

		}else if(h[j] == 'a'){
			b[k] = 1;
			b[k+1] = 0;
			b[k+2] = 1;
			b[k+3] = 0;

		}else if(h[j] == 'b'){
			b[k] = 1;
			b[k+1] = 0;
			b[k+2] = 1;
			b[k+3] = 1;

		}else if(h[j] == 'c'){
			b[k] = 1;
			b[k+1] = 1;
			b[k+2] = 0;
			b[k+3] = 0;

		}else if(h[j] == 'd'){
			b[k] = 1;
			b[k+1] = 1;
			b[k+2] = 0;
			b[k+3] = 1;

		}else if(h[j] == 'e'){
			b[k] = 1;
			b[k+1] = 1;
			b[k+2] = 1;
			b[k+3] = 0;

		}else if(h[j] == 'f'){
			b[k] = 1;
			b[k+1] = 1;
			b[k+2] = 1;
			b[k+3] = 1;

		}
		j++;
		k+=4;
	}

	
	
	int binary[tBits];
	for(int i= 0; i < tBits;i++){
		binary[i] = b[(size*4) - tBits + i];
	}
	for(int i = 0;i < tBits;i++){
		printf("%d",binary[i]);	
	}
	printf("\n");


	double mantissa = 1;
	double exponent = 0;
	//double temp;
	int sign = 1;
	double ans;
	int u = -1; //used to find denormalized values
	
	for(int i = 1;i <= eBits;i++){
		if(binary[i] == 1){
			u = 0;
			break;
		}
	}
	if(u == -1){
		denormal(tBits,eBits,binary,prec);
		//int tBits,int eBits,int binary[tBits],int prec
		return;
	}
	
	

	if(binary[0] == 1){
		sign = -1;
	}
	//printf("%d\n", sign);
	int z = 0;
	for(int i = eBits; i>0; i--){
		if(binary[i] == 1){
			exponent+= pow(2,z);
			
			/*temp = 1;
			for(int j = 0; j<eBits-i;j++){
				temp = temp * 2;
			}
			exponent+=temp;*/
			//u = 1;
		}
		z++;	
	}
	double bias = pow(2,eBits-1)-1;
	double count = exponent - bias;
	count = pow(2,count);
	int d = -1;
	for(int i = eBits+1; i < tBits; i++){
		if(binary[i] == 1){
			mantissa = mantissa + pow(2,d);	
		}
		d--;
	}	
		

/*

	c > 0
		whie c != 0
			double 
			count --
	else if
		c < 0
			while 
				c != 0
				m/=2
				c++;		
*/

	/*temp = 1;
	for(int j = 0; j<eBits - 1;j++){
		temp = temp * 2;
	}*/
	/*if(u == 0){
	p = temp * 2;
	}*/
	
	ans = (sign) * (mantissa) * (count);
	printf("%d\n", sign);
	printf("%lf\n", exponent);
	printf("%lf\n",mantissa);
	printf("%.*lf\n",prec,ans);
	
}


int main(int argc, char* argv[argc+1]){

	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}

	FILE* fp = fopen(argv[1],"r");

	int tBit;
	int eBit;
	int mBit;
	char hex[20];
	int precision;

	while(fscanf(fp,"%d %d %d %s %d\n", &tBit, &eBit, &mBit, hex, &precision) != EOF){
		


		binaryToDecimal(hex,tBit,eBit,mBit,precision);
		//char hex[],int tBits,int eBits, int mBits, int prec
	
		

	}
	
	fclose(fp);
	//hexToBinary("0x4d");
	
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * Pre defining the function to rotate x by n bits
 */
#define rotateleft(x,n) ((x<<n) | (x>>(32-n)))

/**
 * Converts the input string to Binary.
 * \param char *input : pointer to the input string(FSoc22/23 is fun!)
 * \return char* : returns a pointer of the converted string
 */
char* strToBin(char *input);

/**
 * Preprocessing of the input message. The input message is padded with '1' and zeros.
 * Also the original length of the input message is added at the last 64bits.
 * \param char *bin : binary string of the input message
 * \param int len : Length of the original message
 * \return char* : returns a pointer to the preprocessed string
 */
char* preprocessing(char *bin, int len);

/**
 * The 80 round SHA-1 compression function is applied.
 * It is divided into 4 stages of 20 rounds each and bitwise operations like XOR, AND, OR are applied.
 * \param uint32_t *w : the sixteen 32 bit words are passed to the function
 * \param uint32_t *h : the initial hash values/ the magic numbers
 * \return uint32_t* : returns a pointer of the array of processed values
 */
uint32_t * sha1(const uint32_t *w,const uint32_t *h);

// Main program
int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	///The input string for SHA-1 algorithm
	char *input = "FSOC22/23 is fun!";
	printf("The Input message : %s",input);
	printf("\n");

	//Initializing the magic numbers
	uint32_t h[5];
	h[0] = 0x67452301;
	h[1] = 0xEFCDAB89;
	h[2] = 0x98BADCFE;
	h[3] = 0x10325476;
	h[4] = 0xC3D2E1F0;

	///Coverting the input string to binary
	char *bin;
	bin = strToBin(input);
	printf("The original input message in binary \n");
	printf(bin);
	///calculating length of the input message
	int len = strlen(bin);

	///Pre-processig of input string
	char *preprocessed = malloc(64);
	preprocessed = preprocessing(bin,len);
	int l = strlen(preprocessed);
	printf("\nLength of input message = %d", len);
	printf("\nLength of pre-processed message = %d \n", l);
	printf(preprocessed);
	///Dividing the original 512 bit message into sixteen 32 bit words
	char word[40][40];
	int j;
	int z =0;
	for(int i=0;i<16;i++)
	{
		for(j=0;j<32;j++)
		{
			word[i][j]= preprocessed[z];
			z++;
			//printf("%c",word[i][j]);
		}
		word[i][j] = '\0';
	}

	///Converting to binary string to decimal
	uint32_t w[80];
	for(int i=0;i<16;i++)
	{
		w[i] = strtol(word[i],NULL,2);
	}

	///Expanding the 16 words to 80 words
	for(int i=16; i<80;i++)
	{
		w[i] = rotateleft((w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]), 1);
	}

	///Post-processing and adding the hash values
	uint32_t *hash;
	hash = sha1(w,h);

	h[0] = h[0] + *(hash+0);
	h[1] = h[1] + *(hash+1);
	h[2] = h[2] + *(hash+2);
	h[3] = h[3] + *(hash+3);
	h[4] = h[4] + *(hash+4);

	printf("\n");
	printf("Hash Value of the input message : %x%x%x%x%x",h[0], h[1], h[2], h[3], h[4]);
	printf("\n");
	printf("\n");

	uint32_t p0 = 0x44877bf4;
	uint32_t p1 = 0x379e5486;
	uint32_t p2 = 0xf63c89fd;
	uint32_t p3 = 0x2e89188a;
	uint32_t p4 = 0x341b5df5;
	if(h[0]==p0 && h[1]==p1 && h[2]==p2 && h[3]==p3 && h[4]==p4)
	{
		printf("Computed hash is correct \n");
	}

	return 0;

}

/**
 * Converts the input string to Binary.
 * \param char *input : pointer to the input string(FSoc22/23 is fun!)
 * \return char* : returns a pointer of the converted string
 */
char* strToBin(char* input)
{
	int len = strlen(input);
	char *binary = malloc(len*8 +1);
	binary[0] ='\0';
	for(int i =0; i < len; i++)
	{
		char ch = input[i];
		for(int j=7; j>=0; --j)
		{
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
		}
	}
	return binary;
}

/**
 * Preprocessing of the input message. The input message is padded with '1' and zeros.
 * Also the original length of the input message is added at the last 64bits.
 * \param char *bin : binary string of the input message
 * \param int len : Length of the original message
 * \return char* : returns a pointer to the preprocessed string
 */
char* preprocessing(char *bin, int len)
{
	char *preprocessed = malloc(512);
	strcpy(preprocessed,bin);
	char zero[367];
	char a = '1';
	///adding 1 to the original message
	strncat(preprocessed,&a,1);

	//Adding padding bits
	//No of padding zero: 448-(137) = 311
	for(int i=0; i< 367; i++)
	{
		zero[i]='0';
	}
	strcat(preprocessed,zero);

	///Padding the length of original message
    char buffer[137];
    itoa(len, buffer,2);
    strcat(preprocessed,buffer);

    return preprocessed;
}

/**
 * The 80 round SHA-1 compression function is applied.
 * It is divided into 4 stages of 20 rounds each and bitwise operations like XOR, AND, OR are applied.
 * \param uint32_t *w : the sixteen 32 bit words are passed to the function
 * \param uint32_t *h : the initial hash values/ the magic numbers
 * \return uint32_t* : returns a pointer of the array of processed values
 */
uint32_t * sha1(const uint32_t *w,const uint32_t *h)
{

    uint32_t a,b,c,d,e,f,k,temp;
    static uint32_t x[5];
    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];

   for(int m=0;m<80;m++)
   {
       if(m<=19)
       {
           f = (b & c) | ((~b) & d);
           k = 0x5A827999;
       }
       else if(m<=39)
       {
           f = b ^ c ^ d;
           k = 0x6ED9EBA1;
       }
       else if(m<=59)
       {
           f = (b & c) | (b & d) | (c & d);
           k = 0x8F1BBCDC;
       }
       else
       {
           f = b ^ c ^ d;
           k = 0xCA62C1D6;
       }

       temp = (rotateleft(a,5) + f + e + k + w[m]);
       e = d;
       d = c;
       c = rotateleft(b,30);
       b = a;
       a = temp;

   }

   x[0]=a;
   x[1]=b;
   x[2]=c;
   x[3]=d;
   x[4]=e;

   return x;

}

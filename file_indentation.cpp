#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(int argc,char* argv[])
{
	int counter=0,index,indent,index1=0; 
	char *c,*d; 
	long numbytes; 
	
	FILE *fptr; 

	fptr=fopen(argv[1],"r"); 
	
	if(fptr==NULL) 
		printf("File could not be opened.\n");
		
	fseek(fptr,0L,SEEK_END); 
	numbytes=ftell(fptr); 
	fseek(fptr,0L,SEEK_SET); 
	
	c=(char*)calloc(numbytes,sizeof(char)); 
	d=(char*)calloc(numbytes+1000,sizeof(char)); 
	
	fread(c,sizeof(char),numbytes,fptr); 
	
	for(index=0;c[index]!='\0';index++)
	{
		
		d[index1++]=c[index]; 
		if(c[index]=='{' && (c[index-1]!='\'' && c[index+1]!='\'')) 
			counter++;
		if(c[index+1]=='}' && (c[index-1]!='\'' && c[index+1]!='\'')) 
			counter--;
		if(c[index]=='\n') 
			for(indent=0;indent<counter;indent++)
				d[index1++]='	';
	}
	fclose(fptr); 
	fptr = fopen(argv[1], "w"); 
	fputs(d, fptr); 
	
	fclose(fptr); 
	free(c);
	free(d);
	return 0;
}

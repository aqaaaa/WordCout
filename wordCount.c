#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	FILE *fp;
	int length;
	char str[10000],c;
	int i,word=0,chars=0,flag=0;
	fp=fopen(argv[2],"r");
	if(fp==NULL)
	{
		printf("can not open file");
		exit(0);
	}
	fseek(fp,00,SEEK_END);
	length=ftell(fp);
	rewind(fp);
	fread(str,sizeof(char),length,fp);
	for(i=0;str[i]!='\0';i++)
	{
		c=str[i];
		if(c=='\n'||c=='\t'){
			chars++;
			continue;
		}
		if(c==' '||c==','){
			if(c==' ')chars++;
			flag=0;
		}else{
			if(flag==0){
				flag=1;
				word++;
			}
		}
	}
	fclose(fp);
	if(strcmp(argv[1],"-c")==0)
		printf("字符数:%d",chars);
	else if(strcmp(argv[1],"-w")==0)
		printf("单词数:%d",word);
		else
			printf("参数输入有误"); 
}


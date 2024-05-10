#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char label[10],opcode[10],operand[10], t1[10],t2[10],t3[10];
int locctr, start, len,o=-1,s=-1,opnd,size=0;  
FILE *f1,*f2,*f3,*f4,*f5;


struct OPTAB{
    char opcode[10];
    char hexcode[10];
}OT[10];


struct SYMTAB{
    char label[10];
    int address;
}ST[10];


void read_OPTAB(){
    while (1)
    {
        o++;
        fscanf(f2,"%s%s",OT[o].opcode,OT[o].hexcode);
        if(feof(f2))break;
    }
}


void read_line(){
    strcpy(t1,"");strcpy(t2,"");strcpy(t3,"");
    fscanf(f1,"%s",t1);
    if(getc(f1)!='\n'){
        fscanf(f1,"%s",t2);
        if(getc(f1)!='\n'){
            fscanf(f1,"%s",t3);
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0){
        strcpy(label,t1);strcpy(opcode,t2);strcpy(operand,t3);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0){
        strcpy(label,"");strcpy(opcode,t1);strcpy(operand,t2);
    }
    else if(strcmp(t1,"")!=0 && strcmp(t2,"")==0 && strcmp(t3,"")==0){
        strcpy(label,"");strcpy(opcode,t1);strcpy(operand,"");
    }
}


int main(){
    //INPUT
    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    //OUTPUT
    f3=fopen("symtab.txt","w");
    f4=fopen("intermediate.txt","w");
    f5=fopen("length.txt","w");
    read_OPTAB();
    fscanf(f1,"%s%s%x",label,opcode,&opnd);


    if(strcmp(opcode,"START")==0){
        start=opnd;
        locctr=start;
        fprintf(f4,"\t%s\t%s\t%x\n",label,opcode,opnd);
        read_line();
    }

    else locctr=0;

    while(strcmp(opcode,"END")!=0){
        fprintf(f4,"%x \t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"")!=0){
            for(int i=0;i<=s;i++){
                if(strcmp(ST[i].label,label)==0){
                    printf("Error, duplicate symbol");
                    exit(1);
                }
            }
            s++;
            strcpy(ST[s].label,label); ST[s].address=locctr;
        }
        int f=0;
        for(int i=0;i<=o;i++){
            if(strcmp(OT[i].opcode,opcode)==0){
                size+=3;
                locctr+=0x3;
                f=1;
                break;
            }
        }
        if(f==0){
            if(strcmp(opcode,"WORD")==0){
                locctr+=0x3;
                size+=3;
            }

            else if(strcmp(opcode,"RESW")==0){
                locctr+=(0x3*(atoi(operand)));
            }

            else if(strcmp(opcode,"RESB")==0){
                locctr+=atoi(operand);
            }
            
            else if(strcmp(opcode,"BYTE")==0){
                int l=strlen(operand);
                if(operand[0]=='c' || operand[0]=='C'){
                    l-=3;
                }
                else {
                    l=(l-3)/2;
                }
                locctr+=l;
                size+=l;
            }

        }
        printf("%x\n",locctr);
        read_line();
    }

    fprintf(f4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    for(int i=0;i<=s;i++){
        fprintf(f3,"%s\t%x\n",ST[i].label,ST[i].address);
    }

    fprintf(f5,"%x\n%x",locctr-start,size);
    printf("%x %x",locctr,start);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    return 0;
}
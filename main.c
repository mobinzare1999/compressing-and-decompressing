#include <stdio.h>
int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);
int main() {
    FILE *fp,*fo,*fp2,*fo2;
    char A;
    printf("which operation you want to do write c for compressing d for decompressing:\n");
    scanf("%c",&A);
    if(A == 'c' || A == 'C'){
        fp = fopen("source.txt","r");
        fo = fopen("compressed.txt","w");
        compressing(fp,fo);
    }else if(A == 'd' || A == 'D'){
        fp = fopen("C:\\Users\\mobin\\Desktop\\source.txt","r");
        fo = fopen("compressed.txt","w");
        compressing(fp,fo);
        fp2 = fopen("compressed.txt","r");
        fo2 = fopen("source2.txt","w");
        decompressing(fp2, fo2);
    }else{
        printf("wrong answer\n");
    }
    fp2 = fopen("compressed.txt","r");
    fo2 = fopen("source2.txt","w");
    decompressing(fp2, fo2);
    return 0;
}
int compressing(FILE *fp, FILE *fo){
    if(fp == NULL){
        return 0;
    }
    int i = 0;
    char ch, ch2;
    ch = fgetc(fp);
    while(ch != EOF){
        ch2 = fgetc(fp);
        while (ch == ch2){
            i++;
            ch2 = fgetc(fp);
        }
        if(i>=1){
            fputc(ch,fo);
            fputc('$',fo);
            fprintf(fo,"%d",i);
            ch = ch2;
            i = 0;
        } else{
            fputc(ch,fo);
            ch = ch2;
        }
    }
    fclose(fp);
    fclose(fo);
}
int decompressing(FILE *fp2, FILE *fo2){
    if(fp2 == NULL){
        return 0;
    }
    int i;
    char ch, ch2;
    ch = fgetc(fp2);
    while(ch != EOF){
        ch2 = fgetc(fp2);
        while (ch2 != '$'){
            fputc(ch,fo2);
            ch = ch2;
            ch2 = fgetc(fp2);
        }
        ch2 = fgetc(fp2);
        i = ch2;
        i = i - 48;
        for (int j = 0; j <= i; ++j) {
            fputc(ch,fo2);
        }
        ch2 = fgetc(fp2);
        ch = ch2;
    }
    fclose(fp2);
    fclose(fo2);
}
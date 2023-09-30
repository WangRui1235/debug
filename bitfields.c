#include<stdio.h>

#include<stdlib.h>

typedef struct alignment
{ 
    int a:1; 
    int :2 ; 
    int b:3; 
    int c:2; 
}example1; 

typedef union char_aligned{
    char  c ;
    short s : 8 ;
}example2; 
typedef struct named{
   
    char c ;
    int : 0;
    char d ;
    short f: 9 ;
    char e ;
    char : 0 ;
}__attribute__((aligned(4)))example3;
typedef struct named_1{
   
    char c ;
    int : 0;
    char d ;
    short f: 9 ;
    char e ;
    char : 0 ;
}__attribute__((packed))example4;

struct unnamed{
   
    char c ;
    int : 0 ;
    char d ;
    short f: 9 ;
    char e ;
    char : 0 ;
}unnamed;
struct 
{
    unsigned int field1:30;
    unsigned int        :2;
    unsigned int field2:4;
    unsigned int       :0;
    unsigned int field3:3;
}stuff;
typedef unsigned char *byte_pointer;
void showbytes(byte_pointer start,size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
    {
        printf("%.2x\t",start[i]);
    }
    printf("\n");
}
void show_struct(example3 x)
{
    showbytes((byte_pointer)&x,sizeof(example3));
}

int main()
{
    example1 test1={ 0 };
    example2 test2={ 0 };
    example3 test3={ 65,102,260,103};
    example4 test4={ 65,102,260,103};
    
    
    printf("%d byte allocated.\n",sizeof(test1));
    printf("%d byte allocated.\n",sizeof(test2));
    printf("%d byte allocated.\n",sizeof(test3));
    printf("%d byte allocated.\n",sizeof(test4));
    printf("%d byte allocated.\n",sizeof(unnamed));
    printf("%d byte allocated.\n",sizeof(stuff));
    

    printf("%#x unname.c\n",&test3.c);

    printf("%#x unname.d\n",&test3.d);

     //printf("%#x unname.d\n",&test3.f);
    show_struct(test3);

    return 0;
}

int main()
{
  int number=0x04030201;
  char* pChar=(char*)&number;
/*
char a=  *pChar++ ;
char b=  *pChar++ ;
char c=  *pChar++ ;
char d=  *pChar ;
pChar=(char*)&number;
*/     

    if (*pChar > *(pChar+1))
        printf("This computer is big-endian. \n");
    else 
        printf("This computer is little-endian. \n");

  return 0;
}

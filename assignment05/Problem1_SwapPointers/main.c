void swap_pointers(int** a, int** b);

void swap_pointers(int** a, int** b)
{
    int* temp;
    temp=*a;
    *a=*b;
    *b=temp;    
}



int main()
{
  int x=2000000;
  int y=1000000;
  int* prt_x=&x;
  int* prt_y=&y;
  swap_pointers(&prt_x, &prt_y);
  
  
  
  return 0;
}

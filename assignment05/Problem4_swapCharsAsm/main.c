

int SwapCharsAsm(char* a, char* b);

void main() {


  char x='x';
  char y='y';
int result=0;
result=SwapCharsAsm(&x, &y);
 

  x='x';
  y='x';
result=0;
result=SwapCharsAsm(&x, &y);

}


  
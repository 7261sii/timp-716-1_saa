#include <stdio.h>

int main(){
 int n, c = 0, i = 0;
 double x;
 scanf("%d", &n);
 for( i; i < n; i++ ){
  scanf("%lf", &x); 
  if(x >= 0) c++;
  }
 printf("%d\n", c);
 return 0;
}

#include <stdio.h>
int main(){
 int n, i = 0, r = 0;
 double x, q;
 scanf("%d", &n);
 scanf("%lf", &q);
 for(i; i<n-1; i++){
  scanf("%lf", &x);
  if(q < x) r += 1;
  q = x;}
if (r != 0) printf("0\n"); else printf("1\n");
return 0;
}

nclude <stdio.h>

void shall(int n, int arr[]){
  int i, j, step;
  int tmp;
  for (step = n / 2; step > 0; step /= 2)
   for (i = step; i < n; ++i)
   {
     tmp = arr[i];
     for (j = i; j >= step; j -= step)
     {
       if (tmp < arr[j - step])
        arr[j] = arr[j - step];
       else
        break;
     }
      arr[j] = tmp;
    }
}

int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; ++i)
   scanf("%d", &arr[i]);
  ShellSort(n, arr);
  for (int i = 0; i < n; ++i)
   printf("%d ", arr[i]);
  printf("\n");
  return 0;
}

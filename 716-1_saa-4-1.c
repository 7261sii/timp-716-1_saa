#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;
typedef node* list;

int init(list *root) { //инициализация стека
  *root = NULL;
  return 1;
}

int push(list *head, int value) { //ввод значения в стек
  list tmp = (list)malloc(sizeof(node));
  tmp->next = *head;
  tmp->value = value;
  *head = tmp;
  return 1;
}

int pop(node **head) { // вытаскиваем значение из стека
  node *out;
  int value;
  out = *head;
  *head = (*head)->next;
  value = out->value;
  free(out);
  return value;
}

int destroy(list *root) { //чистим стек
  list next;
       while (*root != NULL) {
		next = *root;
		*root = (*root)->next;
		free(next);
	}
  return 1;
}

int print(list *lst) { //вывод стека и его отображение как есть
  list buff = *lst;
        while (buff != NULL) {
		printf("%d ", buff->value);
		buff = buff->next;
	}
  printf("\n");
  return 1;
}

int main() {
  list head;
  init(&head); //инициализируем стек
  int x, sz, k;

  scanf("%d", &sz); //задаем размер 
	for (int i = 0; i < sz; ++i) //забиваем стек значениями
	{
		scanf("%d", &x);
		push(&head, x); 
	}
  print(&head); 
  scanf("%d", &k);
	for (int i = 0; i < k; ++i) {  //просматриваем стек после к-того элемента
		pop(&head);
	}
  print(&head);
  destroy(&head); //чистим стек
  print(&head);
  return 0;
}

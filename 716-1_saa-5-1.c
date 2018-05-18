#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
  int value;
  int key;
  struct list *left;
  struct list *right;
} list;

typedef list* tree;

int init(tree *root)
{
  *root = NULL;
  return 1;
}

int newnode(int key, int vle, tree *root)
{
  tree tmp = (*root);
  tree buff = (tree)malloc(sizeof(list));
  buff->key = key;
  buff->value = vle;
  buff->left = NULL;
  buff->right = NULL;
  if ((*root) == NULL)
  {
   (*root) = buff;
   return 1;
  }
  while (1)
  {
    if (key > tmp->key)
    {
      if (tmp->right == NULL)
      {
	tmp->right = buff;
	return 1;
      }
     tmp = tmp->right;
    }
    else if (key < tmp->key)
    {
      if (tmp->left == NULL)
      {
	tmp->left = buff;
	return 1;
      }
     tmp = tmp->left;
    }
    else return 1;
  }
}

int main()
{
  tree head;
  init(&head);
  int i, vle, key, sz, count, el;
  bool z = 1;
  scanf("%d", &sz);
  for (i = 0; i < sz; ++i)
  {
    scanf("%d", &key);
    scanf("%d", &vle);
    newnode(key, vle, &head);
  }
  for (i = 0; i < 3; ++i)
  {
    tree tmp = head;
    scanf("%d", &el);
    count = 0;
    while (z != 0)
    {
      if (tmp != NULL)
      {
        if (tmp->key == el)
	{
	  printf("%d ", count);
	  printf("%d ", tmp->value);
	  z = 0;
	}
	else
	{
	  if (tmp->key > el) tmp = tmp->left;
	  if (tmp->key < el) tmp = tmp->right;
	  ++count;
	}
      }
      else
      {
        printf("%d ", -1);
	z = 0;
      }
     }
    z = 1;
    printf("\n");
  }
  return 0;
}


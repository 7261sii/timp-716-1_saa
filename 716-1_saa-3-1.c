
#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;

int init(list *root)
{
	*root = NULL;
	return 1;
}

list find(list root, int value) {
	while (root->value != value) {
		root = root->next;
		if (root == NULL)
			return NULL;
	}
	return root;
}

int removing(list *lst) {
	if (*lst != NULL) {
		list del = *lst;
		if (((*lst)->prev != NULL) && ((*lst)->next != NULL)) {
			(*lst)->prev->next = (*lst)->next;
			(*lst)->next->prev = (*lst)->prev;
		}
		if (((*lst)->prev == NULL) && ((*lst)->next != NULL)) {
			(*lst)->next->prev = NULL;
			(*lst) = (*lst)->next;
		}
		if (((*lst)->prev != NULL) && ((*lst)->next == NULL)) {
			(*lst)->prev->next = NULL;
		}
		free(del);
	}
	return 1;
}

int isEmpty(list root) {
	if (root) return 1;
	else return 0;
}

int destroy(list *root) {
	list next;
	while (*root != NULL) {
		next = *root;
		*root = (*root)->next;
		free(next);
	}
	return 1;
}

int append(list *lst, int value) {
	if ((*lst) == NULL) {
		list buff = (list)malloc(sizeof(node));
		buff->next = NULL;
		buff->value = value;
		buff->prev = NULL;
		*lst = buff;
		return 1;
	}
	if ((*lst)->next == NULL) {
		list buff = (list)malloc(sizeof(node));
		buff->next = NULL;
		buff->value = value;
		buff->prev = *lst;
		(*lst)->next = buff;
		return 1;
	}
	else {
		list buff = (list)malloc(sizeof(node));
		buff->next = (*lst)->next;
		buff->value = value;
		buff->prev = *lst;
		(*lst)->next->prev = buff;
		(*lst)->next = buff;
		return 1;
	}
}

int prepend(list *lst, int value) {
	if ((*lst) == NULL) {
		list buff = (list)malloc(sizeof(node));
		buff->next = NULL;
		buff->value = value;
		buff->prev = NULL;
		*lst = buff;
		return 1;
	}
	if ((*lst)->prev == NULL) {
		list buff = (list)malloc(sizeof(node));
		buff->prev = NULL;
		buff->value = value;
		buff->next = *lst;
		(*lst)->prev = buff;
		(*lst) = (*lst)->prev;
		return 1;
	}
	else {
		list buff = (list)malloc(sizeof(node));
		buff->value = value;
		buff->prev = (*lst)->prev;
		buff->next = *lst;
		(*lst)->prev->next = buff;
		(*lst)->prev = buff;
		return 1;
	}
}

int print(list *lst) {
	list tmp = *lst;
	while (tmp != NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	return 1;
}

int main() {
	list head;
	init(&head);
	int i, el, sz, k, m, a, b, c, d;
	scanf("%d", &sz);
	if (sz > 0) {
		scanf("%d", &el);
		append(&head, el);
	}
	list tmp = head;
	for (i = 1; i < sz; ++i) {
		scanf("%d", &el);
		append(&tmp, el);
		tmp = tmp->next;
	}
	print(&head);
	scanf("%d", &k);
		if (k == 1)
			removing(&head);
		else {
			list next = head;
			for (i = 1; i < k; ++i) {
				next = next->next;
			}
			removing(&next);
		}
	print(&head);
	scanf("%d", &m);
	list del = find(head, m);
	if (del == head)
		removing(&head);
	else
		removing(&del);
	print(&head);
	scanf("%d%d", &a, &b);
		list next = head;
		for (i = 1; i < a; ++i) {
			next = next->next;
		}
		append(&next, b);
	print(&head);
	scanf("%d%d", &c, &d);
	if (c == 1)
		prepend(&head, d);
	else {
		list next = head;
		for (i = 1; i < c; ++i) {
			next = next->next;
		}
		prepend(&next, d);
	}
	print(&head);
	return 0;
}


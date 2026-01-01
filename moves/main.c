#include <stdlib.h>
#include <stdio.h>
typedef struct s_lst
{
	int data;
	struct s_lst *next;
	struct s_lst *prev;
} t_lst;
t_lst *nlst(int data)
{
	t_lst *n = malloc(sizeof(t_lst));
	if(!n)
		return NULL;
	n->data = data;
	n->next=NULL;
	n->prev=NULL;
	return n;
}
t_lst *lstlast(t_lst *lst)
{
	if (!lst) return NULL;
	while(lst->next)
		lst=lst->next;
	return lst;
}
void addback(t_lst **lst, t_lst *n)
{
	if(!lst || !n) return;
	if(!*lst){
		*lst = n;
		return ;
	}
	t_lst *last;
	last = lstlast(*lst);
	last->next=n;
	n->prev=last;
}
void addfront(t_lst **lst, t_lst *n)
{
	if(!lst || !n) return;
	if(*lst){
		(*lst)->prev=n;
		n->next = (*lst);
	}
	n->prev=NULL;
	(*lst) = n;
}
// int lstsize(t_lst *lst)
// {
// 	int s = 0;
// 	while(lst)
// 	{
// 		s++;
// 		lst=lst->next;
// 	}
// 	return s;
// }
void swap(t_lst **lst){
	if(!lst || !*lst || !(*lst)->next)return;
	int s = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data=s;
}
void push(t_lst **src, t_lst **dst){
	if(!src || !*src)return;
	int p = (*src)->data;
	addfront(dst, nlst(p));
	t_lst *tmp = (*src);
	if((*src)->next){
		(*src)=(*src)->next;
		(*src)->prev=NULL;
	}
	else
		(*src) = NULL;
	free(tmp);
}
void rotate(t_lst **lst)
{
	t_lst *last = lstlast(*lst);
	t_lst *fst = (*lst);
	if(!lst || !*lst || !(*lst)->next)return;
	(*lst)= fst->next;
	(*lst)->prev=NULL;
	last->next=fst;
	fst->prev=last;
	fst->next=NULL;
}
void reverse_rotate(t_lst **lst)
{
	t_lst *last = lstlast(*lst);
	t_lst *fst = (*lst);
	if(!lst || !*lst || !(*lst)->next)return;
	last->prev->next=NULL;
	last->next=fst;
	last->prev=NULL;
	fst->prev=last;
	(*lst) = last;
}
int main()
{
	t_lst *lst = nlst(10);
	t_lst *d = NULL;
	addfront(&lst, nlst(20));
	addback(&lst, nlst(30));
	swap(&lst);
	printf("Swap:\nA:[%d] <-> [%d] <-> [%d] <-> NULL\n", lst->data, lst->next->data, lst->next->next->data);
	push(&lst, &d);
	printf("Push:\nB:\n[%d] <-> NULL\n",d->data);
	printf("A:\n");
	t_lst *p = lst;
	while(p){
		printf("[%d] <-> ", p->data);
		p=p->next;
	}
	printf("NULL");
	rotate(&lst);
	printf("\nRotate A :\n");
	t_lst *r=lst;
	while(r){
		printf("[%d] <-> ", r->data);
		r=r->next;
	}
	printf("NULL");
	printf("\nReverse Rotate A :\n");
	reverse_rotate(&lst);
	while(lst){
		printf("[%d] <-> ", lst->data);
		lst=lst->next;
	}
	printf("NULL");
}
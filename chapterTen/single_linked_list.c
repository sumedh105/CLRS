#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

static void insert_end(struct node **root_node, int data);
static void insert_beg(struct node **root_node, int data);
static int del_end(struct node **root_node);
static int del_beg(struct node **root_node);
static void display(struct node *root_node);

int main()
{
	int choice = 0;
	int data = 0;
	struct node *root_node = NULL;

	while (1)
	{
		printf("\nEnter 0 to exit\n");
		printf("\nEnter 1 to insert the node at the end\n");
		printf("\nEnter 2 to insert the node at the beginning\n");
		printf("\nEnter 3 to delete the node at the end\n");
		printf("\nEnter 4 to delete the node at the beginning\n");
		printf("\nEnter 5 to display\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				printf("\nEnter the data that needs ot be entered\n");
				scanf("%d", &data);
				insert_end(&root_node, data);
				break;
			case 2:
				printf("\nEnter the data that needs ot be entered\n");
				scanf("%d", &data);
				insert_beg(&root_node, data);
				break;
			case 3:
				data = del_end(&root_node);
				printf("\nThe deleted data is: %d\n", data);
				break;
			case 4:
				data = del_beg(&root_node);
				printf("\nThe deleted data is: %d\n", data);
				break;
			case 5:
				display(root_node);
				break;
			default:
				break;
				
		}
	}

	return 0;
}

static void insert_end(struct node **root_node, int data)
{
	struct node *temp = NULL;
	struct node *cur = NULL;

	cur = (struct node *)malloc(sizeof(struct node));
	cur->data = data;
	cur->next = NULL;

	if (*root_node == NULL)
	{
		*root_node = cur;
	}
	else
	{
		temp = *root_node;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = cur;
	}
}

static void insert_beg(struct node **root_node, int data)
{
	struct node *temp = NULL;
	struct node *cur = NULL;

	cur = (struct node *)malloc(sizeof(struct node));
	cur->data = data;
	
	if (*root_node == NULL)
	{
		cur->next = NULL;
		*root_node = cur;
	}
	else
	{
		temp = *root_node;
		cur->next = temp;
		*root_node = cur;
	}
}

static int del_end(struct node **root_node)
{
	int data = 0;
	struct node *prev = NULL;
	struct node *cur = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, nothing can be removed\n");
	}
	else
	{
		cur = *root_node;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}

		data = cur->data;
		prev->next = NULL;
		free(cur);
	}

	return data;
}

static int del_beg(struct node **root_node)
{
	int data = 0;
	struct node *prev = NULL;
	struct node *cur = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, nothing can be removed\n");
	}
	else
	{
		cur = *root_node;
		data = cur->data;
		*root_node = cur->next;
		free(cur);
	}

	return data;
}

static void display(struct node *root_node)
{
	struct node *temp = NULL;

	temp = root_node;

	while (temp != NULL)
	{
		printf("\n%d\n", temp->data);
		temp = temp->next;
	}
}

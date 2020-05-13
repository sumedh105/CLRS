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
		printf("\nEnter 1 to insert the data at the end\n");
		printf("\nEnter 2 to insert the data at the beginning\n");
		printf("\nEnter 3 to delete the data from the end\n");
		printf("\nEnter 4 to delete the data from the beginning\n");
		printf("\nEnter 5 to display the linked list\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(0);
			case 1:
				printf("\nEnter the data that needs to be inserted\n");
				scanf("%d", &data);
				insert_end(&root_node, data);
				break;
			case 2:
				printf("\nEnter the data that needs to be inserted\n");
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

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	if (*root_node == NULL)
	{
		*root_node = temp;
		(*root_node)->next = *root_node;
	}
	else
	{
		temp->next = *root_node;
		cur = *root_node;
		while (cur->next != *root_node)
		{
			cur = cur->next;
		}
		cur->next = temp;
	}
}

static void insert_beg(struct node **root_node, int data)
{
	struct node *temp = NULL;
	struct node *prev = NULL;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	if (*root_node == NULL)
	{
		*root_node = temp;
		(*root_node)->next = *root_node;
	}
	else
	{
		prev = *root_node;
		while (prev->next != *root_node)
		{
			prev = prev->next;
		}
		temp->next = *root_node;
		prev->next = temp;
		*root_node = temp;
	}
}

static int del_end(struct node **root_node)
{
	int data = 0;
	struct node *prev = NULL;
	struct node *temp = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, nothing can be deleted from the list\n");
	}
	else if ((*root_node)->next == NULL)
	{
		free(*root_node);
	}
	else
	{
		temp = *root_node;
		while (temp->next != *root_node)
		{
			prev = temp;
			temp = temp->next;
		}
		data = temp->data;
		prev->next = temp->next;
		free(temp);
	}

	return data;
}

static int del_beg(struct node **root_node)
{
	int data = 0;
	struct node *cur = NULL;
	struct node *prev = NULL;
	struct node *temp = NULL;

	if (*root_node == NULL)
	{
		printf("\nList is empty, nothing can be removed from the list\n");
	}
	else if ((*root_node)->next == NULL)
	{
		free(*root_node);
	}
	else
	{
		temp = *root_node;
		prev = *root_node;
		while (temp->next != *root_node)
		{
			temp = temp->next;
		}
		cur = prev->next;
		temp->next = cur;
		*root_node = cur;
		data = prev->data;
		free(prev);
	}

	return data;
}

static void display(struct node *root_node)
{
	struct node *temp = NULL;

	temp = root_node;
	while (temp->next != root_node)
	{
		printf("\n%d\n", temp->data);
		temp = temp->next;
	}
	printf("\n%d\n", temp->data);
}

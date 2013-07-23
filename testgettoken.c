#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct token_node
{
  char line_number[10];
  char kind[20];
  char value[20];
  struct token_node * next;
};

struct token_node * get_token(FILE *fp)
{
  struct token_node * head, *current, *tail;
  head = tail = NULL;

  while(!feof(fp))
  {
    current = (struct token_node*)malloc(sizeof(struct token_node));
    fscanf(fp, "%s%s%s", current->line_number, current->kind, current->value);
    while(fgetc(fp)!='\n'&&fgetc(fp)!=EOF)
    {
      fgetc(fp);
    }

    if(head==NULL)
      head = tail = current;
    else
      tail = tail->next = current;
  }
  return head;
}

struct token_node *current_token;
main()
{
  FILE * fp;
  fp = fopen ("token","r");

  current_token = get_token(fp);
  fclose(fp);

  while(current_token->next!= NULL)
  {
    printf("%s\n",current_token->value);
    current_token = current_token->next;
  }

  printf("%s\n", current_token->value);
}
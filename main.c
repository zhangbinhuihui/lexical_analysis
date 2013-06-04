#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void print_tree(struct syntax_node * t, int deep)
{
  int i;
  int j;
  for(i = 0; i<deep*6;i++)
  {
    printf(" ");
  }
  printf("%s\n", t->kind_name);

  for(i=0;i<10;++i)
  {
    if(t->child[i]!=NULL)
      print_tree(t->child[i], deep+1);
  }
}

struct token_node * get_token(FILE *fp)
{
  struct token_node * head, *current, *tail;
  head = tail = NULL;

  while(!feof(fp))
  {
    current = (struct token_node*)malloc(sizeof(struct token_node));
    fscanf(fp, "%s%s%s",  current->line_number, current->kind, current->value);
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

struct token_node * current_token;

main()
{
  FILE * fp;
  fp = fopen ("snl_token2","r");


  current_token = get_token(fp);
  fclose(fp);

  struct syntax_node * t;
  t = parse(current_token);

  print_tree(t, 0);
}
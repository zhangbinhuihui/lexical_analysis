#include <stdio.h>
#include <stdlib.h>

struct token_node
{
  char line_number[10];
  char value[20];
  struct token_node * next;
};

struct syntax_node
{
  struct syntax_node * child[3];
  struct syntax_node * brother;

  char kind_name[20];
};

struct token_node * get_token(FILE *f)
{
  struct token_node * head, *current, *tail;
  head = tail = NULL;

  while(!feof(fp))
  {
    current = (struct token_node*)malloc(sizeof(struct token_node));
    fscanf(fp, "%s%s",  current->line_number, current->value);
    // printf("line: %s\nword: %s\n", current->line_number, current->value);

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


main()
{
  FILE * fp;
  fp = fopen ("snl_token2","r");

  struct token_node * current_token;

  current_token = get_token(fp);
  fclose(fp);

  struct syntax_node * t;
  t = parse(current_token);

  print_tree(t);
}
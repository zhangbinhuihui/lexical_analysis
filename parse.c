#include <string.h>
#include "node.h"

struct syntax_node * parse(struct token_node * taken)
{
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t = program(token);
  return t
}

struct syntax_node * program()
{
  struct syntax_node * t, * p_head, * dec_part, * p_body;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  p_head   = program_head();
  dec_part = declare_part();
  p_body   = program_body();

  t->child[0] = p_head;
  t->child[0] = p_head;
  t->child[0] = p_head;
  strcpy(t->kind_name, 'program');
  return t;
}

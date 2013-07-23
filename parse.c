#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

void chushihua_t(struct syntax_node *t)
{
  int i;
  for(i = 0; i<10; i++)
  {
    t->child[i] = NULL;
  }
}

struct syntax_node * parse()
{
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t = program();
  return t;
}

struct syntax_node * program()
{
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = program_head();
  t->child[1] = declare_part();
  t->child[2] = program_body();
  strcpy(t->kind_name, "Program");
  return t;
}

struct syntax_node * program_head(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = rev_program();
  t->child[1] = program_name();
  strcpy(t->kind_name, "ProgramHead");
  return t;
}

struct syntax_node * program_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = id();
  strcpy(t->kind_name, "ProgramName");
  return t;
}

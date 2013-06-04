#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

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

  t->child[0] = program_head();
  t->child[1] = declare_part();
  t->child[2] = program_body();
  strcpy(t->kind_name, "Program");
  return t;
}

struct syntax_node * program_head(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_program();
  t->child[1] = program_name();
  strcpy(t->kind_name, "ProgramHead");

  return t;
}

// struct syntax_node * declare_part(){
//   struct syntax_node * t, * PROGRAM, * p_name;
//   t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

//   PROGRAM = rev_program();
//   p_name  = program_name();

//   t->child[0] = p_head;
//   t->child[0] = p_head;
//   strcpy(t->kind_name, 'program');
// }

struct syntax_node * program_body(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_program();
  t->child[1] = program_name();
  strcpy(t->kind_name, "program");
}

struct syntax_node * rev_program(){
  if(strcmp(current_token->value, "program") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"program\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));
  strcpy(t->kind_name, current_token->value);

  current_token = current_token->next;
  return t;
}

struct syntax_node * program_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_program_name();
  strcpy(t->kind_name, "ProgramName");

  return t;
}

struct syntax_node * id_program_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);

  current_token = current_token->next;
  return t;
}
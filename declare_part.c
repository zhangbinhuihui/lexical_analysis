#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * declare_part(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = type_decpart();
  t->child[1] = var_decpart();
  t->child[2] = proc_decpart();
  strcpy(t->kind_name, "DeclarePart");

  return t;
}

struct syntax_node * type_decpart(){
  if(strcmp(current_token->value, "type") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = type_dec();
  strcpy(t->kind_name, "DeclarePart");

  return t;
}

struct syntax_node * var_decpart(){
  if((current_token->value, "var") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = var_dec();
  strcpy(t->kind_name, "VarDecpart");

  return t;
}

struct syntax_node * proc_decpart(){
  if(strcmp(current_token->value, "procedure"))
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = pro_dec();
  strcpy(t->kind_name, "ProcDecpart");

  return t;
}

struct syntax_node * type_dec(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_type();
  t->child[1] = type_declist();
  strcpy(t->kind_name, "TypeDec");

  return t;
}

struct syntax_node * rev_type(){
  if(strcmp(current_token->value, "type") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"type\".\n");
    exit(1);
  }

  struct syntax_node * t;

  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));
  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * type_declist(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = type_id();
  t->child[1] = denghao();
  t->child[2] = type_def();
  t->child[3] = fenhao();
  t->child[4] = type_dec_more();
  strcpy(t->kind_name, "TypeDecList");

  return t;
}

struct syntax_node * type_id(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_type_id();
  strcpy(t->kind_name, "TypeId");

  return t;
}

struct syntax_node * id_type_id(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_type_id();
  strcpy(t->kind_name, current_token->value);

  current_token = current_token->next;
  return t;
}

struct syntax_node * denghao(){
  if(strcmp(current_token->value, "=") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss denghao \"=\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));
  strcpy(t->kind_name, current_token->value);

  current_token = current_token->next;
  return t;
}

struct syntax_node * type_def(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "integer") == 0||strcmp(current_token->value, "integer") == 0)
  {
    t->child[0] = base_type();
  }

  else if(strcmp(current_token->value, "array") == 0)
  {
    t->child[0] = structure_type();
  }

  strcpy(t->kind_name, "TypeDef");
  return t;
}

struct syntax_node * base_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_base_type();
  strcpy(t->kind_name, "BaseType");
  return t;
}

struct syntax_node * rev_base_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  return t;
}

struct syntax_node * structure_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = array_type();
  strcpy(t->kind_name, "StructureType");
  return t;
}

struct syntax_node * array_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_array();
  t->child[1] = zuofangkuo();
  t->child[2] = low();
  t->child[3] = shuangdian();
  t->child[4] = top();
  t->child[5] = youfangkuo();
  t->child[6] = rev_of();
  t->child[7] = base_type();
  strcpy(t->kind_name, "ArrayType");
  return t;
}

struct syntax_node * rev_array(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * zuofangkuo(){
  if(strcmp(current_token->value, "[") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss zuofangkuo \"[\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * low(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = intc();
  strcpy(t->kind_name, "Low");
  return t;
}

struct syntax_node * intc(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * shuangdian(){
  if(strcmp(current_token->value, "..") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss shuangdian \"..\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * top(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = intc();
  strcpy(t->kind_name, "Top");
  return t;
}

struct syntax_node * youfangkuo(){
  if(strcmp(current_token->value, "]") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss youfangkuo \"]\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_of(){
  if(strcmp(current_token->value, "of") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"of\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}


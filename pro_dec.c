#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * pro_dec(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_procedure();
  t->child[1] = proc_name();
  t->child[2] = zuohuohao();
  t->child[3] = param_list();
  t->child[4] = youkuohao();
  t->child[5] = fenhao();
  t->child[6] = proc_dec_part();
  t->child[7] = proc_body();
  t->child[8] = proc_dec_more();
  strcpy(t->kind_name, "ProDec");

  return t;
}

struct syntax_node * rev_procedure(){
  if(strcmp(current_token->value, "procedure") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"procedure\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * proc_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_proc_name();
  strcpy(t->kind_name, "ProcName");
  current_token = current_token->next;

  return t;
}

struct syntax_node * id_proc_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * zuohuohao(){
  if(strcmp(current_token->value, "(") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss zuokuohao \"(\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * youhuohao(){
  if(strcmp(current_token->value, ")") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \")\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * param_list(){
  if(strcmp(current_token->value, "integer") != 0&&
     strcmp(current_token->value, "char")    != 0&&
     strcmp(current_token->value, "array")   != 0&&
     strcmp(current_token->value, "var")     != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = param_dec_list();
  strcpy(t->kind_name, "ParamList");

  return t;
}

struct syntax_node * param_dec_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = param();
  t->child[1] = param_more();
  strcpy(t->kind_name, "ParamDecList");

  return t;
}

struct syntax_node * param(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "integer") == 0||
     strcmp(current_token->value, "char")    == 0||
     strcmp(current_token->value, "array")   == 0||
     strcmp(current_token->kind, "ID")       == 0||)
  {
    t->child[0] = type_def();
    t->child[1] = form_list();
  }

  if(strcmp(current_token->value, "var") == 0)
  {
    t->child[0] = rev_var();
    t->child[1] = type_def();
    t->child[2] = form_list();
  }

  strcpy(t->kind_name, "Param");

  return t;
}

struct syntax_node * rev_var(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;

  return t;
}

struct syntax_node * form_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_proc_name();
  t->child[1] = fid_more();

  strcpy(t->kind_name, "FormList");
  current_token = current_token->next;

  return t;
}

struct syntax_node * form_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id_proc_name();
  t->child[1] = fid_more();

  strcpy(t->kind_name, "FormList");
  current_token = current_token->next;

  return t;
}
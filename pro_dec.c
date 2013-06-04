#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * proc_dec(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_procedure();
  t->child[1] = proc_name();
  t->child[2] = zuokuohao();
  t->child[3] = param_list();
  t->child[4] = youkuohao();
  t->child[5] = fenhao();
  t->child[6] = proc_dec_part();
  t->child[7] = proc_body();
  t->child[8] = proc_dec_more();
  strcpy(t->kind_name, "ProDec");

  return t;
}

struct syntax_node * proc_name(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id();
  strcpy(t->kind_name, "ProcName");
  current_token = current_token->next;

  return t;
}

struct syntax_node * param_list(){
  if(strcmp(current_token->value, "integer") != 0&&
     strcmp(current_token->value, "char")    != 0&&
     strcmp(current_token->kind, "ID")       != 0&&
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
     strcmp(current_token->kind, "ID")       == 0||
     strcmp(current_token->value, "array")   == 0)
  {
    t->child[0] = type_def();
    t->child[1] = form_list();
  }

  else
  {
    t->child[0] = rev_var();
    t->child[1] = type_def();
    t->child[2] = form_list();
  }

  strcpy(t->kind_name, "Param");
  return t;
}

struct syntax_node * form_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id();
  t->child[1] = fid_more();
  strcpy(t->kind_name, "FormList");
  return t;
}

struct syntax_node * fid_more(){
  if(strcmp(current_token->value, ",") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = douhao();
  t->child[1] = form_list();
  strcpy(t->kind_name, "FidMore");
  return t;
}

struct syntax_node * param_more(){
  if(strcmp(current_token->value, ";") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = fenhao();
  t->child[1] = param_dec_list();
  strcpy(t->kind_name, "ParamMore");
  return t;
}

struct syntax_node * proc_dec_part(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = declare_part();
  strcpy(t->kind_name, "ProcDecPart");
  return t;
}

struct syntax_node * proc_body(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = program_body();
  strcpy(t->kind_name, "ProcBody");
  return t;
}

struct syntax_node * program_body(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_begin();
  t->child[1] = stm_list();
  t->child[2] = rev_end();
  strcpy(t->kind_name, "ProgramBody");
  return t;
}

struct syntax_node * stm_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = stm();
  t->child[1] = stm_more();
  strcpy(t->kind_name, "StmList");
  return t;
}

struct syntax_node * stm_more(){
  if(strcmp(current_token->value, ";") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = fenhao();
  t->child[1] = stm_list();
  strcpy(t->kind_name, "StmMore");
  return t;
}

struct syntax_node * stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "if")     == 0)
  {
    t->child[0] = conditional_stm();
  }
  else if(strcmp(current_token->value, "while")  == 0)
  {
    t->child[0] = loop_stm();
  }
  else if(strcmp(current_token->value, "read")   == 0)
  {
    t->child[0] = input_stm();
  }
  else if(strcmp(current_token->value, "write")  == 0)
  {
    t->child[0] = output_stm();
  }
  else if(strcmp(current_token->value, "return") == 0)
  {
    t->child[0] = return_stm();
  }
  else
  {
    t->child[0] = id();
    t->child[1] = ass_call();
  }

  strcpy(t->kind_name, "Stm");
  return t;
}

struct syntax_node * proc_dec_more(){
  if(strcmp(current_token->value, "procedure") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = proc_dec();
  strcpy(t->kind_name, "ProcDecMore");
  return t;
}

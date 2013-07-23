#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * declare_part(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
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

  chushihua_t(t);
  t->child[0] = type_dec();
  strcpy(t->kind_name, "TypeDecpart");
  return t;
}

struct syntax_node * var_decpart(){
  if(strcmp(current_token->value, "var") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
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

  chushihua_t(t);
  t->child[0] = proc_dec();
  strcpy(t->kind_name, "ProcDecpart");
  return t;
}

struct syntax_node * type_dec(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = rev_type();
  t->child[1] = type_dec_list();
  strcpy(t->kind_name, "TypeDec");
  return t;
}

struct syntax_node * type_dec_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
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

  chushihua_t(t);
  t->child[0] = id();
  strcpy(t->kind_name, "TypeId");
  return t;
}

struct syntax_node * type_def(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  if(strcmp(current_token->value, "integer") == 0||strcmp(current_token->value, "integer") == 0)
  {
    t->child[0] = base_type();
  }

  else if(strcmp(current_token->value, "array") == 0)
  {
    t->child[0] = structure_type();
  }

  else
  {
    t->child[0] = id();
  }

  strcpy(t->kind_name, "TypeDef");
  return t;
}

struct syntax_node * base_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = rev_base_type();
  strcpy(t->kind_name, "BaseType");
  return t;
}

struct syntax_node * structure_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = array_type();
  strcpy(t->kind_name, "StructureType");
  return t;
}

struct syntax_node * array_type(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
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

struct syntax_node * low(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = intc();
  strcpy(t->kind_name, "Low");
  return t;
}

struct syntax_node * top(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = intc();
  strcpy(t->kind_name, "Top");
  return t;
}

struct syntax_node * type_dec_more(){
  if(strcmp(current_token->kind, "ID") != 0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = type_dec_list();
  strcpy(t->kind_name, "TypeDecMore");
  return t;
}

struct syntax_node * var_dec(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = rev_var();
  t->child[1] = var_dec_list();
  strcpy(t->kind_name, "VarDec");
  return t;
}

struct syntax_node * var_dec_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = type_def();
  t->child[1] = var_id_list();
  t->child[2] = fenhao();
  t->child[3] = var_dec_more();
  strcpy(t->kind_name, "VarDecList");
  return t;
}

struct syntax_node * var_dec_more(){
  if(strcmp(current_token->value, "integer")!=0&&
     strcmp(current_token->value, "char")   !=0&&
     strcmp(current_token->value, "array")  !=0&&
     strcmp(current_token->kind, "ID")      !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = var_dec_list();
  strcpy(t->kind_name, "VarDecMore");
  return t;
}

struct syntax_node * var_id_list(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = id();
  t->child[1] = var_id_more();
  strcpy(t->kind_name, "VarIdList");
  return t;
}

struct syntax_node * var_id_more(){
  if(strcmp(current_token->value, ",")!=0)
  {
    return NULL;
  }
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  chushihua_t(t);
  t->child[0] = douhao();
  t->child[1] = var_id_list();
  strcpy(t->kind_name, "VarIdMore");
  return t;
}
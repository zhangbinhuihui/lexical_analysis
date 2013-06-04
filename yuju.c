#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * conditional_stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_if();
  t->child[1] = rel_exp();
  t->child[2] = rev_then();
  t->child[3] = stm_list();
  t->child[4] = rev_else();
  t->child[5] = stm_list();
  t->child[6] = rev_fi();
  strcpy(t->kind_name, "ConditionalStm");
  return t;
}

struct syntax_node * loop_stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_while();
  t->child[1] = rel_exp();
  t->child[2] = rev_do();
  t->child[3] = stm_list();
  t->child[4] = rev_endwh();
  strcpy(t->kind_name, "LoopStm");
  return t;
}

struct syntax_node * input_stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_read();
  t->child[1] = zuokuohao();
  t->child[2] = invar();
  t->child[3] = youkuohao();
  strcpy(t->kind_name, "InputStm");
  return t;
}

struct syntax_node * output_stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_write();
  t->child[1] = zuokuohao();
  t->child[2] = Exp();
  t->child[3] = youkuohao();
  strcpy(t->kind_name, "OutputStm");
  return t;
}

struct syntax_node * return_stm(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = rev_return();
  strcpy(t->kind_name, "ReturnStm");
  return t;
}

struct syntax_node * ass_call(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "("))
  {
    t->child[0] = call_stm_rest();
  }

  else if(strcmp(current_token->value, "[") == 0||
          strcmp(current_token->value, ".") == 0)
  {
    t->child[0] = assignment_rest();
  }

  else
  {
    return NULL;
  }

  strcpy(t->kind_name, "AssCall");
  return t;
}

struct syntax_node * rel_exp(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = Exp();
  t->child[1] = other_rel_e();
  strcpy(t->kind_name, "RelExp");
  return t;
}

struct syntax_node * Exp(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = term();
  t->child[1] = other_term();
  strcpy(t->kind_name, "Exp");
  return t;
}

struct syntax_node * term(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = factor();
  t->child[1] = other_factor();
  strcpy(t->kind_name, "Term");
  return t;
}

struct syntax_node * factor(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "(") == 0)
  {
    t->child[0] = zuokuohao();
    t->child[1] = Exp();
    t->child[2] = youkuohao();
  }

  else if(strcmp(current_token->kind, "INTC") == 0)
  {
    t->child[0] = intc();
  }

  else
  {
    t->child[0] = variable();
  }

  strcpy(t->kind_name, "Factor");
  return t;
}

struct syntax_node * variable(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id();
  t->child[1] = vari_more();
  strcpy(t->kind_name, "variable");
  return t;
}

struct syntax_node * vari_more(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "[") == 0)
  {
    t->child[0] = zuofangkuo();
    t->child[1] = Exp();
    t->child[2] = youfangkuo();
  }
  else if(strcmp(current_token->value, ".") ==0)
  {
    t->child[0] = dianhao();
    t->child[1] = field_var();
  }
  else
  {
    return NULL;
  }

  strcpy(t->kind_name, "VariMore");
  return t;
}

struct syntax_node * field_var(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id();
  t->child[1] = field_var_more();
  strcpy(t->kind_name, "FieldVar");

  return t;
}

struct syntax_node * field_var_more(){
  if(strcmp(current_token->value, "[") !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = zuofangkuo();
  t->child[1] = Exp();
  t->child[0] = youfangkuo();
  strcpy(t->kind_name, "FieldVarMore");
  return t;
}

struct syntax_node * cmp_op(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "<") ==0)
  {
    t->child[0] = xiaoyuhao();
  }
  else
  {
    t->child[1] = denghao();
  }

  strcpy(t->kind_name, "CmpOp");
  return t;
}

struct syntax_node * add_op(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "+") ==0)
  {
    t->child[0] = jiahao();
  }
  else
  {
    t->child[1] = jianhao();
  }

  strcpy(t->kind_name, "AddOp");
  return t;
}

struct syntax_node * mult_op(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  if(strcmp(current_token->value, "*") ==0)
  {
    t->child[0] = chenghao();
  }
  else
  {
    t->child[1] = chuhao();
  }

  strcpy(t->kind_name, "MultOp");
  return t;
}

struct syntax_node * invar(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = id();
  strcpy(t->kind_name, "Invar");
  return t;
}

struct syntax_node * call_stm_rest(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = zuokuohao();
  t->child[1] = act_param_list();
  t->child[2] = youkuohao();
  strcpy(t->kind_name, "CallStmRest");
  return t;
}

struct syntax_node * act_param_list(){
  if(strcmp(current_token->value, "(")   !=0&&
     strcmp(current_token->kind, "INTC") !=0&&
     strcmp(current_token->kind, "ID")   !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = Exp();
  t->child[1] = act_param_more();
  strcpy(t->kind_name, "ActParamList");
  return t;
}

struct syntax_node * act_param_more(){
  if(strcmp(current_token->value, ",") !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = douhao();
  t->child[1] = act_param_list();
  strcpy(t->kind_name, "ActParamMore");
  return t;
}

struct syntax_node * other_rel_e(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = cmp_op();
  t->child[1] = Exp();
  strcpy(t->kind_name, "OtherRelE");
  return t;
}

struct syntax_node * other_term(){
  if(strcmp(current_token->value, "+") !=0&&
     strcmp(current_token->value, "-") !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = add_op();
  t->child[1] = Exp();
  strcpy(t->kind_name, "OtherTerm");
  return t;
}

struct syntax_node * other_factor(){
  if(strcmp(current_token->value, "*") !=0&&
     strcmp(current_token->value, "/") !=0)
  {
    return NULL;
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = mult_op();
  t->child[1] = term();
  strcpy(t->kind_name, "OtherFactor");
  return t;
}

struct syntax_node * assignment_rest(){
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  t->child[0] = vari_more();
  t->child[1] = maodenghao();
  t->child[1] = Exp();
  strcpy(t->kind_name, "AssignmentRest");
  return t;
}

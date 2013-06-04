#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct syntax_node * rev_begin(){
  if(strcmp(current_token->kind, "begin") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"begin\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_end(){
  if(strcmp(current_token->kind, "end") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"end\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_var(){
  if(strcmp(current_token->value, "var") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"var\".\n");
    exit(1);
  }
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
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

struct syntax_node * rev_base_type(){
  if(strcmp(current_token->value, "integer") != 0&&
     strcmp(current_token->value, "char"))
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"integer\" or \"char\".\n");
    exit(1);
  }
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  return t;
}

struct syntax_node * rev_array(){
  if(strcmp(current_token->value, "array") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"array\".\n");
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

struct syntax_node * rev_if(){
  if(strcmp(current_token->kind, "if") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"if\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_then(){
  if(strcmp(current_token->kind, "then") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"then\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_else(){
  if(strcmp(current_token->kind, "else") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"else\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_fi(){
  if(strcmp(current_token->kind, "fi") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"fi\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_while(){
  if(strcmp(current_token->kind, "while") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"while\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_do(){
  if(strcmp(current_token->kind, "do") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"do\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_endwh(){
  if(strcmp(current_token->kind, "endwh") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"endwh\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_read(){
  if(strcmp(current_token->kind, "read") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"read\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_write(){
  if(strcmp(current_token->kind, "write") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"write\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
  current_token = current_token->next;
  return t;
}

struct syntax_node * rev_return(){
  if(strcmp(current_token->kind, "return") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss key word \"return\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, "ConditionalStm");
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

struct syntax_node * dianhao(){
  if(strcmp(current_token->value, ".") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss dianhao \".\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * xiaoyuhao(){
  if(strcmp(current_token->value, "<") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss xiaoyuhao \"<\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * jiahao(){
  if(strcmp(current_token->value, "+") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss jiahao \"+\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * jianhao(){
  if(strcmp(current_token->value, "-") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss jianhao \"-\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * chenghao(){
  if(strcmp(current_token->value, "*") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss chenghao \"*\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * chuhao(){
  if(strcmp(current_token->value, "/") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss chuhao \"/\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * fenhao(){
  if(strcmp(current_token->kind, ";") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss fenhao \";\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
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

struct syntax_node * intc(){
  if(strcmp(current_token->kind, "INTC") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss INTC.\n");
    exit(1);
  }
  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * id(){
  if(strcmp(current_token->kind, "ID") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss ID.\n");
    exit(1);
  }
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

struct syntax_node * zuokuohao(){
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

struct syntax_node * youkuohao(){
  if(strcmp(current_token->value, ")") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss youkuohao \")\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * douhao(){
  if(strcmp(current_token->value, ",") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss douhao \",\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

struct syntax_node * maodenghao(){
  if(strcmp(current_token->value, ":=") != 0)
  {
    fprintf(stderr, "line %s has error!\n", current_token->line_number);
    fprintf(stderr, "miss maodeng \":=\".\n");
    exit(1);
  }

  struct syntax_node * t;
  t = (struct syntax_node*)malloc(sizeof(struct syntax_node));

  strcpy(t->kind_name, current_token->value);
  current_token = current_token->next;
  return t;
}

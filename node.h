
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


extern token_node * current_token;
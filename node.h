
struct token_node
{
  char line_number[10];
  char kind[20];
  char value[20];
  struct token_node * next;
};

struct syntax_node
{
  struct syntax_node * child[3];
  struct syntax_node * brother;

  char kind_name[20];
};

extern struct token_node * current_token;

struct syntax_node * array_type();
struct syntax_node * base_type();
struct syntax_node * declare_part();
struct syntax_node * declare_part();
struct syntax_node * denghao();
struct syntax_node * id_program_name();
struct syntax_node * id_type_id();
struct syntax_node * intc();
struct syntax_node * low();
struct syntax_node * parse();
struct syntax_node * proc_decpart();
struct syntax_node * program();
struct syntax_node * program_body();
struct syntax_node * program_head();
struct syntax_node * program_name();
struct syntax_node * rev_array();
struct syntax_node * rev_program();
struct syntax_node * rev_type();
struct syntax_node * shuangdian();
struct syntax_node * structure_type();
struct syntax_node * top();
struct syntax_node * type_dec();
struct syntax_node * type_declist();
struct syntax_node * type_decpart();
struct syntax_node * type_def();
struct syntax_node * type_id();
struct syntax_node * var_decpart();
struct syntax_node * youfangkuo();
struct syntax_node * zuofangkuo();
struct syntax_node * var_dec();
struct syntax_node * pro_dec();
struct syntax_node * fenhao();
struct syntax_node * type_dec_more();
struct syntax_node * rev_base_type();
struct syntax_node * rev_of();

void print_tree(struct syntax_node * t);
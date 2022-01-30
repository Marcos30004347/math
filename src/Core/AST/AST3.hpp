#include "Integer.hpp"
#include <cstddef>
#include <initializer_list>
#include <string>
#include <vector>

namespace ast_teste {
enum kind {
  FACT = (1 << 0),
  POW = (1 << 1),
  MUL = (1 << 2),
  ADD = (1 << 3),
  SUB = (1 << 4),
  DIV = (1 << 5),
  SQRT = (1 << 6),
  INF = (1 << 7),
  NEG_INF = (1 << 8),
  UNDEF = (1 << 9),
  INT = (1 << 10),
  FRAC = (1 << 11),
  SYM = (1 << 12),
  FAIL = (1 << 13),
  FUNC = (1 << 14),
  CONST = INT | FRAC,
  SUMMABLE = MUL | POW | SYM,
  MULTIPLICABLE = POW | SYM | ADD,
  NON_CONSTANT = SYM | FUNC,
  TERMINAL = FAIL | UNDEF | FAIL | INF | NEG_INF | SYM | INT | FRAC,
	ORDERED = POW | DIV | SQRT | FUNC
};

struct ast {
  kind kind_of = UNDEF;

  union {
    char *ast_sym;
    Int *ast_int;
  };

	std::vector<ast> ast_childs;

	ast();
	ast(kind k);
	ast(ast&& other);
	ast(const ast& other);

	~ast();



	ast& operator=(const ast&);
	ast& operator=(ast&&);

	ast& operator[](size_t idx);

	ast operator+(const ast&);
	ast operator+(ast&&);
	ast operator-(const ast&);
	ast operator-(ast&&);
	ast operator*(const ast&);
	ast operator*(ast&&);
	ast operator/(const ast&);
	ast operator/(ast&&);

	ast& operator+=(const ast&);
	ast& operator+=(ast&&);
	ast& operator-=(const ast&);
	ast& operator-=(ast&&);

	friend ast pow(const ast& a, const ast& b);
	friend ast pow(ast&& a, ast&& b);
	friend ast pow(ast&& a, const ast& b);
	friend ast pow(const ast& a, ast&& b);

	friend ast sqrt(const ast& a);
	friend ast sqrt(ast&& a);

	friend ast fact(const ast& a);
	friend ast fact(ast&& a);
};

void insert(ast *a, const ast& b);
void insert(ast *a, ast&& b);

void insert(ast *a, const ast& b, size_t idx);
void insert(ast *a, ast&& b, size_t idx);

void remove(ast *a, size_t idx);
void remove(ast *a);

void sort(ast *a);

ast create(kind kind);

ast create(kind kind, std::initializer_list<ast>&&);

ast symbol(const char *id);

ast integer(Int value);

ast fraction(Int num, Int den);

inline ast *operand(ast *a, size_t i) { return &a->ast_childs[i]; }

inline int is(ast *a, int k) { return a->kind_of & k; }

inline size_t size_of(ast *ast) { return ast->ast_childs.size(); }

inline kind kind_of(ast *ast) { return ast->kind_of; }

inline char *get_id(ast *ast) { return ast->ast_sym; }

inline Int get_val(ast *ast) { return Int(*ast->ast_int); }

inline char *get_func_id(ast *ast) { return ast->ast_sym; }

std::string to_string(ast *a);

int compare(ast *a, ast *b, kind ctx);

void reduce(ast *a);

void expand(ast *a);

void ast_print(ast *a, int tabs = 0);

// class expression {
//   ast *root = 0;
// 	expression* child = 0;

// 	explicit expression(ast *d);

//   ast *remove_data();

// 	expression();

// public:
//   expression(Int v);
//   expression(int v);
//   expression(long int v);
//   expression(long long v);

// 	expression(expression &);
//   expression(expression &&);

//   expression(std::string v);

//   ~expression();

//   expression &operator[](size_t i);

//   expression operator+(expression &a);
//   expression operator+(expression &&a);

//   expression operator-(expression &a);
//   expression operator-(expression &&a);

//   expression operator*(expression &a);
//   expression operator*(expression &&a);

//   expression operator/(expression &a);
//   expression operator/(expression &&a);

//   expression &operator=(expression &a);
//   expression &operator=(expression &&a);

//   void printAST() const;
// 	std::string toString() const;
// };

} // namespace ast_teste

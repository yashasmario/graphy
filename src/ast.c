
ASTNode* parse_expression(const char* expr, char* err_buf, size_t err_buf_len);
double   evaluate(const ASTNode* node, double x);
void     free_ast(ASTNode* node);

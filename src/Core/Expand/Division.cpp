#include "Division.hpp"

using namespace ast;
using namespace algebra;

namespace expand {

AST* expandDivision(AST* n, AST* d) {
	if(n->numberOfOperands() > 1) {
		AST* e = new AST(n->kind());
		for(unsigned int i=0; i<n->numberOfOperands(); i++)
			e->includeOperand(
				div(
					n->operand(i)->deepCopy(),
					d->deepCopy()
				)
			);			
		return e;
	}
	return div(n->deepCopy(), d->deepCopy());
}

AST* expandDivisionAST(AST* n) {
	return expandDivision(n->operand(0), n->operand(1));
}

}

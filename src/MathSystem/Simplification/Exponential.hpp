#ifndef SIMPLIFICATION_TRIGONOMETRIC_H
#define SIMPLIFICATION_TRIGONOMETRIC_H

#include "MathSystem/Algebra/Algebra.hpp"

namespace simplification {

ast::Expr reduceExponentialAST(ast::Expr& u);
ast::Expr reduceExponentialAST(ast::Expr&& u);

}

#endif
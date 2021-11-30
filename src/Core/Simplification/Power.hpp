#ifndef SIMPLIFICATION_POWER_H
#define SIMPLIFICATION_POWER_H

#include "Core/Algebra/Algebra.hpp"

namespace simplification {

ast::Expr reducePowerExpr(ast::Expr& u);
ast::Expr reducePowerExpr(ast::Expr&& u);

}

#endif

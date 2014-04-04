/**
 * Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
 *
 * Please see distribution for license.
 */

#include <stdio.h>
#include "entrypt.hh"
#include "dispatch.hh"
#include "numeric.hh"
#include "expression.hh"
#include "execution.hh"
#include "terminal.hh"
#include "exprtypeenum.h"
#include <typeinfo>
#include <iostream>

using namespace std;

namespace librdag
{
/*
 * forward definition of the Walker class, this class essentially encapsulates walking
 * an OGNumeric tree.
 */
class Walker
{
    int level;
    librdag::Visitor * visitor;
  public:
    Walker();
    ~Walker();
    librdag::OGNumeric * walk(librdag::OGNumeric* numeric_expr_types);
    void talkandwalk(librdag::OGNumeric const * numeric_expr_types);
};

/**
 * Visitor for printing info specific to tree nodes
 */
class PrintTreeVisitor: public librdag::Visitor
{
    Walker * _walker;
  public:
    PrintTreeVisitor(Walker * walker)
    {
      _walker = walker;
    }
    ~PrintTreeVisitor()
    {
      _walker = NULL;
    }
    virtual void visit(librdag::OGExpr const *thing) override
    {
      cout << "Have OGExpr type ";
      thing->debug_print();
      cout << "\n";
      const ArgContainer& tmp = thing->getArgs();
      //hmmm perhaps we should either store the args as a raw array, or insist on everything being a vector.
      // anyway, walk over given args
      for(auto it = tmp.begin();  it != tmp.end(); it++)
      {
        _walker->talkandwalk(*(it));
      }
    };
    void visit(librdag::OGScalar<real16> const *thing) override
    {
      cout << "Have OGScalar<real16> " << thing << endl;
    }
    void visit(librdag::OGScalar<complex16> const *thing) override
    {
      cout << "Have OGScalar<complex16> " << thing << endl;
    }
    void visit(librdag::OGScalar<int> const *thing) override
    {
      cout << "Have OGScalar<int> " << thing << endl;
    }
    void visit(librdag::OGMatrix<real16> const *thing) override
    {
      cout << "Have OGMatrix<real16> " << thing << endl;
    }
    void visit(librdag::OGMatrix<complex16> const *thing) override
    {
      cout << "Have OGMatrix<complex16> " << thing << endl;
    }
    void visit(librdag::OGDiagonalMatrix<real16> const *thing) override
    {
      cout << "Have OGDiagonalMatrix<real16> " << thing << endl;
    }
    void visit(librdag::OGDiagonalMatrix<complex16> const *thing) override
    {
      cout << "Have OGDiagonalMatrix<complex16> " << thing << endl;
    }
    void visit(librdag::OGSparseMatrix<real16> const *thing) override
    {
      cout << "Have OGSparseMatrix<real16> " << thing << endl;
    }
    void visit(librdag::OGSparseMatrix<complex16> const *thing) override
    {
      cout << "Have OGSparseMatrix<complex16> " << thing << endl;
    }
};

/*
 * Definition of Walker class
 * a bit hideous, Walker has internal state for "level" so we pass "this" to the PrintTreeVisitor
 */
Walker::Walker()
{
  level = 0;
  visitor = new PrintTreeVisitor(this);
}

Walker::~Walker()
{
  delete visitor;
}

librdag::OGNumeric * Walker::walk(librdag::OGNumeric * numeric_expr_types)
{
  printf("Walking DAG.\n");
  this->talkandwalk(numeric_expr_types);
  printf("Finished Walking DAG.\n");
  return numeric_expr_types;
}
void Walker::talkandwalk(librdag::OGNumeric const * numeric_expr_types)
{
  level++;
  const char ch = ' ';
  cout << std::string(level*2,ch);
  numeric_expr_types->accept(*visitor);
  level--;
}

const OGTerminal*
entrypt(const OGNumeric* expr)
{
  const OGTerminal* asTerminal = expr->asOGTerminal();
  if (asTerminal!=nullptr)
  {
    // If we were passed a terminal, return a copy of it.
    // Slightly fiddly because we get an OGNumeric* back from copy.
    return asTerminal->copy()->asOGTerminal();
  }
  else
  {
    ExecutionList* el = new ExecutionList(expr);
    Dispatcher * disp = new Dispatcher();
    
    DEBUG_PRINT("Dispatching from entrypt\n");

    for (auto it = el->begin(); it != el->end(); ++it)
    {
      const OGExpr* exprToDispatch = (*it)->asOGExpr();
      if (exprToDispatch != nullptr)
      {
        disp->dispatch(exprToDispatch);
      }
    }

    const RegContainer * reg = expr->asOGExpr()->getRegs();
    
    // Make a copy of the result because it gets blown away by the deletion of the tree
    const OGNumeric * answer = (*reg)[0]->copy();
    const OGTerminal * returnTerm = answer->asOGTerminal();
    
    if(returnTerm==nullptr)
    {
      throw rdag_error("Evaluated terminal is not casting asOGTerminal correctly.");
    }
    delete disp;
    delete el;
    return returnTerm;
  }
}

} // namespace librdag

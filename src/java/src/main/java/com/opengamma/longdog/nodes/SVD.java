/**
 * Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
 *
 * Please see distribution for license.
 */

package com.opengamma.longdog.nodes;

import com.opengamma.longdog.datacontainers.ExprTypeEnum;
import com.opengamma.longdog.datacontainers.OGNumeric;
import com.opengamma.longdog.datacontainers.lazy.OGExprVariadicReturn;

/**
 * SVD class.
 */
public class SVD extends OGExprVariadicReturn {

  private static int s_nPossibleResults = 3;

  @Override
  public ExprTypeEnum getType() {
    return ExprTypeEnum.SVD;
  }

  public SVD(OGNumeric arg0) {
    super(arg0, s_nPossibleResults);
  }

}
/**
 * Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
 * 
 * Please see distribution for license.
 */
package com.opengamma.maths.datacontainers.matrix;

import static org.testng.Assert.assertTrue;
import static org.testng.AssertJUnit.assertFalse;

import java.util.Arrays;

import org.testng.annotations.Test;

import com.opengamma.maths.datacontainers.ExprEnum;
import com.opengamma.maths.datacontainers.matrix.OGComplexDiagonalMatrix;
import com.opengamma.maths.datacontainers.scalar.OGComplexScalar;
import com.opengamma.maths.exceptions.MathsExceptionIllegalArgument;
import com.opengamma.maths.exceptions.MathsExceptionNullPointer;
import com.opengamma.maths.helpers.DenseMemoryManipulation;
import com.opengamma.maths.helpers.FuzzyEquals;

/**
 * Tests the {@link OGComplexDiagonalMatrix} Class
 */
public class OGComplexDiagonalMatrixTest {

  double[] data4x3diagdreal = new double[] { 1, 2, 3 };
  double[] data4x3diagdimag = new double[] { 10, 20, 30 };
  double[] interleavedfull4x3 = DenseMemoryManipulation.convertTwoSinglePointersToInterleavedSinglePointer(data4x3diagdreal, data4x3diagdimag);
  double[] interleavedreal4x3 = DenseMemoryManipulation.convertSinglePointerToZeroInterleavedSinglePointer(data4x3diagdreal);
  OGComplexScalar[][] data4x3full = new OGComplexScalar[][] {//
  { new OGComplexScalar(1, 10), new OGComplexScalar(0.00), new OGComplexScalar(0.00) },//
    { new OGComplexScalar(0.00), new OGComplexScalar(2, 20), new OGComplexScalar(0.00) }, //
    { new OGComplexScalar(0.00), new OGComplexScalar(0.00), new OGComplexScalar(3, 30) },//
    { new OGComplexScalar(0.00), new OGComplexScalar(0.00), new OGComplexScalar(0.00) } };

  OGComplexDiagonalMatrix defaultVal = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 4, 3);
  OGComplexDiagonalMatrix same = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 4, 3);
  OGComplexDiagonalMatrix withindiffnumber = new OGComplexDiagonalMatrix(new double[] { 1 + FuzzyEquals.getDefaultTolerance() / 2, 2, 3 }, data4x3diagdimag, 4, 3);
  OGComplexDenseMatrix diffclass = new OGComplexDenseMatrix(1);
  OGComplexDiagonalMatrix diffrows = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 7, 3);
  OGComplexDiagonalMatrix diffcols = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 4, 5);
  OGComplexDiagonalMatrix diffnumber = new OGComplexDiagonalMatrix(new double[] { 1337, 2, 3 }, data4x3diagdimag, 4, 3);
  OGComplexDenseMatrix samediffclass = new OGComplexDenseMatrix(new double[][] { { 1, 0, 0 }, { 0, 2, 0 }, { 0, 0, 3 }, { 0, 0, 0 } }, new double[][] { { 10, 0, 0 }, { 0, 20, 0 }, { 0, 0, 30 },
    { 0, 0, 0 } });

  // sending in null ptr double[] constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrConstructorNullPtrTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(tmp);
  }

  // sending in null ptr double[], int, int constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrIntIntConstructorNullPtrTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(tmp, 1, 1);
  }

  // sending in null ptr double[] double[] constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrDoublePtrConstructorNullPtrFirstArgTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(tmp, data4x3diagdimag);
  }

  // sending in null ptr double[] double[] constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrDoublePtrConstructorNullPtrSecondArgTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(data4x3diagdreal, tmp);
  }

  // sending in null ptr OGComplexScalar[] constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testOGComplexScalarPtrConstructorNullPtrTest() {
    OGComplexScalar[] tmp = null;
    new OGComplexDiagonalMatrix(tmp);
  }

  // sending in null ptr double[] double[] int int  constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrDoublePtrIntIntConstructorNullPtrFirstArgTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(tmp, data4x3diagdimag, 4, 3);
  }

  // sending in null ptr double[] double[] int int  constructor
  @Test(expectedExceptions = MathsExceptionNullPointer.class)
  public void testDoublePtrDoublePtrIntIntConstructorNullPtrSecondArgTest() {
    double[] tmp = null;
    new OGComplexDiagonalMatrix(data4x3diagdreal, tmp, 4, 3);
  }

  // sending in non commuting args double[] double[]  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrDoublePtrConstructorNonConformantArgTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, new double[] { 1, 2 });
  }

  // sending in non commuting args double[] double[] int int  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrDoublePtrIntIntConstructorNonConformantArgTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, new double[] { 1, 2 }, 4, 3);
  }

  // sending in bad rows double[], int, int constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrIntIntConstructorBadRowsDataTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, -1, 3);
  }

  // sending in bad rows double[], int, int  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrIntIntConstructorBadColsDataTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, 3, -1);
  }

  // sending in bad rows double[], double[], int, int constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrDoublePtrIntIntConstructorBadRowsDataTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, -1, 3);
  }

  // sending in bad rows double[], double[], int, int  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoublePtrDoublePtrIntIntConstructorBadColsDataTest() {
    new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 3, -1);
  }

  // sending in bad rows double, int, int constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoubleIntIntConstructorBadRowsDataTest() {
    new OGComplexDiagonalMatrix(1, -1, 3);
  }

  // sending in bad cols double, int, int  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoubleIntIntConstructorBadColsDataTest() {
    new OGComplexDiagonalMatrix(1, 3, -1);
  }

  // sending in bad rows double, int, int constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoubleDoubleIntIntConstructorBadRowsDataTest() {
    new OGComplexDiagonalMatrix(1, 2, -1, 3);
  }

  // sending in bad cols double, int, int  constructor
  @Test(expectedExceptions = MathsExceptionIllegalArgument.class)
  public void testDoubleDoubleIntIntConstructorBadColsDataTest() {
    new OGComplexDiagonalMatrix(1, 2, 3, -1);
  }

  // sending in ok OGComplexScalar[] constructor
  @Test
  public void testOGComplexScalarPtrConstructorInternalDataTest() {
    OGComplexScalar[] tmp = new OGComplexScalar[] { new OGComplexScalar(1, 10), new OGComplexScalar(2, 20), new OGComplexScalar(3, 30) };
    new OGComplexDiagonalMatrix(tmp);
  }

  // sending in ok double[] constructor
  @Test
  public void testDoublePtrConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), interleavedreal4x3));
    assertTrue(D.getRows() == 3);
    assertTrue(D.getCols() == 3);
  }

  // sending in ok double[] double[] constructor
  @Test
  public void testDoublePtrDoublePtrConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), interleavedfull4x3));
    assertTrue(D.getRows() == 3);
    assertTrue(D.getCols() == 3);
  }

  // sending in ok double[] double[] constructor
  @Test
  public void testDoublePtrDoublePtrIntIntConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag, 4, 3);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), interleavedfull4x3));
    assertTrue(D.getRows() == 4);
    assertTrue(D.getCols() == 3);
  }

  // sending in ok double[], int, int constructor
  @Test
  public void testDoublePtrIntIntConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, 6, 7);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), new double[] { 1, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0 }));
    assertTrue(D.getRows() == 6);
    assertTrue(D.getCols() == 7);
  }

  // sending in ok double, int, int  constructor
  @Test
  public void testDoubleIntIntConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(3, 13, 37);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), new double[] { 3 }));
    assertTrue(D.getRows() == 13);
    assertTrue(D.getCols() == 37);
  }

  // sending in ok double constructor
  @Test
  public void testDoubleConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(3.d);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), new double[] { 3 }));
    assertTrue(D.getRows() == 1);
    assertTrue(D.getCols() == 1);
  }

  // sending in ok int constructor
  @Test
  public void testIntConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix((int) 3);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), new double[] { 3 }));
    assertTrue(D.getRows() == 1);
    assertTrue(D.getCols() == 1);
  }

  // sending in ok real imag constructor
  @Test
  public void testDoubleDoubleConstructorInternalDataTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix((double) 3, (double) 4);
    assertTrue(D.getClass() == OGComplexDiagonalMatrix.class);
    assertTrue(Arrays.equals(D.getData(), new double[] { 3, 4 }));
    assertTrue(D.getRows() == 1);
    assertTrue(D.getCols() == 1);
  }

  // test get rows
  @Test
  public void testGetRowsTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, 4, 3);
    assertTrue(D.getRows() == 4);
  }

  // test get cols
  @Test
  public void testGetColumnsTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, 4, 3);
    assertTrue(D.getCols() == 3);
  }

  @Test
  public void testGetTypeEnum() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag);
    assertTrue(D.getType().equals(ExprEnum.OGComplexDiagonalMatrix));
  }

  @Test
  public void toStringTest() {
    OGComplexDiagonalMatrix D = new OGComplexDiagonalMatrix(data4x3diagdreal, data4x3diagdimag);
    D.toString();
  }
  
  @Test
  public void testHashCode() {
    assertTrue(defaultVal.hashCode() == same.hashCode());
    assertFalse(defaultVal.hashCode() == diffnumber.hashCode());
  }

  @Test
  public void testEquals() {
    assertTrue(defaultVal.equals(defaultVal));
    assertTrue(defaultVal.equals(same));
    assertFalse(defaultVal.equals(diffrows));
    assertFalse(defaultVal.equals(diffcols));
    assertFalse(defaultVal.equals(diffclass));
    assertFalse(defaultVal.equals(diffnumber));
  }

  @Test
  public void testFuzzyEquals() {
    assertTrue(defaultVal.fuzzyequals(defaultVal));
    assertTrue(defaultVal.fuzzyequals(same));
    assertTrue(defaultVal.fuzzyequals(withindiffnumber));
    assertFalse(defaultVal.fuzzyequals(diffrows));
    assertFalse(defaultVal.fuzzyequals(diffcols));
    assertFalse(defaultVal.fuzzyequals(diffclass));
    assertFalse(defaultVal.fuzzyequals(diffnumber));
    assertFalse(defaultVal.fuzzyequals(samediffclass));
  }

  @Test
  public void testMathsEquals() {
    assertTrue(defaultVal.mathsequals(defaultVal));
    assertTrue(defaultVal.mathsequals(same));
    assertTrue(defaultVal.mathsequals(withindiffnumber));
    assertFalse(defaultVal.mathsequals(diffclass));
    assertFalse(defaultVal.mathsequals(diffrows));
    assertFalse(defaultVal.mathsequals(diffcols));
    assertFalse(defaultVal.mathsequals(diffnumber));
    assertTrue(defaultVal.mathsequals(samediffclass));
  }

}


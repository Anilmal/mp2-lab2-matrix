#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> mx(8);
	TMatrix<int> mx1(mx);
	EXPECT_EQ(mx,mx1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> mx(8);
	TMatrix<int> mx1(mx);
	EXPECT_TRUE( &mx[0][0]!= &mx[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> mx(10);
	EXPECT_EQ(mx.GetSize(),10);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> mx(10);
	ASSERT_NO_THROW(mx[8][7] = 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mx(10);
	ASSERT_ANY_THROW(mx[-10][-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mx(3);
	ASSERT_ANY_THROW(mx[MAX_MATRIX_SIZE + 1][MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mx(10);
	ASSERT_NO_THROW(mx = mx);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> mx(3);
	TMatrix<int> mx1(3);
	mx1[0][0] = 1;
	ASSERT_NO_THROW(mx = mx1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> mx(5);
	TMatrix<int> mx1(3);
	mx = mx1;
	EXPECT_EQ(3, mx.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> mx(5);
	TMatrix<int> mx1(6);
	for (int i=0;i<6;i++)
    	mx1[i][i] = i;
	ASSERT_NO_THROW(mx = mx1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mx(7);
	TMatrix<int> mx1(7);
	mx = mx1;
	EXPECT_TRUE(mx == mx1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mx(4);
	EXPECT_TRUE(mx == mx);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mx(8);
	TMatrix<int> mx1(3);
	EXPECT_TRUE(mx != mx1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mx(8);
	TMatrix<int> mx1(8);
	ASSERT_NO_THROW(mx + mx1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mx(7);
	TMatrix<int> mx1(3);
	ASSERT_ANY_THROW(mx + mx1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> mx(6);
	TMatrix<int> mx1(6);
	ASSERT_NO_THROW(mx - mx1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mx(6);
	TMatrix<int> mx1(4);
	ASSERT_ANY_THROW(mx - mx1);
}
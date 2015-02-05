/*
 * =====================================================================================
 *
 *       Filename:  max_product.cc
 *
 *    Description:  max product algorithms
 *
 *        Version:  1.0
 *        Created:  02/05/2015 05:56:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

template<typename Type>
inline Type Max(Type t1, Type t2, Type t3)
{
	t1 = t1 > t2 ? t1 : t2;
	return t1 > t3 ? t1 : t3;
}

template<typename Type>
inline Type Min(Type t1, Type t2, Type t3)
{
	t1 = t1 < t2 ? t1 : t2;
	return t1 < t3 ? t1 : t3;
}

/*
 * Find the maximum continuous product sub-array
 */
template<typename Type>
Type MaxContinuousProduct(Type* array, int32_t size)
{
	int i;
	Type max;
	Type* max_array = (Type*)malloc(size*sizeof(Type));
	Type* min_array = (Type*)malloc(size*sizeof(Type));

	max = array[0];
	max_array[0] = array[0];
	min_array[0] = array[0];
	for(i = 1; i < size; ++i)
	{
		max_array[i] = Max(array[i], array[i] * max_array[i-1], array[i]*min_array[i-1]);
		min_array[i] = Min(array[i], array[i] * max_array[i-1], array[i]*min_array[i-1]);
		if(max_array[i] > max)
			max = max_array[i];
	}
	free(max_array);
	free(min_array);
	return max;
}

int main()
{
	int array[9] = {-3, 5, 5, 10, -3, 9, 8, 2, -1};
	int ans = MaxContinuousProduct(array, 9);
	fprintf(stdout, "Max: %d\n", ans);
	return 0;
}

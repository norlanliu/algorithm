/*
 * =====================================================================================
 *
 *       Filename:  2_Median_Two_Sorted_Arrays.cc
 *
 *    Description:  Find the median of two sorted arrays.
 *
 *        Version:  1.0
 *        Created:  02/17/2015 04:16:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdio.h>

double findKthNumber(int A[], int abgn, int aend, int B[], int bbgn, int bend, int k);
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	if(m == 0 && n > 0)
	{
		if(n & 1)
			return B[n/2];
		else
			return (double)(B[n/2-1] + B[n/2]) / 2;
	}
	else if(m != 0 && n == 0)
	{
		if(m & 1)
			return A[m/2];
		else
			return (double)(A[m/2-1] + A[m/2]) / 2;
	}
	else if(m <= 0 && n <= 0)
		return -1;

	int k = (m + n + 1) / 2;
	if((m+n) & 1)
		return findKthNumber(A, 0, m-1, B, 0, n-1, k);
	else
		return (double)(findKthNumber(A, 0, m-1, B, 0, n-1, k) + 
				findKthNumber(A, 0, m-1, B, 0, n-1, k+1)) / 2;

}

double findKthNumber(int A[], int abgn, int aend, int B[], int bbgn, int bend, int k)
{
	if(abgn > aend)
	{
		return B[bbgn + k - 1];
	}
	if(bbgn > bend)
	{
		return A[abgn + k - 1];
	}

	int amid = abgn + (aend - abgn) / 2;
	int bmid = bbgn + (bend - bbgn) / 2;
	int length = amid - abgn + bmid - bbgn + 2;

	if(A[amid] < B[bmid])
	{
		if(length > k)
			return findKthNumber(A, abgn, aend, B, bbgn, bmid-1, k);
		else
			return findKthNumber(A, amid+1, aend, B, bbgn, bend, k-(amid - abgn + 1));
	}
	else
	{
		if(length > k)
			return findKthNumber(A, abgn, amid-1, B, bbgn, bend, k);
		else
			return findKthNumber(A, abgn, aend, B, bmid+1, bend, k-(bmid - bbgn + 1));
	}
}

int main()
{
	int A[] = {1};
	int B[] = {4};

	double mid = findMedianSortedArrays(A, 1, B, 1);
	fprintf(stdout, "%lf\n", mid);
	return 0;
}

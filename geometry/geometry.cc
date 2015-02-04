/*
 * =====================================================================================
 *
 *       Filename:  segment.cc
 *
 *    Description:  some segment algorithms
 *
 *        Version:  1.0
 *        Created:  01/22/2015 09:43:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <float.h>
#include <cmath>

const int32_t CLOCKWISE_SIGNAL = 1;
const int32_t COUNTER_CLOCKWISE_SIGNAL = -1;
const int32_t COLLINEAR = 0;
#define SAME_SIGN(x, y) (((x) > 0) ^ ((y) < 0))
typedef struct _Point{
	double x;
	double y;
}Point_t;
typedef struct _Line{
	Point_t start;
	Point_t end;
}Line_t;

typedef struct _CrossPoint{
	Point_t point;
	double cross_mult;
}CrossPoint_t;

typedef struct _PointArray{
	Point_t* points;
	int32_t size;
}PointArray_t;

double Distance(Point_t p1, Point_t p2)
{
	return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
}

double CrossMultiply(Point_t p1, Point_t p2, Point_t p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}

int ComparePolarAngel(const void* first,const void* second)
{
	int ret = 0;
	CrossPoint_t* cp1 = (CrossPoint_t*)first;
	CrossPoint_t* cp2 = (CrossPoint_t*)second;
	if(cp1->cross_mult == cp2->cross_mult)
		ret = 0;
	else if(cp1->cross_mult == 0)
		return -1;
	else if(cp2->cross_mult == 0)
		return 1;
	else if((cp1->cross_mult > 0 && cp2->cross_mult > 0) ||
			(cp1->cross_mult < 0 && cp2->cross_mult < 0))
	{
		if(cp1->cross_mult < cp2->cross_mult)
			ret = -1;
		else
			ret = 1;
	}
	else if(cp1->cross_mult < 0)
		ret = 1;
	else 
		ret = -1;
	
	return ret;
}
/*
 * Sort points by polar angel related to points[0]
 * If more than one point has same polar angel,
 * remove all but the one that is farthest from points[0]
 */
PointArray_t SortPointsByPolarAngel(Point_t* points, int32_t size)
{
	int32_t i, j;
	double x;
	CrossPoint_t* cpoints = (CrossPoint_t*)malloc(size*sizeof(CrossPoint_t));
	PointArray_t ps;
	ps.points = (Point_t*)malloc(size*sizeof(Point_t));
	for(i = 1; i < size; ++i)
	{
		x = points[i].x - points[0].x;
		cpoints[i].point = points[i];
		if(x == 0)
			cpoints[i].cross_mult = DBL_MAX;
		else
			cpoints[i].cross_mult = (points[i].y - points[0].y)/x;
	}
	qsort(cpoints+1, size-1, sizeof(CrossPoint_t), ComparePolarAngel); 
	ps.points[0] = points[0];
	ps.points[1] = cpoints[1].point;
	for(i = 2, j = 1; i < size; ++i)
	{
		if(cpoints[i].cross_mult == cpoints[j].cross_mult)
		{
			if(Distance(points[0], ps.points[j]) < Distance(points[0],
						cpoints[i].point))
				ps.points[j] = cpoints[i].point;
		}
		else
			ps.points[++j] = cpoints[i].point;
	}
	ps.size = j+1;
	free(cpoints);

	return ps;
}
/*
 * Find the left-bottom point of the points array
 */
void FindLeftBottomPoint(Point_t* points, int32_t size)
{
	int i;
	Point_t p = points[0];
	for(i = 1; i < size; ++i)
	{
		if((points[i].y < p.y) || (points[i].y == p.y && points[i].x < p.x))
		{
			p = points[i];
			points[i] = points[0];
			points[0] = p;
		}
	}
}

/*
 * Judge the direction of second line related to first line
 * @RET 
 *     1  for clockwise
 *     -1 for counter clockwise
 *     0  for collinear
 */
int32_t JudgeDirection(const Point_t origin, const Point_t first, const Point_t second)
{
	double vx = (first.x - origin.x) * (second.y - origin.y);
	double vy = (first.y - origin.y) * (second.x - origin.x);
	vx -= vy;
	if(vx < 0)
		return CLOCKWISE_SIGNAL;
	else if(vx > 0)
		return COUNTER_CLOCKWISE_SIGNAL;
	else
		return COLLINEAR;
}
/*
 * Graham scan algorithm for finding the convex hull
 */
void GrahamScan(Point_t* points, int32_t size, PointArray_t* stack)
{
	int i, top, new_size;
	PointArray_t points_array;
	Point_t* rpoints;

	FindLeftBottomPoint(points, size);
	points_array = SortPointsByPolarAngel(points, size);

	rpoints = points_array.points;
	new_size = points_array.size;

	top = 0;
	stack->points[top++] = rpoints[0];
	stack->points[top++] = rpoints[1];
	stack->points[top++] = rpoints[2];

	for(i = 3; i < new_size; ++i)
	{
		if(JudgeDirection(stack->points[top-2], stack->points[top-1],
					rpoints[i]) != COUNTER_CLOCKWISE_SIGNAL)
		{
			top--;
		}
		stack->points[top++] = rpoints[i];
	}
	stack->size = top;

	free(rpoints);
}

bool OnSegment(const Point_t p1, const Point_t p2, const Point_t p0)
{
	if(((p0.x > p1.x) && (p0.x < p2.x)) || ((p0.x < p1.x) && (p0.x > p2.x)))
		return true;
	else if(((p0.y > p1.y) && (p0.y < p2.y)) || ((p0.y < p1.y) && (p0.y > p2.y)))
		return true;
	else
		return false;
}
/*
 * Judge whether tow lines intersect
 */
bool JudgeIntersection(const Line_t first, const Line_t second)
{
	bool ret = false;
	int32_t start2first = JudgeDirection(first.start, first.end, second.start);
	int32_t end2first = JudgeDirection(first.start, first.end, second.end);
	int32_t start2second = JudgeDirection(second.start, second.end, first.start);
	int32_t end2second = JudgeDirection(second.start, second.end, first.end);

	if(((start2first > 0 && end2first < 0) ||  (start2first < 0 && end2first > 0)) &&
				((start2second > 0 && end2second < 0) || (start2second < 0 && end2second > 0)))
		ret = true;
	else if((start2first == 0) && OnSegment(first.start, first.end, second.start))
		ret = true;
	else if((end2first == 0) && OnSegment(first.start, first.end, second.end))
		ret = true;
	else if((start2second == 0) && OnSegment(second.start, second.end, first.start))
		ret = true;
	else if((end2second == 0) && OnSegment(second.start, second.end, first.end))
		ret = true;

	return ret;
}

Point_t* ReadPointsData(const char* file_name, int32_t* size)
{
	int i, count;
	Point_t* points;
	freopen(file_name, "r", stdin);
	scanf("%d", size);
	count = *size;
	points = (Point_t*)malloc(count * sizeof(Point_t));
	for(i = 0; i < count; ++i)
	{
		scanf("%lf %lf", &(points[i].x), &(points[i].y)); 
	}
	return points;
}

int main()
{
	int32_t start;
	Point_t first, second;
	Line_t line1, line2;

	first.x = 1;
	first.y = 1;
	second.x = 3;
	second.y = 3;
	line1.start = first;
	line1.end = second;

	first.x = 1;
	first.y = 0;
	second.x = 1;
	second.y = 6;
	line2.start = first;
	line2.end = second;

	fprintf(stdout, "Line Ans: %d\n", JudgeIntersection(line1, line2));

	//Test Graham scan algorithm
	int size;
	Point_t* points;
	PointArray_t stack; 

	const char* file_name = "points.data";
	points = ReadPointsData(file_name, &size);
	stack.size = 0;
	stack.points = (Point_t*)malloc(size*sizeof(Point_t));
	start = clock();
	GrahamScan(points, size, &stack);
	fprintf(stdout, "Time : %.3lf\n", double(clock()-start)/CLOCKS_PER_SEC); 
	fprintf(stdout, "Convex Hull Size: %d \n", stack.size);
	free(points);
	free(stack.points);
	return 0;
}

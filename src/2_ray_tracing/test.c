#include "../../inc/minirt.h"

// int	main(void)
// {
// 	double	angle;

// 	angle = acos((0 * 0 + 0 * 0 + 1 * 1) / sqrt((0 * 0) + (0 * 0) + (1 * 1)));
// 	printf ("angle = %lf\n", angle);
// 	return (0);
// }

// double	distance_between_two_points(t_point3 p1, t_point3 p2)
// {
// 	double	len;

// 	len = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y))
// 		+ ((p2.z - p1.z) * (p2.z - p1.z)));
// 	return (len);
// }

// int	is_on_line(t_point3 center, t_vec3 vector, double len, t_point3 hit_point)
// {
// 	double		distance;
// 	t_point3	test_point;

// 	distance = distance_between_two_points(center, hit_point);
// 	if (distance > len)
// 		return (0);
// 	test_point.x = center.x + (vector.x * distance);
// 	test_point.y = center.y + (vector.y * distance);
// 	test_point.z = center.z + (vector.z * distance);
// 	if(test_point.x == hit_point.x && test_point.y == hit_point.y && test_point.z == hit_point.z)
// 		return (1);
// 	return (0);
// }

// testing is on line

// int	main(void)
// {
// 	t_point3	center;
// 	t_vec3		vector;
// 	t_point3	hit_point;
// 	int	ret;

// 	center.x = 0;
// 	center.y = 0;
// 	center.z = 0;
// 	vector.x = 1;
// 	vector.y = 0;
// 	vector.z = 0;
// 	hit_point.x = 5.01;
// 	hit_point.y = 0;
// 	hit_point.z = 0;
// 	ret = is_on_line(center, vector, 5, hit_point);
// 	printf("ret = %d\n",ret);
// 	return (0);
// }

SELECT x, y, z,
CASE WHEN (x+y>z AND x+z>y AND y+z>x) THEN 'Yes' ELSE 'No'
END AS triangle
FROM Triangle


SELECT *, IF(x+y>z and x+z>y and y+z>x, 'Yes', 'No') as triangle FROM triangle
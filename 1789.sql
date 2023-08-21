# Write your MySQL query statement below

SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(department_id) = 1
UNION
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y';


-- some tricks
select employee_id,
       coalesce(max(case when primary_flag='Y' then department_id else null end), max(department_id)) department_id
  from employee t
  group by employee_id


  select employee_id, 
  abs(max(if(primary_flag = 'Y', department_id, -department_id))) as department_id
  from Employee 
  group by employee_id;



SELECT employee_id, department_id
FROM (SELECT *, COUNT(*) OVER(PARTITION BY employee_id) cnt
FROM Employee) t1
WHERE (cnt=1) OR (cnt<>1 AND primary_flag='Y');
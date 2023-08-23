-- we would have used FULL OUTER JOIN but its not available on mysql, thus we have to create one ourselves

SELECT t.employee_id
FROM
    (SELECT * FROM Employees LEFT JOIN Salaries USING(EMPLOYEE_ID)
    UNION
    SELECT * FROM Employees RIGHT JOIN Salaries USING(EMPLOYEE_ID))
AS t
WHERE t.salary IS NULL OR t.name IS NULL
ORDER BY employee_id;









SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION 
SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)

ORDER BY 1;
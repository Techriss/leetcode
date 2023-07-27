SELECT e2.unique_id, e1.name
FROM Employees e1
LEFT JOIN EmployeeUNI e2
ON e1.id = e2.id;

SELECT unique_id, name
FROM Employees
LEFT JOIN EmployeeUNI
USING(id);
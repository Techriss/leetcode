SELECT e.name as Employee
FROM Employee e
INNER JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;


SELECT name AS Employee FROM Employee e WHERE (SELECT salary FROM Employee WHERE id=e.managerId) < e.salary
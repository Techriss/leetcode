SELECT name, bonus
FROM (Employee LEFT JOIN Bonus USING(empId))
WHERE COALESCE(bonus, 0) < 1000;



SELECT name, bonus
FROM Employee LEFT JOIN Bonus
ON Employee.empID = Bonus.empID
WHERE bonus<1000 OR bonus IS NULL;



SELECT e.name, b.bonus
FROM Employee e LEFT JOIN bonus b USING(empId)
WHERE IFNULL(b.bonus, 0) < 1000;
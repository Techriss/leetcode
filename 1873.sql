-- IF
    SELECT 
        employee_id,
        IF (employee_id % 2 = 0 OR name LIKE 'M%', 0, salary) AS bonus
    FROM Employees
    ORDER BY employee_id;


-- UNION
    select employee_id , salary as bonus 
    from employees 
    where employee_id%2 <>0 and name not like 'M%'
    
    union
    
    select employee_id , 0 as bonus
    from employees
    where employee_id%2 = 0 or name like 'M%'
    order by employee_id;


-- BOOL TRICK
    select employee_id, salary * (employee_id % 2) * (name not like 'M%') as bonus
    from employees
    order by employee_id;
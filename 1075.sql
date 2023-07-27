SELECT project_id, ROUND(AVG(experience_years), 2) as average_years
FROM Project 
LEFT JOIN Employee USING(employee_id)
GROUP BY project_id;
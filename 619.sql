-- doesnt give null somehow

SELECT num FROM MyNumbers
GROUP BY num
HAVING COUNT(num) = 1
ORDER BY num DESC
LIMIT 1;


SELECT MAX(num) AS num FROM
(
    SELECT num 
    FROM mynumbers 
    GROUP BY num 
    HAVING count(num) = 1
) AS num
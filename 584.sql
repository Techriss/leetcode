SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) <> 2;

SELECT name
FROM Customer
WHERE COALESCE(referee_id,0) <> 2;
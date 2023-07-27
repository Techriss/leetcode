SELECT DISTINCT author_id as id
FROM Views
WHERE viewer_id=author_id
ORDER BY author_id ASC;



SELECT author_id AS id FROM Views 
where author_id = viewer_id 
GROUP BY id
ORDER BY id;
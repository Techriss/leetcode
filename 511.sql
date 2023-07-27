SELECT player_id, MIN(event_date) as first_login
FROM Activity GROUP BY player_id

-- OR
SELECT DISTINCS player_id, min(event_date) over (partition by player_id) first_login from Activity 
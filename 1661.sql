SELECT 
    machine_id,
    ROUND(
        SUM(IF(activity_type = 'start', -1, 1) * timestamp) / COUNT(DISTINCT process_id),
        3
    ) AS processing_time
FROM Activity a
GROUP BY machine_id;


select a.machine_id, round(avg(b.timestamp - a.timestamp), 3) as processing_time 
from activity a join activity b
on a.machine_id = b.machine_id and a.process_id = b.process_id and a.activity_type = 'start' and b.activity_type = 'end'
group by 1;

select 
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time
from Activity a1
join Activity a2
on a1.process_id = a2.process_id
and a1.machine_id = a2.machine_id
and a1.timestamp < a2.timestamp
group by a1.machine_id;
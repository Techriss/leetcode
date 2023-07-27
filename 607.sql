SELECT Salesperson.name
FROM Orders o 
    JOIN Company c ON (o.com_id = c.com_id AND c.name = 'RED')
    RIGHT JOIN Salesperson ON Salesperson.sales_id = o.sales_id
WHERE o.sales_id IS NULL;



-- easier to understand
select s.name
from SalesPerson s
where s.name not in
    (select s.name
    from SalesPerson s
        left join Orders o on s.sales_id = o.sales_id
        left join Company c on o.com_id = c.com_id
    where c.name = 'Red');



-- grouping
select s.name
from salesperson s
left join orders o on (o.sales_id=s.sales_id)
left join company c on (o.com_id=c.com_id)
group by s.name
having count(order_id)=0 or not sum(c.name='RED')>0
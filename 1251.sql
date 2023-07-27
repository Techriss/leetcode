SELECT p.product_id, ROUND(SUM(units*price)/SUM(units), 2) as average_price
FROM Prices p
JOIN UnitsSold u
ON p.product_id=u.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY p.product_id;


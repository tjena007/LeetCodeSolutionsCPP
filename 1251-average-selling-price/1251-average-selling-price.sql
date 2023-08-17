# Write your MySQL query statement below
select p.product_id, round(sum(u.units*p.price) / sum(u.units),2) as average_price 
from Prices p inner join UnitsSold u on (u.purchase_date between p.start_date and p.end_date and p.product_id = u.product_id) 
group by p.product_id 
order by p.product_id
# Write your MySQL query statement below
select contest_id,round((count(r.user_id)*100)/(SELECT COUNT(*) FROM Users),2) AS percentage 
from Users u inner join Register r on u.user_id = r.user_id 
group by contest_id order by percentage desc,contest_id asc
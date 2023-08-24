# Write your MySQL query statement below
select query_name, 
 round(sum(rating/position) / count(query_name),2) as quality,
 round(COUNT(CASE WHEN rating < 3 THEN 1 ELSE NULL END) * 100 / count(query_name),2)  as poor_query_percentage
 from Queries group by query_name
# select count(query_name)  from Queries where rating < 3
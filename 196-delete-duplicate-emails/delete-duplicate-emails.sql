# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (SELECT minID FROM (SELECT MIN(id) as minId FROM Person GROUP BY email) as temp)


# Write your MySQL query statement below
SELECT DISTINCT a.email from Person a, Person b
WHERE a.id != b.id AND a.email = b.email;
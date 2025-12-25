# Write your MySQL query statement below
SELECT a.name as Employee 
FROM Employee a
JOIN Employee b
where a.managerId = b.id and a.salary > b.salary;
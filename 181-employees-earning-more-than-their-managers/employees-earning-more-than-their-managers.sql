# Write your MySQL query statement below
SELECT a.name AS employee FROM Employee a, Employee b
WHERE a.managerId = b.id AND a.salary > b.salary;
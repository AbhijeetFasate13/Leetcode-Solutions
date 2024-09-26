# Write your MySQL query statement below
SELECT a.name as Department, b.name as Employee, b.salary as Salary FROM Employee b, Department a
WHERE a.id = b.departmentId AND
b.salary = (SELECT MAX(salary) from Employee WHERE departmentId = a.id)
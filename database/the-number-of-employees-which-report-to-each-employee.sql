# Write your MySQL query statement below
SELECT
    mgr.employee_id,
    mgr.name,
    COUNT(emp.reports_to) AS reports_count,
    ROUND(AVG(emp.age)) AS average_age
FROM Employees AS mgr
JOIN Employees AS emp
ON emp.reports_to = mgr.employee_id
GROUP BY mgr.employee_id
ORDER BY mgr.employee_id ASC;
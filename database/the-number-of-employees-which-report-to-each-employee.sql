SELECT
    mgr.employee_id,
    mgr.name,
    COUNT(mgr.employee_id) AS reports_count,
    ROUND(AVG(emp.age)) AS average_age
FROM Employees AS emp
JOIN Employees AS mgr ON emp.reports_to = mgr.employee_id
GROUP BY mgr.employee_id, mgr.name
ORDER BY mgr.employee_id;
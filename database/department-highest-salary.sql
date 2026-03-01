# Write your MySQL query statement below
WITH RankedSalary AS (
    SELECT
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rnk
    FROM Employee AS e
    JOIN Department AS d ON e.departmentId = d.id
)

SELECT
    Department,
    Employee,
    Salary
FROM RankedSalary
WHERE rnk = 1;
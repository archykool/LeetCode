# Write your MySQL query statement below
WITH RankSalary AS(
    SELECT
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rnk
    FROM Employee AS e
    LEFT JOIN Department AS d ON e.departmentId = d.id
)

SELECT
    Department,
    Employee,
    Salary
FROM RankSalary WHERE rnk = 1;
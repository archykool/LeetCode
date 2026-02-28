# Write your MySQL query statement below
SELECT
    ROUND(
        COUNT(a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2
        ) AS fraction
FROM Activity AS a
JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) AS fli ON a.player_id = fli.player_id 
      AND DATEDIFF(a.event_date, fli.first_login) = 1;
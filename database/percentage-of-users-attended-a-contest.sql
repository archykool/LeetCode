SELECT
    contest_id,
    ROUND(COUNT(user_id) * 100 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY PERCENTAGE DESC, contest_id ASC;
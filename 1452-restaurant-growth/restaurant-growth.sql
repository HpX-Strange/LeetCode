# Write your MySQL query statement below
SELECT visited_on, amount, ROUND(average_amount,2) as average_amount
FROM (
    SELECT visited_on,
    SUM(SUM(amount)) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount,
    AVG(SUM(amount)) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as average_amount,
    ROW_NUMBER() OVER(ORDER BY visited_on) as RN
    FROM Customer
    GROUP BY visited_on
) as C
WHERE RN>=7;
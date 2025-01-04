# Write your MySQL query statement below
SELECT name,population,area 
FROM World
Where area > 2999999 OR population > 24999999
ORDER BY area;
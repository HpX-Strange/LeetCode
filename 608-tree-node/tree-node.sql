# Write your MySQL query statement below
with recursive tree_cte as (
    select id, p_id, 1 as level from Tree where p_id is NULL

    union all

    select t.id, t.p_id, tree.level+1 from tree_cte t join Tree tr on t.p_id=tr.id

)
SELECT
    t1.id,

    CASE
        WHEN t1.p_id IS NULL THEN 'Root'

        WHEN EXISTS (
            SELECT 1 FROM Tree t2 WHERE t2.p_id = t1.id
        ) THEN 'Inner'

        ELSE 'Leaf'
    END AS type

FROM tree t1
ORDER BY t1.id;
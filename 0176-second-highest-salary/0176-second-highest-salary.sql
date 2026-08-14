# Write your MySQL query statement below
-- select max(e1.salary) as SecondHighestSalary     #highest salary will be gone that makes 2nd highest as max
-- from Employee e1
-- inner join Employee e2
-- on e1.salary < e2.salary;

select(
    select distinct salary
    from Employee
    order by salary desc
    limit 1 offset 1
) as SecondHighestSalary ;
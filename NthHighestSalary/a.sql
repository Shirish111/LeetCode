/*
Nth Highest Salary

Write a SQL query to get the nth highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query should return null.

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+

*/ /* CREATE */
CREATE TABLE Employee(id INT,salary INT);

/* Insert */
INSERT INTO Employee
VALUES (1, 100),
       (2, 200),
       (3, 300),
       (4, 400),
       (5, 400);


INSERT INTO Employee
VALUES (1, 100);

/* Delete */
DELETE
FROM Employee;

/* Solution 1 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN DECLARE M INT;
SET M=n-1; RETURN
  (SELECT DISTINCT salary
   FROM Employee
   ORDER BY salary DESC
   LIMIT M,
         1); END;

/* Call function */
SELECT getNthHighestSalary(3)
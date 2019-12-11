/*
Second Highest Salary

Write a SQL query to get the second highest salary from the Employee table.
 +----+--------+
 | Id | Salary |
 +----+--------+
 | 1  | 100    |
 | 2  | 200    |
 | 3  | 300    |
 +----+--------+
For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.
 +---------------------+
 | SecondHighestSalary |
 +---------------------+
 | 200                 |
 +---------------------+

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
SELECT
  (SELECT DISTINCT salary
   FROM Employee
   ORDER BY salary DESC
   LIMIT 1
   OFFSET 1) AS SecondHighestSalary;

/* Solution 2*/
SELECT IFNULL(
                (SELECT DISTINCT salary
                 FROM Employee
                 ORDER BY salary DESC
                 LIMIT 1
                 OFFSET 1),NULL) AS SecondHighestSalary;

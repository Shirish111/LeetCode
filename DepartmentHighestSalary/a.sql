/*

Department Highest Salary

The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, your SQL query should return the following rows (order of rows does not matter).

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
Explanation:

Max and Jim both have the highest salary in the IT department and Henry has the highest salary in the Sales department.

*/;

/* CREATE */
CREATE TABLE Department (Id INT PRIMARY KEY,
                                        NAME VARCHAR(60));


CREATE TABLE Employee
  (id INT PRIMARY KEY,
                  NAME VARCHAR(60),
                       salary INT, DepartmentId INT,
   FOREIGN KEY (DepartmentId) REFERENCES Department(Id) ON DELETE
   SET NULL);

/* INSERT */
INSERT INTO Department
VALUES (1, 'IT'),
       (2, 'Sales');


INSERT INTO Employee
VALUES (1, 'Joe', 70000, 1),
       (2, 'Jim', 90000, 1),
       (3, 'Henry', 80000, 2),
       (4, 'Sam', 60000, 2),
       (5, 'MAX', 90000, 1);

/* Solution */
SELECT D.NAME AS Department,
       E.NAME AS Employee,
       E.salary AS Salary
FROM Employee E
INNER JOIN Department D ON E.DepartmentId = D.Id
AND (DepartmentId,
     Salary) IN
  (SELECT DepartmentId,
          MAX(salary)
   FROM Employee
   GROUP BY DepartmentId);

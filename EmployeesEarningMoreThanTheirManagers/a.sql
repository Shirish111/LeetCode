/*

Employees Earning More Than Their Managers

The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

+----------+
| Employee |
+----------+
| Joe      |
+----------+

*/;

/* CREATE */
CREATE TABLE Employee
  (Id INT PRIMARY KEY,
                  NAME VARCHAR(60),
                       salary INT, managerId INT,
   FOREIGN KEY(managerId) REFERENCES Employee(Id) ON DELETE
   SET NULL);

/* INSERT */
INSERT INTO Employee
VALUES (3, 'Sam', 60000, NULL),
       (4, 'MAX', 90000, NULL),
       (1, 'Joe', 70000, 3),
       (2, 'Henry', 80000, 4);

/* Solution */
SELECT NAME AS Employee
FROM `Employee` AS E
WHERE salary >
    (SELECT salary
     FROM `Employee`
     WHERE id=E .managerId);

/* Solution2 */
SELECT a.NAME AS Employee
FROM `Employee` a
JOIN `Employee` b
WHERE a.managerId = b.Id
  AND a.salary > b.salary;

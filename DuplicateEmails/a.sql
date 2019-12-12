/*

Duplicate Emails

Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.

*/;

/* CREATE */
CREATE TABLE Person (Id INT, Email VARCHAR(60));

/* INSERT */
INSERT INTO Person
VALUES (1, 'a@b.com'),
       (2, 'c@d.com'),
       (3, 'a@b.com');

/* Solution */
SELECT Email
FROM
  (SELECT Email,
          COUNT(Email) AS COUNT
   FROM Person
   GROUP BY Email
   HAVING COUNT>1) T;

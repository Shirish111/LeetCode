/*

Customers Who Never Order

Suppose that a website contains two tables, the Customers table and the Orders table. Write a SQL query to find all customers who never order anything.

Table: Customers.

+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Table: Orders.

+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Using the above tables as example, return the following:

+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

*/;

/* CREATE */
CREATE TABLE Customers (Id INT PRIMARY KEY,
                                       NAME VARCHAR(60));


CREATE TABLE Orders (id INT, CustomerId INT,
                     FOREIGN KEY(CustomerId) REFERENCES Customers(Id));

/* INSERT */
INSERT INTO Customers
VALUES (1, 'Joe'),
       (2, 'Henry'),
       (3, 'Sam'),
       (4, 'MAX');


INSERT INTO Orders
VALUES (1, 3),
       (2, 1);

/* Solution */
SELECT NAME AS Customers
FROM Customers
WHERE Id NOT IN
    (SELECT DISTINCT CustomerId
     FROM Orders);

/* Solution */
SELECT NAME AS Customers
FROM Customers
LEFT JOIN Orders ON Customers.id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;

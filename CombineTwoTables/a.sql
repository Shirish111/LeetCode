/*

Combine Two Tables

SQL Schema
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId is the primary key column for this table.
Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId is the primary key column for this table.


Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:

FirstName, LastName, City, State
*/ /*
 * MYSQL
*/
CREATE TABLE Person(PersonId INT, FirstName VARCHAR(60),
                                            LastName VARCHAR(60));


CREATE TABLE Address(AddressId INT, PersonId INT, City VARCHAR(60),
                                                       STATE VARCHAR(60));

/* insert into Person */
INSERT INTO Person
VALUES(1, "f1", "l1"),
      (2, "f2", "l2"),
      (3, "f3", "l3"),
      (4, "f4", "l4"),
      (5, "f5", "l5");

/* insert into Address */
INSERT INTO Address
VALUES (1,1, 'C1', 'S1'),
       (2,2, 'C2', 'S2'),
       (3,3, 'C3', 'S3'),
       (4,4, 'C4', 'S4');

/* Solution */
SELECT FirstName,
       LastName,
       City,
       STATE
FROM Person
LEFT JOIN Address ON Person.PersonId = Address.PersonId;

/*

Rising Temperature

Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

+---------+------------------+------------------+
| Id(INT) | RecordDate(DATE) | Temperature(INT) |
+---------+------------------+------------------+
|       1 |       2015-01-01 |               10 |
|       2 |       2015-01-02 |               25 |
|       3 |       2015-01-03 |               20 |
|       4 |       2015-01-04 |               30 |
+---------+------------------+------------------+
For example, return the following Ids for the above Weather table:

+----+
| Id |
+----+
|  2 |
|  4 |
+----+

Comment

*/;

/* CREATE */
CREATE TABLE Weather (Id INT, RecordDate DATE, Temperature INT);

/* INSERT */
INSERT INTO Weather
VALUES (1, '2015-01-01', 10),
       (2, '2015-01-02', 25),
       (3, '2015-01-03', 20),
       (4, '2015-01-04', 30);

/* Solution */
SELECT w1.Id
FROM Weather w1
JOIN Weather w2 ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
and w1.Temperature > w2.Temperature;

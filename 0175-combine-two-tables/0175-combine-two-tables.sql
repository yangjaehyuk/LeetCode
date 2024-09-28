/* Write your PL/SQL query statement below */
SELECT A.FIRSTNAME, A.LASTNAME, B.CITY, B.STATE
FROM PERSON A
LEFT JOIN ADDRESS B ON A.personId = B.personId;
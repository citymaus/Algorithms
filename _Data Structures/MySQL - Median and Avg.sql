/*A median is defined as a number separating the higher half of a data set from the lower half. 
   Query the median of the Northern Latitudes (LAT_N) from STATION and round your answer to 44 decimal places.

Input Format

The STATION table is described as follows:
Field       Type
-------------------
ID          NUMBER
CITY        VARCHAR2(21)
STATE       VARCHAR2(2)
LAT_N       NUMBER
LONG_W      NUMBER
*/

SELECT ROUND(avg(t1.LAT_N), 4) as median_val FROM (
SELECT @rownum:=@rownum+1 as `row_number`, d.LAT_N
  FROM STATION d,  (SELECT @rownum:=0) r
  WHERE 1
  -- put some where clause here
  ORDER BY d.LAT_N
) as t1, 
(
  SELECT count(*) as total_rows
  FROM STATION d
  WHERE 1
  -- put same where clause here
) as t2
WHERE 1
AND t1.row_number in ( floor((total_rows+1)/2), floor((total_rows+2)/2) );


/*Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent) 
and their respective average city populations (CITY.Population) rounded down to the nearest integer.

Note: CITY.CountryCode and COUNTRY.Code are matching key columns. Do not include continents without 
cities in your output.

The CITY and COUNTRY tables are described as follows:
CITY
Field		Type
ID			NUMBER
NAME		VARCHAR2(17)
COUNTRYCODE	VARCHAR2(3)
DISTRICT	VARCHAR2(20)
POPULATION	NUMBER

COUNTRY
Field		Type
CODE		VARCHAR2(3)
NAME		VARCHAR2(44)
CONTINENT	VARCHAR2(13)
REGION		VARCHAR2(25)
...
*/
SELECT continent, floor(avg(population)) FROM
	(SELECT COUNTRY.CONTINENT as continent, COUNTRY.NAME as country, CITY.NAME as city, CITY.POPULATION as population 
	FROM CITY
	INNER JOIN COUNTRY on CITY.COUNTRYCODE = COUNTRY.CODE
	ORDER BY COUNTRY.CONTINENT ASC, COUNTRY.NAME ASC, CITY.NAME ASC) as all_entries
GROUP BY continent;
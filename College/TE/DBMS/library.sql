DECLARE
P_rollno int;
p_nameofbook varchar(30);
p_dateofissue date;
currentdate date;
noofdays int;
amount int;
nodata EXCEPTION;
BEGIN
P_rollno := &roll_no;
p_nameofbook := '&name_of_book';
currentdate := trunc(SYSDATE);
IF(p_rollno <= 0)THEN 
RAISE nodata;
END IF;
SELECT dateofissue INTO p_dateofissue FROM borrower WHERE roll_no=p_rollno AND name_of_book=p_nameofbook;
SELECT trunc(SYSDATE)-P_dateofissue INTO noofdays FROM dual;
dbms_output.put_line(noofdays);
IF(noofdays >= 15 AND noofdays <= 30)THEN amount := noofdays*5;
ELSIF(noofdays > 30)THEN amount := noofdays * 50;
END IF;
IF(amount > 0)THEN
INSERT INTO fine values(p_rollno,sysdate,amount);
END IF;
UPDATE borrower set status='R' WHERE roll_no=p_rollno;
EXCEPTION
WHEN nodata THEN
dbms_output.put_line('ROLL NO NOT FOUND');
END;
/


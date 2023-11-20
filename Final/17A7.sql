
-- Write a PL/SQL block of code using Cursor that will merge the data available in the newly created table N_Roll Call with the 
-- data available in the table O_RollCall. If the data in the first table already exist in the second table then that data should be 
-- skipped.

--CREATE TABLE O_ROLL_CALL(Roll_No NUMBER(5) PRIMARY KEY,Name VARCHAR2(20));
--CREATE TABLE N_ROLL_CALL(Roll_No NUMBER(5) PRIMARY KEY,Name VARCHAR2(20));
--INSERT INTO O_ROLL_CALL VALUES(01,'TEST');
--INSERT INTO O_ROLL_CALL VALUES(02,'TEST1');
--INSERT INTO O_ROLL_CALL VALUES(03,'TEST2');
--INSERT INTO O_ROLL_CALL VALUES(04,'TEST3');
--INSERT INTO O_ROLL_CALL VALUES(05,'TEST4');
--INSERT INTO N_ROLL_CALL VALUES(10,'TEST5');
--INSERT INTO N_ROLL_CALL VALUES(11,'TEST6');

DECLARE 
    rollno number;
    flag int(2);
    cursor c_roll(rollno number) is select * from O_ROLL_CALL where Roll_no not in 
    (select Roll_no from N_ROLL_CALL where N_ROLL_CALL.Roll_no = O_ROLL_CALL.Roll_no);
    info N_ROLL_CALL%rowtype;

BEGIN
    rollno := &rollno;
    flag := 0;
    open c_roll(rollno);
    loop fetch c_roll into info;
    exit when c_roll%notfound;
        if (info.Roll_No = rollno) then insert into N_ROLL_CALL values(info.Roll_No,info.Name);
        flag:= 1;
        end if;
    end loop;
        if(c_roll%rowcount = 0 or flag = 0) then dbms_output.put_line('Record already exists');
        else dbms_output.put_line('Record added successfully');
        end if;
    close c_roll;
END;
/
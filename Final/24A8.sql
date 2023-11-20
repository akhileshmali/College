-- Trigger :Write a after trigger for Insert, update and delete event considering following requirement:
-- Emp(Emp_no, Emp_name, Emp_salary)
-- a) Trigger should be initiated when salary tried to be inserted is less than Rs.50,000/-
-- b) Trigger should be initiated when salary tried to be updated for value less than Rs. 50,000/-
-- Also the new values expected to be inserted will be stored in new table Tracking(Emp_no,Emp_salary).

-- CREATE TABLE EMP (
--     Emp_no NUMBER PRIMARY KEY,
--     Emp_name VARCHAR2(100),
--     Emp_salary NUMBER
-- );

-- CREATE TABLE TRACKING (
--     Emp_no NUMBER,
--     Emp_salary NUMBER
-- );

-- INSERT INTO EMP VALUES (101, 'Raj', 50000);
-- INSERT INTO EMP VALUES (102, 'Ram', 60000);
-- INSERT INTO EMP VALUES (103, 'Shyam', 70000);

CREATE OR REPLACE TRIGGER check_salary_trigger
AFTER INSERT OR UPDATE OR DELETE
ON EMP
FOR EACH ROW
DECLARE
    v_new_salary NUMBER;
BEGIN
    -- Check if the trigger is initiated due to INSERT or UPDATE operation
    IF INSERTING OR UPDATING THEN
        -- Check if the new salary is less than Rs. 50,000/-
        IF :NEW.Emp_salary < 50000 THEN
            -- Insert the new values into the TRACKING table
            INSERT INTO TRACKING (Emp_no, Emp_salary)
            VALUES (:NEW.Emp_no, :NEW.Emp_salary);

            -- Display a message indicating the salary is less than Rs. 50,000/-
            DBMS_OUTPUT.PUT_LINE('Salary less than Rs. 50,000/-. Tracking the change.');
        END IF;
    END IF;
END;
/

-- TEST
-- INSERT INTO EMP VALUES (104, 'Mohan', 40000);
-- UPDATE EMP SET Emp_salary = 45000 WHERE Emp_no = 101;
-- DELETE FROM EMP WHERE Emp_no = 102;
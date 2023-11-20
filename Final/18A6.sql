-- Write a PL/SQL block for following requirements and handle the 
-- exceptions. Roll no. of students will be entered by the user. 
-- Attendance of roll no. entered by user will be checked in the 
-- Stud table. If attendance is less than 75% then display the 
-- message “Term not granted” and set the status in stud table as 
-- “Detained”. Otherwise display message “Term granted” and set the 
-- status in stud table as “Not Detained”
--  Student (Roll, Name, Attendance ,Status)

-- CREATE TABLE Stud (
--   Roll NUMBER PRIMARY KEY,
--   Name VARCHAR2(50) NOT NULL,
--   Attendance NUMBER NOT NULL,
--   Status VARCHAR2(20) NOT NULL
-- );

-- INSERT INTO Stud VALUES (1, 'John', 80, 'Not Detained');
-- INSERT INTO Stud VALUES (2, 'Jane', 70, 'Not Detained');
-- INSERT INTO Stud VALUES (3, 'Bob', 60, 'Detained');

DECLARE
  v_roll_no NUMBER;
  v_attendance NUMBER;
BEGIN
  v_roll_no := &roll_no;
  SELECT attendance INTO v_attendance FROM Stud WHERE Roll = v_roll_no;

  IF v_attendance < 75 THEN
    UPDATE Stud SET Status = 'Detained' WHERE Roll = v_roll_no;
    DBMS_OUTPUT.PUT_LINE('Term not granted');
  ELSE
    UPDATE Stud SET Status = 'Not Detained' WHERE Roll = v_roll_no;
    DBMS_OUTPUT.PUT_LINE('Term granted');
  END IF;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Invalid roll number');
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/
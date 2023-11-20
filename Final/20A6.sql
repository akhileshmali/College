/*
Write a Stored Procedure namely proc_Grade for the categorization of student. If marks scored by 
students in examination is <=1500 and marks>=990 then student will be placed in distinction category 
if marks scored are between 989 and 900 category is first class, if marks 899 and 825 category is 
Higher Second Class.
Write a PL/SQL block for using procedure created with above requirement.
Stud_Marks(name, total_marks), 
Result(Roll,Name, Class)
*/
CREATE OR REPLACE PROCEDURE proc_Grade (
    p_roll IN NUMBER,
    p_name IN VARCHAR2,
    p_total_marks IN NUMBER
) AS
    v_class VARCHAR2(50);
BEGIN
    -- Categorize students based on total marks
    IF p_total_marks <= 1500 AND p_total_marks >= 990 THEN
        v_class := 'Distinction';
    ELSIF p_total_marks >= 900 AND p_total_marks <= 989 THEN
        v_class := 'First Class';
    ELSIF p_total_marks >= 825 AND p_total_marks <= 899 THEN
        v_class := 'Higher Second Class';
    ELSE
        v_class := 'Not categorized';
    END IF;

    -- Insert into Result table
    INSERT INTO Result (Roll, Name, Class)
    VALUES (p_roll, p_name, v_class);

    DBMS_OUTPUT.PUT_LINE('Student ' || p_name || ' with Roll ' || p_roll || ' categorized as ' || v_class);
END proc_Grade;

/
-- Execute the PL/SQL block
DECLARE
    v_roll NUMBER := 1; -- Replace with actual roll number
    v_name VARCHAR2(50) := 'TEST'; -- Replace with actual name
    v_total_marks NUMBER := 950; -- Replace with actual total marks
BEGIN
    -- Call the procedure
    proc_Grade(v_roll, v_name, v_total_marks);
END;
/
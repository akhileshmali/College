/*
Write a Unnamed PL/SQL of code for the following requirements:-
Schema:
 Borrower (Rollin, Name, DateofIssue, NameofBook, Status)
 Fine (Roll_no,Date,Amt)
Accept roll_no & name of book from user.
Check the number of days (from date of issue).
1. If days are between 15 to 30 then fine amounts will be Rs 5 per day.
2. If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per day.
3. After submitting the book, status will change from I to R.
4. If condition of fine is true, then details will be stored into fine table.
*/

/*CREATE TABLE BORROWER (Roll_no number(10) PRIMARY KEY,Name varchar2(20),Date_of_issue Date,
Book_name varchar2(30),Status char(1));
CREATE TABLE FINE(Roll_no number(10),Date_of_Return Date,Amount number(5),FOREIGN KEY(Roll_no) 
REFERENCES BORROWER(Roll_no));*/

/*INSERT INTO BORROWER VALUES(20,'SHIVA SRESHTH',TO_DATE('12-09-2022','DD-MM-YYYY'),'NIRALI','I');
INSERT INTO BORROWER VALUES(55,'SAMPADA AGHAV',TO_DATE('15-09-2022','DD-MM-YYYY'),'HCI','I');
INSERT INTO BORROWER VALUES(35,'AYUSH ACHARYA',TO_DATE('15-09-2022','DD-MM-YYYY'),'SPOS','I');
INSERT INTO BORROWER VALUES(39,'KAUSTUBH WARADE',TO_DATE('15-09-2022','DD-MM-YYYY'),'CNS','I');*/

DECLARE
 v_roll_no NUMBER ; 
 v_book_name VARCHAR2(30); 
 v_issue_date DATE;
 v_status CHAR(1);
 v_fine_amt NUMBER;
 v_days_diff NUMBER;
 
BEGIN
 v_roll_no := &Roll_no;
 v_book_name := '&Book_name';
 SELECT Roll_no, Date_of_issue, Status
 INTO v_roll_no, v_issue_date, v_status
 FROM Borrower
 WHERE Roll_no = v_roll_no AND Book_name = v_book_name;
 v_days_diff := trunc(SYSDATE) - v_issue_date;
 
 IF v_status = 'I' THEN
 IF v_days_diff <= 30 THEN v_fine_amt := v_days_diff * 5;
 ELSE
 -- Calculate fine at Rs 50 per day for each day beyond 30 days
 v_fine_amt := (v_days_diff - 30) * 50 + 30 * 5;
 END IF;
 INSERT INTO Fine (Roll_no, Date_of_Return, Amount)
 VALUES (v_roll_no, trunc(SYSDATE), v_fine_amt);
 UPDATE Borrower
 SET Status = 'R'
 WHERE Roll_no = v_roll_no AND Book_name = v_book_name;
 DBMS_OUTPUT.PUT_LINE('Fine Amount: Rs ' || v_fine_amt);
 ELSE
 RAISE_APPLICATION_ERROR(-20001, 'Book not issued or already returned');
 END IF;
EXCEPTION
 WHEN NO_DATA_FOUND THEN
 DBMS_OUTPUT.PUT_LINE('Book not found for the given Roll_no and Book_name');
 WHEN OTHERS THEN
 DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END;
/


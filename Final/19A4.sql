-- Write a PL/SQL Block to increase the salary of employees by 10% 
-- of existing salary, who are having salary less than average 
-- salary of organization, whenever such salary updates takes place, 
-- a record for same is maintained in the increment_salary table.
-- emp(emp_no, salary)
-- increment_salary(emp_no, salary)

-- CREATE TABLE emp1(emp_no NUMBER NOT NULL PRIMARY KEY,salary int);
-- CREATE TABLE increment_salary(emp_no NUMBER,salary int,FOREIGN KEY(emp_no) REFERENCES emp1(emp_no) );
-- INSERT INTO emp1 VALUES (1, 50000);
-- INSERT INTO emp1 VALUES (3, 70000);
-- INSERT INTO emp1 VALUES (2, 60000);

DECLARE
  avg_salary NUMBER;
BEGIN
  SELECT AVG(salary) INTO avg_salary FROM emp1;
  DBMS_OUTPUT.PUT_LINE('Average Salary is ' || avg_salary);
  FOR emp_rec IN (SELECT emp_no, salary FROM emp1 WHERE salary < avg_salary) LOOP
    BEGIN
      UPDATE emp1 SET salary = salary * 1.1 WHERE emp_no = emp_rec.emp_no;
      INSERT INTO increment_salary (emp_no, salary) VALUES (emp_rec.emp_no, emp_rec.salary * 0.1);
      DBMS_OUTPUT.PUT_LINE('Salary increased for employee ' || emp_rec.emp_no || ' by 10%');
    EXCEPTION
      WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
    END;
  END LOOP;

  DBMS_OUTPUT.PUT_LINE('Salary update process completed');
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/
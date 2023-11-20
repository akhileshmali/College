-- Write a Row Level Before and After Trigger on Library table. The System should keep track of the 
--records that are being updated or deleted. The old value of updated or deleted records should be added 
--in Library_Audit table.
-- Create the BEFORE trigger to capture old data before an update or delete

-- The :OLD. prefix is used to distinguish the old values from the new values. The :NEW. prefix is used to 
--refer to the new values of the columns 
-- after an update or insert operation.

-- Using the :OLD. and :NEW. prefixes allows you to capture the old and new values of the columns in a trigger 
--and use them for various purposes, 
-- such as logging changes, auditing, and enforcing data integrity.

-- Create table Library(rollno int, name char(10), dateofissue date, nameofbook char(10),status char(10));
-- Create table Library_audit(rollno int, name char(10), dateofissue date, nameofbook char( 10), status char(10), ts timestamp);

-- INSERT INTO Library VALUES (101,'Ram',to_date('20230111','YYYYMMDD'),'DBMS','I');
-- INSERT INTO Library VALUES (102,'Sham',to_date('20230511','YYYYMMDD'),'CNS','I');
-- INSERT INTO Library VALUES (103,'Sai',to_date('20231011','YYYYMMDD'),'TOC','I');
-- INSERT INTO Library VALUES (104,'Laxman',to_date('20231011','YYYYMMDD'),'SPOS','I');
-- INSERT INTO Library VALUES (105,'Ganesh',to_date('20231016','YYYYMMDD'),'IOT','I');

-- Create the BEFORE trigger to capture old data before an update or delete
CREATE OR REPLACE TRIGGER library_audit_before
BEFORE UPDATE OR DELETE ON Library
FOR EACH ROW

BEGIN
  -- Insert the old data into the Library_Audit table
  INSERT INTO Library_Audit (
    rollno,
    name,
    dateofissue,
    nameofbook,
    status,
    ts
  ) VALUES (
    :OLD.rollno,
    :OLD.name,
    :OLD.dateofissue,
    :OLD.nameofbook,
    :OLD.status,
    SYSDATE
  );
END;
/

-- Create the AFTER trigger to capture new data after an insert or update
CREATE OR REPLACE TRIGGER library_audit_after
AFTER INSERT OR UPDATE ON Library
FOR EACH ROW
BEGIN
  -- Insert the new data into the Library_Audit table if it's an insert or an update
  IF INSERTING OR UPDATING THEN
    INSERT INTO Library_Audit (
      rollno,
      name,
      dateofissue,
      nameofbook,
      status,
      ts
    ) VALUES (
      :NEW.rollno,
      :NEW.name,
      :NEW.dateofissue,
      :NEW.nameofbook,
      :NEW.status,
      SYSDATE
    );
  END IF;
END;
/

-- test cases:
--  UPDATE Library SET status = 'R' WHERE rollno = 101;
--   DELETE FROM library WHERE rollno = 101;
--   INSERT INTO Library VALUES (789, 'John Doe', to_date('20231004','YYYYMMDD'), 'TEST', 'I');
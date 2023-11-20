-- Write a PL/SQL code block to calculate the area of a circle for a 
-- value of radius varying from 5 to 9. Store the radius and the 
-- corresponding values of calculated area in an empty table named 
-- areas, consisting of two columns, radius and area.

-- CREATE TABLE areas (
--     radius NUMBER,
--     area NUMBER
-- );

DECLARE
    r NUMBER;
    a NUMBER;
BEGIN
    -- Loop through the range of radius values
    FOR r IN 5..9 LOOP
        -- Calculate the area of the circle
        a := 3.14159 * POWER(r, 2);

        -- Insert the radius and corresponding area into the table
        INSERT INTO areas (radius, area) VALUES (r, a);
    END LOOP;
    
END;
/
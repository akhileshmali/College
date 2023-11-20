/*
Create a stored function titled 'Age_calc'. Accept the date of birth of a person as a parameter.
Calculate the age of the person in years, months and days e.g. 3 years, 2months, 10 days.
Return the age in years directly (with the help of Return statement).
The months and days are to be returned indirectly in the form of OUT parameters.
*/
CREATE OR REPLACE FUNCTION Age_calc(
    p_birthdate IN DATE,
    o_years OUT NUMBER,
    o_months OUT NUMBER,
    o_days OUT NUMBER
) RETURN NUMBER
IS
    -- Declare variables
    v_birthdate DATE := p_birthdate;
    v_today DATE := SYSDATE;
    v_years NUMBER;
    v_months NUMBER;
    v_days NUMBER;
BEGIN
    -- Calculate the difference in years, months, and days
    v_years := EXTRACT(YEAR FROM v_today) - EXTRACT(YEAR FROM v_birthdate);
    v_months := EXTRACT(MONTH FROM v_today) - EXTRACT(MONTH FROM v_birthdate);
    v_days := EXTRACT(DAY FROM v_today) - EXTRACT(DAY FROM v_birthdate);

    -- Adjust for negative values
    IF v_days < 0 THEN
        v_months := v_months - 1;
        v_days := v_days + ABS(LAST_DAY(v_birthdate) - v_birthdate);
    END IF;

    IF v_months < 0 THEN
        v_years := v_years - 1;
        v_months := v_months + 12;
    END IF;

    -- Set OUT parameters
    o_years := v_years;
    o_months := v_months;
    o_days := v_days;

    -- Return the age in years
    RETURN v_years;
END Age_calc;
/

DECLARE
    v_years NUMBER;
    v_months NUMBER;
    v_days NUMBER;
    v_age_in_years NUMBER;
BEGIN
    -- Call the function
    v_age_in_years := Age_calc(TO_DATE('1990-01-01', 'YYYY-MM-DD'), v_years, v_months, v_days);

    -- Display the results
    DBMS_OUTPUT.PUT_LINE('Age: ' || v_years || ' years, ' || v_months || ' months, ' || v_days || ' days');
END;
/
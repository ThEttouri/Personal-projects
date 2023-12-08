-- Step 1: Checking the crime scene reports for the given date and location
SELECT *
FROM crime_scene_reports
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street';

-- Step 2: Finding the names and transcripts of interviews conducted on July 28, 2021
SELECT id, name, transcript
FROM interviews
WHERE year = 2021
  AND month = 7
  AND day = 28;

-- Step 3: Checking the bakery security logs to find the people who exited the bakery between 10:00 AM and 11:00 AM on July 28, 2021.
SELECT id, hour, minute, activity, license_plate
FROM bakery_security_logs
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND hour >= 10
  AND hour < 11
  AND activity = 'exit';

-- Step 4: Checking the ATM transactions on July 28, 2021, at 'Leggett Street' to find the withdrawals made.
SELECT id, account_number, amount
FROM atm_transactions
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';

-- Step 5: Finding additional information about the people involved in ATM withdrawals on July 28, 2021, at 'Leggett Street'.
SELECT name, phone_number, passport_number, license_plate, account_number
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021
      AND month = 7
      AND day = 28
      AND atm_location = 'Leggett Street'
      AND transaction_type = 'withdraw'
);

-- Step 6: Finding individuals who were involved in both ATM withdrawals at 'Leggett Street' and exited the bakery between 10:00 AM and 11:00 AM on July 28, 2021.
SELECT name, phone_number, passport_number, license_plate, account_number
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021
      AND month = 7
      AND day = 28
      AND atm_location = 'Leggett Street'
      AND transaction_type = 'withdraw'
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
      AND month = 7
      AND day = 28
      AND hour >= 10
      AND hour < 11
      AND activity = 'exit'
);

-- Step 7: Finding phone call records for individuals involved in ATM withdrawals and with a call duration less than 79 seconds on July 28, 2021.
SELECT id, caller, receiver, duration
FROM phone_calls
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND (
    caller IN (
      SELECT phone_number
      FROM people
      JOIN bank_accounts ON people.id = bank_accounts.person_id
      WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
      )
    )
    OR receiver IN (
      SELECT phone_number
      FROM people
      JOIN bank_accounts ON people.id = bank_accounts.person_id
      WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
      )
    )
  )
  AND duration < 79;

-- Step 8: Retrieving phone call records made by individuals involved in ATM withdrawals on July 28, 2021, with a call duration of 79 seconds or less.
SELECT id, caller, receiver, duration
FROM phone_calls
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND caller IN (
    SELECT phone_number
    FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    WHERE account_number IN (
      SELECT account_number
      FROM atm_transactions
      WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
  )
  AND duration <= 79;

-- Step 9: Retrieving information about individuals who made ATM withdrawals at 'Leggett Street' on July 28, 2021, and made phone calls with a duration of 79 seconds or less.
SELECT name, phone_number, passport_number, license_plate, account_number
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (
  SELECT account_number
  FROM atm_transactions
  WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
)
AND phone_number IN (
  SELECT caller
  FROM phone_calls
  WHERE year = 2021
    AND month = 7
    AND day = 28
    AND caller IN (
      SELECT phone_number
      FROM people
      JOIN bank_accounts ON people.id = bank_accounts.person_id
      WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
      )
    )
    AND duration <= 79
);

-- Step 10: Finding potential accomplices who received phone calls from suspicious individuals on July 28, 2021.
SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE phone_number IN (
  SELECT receiver
  FROM phone_calls
  WHERE year = 2021
    AND month = 7
    AND day = 28
    AND caller IN (
      SELECT phone_number
      FROM people
      JOIN bank_accounts ON people.id = bank_accounts.person_id
      WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
      )
    )
    AND duration <= 79
);

-- Step 11: Finding flights on July 29, 2021.
SELECT *
FROM flights
WHERE year = 2021
  AND month = 7
  AND day = 29;

-- Step 12: Retrieving the earliest flight and its corresponding passengers on July 29, 2021, who meet specific criteria.
SELECT flights.*, passengers.*
FROM flights
JOIN passengers ON flights.id = passengers.flight_id
WHERE year = 2021
  AND month = 7
  AND day = 29
  AND hour < 12
  AND passport_number IN (
    SELECT passport_number
    FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    WHERE account_number IN (
      SELECT account_number
      FROM atm_transactions
      WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
    AND phone_number IN (
      SELECT caller
      FROM phone_calls
      WHERE year = 2021
        AND month = 7
        AND day = 28
        AND caller IN (
          SELECT phone_number
          FROM people
          JOIN bank_accounts ON people.id = bank_accounts.person_id
          WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE year = 2021
              AND month = 7
              AND day = 28
              AND atm_location = 'Leggett Street'
              AND transaction_type = 'withdraw'
          )
          AND duration <= 79
        )
    )
);

--Step 13: Retrieving suspects' details associated with a specific flight on July 29, 2021, based on certain criteria.
SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM flights
    JOIN passengers ON flights.id = passengers.flight_id
    WHERE year = 2021 AND month = 7 AND day = 29 AND hour < 12
    AND passport_number IN (
        SELECT passport_number
        FROM people
        JOIN bank_accounts ON people.id = bank_accounts.person_id
        WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
        )
        AND phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE year = 2021 AND month = 7 AND day = 28 AND caller IN (
                SELECT phone_number
                FROM people
                JOIN bank_accounts ON people.id = bank_accounts.person_id
                WHERE account_number IN (
                    SELECT account_number
                    FROM atm_transactions
                    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
                )
                AND duration <= 79
            )
        )
    )
);

-- Step 14: Retrieving details of potential ACCOMPLICES who have account numbers associated with the final suspects.
SELECT name, phone_number, passport_number, license_plate, account_number
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28
    AND caller IN (
        SELECT phone_number
        FROM people
        WHERE passport_number IN (
            SELECT passport_number
            FROM flights
            JOIN passengers ON flights.id = passengers.flight_id
            WHERE year = 2021 AND month = 7 AND day = 29
            AND hour < 12
            AND passport_number IN (
                SELECT passport_number
                FROM people
                JOIN bank_accounts ON people.id = bank_accounts.person_id
                WHERE account_number IN (
                    SELECT account_number
                    FROM atm_transactions
                    WHERE year = 2021 AND month = 7 AND day = 28
                    AND atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                )
                AND phone_number IN (
                    SELECT caller
                    FROM people
                    JOIN bank_accounts ON people.id = bank_accounts.person_id
                    WHERE account_number IN (
                        SELECT account_number
                        FROM atm_transactions
                        WHERE year = 2021 AND month = 7 AND day = 28
                        AND atm_location = 'Leggett Street'
                        AND transaction_type = 'withdraw'
                    )
                    AND duration <= 79
                )
            )
        )
    )
);

-- Step 14: Retrieving details of the potential thief based on specific criteria.
SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE phone_number = (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND receiver = (
        SELECT phone_number
        FROM people
        JOIN bank_accounts ON people.id = bank_accounts.person_id
        WHERE phone_number IN (
            SELECT receiver
            FROM phone_calls
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND caller IN (
                SELECT phone_number
                FROM people
                WHERE passport_number IN (
                    SELECT passport_number
                    FROM flights
                    JOIN passengers ON flights.id = passengers.flight_id
                    WHERE year = 2021
                    AND month = 7
                    AND day = 29
                    AND hour < 12
                    AND passport_number IN (
                        SELECT passport_number
                        FROM people
                        JOIN bank_accounts ON people.id = bank_accounts.person_id
                        WHERE account_number IN (
                            SELECT account_number
                            FROM atm_transactions
                            WHERE year = 2021
                            AND month = 7
                            AND day = 28
                            AND atm_location = 'Leggett Street'
                            AND transaction_type = 'withdraw'
                        )
                        AND phone_number IN (
                            SELECT caller
                            FROM phone_calls
                            WHERE year = 2021
                            AND month = 7
                            AND day = 28
                            AND caller IN (
                                SELECT phone_number
                                FROM people
                                JOIN bank_accounts ON people.id = bank_accounts.person_id
                                WHERE account_number IN (
                                    SELECT account_number
                                    FROM atm_transactions
                                    WHERE year = 2021
                                    AND month = 7
                                    AND day = 28
                                    AND atm_location = 'Leggett Street'
                                    AND transaction_type = 'withdraw'
                                )
                            )
                            AND duration <= 79
                        )
                    )
                )
            )
        )
    )
);

-- Step 15: Finding the destination airport of the potential thief's flight on July 29, 2021.
SELECT *
FROM airports
WHERE id = (
  SELECT destination_airport_id
  FROM flights
  JOIN passengers ON flights.id = passengers.flight_id
  WHERE year = 2021 AND month = 7 AND day = 29
    AND passport_number = (
      SELECT passport_number
      FROM people
      WHERE name = 'Bruce'
    )
);


-- Conclusion:
-- Based on the available information, we deduce that:
-- the accomplice is responsible for purchasing the tickets. As James and Doris do not have Account Numbers, it is improbable that they are the accomplices since they cannot fulfill this requirement.
-- Bruce emerges as the primary suspect in the alleged theft. He was present at the cafeteria during the time of the incident, made a call within the given timeframe, and subsequently withdrew money from the given location ('Leggett Street'), and took the earliest flight available on 29/07/2021. These factors raise strong suspicions against him.
-- Additionally, Robin appears to be a potential accomplice since they could fulfill the task of buying tickets as directed by Bruce, the suspected thief. However, these conclusions are still considered tentative, and a more comprehensive investigation is necessary to make a final determination.

-- It is crucial to consider all the evidence, including the financial transactions, cafeteria footage, and phone records, to establish a clear timeline of events and determine the actual roles of each individual. Further examination by the appropriate authorities is imperative to ascertain the truth and bring about a fair resolution.
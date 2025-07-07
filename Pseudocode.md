






        FUNCTION STRING setTrack(STRING& bookingType, STRING& raceFormat)
                DECLARE INTEGER trackID

                IF bookingType == "Group" AND raceFormat == "Circuit Race" THEN
                        DISPLAY "

        MODULE setEngineCapacity(INTEGER driverCount, STRING driverName[], INTEGER driverAge[], CHARACTER license[])
                FOR INTEGER i = 0, i < driverCount, i++
                        DISPLAY "Driver : ", driverName[i]

                        CALL displayEngineCapacities(driverAge[i], license[i])

                        IF driverAge[i] < 13 THEN
                                DISPLAY "Driver under 13: Go-Kart must be under 200cc"
                                DISPLAY "Defaulting to 120cc"
                                SET engineCapacity[i] = 120
                                CONTINUE
                        END IF
                        IF license[i] != 'Y' THEN
                                DISPLAY "Choose your desired engine capacity (1 - 2): "
                                SET engineCapacity[i] = getValidIntegerInput("engine capacity", 1, 2)
                        END IF
                        IF license[i] == 'Y'
                                DISPLAY "Choose your desired engine capacity (1 - 3): "
                                SET engineCapacity[i] = getValidIntegerInput("engine capacity", 1, 3)
                        END IF

                        IF engineCapacity[i] = 1 THEN
                                engineCapacity = 120
                        ELSE IF enginecapacity[i] = 2 THEN
                                engineCapacity = 200
                        ELSE
                                engineCapacity = 270
                        END IF
                END FOR
        END MODULE

        FUNCTION setLaps(INTEGER driverCount, STRING& raceFormat)
                DECLARE INTEGER laps

                IF raceFormat == "Circuit Race" THEN
                        DISPLAY "Available number of laps: 2, 3, 4"
                        PROMPT "How many laps would you like? (2/3/4): "
                        READ laps
                ELSE IF raceFormat == "Sprint Race" OR raceFormat == "Drag Race" THEN
                        DISPLAY "Sprint Races and Drag Races only have 1 lap"
                        SET laps = 1
                ELSE IF raceFormat == "Time Trial" THEN
                        DISPLAY "Available number of laps: Unlimited"
                        PROMPT "How many laps would you like? :"
                        READ laps
                ELSE
                        DISPLAY "Number of laps corresponds with the number of drivers"
                        SET laps = driverCount - 1
                        DISPLAY "Laps = Driver Count - 1"
                        DISPLAY "Laps = ", driverCount, " - 1"
                        DISPLAY "Laps = ", laps
                END IF
                RETURN LAPS
        END FUNCTION
                        


        MODULE driverGear(INTEGER& i, STRING driverName[])
                displayRacingGear()

                DISPLAY "Driver: ", driverName[i]
        END MODULE

        FUNCTION float selectHelmet (INTEGER i, STRING helmetSize[], FLOAT helmetPrice[])
                PROMPT "Please choose your helmet size (S/M/L/XL): "
                READ helmetSize[i]

                SET transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper)

                WHILE cin.fail() || (helmetSize[i] != "S" && helmetSize[i] != "M" && helmetSize[i] != "L" && helmetSize[i] != "XL")
                        PROMPT "Please choose a valid helmet size (S/M/X/XL): "
                        READ helmetSize[i]

                        SET transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper)
                END WHILE

                IF helmetSize[i] == "S" THEN
                        helmetPrice[i] = 2
                END IF
                IF helmetSize[i] == "M" THEN
                        helmetPrice[i] = 4
                END IF
                IF helmetSize[i] == "L" THEN
                        helmetPrice[i] = 6
                END IF
                IF helmetSize[i] == "XL" THEN
                        helmetPrice[i] = 8
                END IF

                RETURN helmetPrice[i]
        END FUNCTION

        FUNCTION float selectSuit (INTEGER i, STRING suitSize[], FLOAT suitPrice[])
                PROMPT "Please choose your suit size (S/M/L/XL): "
                READ suitSize[i]

                SET std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper)

                WHILE cin.fail() || (suitSize[i] != "S" && suitSize[i] != "M" && suitSize[i] != "L" && suitSize[i] != "XL")
                        PROMPT "Please choose a valid helmet size (S/M/X/XL): "
                        READ helmetSize[i]
                        SET std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper)
                END WHILE

                IF suitSize[i] == "S" THEN
                        suitPrice[i] = 2
                END IF
                IF suitSize[i] == "M" THEN
                        suitPrice[i] = 4
                END IF
                IF suitSize[i] == "L" THEN
                        suitPrice[i] = 6
                END IF
                IF helmetSize[i] == "XL" THEN
                        suitPrice[i] = 8
                END IF

                RETURN suitPrice[i]
        END FUNCTION

        FUNCTION FLOAT selectShoe(INTEGER i, INTEGER shoeSize[], FLOAT shoePrice[])
                PROMPT "Please choose your shoe size (20 - 35): "
                READ shoeSize[i]

                WHILE std::cin.fail() || (shoeSize[i] < 20 || shoeSizep[i] > 35
                        PROMPT "Please choose a valid shoe size (20 - 35): "
                        READ shoeSize[i]
                END WHILE

                IF shoeSize[i] <= 25 THEN
                        shoePrice[i] = 3
                ELSE
                        shoePrice[i] = 6
                END IF
        RETURN shoePrice[i]
        END FUNCTION

        FUNCTION FLOAT calculateTotalGearPrice(INTEGER& driverCount, FLOAT helmetPrice[], FLOAT suitPrice[], FLOAT gearPrice[])
                DECLARE totalGearPrice
                SET totalGearPrice = 0

                FOR INTEGER i = 0, i < driverCount, i++
                        gearPrice[i] = helmetPrice[i] + suitPrice[i] + shoePrice [i]
                        totalGearPrice += gearPrice[i]
                END FOR
        RETURN totalGearPrice
        END FUNCTION

        FUNCTION FLOAT setMembershipDiscount ()
                DECLARE CHAR membership
                PROMPT "Do you have a membership? (Y/N): "
                SET membership = getValidCharacterInput()

                IF membership == 'Y' THEN
                        RETURN 0.1
                ELSE
                        RETURN 0.0
                END IF
        END FUNCTION
        
        FUNCTION FLOAT calculatePrice (int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount)
                SET pricePerCC = 03
                SET totalKartPrice = 0

                FOR i = 0, i < driverCount, i++
                        totalKartPrice += (engineCapacity[i] * pricePerCC) * laps
                END FOR
                
                finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount)
        END FUNCTION

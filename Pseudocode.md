        FUNCTION INTEGER main()
                CALL menu()

                DECLARE CHARACTER continueChoice
                DECLARE INTEGER customer = 0
                DECLARE FLOAT totalIncome = 0

                DO
                        //Initializations (in order)
                        STRING bookingType

                        DECLARE INTEGER driverCount
                        DECLARE STRING driverName[5]
                        DECLARE INTEGER driverAge[5]
                        DECLARE CHARACTER license[5]

                        DECLARE STRING raceFormat
                        DECLARE STRING track
                        
                        DECLARE INTEGER engineCapacity[5]

                        DECLARE INTEGER laps

                        DECLARE STRING helmetSize[5], suitSize[5]
                        DECLARE INTEGER shoeSize[5]
                        DECLARE FLOAT helmetPrice[5], suitPrice[5], shoePrice[5]
                        DECLARE FLOAT gearPrice[5]

                        // The Crux of the Go-Kart Booking System
                        SET bookingType = getBookingType()
                        
                        SET driverCount = getDriverCount(bookingType)

                        CALL getDriverDetails(driverCount, driverName, driverAge, license)

                        SET raceFormat = setRaceFormat(bookingType)

                        SET track = setTrack(bookingType, raceFormat)

                        SET setEngineCapacity(driverCount, driverName, driverAge, license, engineCapacity)

                        SET laps = setLaps(driverCount, raceFormat)

                        FOR INTEGER i = 0; i < driverCount; i++
                                CALL driverGear(i, driverName)
                                CALL selectHelmet(i,helmetSize, helmetPrice)
                                CALL selectSuit(i,suitSize, suitPrice)
                                CALL selectShoe(i, shoeSize, shoePrice)
                        END FOR

                        DECLARE FLOAT totalGearPrice
                        SET totalGearPrice = calculateTotalGearPrice(driverCount, helmetPrice, suitPrice, shoePrice, gearPrice)

                        DECLARE FLOAT membershipDiscount
                        SET membershipDiscount = setMembershipDiscount()

                        DECLARE FLOAT totalPrice
                        SET totalPrice = calculatePrice(engineCapacity, laps, driverCount, totalGearPrice, membershipDiscount)

                        OUTPUT "Race Format: ", raceFormat
                        OUTPUT "Track: ", track

                        std::cout << std::fixed << std::showpoint;

                        FOR INTEGER i = 0; i < driverCount; i++
                                OUTPUT "Driver: ", driverName[i]
                                OUTPUT "Age: ", driverAge[i]
                                OUTPUT "Has License: ", license[i]
                                OUTPUT "Engine Capacity: ", engineCapacity[i], "cc"
                                OUTPUT "Helmet Size: ", helmetSize[i]
                                OUTPUT "Helmet Price: RM", std::setprecision(2), helmetPrice[i]
                                OUTPUT "Suit Size: ", suitSize[i]
                                OUTPUT "Suit Pricet: RM", std::setprecision(2), suitPrice[i]
                                OUTPUT "Shoe Size: ", shoeSize[i], "cm"
                                OUTPUT "Shoe Price: RM", std::setprecision(2), shoePrice[i]
                                OUTPUT "Gear Price: RM", std::setprecision(2), gearPrice[i]
                        END FOR
                        
                        OUTPUT "Total Gear Price: RM", std::setprecision(2), totalGearPrice
                        OUTPUT "Membership Discount\t: ", membershipDiscount * 100, "%"
                        OUTPUT "Total : RM", std::setprecision(2), totalPrice

                        totalIncome += totalPrice
                        customer++

                        PROMPT "Continue for another customer? (Y/N): "
                        SET continueChoice = getValidCharacterInput()

                WHILE std::toupper(continueChoice) == 'Y'

                OUTPUT "Total Income: RM ", std::setprecision(2), totalIncome

                RETURN 0
        END FUNCTION        

        MODULE menu()
                DECLARE INTEGER menu
                
                DO
                        CALL displayMenu()
                        PROMPT "Choose your option: "
                        SET menu = getValidIntegerInput("option", 0, 5)

                        IF menu == 2 THEN
                                displayRaceFormat("Group")
                        END IF
                        IF menu == 3 THEN
                                displayTrackList()
                        END IF
                        IF menu == 4 THEN
                                displayRacingGear()
                        END IF
                        IF menu == 5 THEN
                                displayEngineCapacities(18, 'Y')
                        END IF
                WHILE menu != 1 && menu != 0
        END MODULE

        FUNCTION INTEGER getValidIntegerInput(STRING inputType, INTEGER minValue, INTEGER maxValue)
                int input;
                READ input;
                WHILE std::cin.fail() || (input < minValue || input > maxValue)
                        PROMPT "\t\t\tPlease enter a valid " << inputType << " (" << minValue << " - " << maxValue << "): "
                        READ input
                END WHILE
                RETURN input
        END FUNCTION

        FUNCTION CHARACTER getValidCharacterInput()
                STRING input
                READ input

                WHILE input.length() != 1 || !std::isalpha(input[0])
                        PROMPT "Please enter a valid input (Y/N): "
                        READ input
                END WHILE

                RETURN std::toupper(input[0])
        END FUNCTION

        STRING getBookingType()
                DECLARE INTEGER bookingTypeID

                DISPLAY "1 - Solo"
                DISPLAY "2 - Group (Maximum 5)"
                PROMPT "Please choose your desired booking (1 - 2): "
                SET bookingTypeID = getValidIntegerInput("booking type", 1, 2)

                IF bookingTypeID == 1 THEN
                        RETURN "Solo"
                ELSE
                        RETURN "Group"
                END IF
        END FUNCTION

        FUNCTION INTEGER getDriverCount(STRING& bookingType)
                IF bookingType == "Solo" THEN
                        RETURN 1
                END IF
                PROMPT "Please enter the number of drivers (2 - 5): "
                RETURN getValidIntegerInput("number of drivers", 2, 5)
        END FUNCTION

        MODULE getDriverDetails(INTEGER& driverCount, STRING driverName[], INTEGER driverAge[], CHARACTER license[])
                FOR int i = 0; i < driverCount; i++
                        PROMPT "Driver #", (i+1), " Name: "
                        READ driverName[i]

                        PROMPT "Driver #", (i+1), " Age: "
                        READ driverAge[i]

                        PROMPT "Does Driver #", (i+1), " has a license? (Y/N): "
                        SET license[i] = getValidCharacterInput()
                END FOR
        END MODULE

        FUNCTION STRING setRaceFormat(STRING& bookingType)
                DECLARE INTEGER raceFormatID
                DECLARE STRING raceFormat

                CALL displayRaceFormat(bookingType)

                IF bookingType == "Solo" THEN
                        PROMPT "Please choose the race format (1 - 4): "
                        SET raceFormatID = getValidIntegerInput("race format", 1, 4);
                ELSE IF bookingType == "Group" THEN
                        PROMPT "Please choose the race format (1 - 5): "
                        SET raceFormatID = getValidIntegerInput("race format", 1, 5)
                END IF 

                SWITCH (raceFormatID) 
                        case 1: return "Circuit Race";
                        case 2: return "Sprint Race";
                        case 3: return "Time Trial";
                        case 4: return "Drag Race";
                        case 5: return "Elimination Race";
                        default: return "Invalid Race Format";
        END FUNCTION 

        FUNCTION STRING setTrack(STRING& bookingType, STRING& raceFormat)
                DECLARE INTEGER trackID

                IF bookingType == "Group" AND raceFormat == "Circuit Race" THEN
                        DISPLAY "Available Track:"
                        DISPLAY "1 - Section 9 Circuit"
                        DISPLAY "2 - Blackrock Circuit"
                        PROMPT "Please choose your track (1 - 2): "
                        SET trackID = getValidIntegerInput("track, 1, 2)
                ELSE IF raceFormat == "Time Trial" THEN
                        DISPLAY "Available Track:"
                        DISPLAY "1 - Section 9 Circuit"
                        DISPLAY "2 - Blackrock Circuit"
                        DISPLAY "3 - Rushline Dash"
                        DISPLAY "4 - Chrono Pass"
                        PROMPT "Please choose your track (1 - 4): "
                        SET trackID = getValidIntegerInput("track, 1, 4)
                END IF

                SWITCH (trackID)
                        case 1: return "Section 9 Circuit";
                        case 2: return "Blackrock Circuit";
                        case 3: return "Rushline Dash";
                        default: return "Chrono Pass";

                IF bookingType == "Solo" AND raceFormat == "Circuit Race" THEN
                        DISPLAY "Available Track: Section 9 Circuit"
                        DISPLAY "Defaulting to said track"
                        RETURN "Section 9 Circuit"
                ELSE IF raceFormat == "Elimination Race" THEN
                        DISPLAY "Available Track: Blackrock Circuit"
                        DISPLAY "Defaulting to said track"
                        RETURN "Blackrock Circuit"
                ELSE IF raceFormat == "Sprint Race" THEN
                        DISPLAY "Available Track: Rushline Dash"
                        DISPLAY "Defaulting to said track"
                        RETURN "Rushline Dash"
                ELSE IF raceFormat == "Drag Race" THEN
                        DISPLAY "Available Track: Torque Strip"
                        DISPLAY "Defaulting to said track"
                        RETURN "Torque Strip"
                END IF

                RETURN "Track"
        END FUNCTION
                        
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

                        SWITCH (engineCapacity[i])
                                case 1: engineCapacity[i] = 120; break;
                                case 2: engineCapacity[i] = 200; break;
                                default: engineCapacity[i] = 270; break;
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

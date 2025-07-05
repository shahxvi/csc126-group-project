        FUNCTION float selectHelmet (int i, string helmetSize[], float helmetPrice[])
                PROMPT "Please choose your helmet size (S/M/L/XL): "
                READ helmetSize[i]

                SET std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper)transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper)

                WHILE cin.fail() || (helmetSize[i] != "S" && helmetSize[i] != "M" && helmetSize[i] != "L" && helmetSize[i] != "XL")
                        PROMPT "Please choose a valid helmet size (S/M/X/XL): "
                        READ helmetSize[i]

                        SET std::transform(suitSize[i].begin(), suitSize[i].end(), suitSize[i].begin(), ::toupper)transform(helmetSize[i].begin(), helmetSize[i].end(), helmetSize[i].begin(), ::toupper)
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
        
        FUNCTION FLOAT calcPrice (int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount)
                SET pricePerCC = 03
                SET totalKartPrice = 0

                FOR i = 0, i < driverCount, i++
                        totalKartPrice += (engineCapacity[i] * pricePerCC) * laps
                END FOR
                
                finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount)
        END FUNCTION

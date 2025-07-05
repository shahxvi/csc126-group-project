        MODULE calcPrice (int engineCapacity[], int laps, int driverCount, float totalGearPrice, float membershipDiscount)
                SET pricePerCC = 03
                SET totalKartPrice = 0

                FOR i = 0, i < driverCount, i++
                        totalKartPrice += (engineCapacity[i] * pricePerCC) * laps
                END FOR
                
                finalPrice = (totalKartPrice + totalGearPrice) * (1 - membershipDiscount)
        END MODULE

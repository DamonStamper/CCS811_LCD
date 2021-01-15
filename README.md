Download and install https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

Upload this code to your arduino.

Wire the LCD to 5v, the CCS811 to 3.3, share ground among everything. LCD's and CCS811's SCL go to Arduino's SCL. LCD's and CCS811's SDA go to Arduino's SDA.

You might need to play with the contrast potentiometer on the LCD to get the characters to show up.

The LCD should show a "#" alternating on the LCD to indicate it's still working.

If you've just started using your CCS811 then be aware there is a "burn in" time. Let it run overnight and it should start being usable.

It is normal for the CO2 to start at 400 PPM. That is AFAIK the lowest the sensor goes.
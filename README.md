# AUTOMATIC MINI PHARMACY MACHINE

**Error free** Arduino UNO compilation screenshot: 

![image](https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/7a552af4-4be7-4346-b119-17afbd755c1f.png)



RISCDUINO Compilation Screenshot:
Only warning, no errors:


![image](https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/7124b562-beda-47db-82b9-99a68389e0ba.png)


Steps:
1. The QR code is scanned by the patient. (For the prototype, the data of the QR codes are the letters 'A' and 'B'. In reality, this QR code will be present alongside the medicine name in the prescription given by the doctor.

replace ![ image](https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/3ea69fcd-174a-489d-9cc3-0fe64abc5ec0.png)) with <img src="https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/3ea69fcd-174a-489d-9cc3-0fe64abc5ec0.png)" width="100" height="100">

2. Depending on the QR scanned, the pharmacy machine will release either medicine 'A' or medicine 'B'
3. The medicines are placed on an inclined plane, hence a pair of motors is sufficent for the dropping of the medicine bottle.
4. Consider medicine 'A' once, the QR code is scanned by the ESP CAM module, a python opencv code will decipher the QR nad output 'A' into the serial channel of the riscduino.
5. When the riscduino reads this, the respective motor mechanism is initiated.

* Motor Mechanism:
  1. There are 2 motors for each medicine
  2. The first motor opens its flap and th emedicine bottle rolls down
  3. The first motor closes its flap
  4. The second motor lifts its flap and the next medicine rolls forward to take the place of its predecessor, but it dosent fall down because the flap on motor 1 is closed.
  5. Once the medicine rolls forward, the second motor closes its flap, securing the medicine bottle in place.


Rough circuit with all the compoenents:

![circuit_diagram](https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/032e8d44-c7a2-492f-bc1f-ef253dedcb5c.png)

1. The ESP Code will be uploaded to ESP CAM module through the vsdsqadron. The code will contain wifi name and password. (Code for ESP CAM has been uploaded)

2. The, the IP address of the ESP will be obtianed, and entered into the opencv python code which will identify the QR code in real time. (openCV python code for QR determination is also uploaded)

Testing of the arduino code in TinkerCad:

![image](https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/ffd8e579-5239-4ecb-a1b6-ad9d8b07d948.png)


https://github.com/Navya-tayi/riscv_product_hackathon/assets/79205242/25b71ea2-58f9-4fc9-ac73-5c11d58608b6.mp4



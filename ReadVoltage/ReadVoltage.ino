int last_readings[10] = {0};

void shift_and_append(int array[], int value, int array_size) {
    if (!array_size)
        return;
    
    for (int i = 0; i < array_size - 1; i++) 
        array[i] = array[i+1];
    
    array[array_size - 1] = value;
}

int get_array_max_difference(int array[], int array_size) {
    if (!array_size)
        return 0.0f;
    
    int min = array[0], max = array[0];

    for (int i = 1; i < array_size; i++) {
        if (min > array[i])
            min = array[i];

        if (max < array[i])
            max = array[i];
    }

    return max - min;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
//  Serial.println(value);

  shift_and_append(last_readings, value, 10);
//  Serial.print("\n\n[");
//  for(int i = 0; i < 10; i++) {
//    Serial.print(last_readings[i]);
//    Serial.print(" ");
//  }
//  Serial.print("]\n");
//
//  int diff = get_array_max_difference(last_readings, 10);
//
//  Serial.println(diff);
  delay(100);

  if (diff > 3) {
//    Serial.println("led off");
    digitalWrite(2, 0);
  }
  else {
//    Serial.println("led on");
    digitalWrite(2, 1);
  }
}

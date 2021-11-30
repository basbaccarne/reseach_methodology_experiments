// libraries
import processing.serial.*;

// config
int lf = 10;
String serialString = null;
Serial myPort;
float serialNum;
float maxVal = 0;

void setup() {
  // window size
  size(1200, 800);

  // set COM port
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.clear();
}

void draw() {
  clear();

  // get data from COM port and transform to float
  while (myPort.available() > 0) {
    serialString = myPort.readStringUntil(lf);
    if (serialString != null) {
      print(serialString);
      serialNum=float(serialString);
      println(serialNum);
    }
  }
  myPort.clear();

  // save maximum value
  if (serialNum > maxVal) {
    maxVal = serialNum;
  }

  // dataviz: background
  background(255);

  // dataviz: balloons
  stroke(30, 100, 200);
  fill(30, 100, 200, 100);
  ellipse(600, 400, maxVal*30, maxVal*30);
  ellipse(600, 400, serialNum*30, serialNum*30);

  // // dataviz: text
  String now = "current reading:       " + nf(serialNum) +  " PSI";
  String max = "maximum reading: " + nf(maxVal) +  " PSI";
  fill(30, 100, 200);
  textSize(20);
  text(now, 20, 40);
  text(max, 20, 70);
  
  fill(255, 210, 0);
  text("mouse click = reset max", 20, 100);
}

// reset maximum on mouse click
void mousePressed() {
  maxVal = 0;
}

/* This is Demo(Semi-Final Prototype) 6 - Created on: 16/02/2016 - Editied On: 21/02/2016
 * Created By : Ayush Sharma
 * E-mail: hobbyists.stop@gmail.com
 * Website: bubblesaqua.com
 * Buy Kits at Bubblesaqua.com
 * Do Not Remove this Data as we all should Credit the Orignal Author.
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <FS.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
/* Set these to your desired credentials. */

const char* host = "bubbles-webupdate";
const char *password = "fishes123";
const char *ssid = "Bubbles Aqua";

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

int var;
const int switch1 = 5; // relay control at 5 | check your esp. many have inverted 4 & 5 pins
char val;

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
 
void stateteller(){
  File teller = SPIFFS.open("/config/state.txt", "r");
  if (teller){Serial.println("State-Teller Success");
  while (teller.available()) {
  val = teller.read();
  }
  Serial.println("Teller Says:"); Serial.println(val);
  if(val == '1'){digitalWrite(switch1, HIGH); Serial.println("Switch Turned ON");}
  else if(val == '0'){digitalWrite(switch1, LOW); Serial.println("Switch Turned OFF");}
  else{Serial.println("Error Reading SwitchState");}
  teller.close(); }
  else{ Serial.println("State-Teller Failed");}
}

void handleRoot(){  // ----- Index HTML (MAIN) ------
  File index = SPIFFS.open("/index.html", "r");    // Loading Index.html if this is not a First Run.
  if (!index) {Serial.println("Index Failed");}
  else{Serial.println("Index Success");}
  server.streamFile(index, "text/html") !=index.size();
  index.close();
 }

void handleHelp(){  // ----- HELP HTML  ------
  File help = SPIFFS.open("/help.html", "r");    // Loading Index.html if this is not a First Run.
  if (!help) {Serial.println("Help Failed");}
  else{Serial.println("Help Success");}
  server.streamFile(help, "text/html") !=help.size();
  help.close();
 }

void iconvideo(){  //     ----- Video PNG -----
  File videoguide = SPIFFS.open("/icons/video.png", "r");
  if(!videoguide){Serial.println("Video Guide PNG Error");}else{Serial.println("Video Guide PNG Success");}
  server.streamFile(videoguide, "image/png") !=videoguide.size();
  videoguide.close();
}

void iconapple(){  //     ----- APPLE Touch PNG -----
  File apple = SPIFFS.open("/icons/apple.png", "r");
  if(!apple){Serial.println("APPle PNG Error");}else{Serial.println("APPLE PNG Success");}
  server.streamFile(apple, "image/png") !=apple.size();
  apple.close();
}

void videoguide(){  //     ----- Video MP4 -----
  File video = SPIFFS.open("/video/guide.mp4", "r");
  if(!video){Serial.println("Video MP4 Error");}else{Serial.println("Video MP4 Success");}
  server.streamFile(video, "video/mp4") !=video.size();
  video.close();
}

void iconmenu(){  //     ------ menu SVG ------
  File menu = SPIFFS.open("/icons/menu.svg", "r");
  if(!menu){Serial.println("menu SVG Error");}else{Serial.println("menu SVG Success");}
  server.streamFile(menu, "image/svg+xml") !=menu.size();
  menu.close();
}

void iconon(){  //     ------ ON SVG ------
  File one = SPIFFS.open("/icons/on.svg", "r");
  if(!one){Serial.println("ON SVG Error");}else{Serial.println("ON SVG Success");}
  server.streamFile(one, "image/svg+xml") !=one.size();
  one.close();
}

void iconoff(){  //     ------ OFF SVG ------
  File off = SPIFFS.open("/icons/off.svg", "r");
  if(!off){Serial.println("OFF SVG Error");}else{Serial.println("OFF SVG Success");}
  server.streamFile(off, "image/svg+xml") !=off.size();
  off.close();
}

void iconswitch(){  //     ------ switch PNG ------
  File switch1 = SPIFFS.open("/icons/key.png", "r");
  if(!switch1){Serial.println("switch PNG Error");}else{Serial.println("switch PNG Success");}
  server.streamFile(switch1, "image/png") !=switch1.size();
  switch1.close();
}


void iconback(){  //     ------ Back PNG ------
  File back = SPIFFS.open("/icons/back.png", "r");
  if(!back){Serial.println("Back PNG Error");}else{Serial.println("Back PNG Success");}
  server.streamFile(back, "image/png") !=back.size();
  back.close();
}

void icontemp(){  //     ------ temp SVG ------
  File temp = SPIFFS.open("/icons/cloud.png", "r");
  if(!temp){Serial.println("Temperature Cloud Error");}else{Serial.println("Temperature Cloud Success");}
  server.streamFile(temp, "image/png") !=temp.size();
  temp.close();
}

void iconupload(){  //     ------ upload SVG ------
  File upload = SPIFFS.open("/icons/upload.png", "r");
  if(!upload){Serial.println("upload PNG Error");}else{Serial.println("upload PNG Success");}
  server.streamFile(upload, "image/png") !=upload.size();
  upload.close();
}

void favicon(){  //     ------ Favicon PNG ------
  File favi = SPIFFS.open("/icons/favi.png", "r");
  if(!favi){Serial.println("Favicon PNG Error");}else{Serial.println("Favicon PNG Success");}
  server.streamFile(favi, "image/png") !=favi.size();
  favi.close();
}

void maincss(){  //     ------ Main CSS ------
  File css = SPIFFS.open("/css/main.css", "r");
  if(!css){Serial.println("CSS Error");}else{Serial.println("CSS Success");}
  server.streamFile(css, "text/css") !=css.size();
  css.close();
}

void mainfont(){  //     ------ Main FONT ------
  File font = SPIFFS.open("/css/sansation.ttf", "r");
  if(!font){Serial.println("FONT Error");}else{Serial.println("FONT Success");}
  server.streamFile(font, "font/ttf") !=font.size();
  font.close();
}

void handleControl() {// ------ Handle Control Page ------
  File teller = SPIFFS.open("/config/state.txt", "r");
  if (teller){Serial.println("State-Teller Success");
  while (teller.available()) {
  var = teller.read();
  }
  Serial.println("Teller Says:"); Serial.println(var);
  if(var == '1'){
     File controlp1 = SPIFFS.open("/control1.html", "r");
  if (controlp1) {Serial.println("Control2 Success");}
  else{ Serial.println("Control1 Failed");}
  server.streamFile(controlp1, "text/html") !=controlp1.size();
  controlp1.close();
    }
  else if(var == '0'){
    File controlp2 = SPIFFS.open("/control2.html", "r");
  if (controlp2) {Serial.println("Control2 Success");}
  else{ Serial.println("Control2 Failed");}
  server.streamFile(controlp2, "text/html") !=controlp2.size();
  controlp2.close();
    }
  else{Serial.println("Error Reading SwitchState");}
  teller.close(); }
  else{ Serial.println("State-Teller Failed");}
}

void controlcss(){  // -------- Control CSS --------
  File cpcss = SPIFFS.open("/css/cons.css", "r");
   if(!cpcss){Serial.println("CP-CSS Error");}else{Serial.println("CP-CSS Success");}
  server.streamFile(cpcss, "text/css") !=cpcss.size();
  cpcss.close();
}

void handleswitchon(){  // ------ Switch OFF -------
  {
    digitalWrite(switch1, HIGH);
  File stateon = SPIFFS.open("/config/state.txt", "w");
  if (stateon){
  Serial.println("State-On Success");
  stateon.print("1"); 
  stateon.close();
  Serial.println("State-On Written HIGH");}
  else{ Serial.println("State-On Failed");}
  }{
  File control1 = SPIFFS.open("/control1.html", "r");
  server.streamFile(control1, "text/html") !=control1.size();
  control1.close(); }
}

void handleswitchoff(){  // ------ Switch ON ------
  { digitalWrite(switch1, LOW);
  File stateoff = SPIFFS.open("/config/state.txt", "w");
  if (stateoff){
  Serial.println("State-Off Success");
  stateoff.print("0"); 
  stateoff.close();
  Serial.println("State-Off Written LOW");}
  else{ Serial.println("State-Off Failed");}
  }{
  File control2 = SPIFFS.open("/control2.html", "r");
  server.streamFile(control2, "text/html") !=control2.size();
  control2.close();}
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
	Serial.begin(115200);
	Serial.println("");
  pinMode(switch1, OUTPUT);
  delay(5000);
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);
	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
  SPIFFS.begin();
  Serial.println("Dallas Temperature IC - Begin");
//  sensors.begin();
  MDNS.begin(host);
  httpUpdater.setup(&server);
  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
  server.on("/", handleRoot);                                   // GET Request for Root - Index.html
  server.on("/icons/key.png", HTTP_GET, iconswitch);            // GET Request for Icon - Switch
  server.on("/icons/on.svg", HTTP_GET, iconon);                 // GET Request for Icon - ON
  server.on("/icons/off.svg", HTTP_GET, iconoff);               // GET Request for Icon - OFF
  server.on("/video/guide.mp4", HTTP_GET, videoguide);               // GET Request for Video Guide
  server.on("/icons/apple.png", HTTP_GET, iconapple);           // GET Request for Icon - APPLE Touch
  server.on("/icons/favi.png", HTTP_GET, favicon);              // GET Request for Favicon
  server.on("/icons/video.png", HTTP_GET, iconvideo);           // GET Request for Icon - Video Guide
  server.on("/icons/menu.svg", HTTP_GET, iconmenu);             // GET Request for Icon - Menu
  server.on("/icons/cloud.png", HTTP_GET, icontemp);             // GET Request for Icon - Temperature
  server.on("/icons/upload.png", HTTP_GET, iconupload);         // GET Request for Icon - Upload
  server.on("/icons/back.png", HTTP_GET, iconback);
  server.on("/css/main.css", HTTP_GET, maincss);                // GET Request for CSS  - Main CSS
  server.on("/css/sansation.ttf", HTTP_GET, mainfont);          // GET Request for Font - Sansation
  server.on("/control", handleControl);                         // GET Request for HTML - control.html
  server.on("/help", handleHelp);                               // GET Request for HTML - help.html
  server.on("/css/cons.css", HTTP_GET, controlcss);             // GET Request for CSS  - Control CSS
  server.on("/control/on", HTTP_GET, handleswitchon);           // GET Request for Switch - Turn ON 
  server.on("/control/off", HTTP_GET, handleswitchoff);         // GET Request for Switch - Turn OFF
  server.on("/help", handleHelp);
  server.begin();
  server.onNotFound(handleNotFound);
	Serial.println("HTTP server started");
 
  stateteller();
}

void loop() {
	server.handleClient();
}

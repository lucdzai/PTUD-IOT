#include <EtherCard.h>
#define muaDO 2  
#define muaAO A0 
//// Địa chỉ IP tĩnh của Arduino
//static byte ip_cua_toi[] = { 169, 254, 215, 42 }; 
//// Địa chỉ Gateway
//static byte ip_gateway[] = { 169, 254, 215, 41 }; 
//
//// Địa chỉ MAC Ethernet - cần đảm bảo duy nhất trong mạng
//static byte dia_chi_mac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };

// Chân điều khiển LED
//const int chan_led = 3;
//// Trạng thái LED (mặc định là tắt)
//bool trang_thai_led = LOW;
//
//// Bộ đệm gửi và nhận TCP/IP
//byte Ethernet::buffer[700]; 

void setup() {
//  // Khởi tạo kết nối Ethernet
//  ether.begin(sizeof Ethernet::buffer, dia_chi_mac, SS);
//  // Cài đặt IP tĩnh
//  ether.staticSetup(ip_cua_toi, ip_gateway);
  Serial.begin(9600);
  pinMode(muaDO, INPUT);
  
}
void luc() {
  if (Serial.available() > 0) { // Chỉ gửi khi có yêu cầu từ board nhận
    char request = Serial.read(); // Đọc tín hiệu yêu cầu
    if (request == 'R') {         // Kiểm tra xem tín hiệu có đúng là 'R' không
      int phatHienMua = digitalRead(muaDO); 
      float cuongDoHienTai = analogRead(muaAO); 
      float cuongDoMuaPhanTram = map(cuongDoHienTai, 0, 1023, 0, 100); 
      if (phatHienMua == LOW) {
        Serial.print("MUA,"); 
        Serial.println(cuongDoMuaPhanTram);
      } else {
        Serial.println("KHONG CO MUA");
      }
    }
  }
}

void loop() {
  luc();
//  // Lắng nghe các gói tin và xử lý
//  word vi_tri = ether.packetLoop(ether.packetReceive());
//  if (vi_tri) {
//    // Xử lý yêu cầu HTTP
//    char *du_lieu = (char *)Ethernet::buffer + vi_tri;
//    // Kiểm tra yêu cầu bật LED (GET /led/on)
//    if (strstr(du_lieu, "GET /led/on")) {
//      digitalWrite(chan_led, HIGH);  // Bật LED
//      trang_thai_led = HIGH;         // Cập nhật trạng thái LED
//    } else if (strstr(du_lieu, "GET /led/off")) {
//      digitalWrite(chan_led, LOW);   // Tắt LED
//      trang_thai_led = LOW;          // Cập nhật trạng thái LED
//    }
//    // Gửi phản hồi HTML
//    gui_phan_hoi_http();
//  }
}

//void gui_phan_hoi_http() {
//  // Tạo nội dung HTML phản hồi
//  char phan_hoi_html[400];
//  sprintf(phan_hoi_html,
//          "HTTP/1.1 200 OK\r\n"
//          "Content-Type: text/html; charset=UTF-8\r\n" // Thêm mã hóa UTF-8
//          "Connection: close\r\n"
//          "\r\n"
//          "<!DOCTYPE html>\r\n"
//          "<html>\r\n"
//          "<head>\r\n"
//          "<meta charset=\"UTF-8\">\r\n" // Khai báo mã hóa UTF-8
//          "<title>Điều khiển LED</title>\r\n"
//          "</head>\r\n"
//          "<body>\r\n"
//          "<h1>Điều khiển LED</h1>\r\n"
//          "<p>Trạng thái LED: %s</p>\r\n"
//          "<p><a href=\"/led/on\">Bật</a> | <a href=\"/led/off\">Tắt</a></p>\r\n"
//          "</body>\r\n"
//          "</html>\r\n",
//          (trang_thai_led == HIGH) ? "Bật" : "Tắt");
//
//  // Gửi phản hồi qua Ethernet
//  memcpy(ether.tcpOffset(), phan_hoi_html, strlen(phan_hoi_html));
//  ether.httpServerReply(strlen(phan_hoi_html));
//}

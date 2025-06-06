# ☀️ Hệ Thống Giám Sát và Tối Ưu Hóa Hiệu Suất Pin Mặt Trời Thông Minh 🔋

Dự án này là một giải pháp toàn diện nhằm giám sát và tối ưu hóa hiệu suất của tấm pin mặt trời. Hệ thống sử dụng NodeMCU ESP32 để thu thập các thông số quan trọng như điện áp và dòng điện, từ đó tính toán công suất phát điện. Dữ liệu này được gửi lên một nền tảng web để hiển thị trực quan hiệu suất theo thời gian thực.

Bên cạnh đó, hệ thống còn tích hợp cảm biến bụi hoặc camera để giám sát tình trạng bề mặt tấm pin. Nếu phát hiện bụi bẩn làm giảm hiệu suất, cảnh báo sẽ được gửi đến người quản lý để vệ sinh kịp thời. Hơn nữa, khả năng điều khiển góc tấm pin bằng động cơ servo theo mặt trời được tích hợp để tối ưu hóa lượng điện tạo ra, đảm bảo hiệu suất năng lượng tối đa.

## 🌟 Chức năng Chính

| Chức năng                               | Mô tả                                                                                                                              |
| :-------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------- |
| **Đo lường Công suất Pin** | Sử dụng cảm biến (ví dụ: INA219) để đo điện áp và dòng điện của tấm pin mặt trời, tính toán và theo dõi công suất phát liên tục. |
| **Giám sát Bề mặt Pin** | Sử dụng cảm biến bụi (ví dụ: GP2Y10) hoặc camera (ví dụ: ESP32-CAM) để đánh giá mức độ sạch của bề mặt tấm pin.                         |
| **Cảnh báo Giảm Hiệu suất** | Khi phát hiện bụi bẩn hoặc hiệu suất giảm đáng kể do các yếu tố bên ngoài, hệ thống tự động gửi cảnh báo cần vệ sinh.                 |
| **Hiển thị Dữ liệu Web** | Dữ liệu điện áp, dòng điện, công suất và trạng thái bụi được gửi lên một ứng dụng web để hiển thị biểu đồ và thông tin theo thời gian thực. |
| **Điều chỉnh Góc Tấm Pin (Tùy chọn)** | Tích hợp động cơ servo để tự động điều chỉnh góc nghiêng của tấm pin mặt trời theo vị trí mặt trời nhằm tối ưu hóa hấp thụ năng lượng. |
| **Kết nối Không dây** | Sử dụng Wi-Fi của ESP32 để gửi dữ liệu và cảnh báo đến máy chủ.                                                                   |

## 🔧 Sơ đồ hoạt động hệ thống

(Bạn có thể tạo một sơ đồ mới phù hợp với dự án này hoặc sửa lại sơ đồ cũ. Nếu chưa có, có thể bỏ dòng này hoặc để placeholder.)

![Sơ đồ hệ thống giám sát pin mặt trời](assets/solar_system_diagram.png)
_Sơ đồ khối minh họa luồng dữ liệu và các thành phần chính của hệ thống._

## ⚙️ Công nghệ sử dụng

| Thành phần                         | Mô tả                                                                                                                                                                                                                                                                         |
| :--------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Vi điều khiển (NodeMCU ESP32)** | Bộ điều khiển trung tâm, có khả năng Wi-Fi tích hợp, thu thập dữ liệu từ cảm biến, xử lý và gửi lên server.                                                                                                                                                                   |
| **Cảm biến Điện áp/Dòng điện** | **INA219 Module (hoặc tương đương):** Đo chính xác điện áp và dòng điện của tấm pin mặt trời để tính toán công suất.                                                                                                                                                      |
| **Cảm biến Bụi (Tùy chọn)** | **PMSA003I / GP2Y10 (hoặc tương đương):** Đo nồng độ bụi trong không khí, gián tiếp đánh giá mức độ bám bụi trên bề mặt pin.                                                                                                                                                   |
| **Camera nhỏ (Tùy chọn)** | **ESP32-CAM (hoặc module camera khác):** Chụp ảnh bề mặt tấm pin định kỳ để kiểm tra trực quan mức độ bụi bẩn.                                                                                                                                                                |
| **Động cơ Servo (Tùy chọn)** | **SG90 / MG996R (hoặc tương đương):** Để điều khiển cơ cấu điều chỉnh góc tấm pin tự động.                                                                                                                                                                                    |
| **Nền tảng Web (Flask/Python)** | Máy chủ backend (chạy trên máy tính/Raspberry Pi/VPS) sử dụng Flask để nhận dữ liệu từ ESP32, lưu trữ và cung cấp API/Giao diện người dùng để hiển thị hiệu suất pin theo thời gian thực và lịch sử.                                                                             |
| **Kết nối Internet** | Sử dụng Wi-Fi của ESP32 để truyền dữ liệu đến máy chủ web.                                                                                                                                                                                                                   |
| **Nguồn điện** | Pin hoặc nguồn DC ổn định cho ESP32 và các cảm biến.                                                                                                                                                                                                                        |
| **Vỏ bảo vệ (Tùy chọn)** | Chống nước, chống bụi, bảo vệ thiết bị hoạt động ổn định trong môi trường ngoài trời.                                                                                                                                                                                       |

## 🔄 Chu trình hoạt động cơ bản

1.  **Khởi tạo hệ thống:**
    * ESP32 khởi động, kết nối Wi-Fi và các cảm biến được thiết lập.
    * Mô hình YOLOv8 (nếu sử dụng camera) được tải.

2.  **Thu thập dữ liệu liên tục:**
    * Cảm biến điện áp/dòng điện đọc giá trị của pin mặt trời.
    * Cảm biến bụi đọc mật độ bụi hoặc camera chụp ảnh bề mặt pin.

3.  **Tính toán và Phân tích:**
    * Điện áp và dòng điện được dùng để tính toán công suất tức thời.
    * Dữ liệu bụi được phân tích (hoặc ảnh được xử lý bằng YOLOv8 để phát hiện vật cản/bụi bẩn).
    * Hiệu suất pin được so sánh với các ngưỡng chuẩn hoặc dữ liệu lịch sử.

4.  **Gửi dữ liệu lên Web:**
    * Tất cả các dữ liệu được thu thập (điện áp, dòng điện, công suất, bụi/trạng thái bề mặt) được gửi đến máy chủ web qua Wi-Fi.

5.  **Hiển thị và Cảnh báo:**
    * Ứng dụng web hiển thị dữ liệu trực quan bằng biểu đồ.
    * Nếu hiệu suất giảm do bụi bẩn, hoặc giá trị bụi/vật cản vượt ngưỡng, hệ thống web sẽ kích hoạt gửi cảnh báo (email, thông báo push).

6.  **Tối ưu hóa (Nếu có Servo):**
    * Dựa trên thời gian trong ngày/ánh sáng, ESP32 điều khiển động cơ servo để xoay tấm pin đến góc tối ưu nhất.

7.  **Tiếp tục lặp lại:**
    * Chu trình đọc, tính toán, gửi dữ liệu và điều khiển diễn ra liên tục theo các khoảng thời gian đã định.

## 💡 Mục tiêu mở rộng trong tương lai

* **Lưu trữ dữ liệu đám mây:** Sử dụng các dịch vụ như Firebase, AWS IoT, Azure IoT Hub để lưu trữ dữ liệu lâu dài và truy cập dễ dàng hơn.
* **Ứng dụng di động:** Phát triển ứng dụng trên điện thoại để theo dõi và điều khiển hệ thống từ xa.
* **Dự đoán hiệu suất:** Ứng dụng Machine Learning để dự đoán hiệu suất pin dựa trên điều kiện thời tiết và dữ liệu lịch sử.
* **Tích hợp cảm biến thời tiết:** Bao gồm cảm biến nhiệt độ, độ ẩm, cường độ ánh sáng để phân tích sâu hơn ảnh hưởng đến hiệu suất.
* **Hệ thống tự làm sạch:** Kết hợp với cơ chế phun nước hoặc chổi tự động để tự động làm sạch bề mặt pin khi phát hiện bụi bẩn.

## 👨‍💻 Tác giả

**Họ tên:** Phạm Duy Đức
**GitHub:** [https://github.com/your-username](https://github.com/your-username)
(Hãy thay `your-username` bằng tên người dùng GitHub của bạn)

MQTT測試
===
## 測試情境
需求端發送請求到MTQQ broker，  
服務端訂閱MTQQ的訊息，並將需求端的訊息處理後回傳到MQTT，  
需求端再從MTQQ取得處理後的訊息。

### 檔案說明
mqtt_service_example.py : 模擬服務透過MQTT接收客戶端傳來的需求，將運算結果丟回MQTT  
mqtt_client_example.py : 模擬需求端透過MQTT傳訊息，並等待訊息回傳

### 使用方式
1. 先開一個terminal，執行mqtt_service_example.py。這邊會起一個daemon訂閱markliou/test-service這個topic。
2. 開啟另外一個terminal，執行mqtt_client_example.py。他會推送裡面的一個dictionary內容到markliou/test-service，同時訂閱markliou/test-response。
3. mqtt_service_example.py看到markliou/test-service有訊息就會處理這些資訊。目標是把"encoded_image_string"抓出來。
4. mqtt_service_example.py把資料抓出來以後，就會往markliou/test-response去丟。mqtt_client_example.py會從markliou/test-response把結果抓下來。  

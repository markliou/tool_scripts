# this script will send the request to MQTT, and wait for the response

import paho.mqtt.client as mqtt
import json


brokerAddr = "broker.hivemq.com"
serviceTopic = "markliou/test-service"
responseTopic = "markliou/test-response"


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Connected with result code {reason_code}")
    client.subscribe(responseTopic)


# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    message = f"{msg.topic} {str(msg.payload)}"
    print(message)


clientc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
clientc.on_connect = on_connect
clientc.on_message = on_message

clientc.connect(brokerAddr, 1883, 60)

clientc.loop_start()

## 以下一次性傳送訊息 ##
content = {
    "Eqp": {
        "TYPE": "AICloud",
        "CMD": "Stacker",
        "Station": "Stacker",
        "Eqp_name": "ase2-02",
        "APName": "ase2-02",
        "SN": "current_time_string",
        "mqttlisten": "Wbcim/AI_Service/return/Stacker_AI/ase2-02/current_time_string",
        "VpData": {
            "vpname": "MaskCloud",
            "base64": "encoded_image_string",
            "Storage_grid": "A",
            "Storage_layer": "2",
            "Storage_spaces": "C-12-2",
        },
    }
}

pubFlag = clientc.publish(serviceTopic, json.dumps(content))
pubFlag.wait_for_publish()

# because this request just need to call one-time, that the stop can be set in "on_message" section
clientc.loop_stop()
clientc.disconnect()


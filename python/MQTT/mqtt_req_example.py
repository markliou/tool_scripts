# this script will send the request to MQTT, and wait for the response

import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
import paho.mqtt.subscribe as subscribe

import json


brokerAddr = "broker.hivemq.com"
serviceTopic = "markliou/test-service"
responseTopic = "markliou/test-response"


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
print(f"test msg: {json.dumps(content)}")
publish.single(serviceTopic, json.dumps(content), hostname=brokerAddr)
msg = subscribe.simple(responseTopic, hostname=brokerAddr)
print("%s %s" % (msg.topic, msg.payload))




# this scrip give an exmaple for publishing and subscribing the
# message to the topic
# installation: pip install paho-mq

import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
import json

brokerAddr = "broker.hivemq.com"
serviceTopic = "markliou/test-service"
responseTopic = "markliou/test-response"


def triger_service_example(client, message):
    message = json.loads(message.decode())
    print(message["Eqp"]["VpData"]["base64"])
    # waitFlag = client.publish(responseTopic, message["Eqp"]["VpData"]["base64"])
    # waitFlag.wait_for_publish()
    publish.single(responseTopic, message["Eqp"]["VpData"]["base64"], hostname=brokerAddr)


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Connected with result code {reason_code}")
    client.subscribe(serviceTopic)


# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    message = f"{msg.topic} {msg.payload.decode()}"
    print(message)
    triger_service_example(client, msg.payload)


clientc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
clientc.on_connect = on_connect
clientc.on_message = on_message

clientc.connect(brokerAddr, 1883, 60)

# Start the loop to process incoming messages
clientc.loop_forever()

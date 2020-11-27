import zmq 
import time 

mq_server = zmq.Context().socket(zmq.REP)
mq_server.bind("tcp://127.0.0.1:50001")
print("the reciver is started")

while True:
    print("recieve the message: {}".format(mq_server.recv()))
    feedback = "{}".format(time.time())
    print("sending feedback message: {}".format(feedback))
    # mq_server.send(feedback.encode('ascii'))
    mq_server.send_string(feedback)
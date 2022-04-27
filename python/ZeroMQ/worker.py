import zmq 

mq_target  = zmq.Context().socket(zmq.REQ)
mq_target.connect("tcp://127.0.0.1:50001")

for i in range(100):
    print("sending: {}".format(i))
    # mq_target.send("{}".format(i).encode('ascii'))
    mq_target.send_string("{}".format(i))
    print("feedback:{}".format(mq_target.recv()))


remote build server
==
本機在計算能力不足但需要compile code的狀態下，會需要往遠端的主機送。比較理想的轉送方式是將編譯的環境與程式碼一起打包後傳遞到遠端，再將code送到編譯環境中進行編譯測試。 
這邊紀錄兩種可透過docker進行編譯的方法:
1. docker compose
2. docker swarm 
 
兩者最大的不同點在於透過docker compose需要手動決定在哪個節點跑；使用docker swarm就是由loading balancer來決定放到哪一台機器上跑，使用者也可以透過node的tag來將job放到目標機器上。 

# docker compose 

## References
* https://www.docker.com/blog/how-to-deploy-on-remote-docker-hosts-with-docker-compose/

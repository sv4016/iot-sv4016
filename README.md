# iot-sv4016 

### Features
- Reads live temperature and humidity from topic `greenhouse/monitor/data`
- Evaluates environmental conditions (Cold, Optimal, Hot)
- Publishes LED color commands via MQTT
- Displays data on the Node-RED dashboard

 **Hardware & software :

 <img width="2060" height="894" alt="image" src="https://github.com/user-attachments/assets/0e16194e-a0d8-46be-8b32-8643fcad7ce6" />

** output:****

<img width="1453" height="255" alt="Screenshot 2025-11-10 at 02 33 17" src="https://github.com/user-attachments/assets/fb575516-19fe-4d29-9ddc-ad13f633b8a5" />

![WhatsApp Image 2025-11-10 at 06 54 53](https://github.com/user-attachments/assets/8ecbe362-2d6c-4c4f-b551-ba4f1ecdbf71)

![WhatsApp Image 2025-11-10 at 00 05 25](https://github.com/user-attachments/assets/2ca46336-0722-40e6-b6a7-b38b646a7dd7)

**code output:**


<img width="703" height="328" alt="Screenshot 2025-11-06 at 21 50 25" src="https://github.com/user-attachments/assets/80245dd6-b3c6-4bdd-ac1a-e48c0cb7599d" />


**Live Dashboard Gauges:**


<img width="669" height="416" alt="Screenshot 2025-11-06 at 15 50 54" src="https://github.com/user-attachments/assets/d5635bd1-6662-4c6a-a417-702d67e6dada" />


**Real-Time Temperature & Humidity Chart:**
<img width="802" height="348" alt="Screenshot 2025-11-08 at 21 30 06" src="https://github.com/user-attachments/assets/f61d8926-8643-432e-84ec-6c16da748aed" />

---

## 📚 Historical Data Retrieval
** Collection of data**
Docker:
<img width="972" height="769" alt="Screenshot 2025-11-09 at 23 39 19" src="https://github.com/user-attachments/assets/45665822-afb0-44df-a328-993aa4e18136" />
NODE-RED:
<img width="1290" height="755" alt="Screenshot 2025-11-09 at 21 58 25" src="https://github.com/user-attachments/assets/64c8cab1-d1f8-4fb8-9d69-fa60f4df7769" />


**chart output:**
<img width="1470" height="851" alt="Screenshot 2025-11-09 at 16 29 58" src="https://github.com/user-attachments/assets/43203284-e9aa-4662-a84e-492f4fa73093" />

This flow enables **retrieving and visualizing stored data** from the containerized Node-RED environment.  
It parses JSON records from `/data/greenhouse_data.json` and renders long-term climate trends.

🧾 **Container Data Verification:**
```bash
docker exec -it mynodered bash
cat /data/greenhouse_data.json
```
<img width="562" height="144" alt="Screenshot 2025-11-10 at 02 52 43" src="https://github.com/user-attachments/assets/abf0e266-2645-4d5b-895a-19c8faff46dd" />

Interval & debugging report:

<img width="311" height="118" alt="Screenshot 2025-11-10 at 06 53 42" src="https://github.com/user-attachments/assets/e1255af6-0ff7-4ab0-a839-590b8182880f" />

<img width="1108" height="261" alt="Screenshot 2025-11-10 at 02 34 09" src="https://github.com/user-attachments/assets/30f81220-9ac2-424b-95b0-72a81edc7c35" />






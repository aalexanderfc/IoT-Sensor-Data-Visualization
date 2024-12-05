# IoT Sensor Data Visualization

## Introduction
This project collects temperature and humidity data using a DHT11 sensor connected to an ESP32. The data is sent to AWS IoT Core, stored in DynamoDB, and visualized in Grafana via CloudWatch.

## Features
- Collects real-time temperature and humidity data.
- Sends data securely using MQTT via AWS IoT Core.
- Stores data in DynamoDB for long-term use.
- Uses CloudWatch to stream and query DynamoDB data for visualization in Grafana.

## System Architecture
![System Architecture](images/system_architecture.png)

## Hardware Setup

### Components
- **ESP32**: Microcontroller for data collection and transmission.
- **DHT11 Sensor**: Measures temperature and humidity.
- **LEDs**: (Optional) For smart lighting simulation.

### Wiring Diagram
![Wiring Diagram](images/wiring_diagram.png)

## Software Setup

### Arduino Code
The ESP32 is programmed using Arduino IDE to:
- Collect data from the DHT11 sensor.
- Send data to AWS IoT Core using MQTT.

### AWS IoT Core
1. **Create a Thing** in AWS IoT Core.  
   ![Create a Thing](images/thing.png)
2. **Attach certificates** and a policy to the Thing.
3. **Configure the ESP32** with the Thing’s credentials.

### DynamoDB and CloudWatch
1. **DynamoDB**:
   - Ensure a table is created to store sensor data (e.g., `SensorData`).
2. **CloudWatch**:
   - Configure a log group for streaming data from DynamoDB.
   - Use AWS CloudWatch Logs Insights to query DynamoDB data.
   - Connect CloudWatch with Grafana to visualize queried data.

### Grafana Visualization
1. Use **CloudWatch as a data source** in Grafana.  
   ![AWS CloudWatch](images/cloudwatch.png)
2. Create a dashboard to visualize temperature and humidity over time.
3. Example Dashboard:  
   ![Grafana Dashboard](images/grafana_dashboard.png)

## Results
The project successfully visualizes real-time sensor data. Below is a sample of the Grafana dashboard:  
![Sample Data](images/sample_data.png)

## How to Run

1. **Set Up the Hardware**:
   - Connect the DHT11 sensor to the ESP32.
   - Upload the Arduino code.
2. **AWS IoT Core**:
   - Set up MQTT topics for telemetry.
3. **DynamoDB and CloudWatch**:
   - Ensure the DynamoDB table is set up to store data.
   - Configure CloudWatch to query and stream DynamoDB data.
4. **Grafana**:
   - Create a dashboard connected to CloudWatch for visualization.

## Future Improvements
- Add more sensors (e.g., light, motion).
- Automate alerts based on data thresholds using CloudWatch alarms.
- Explore real-time analytics with AWS Kinesis or Timestream.

## Conclusion
This project successfully integrates IoT hardware with cloud services to collect, store, and visualize sensor data using DynamoDB and CloudWatch with Grafana. The scalable design allows for future enhancements such as adding more sensors or automation features.


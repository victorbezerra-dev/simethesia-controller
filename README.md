# 🎛️ Simethesia Controller (PI Control)

This repository contains the **closed-loop controller** used in the [Simethesia Platform](https://github.com/victorbezerra-dev/simethesia-lab) to regulate anesthesia depth in real-time using BIS (Bispectral Index) feedback.

It implements a **discrete-time Proportional-Integral (PI)** controller that adjusts the infusion rate of propofol. The controller communicates with the [Simethesia Simulator](https://github.com/victorbezerra-dev/simethesia-simulator) via I²C.

---

## ⚙️ Control Strategy

The PI controller is implemented in discrete-time using the following control law:

```text
u[k] = u[k−1] + Kp × e[k] + (Ts × Kp / Ti − Kp) × e[k−1]
```

**Where:**

- `u[k]`: Infusion rate at time step `k`
- `e[k]`: Control error = reference BIS − measured BIS
- `Kp`: Proportional gain
- `Ti`: Integral time constant
- `Ts`: Sampling period

> ⚠️ The infusion rate `u[k]` is saturated between `0` and `30` to reflect safety and physical limits of drug delivery.


## 🚀 How to Run (Arduino)

### 🛠️ Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- Arduino-compatible board (e.g., Uno, Mega, Nano)
- Connection via **I²C** to the [`simethesia-simulator`](https://github.com/simethesia/simethesia-simulator)

### ⚙️ Instructions

1. **Clone this repository:**

   ```bash
   git clone https://github.com/simethesia/simethesia-controller.git
2. Open `main.ino` in the Arduino IDE.

3. Upload the sketch to your Arduino board.

4. Connect the board to the simulator via **I²C**.

5. Open the **Serial Monitor** (set baud rate to `115200`) to monitor **BIS** and **infusion rate** in real time — or use the **Simethesia App** for a graphical and mobile-friendly interface.


## 🎛️ Initial Tuning (SIMC)

The controller was initially tuned using the **SIMC (Skogestad Internal Model Control)** method, which provides a good balance between performance and robustness.

You can adjust the tuning parameters directly in the source code.

### Default Parameters

| Parameter | Value  | Description                 |
|-----------|--------|-----------------------------|
| `Kp`      | -1.0   | Proportional gain           |
| `Ti`      | 20.0   | Integral time (seconds)     |
| `Ts`      | 0.025  | Sampling time (25 ms)       |
| `r`       | 50.0   | Target BIS (setpoint)       |

## 🧩 System Architecture
The simulator is part of a modular architecture designed for real-time hardware-in-the-loop experiments:

## 📊 Results

_Insert your experiment plots and analysis below:_

- 📉 **BIS Response Curve** over time  
- ⚙️ **Control effort** (infusion rate `u`)  
- 📈 **Stability and settling time**  

### 🧪 Performance Metrics
You can use the following metrics to evaluate control quality in your experiments:

| Metric  | Description                                 | Formula                  | Value  |
|---------|---------------------------------------------|--------------------------|--------|
| **ISE**  | Integral of Squared Error                  | `∫ e²(t) dt`             | -      |
| **IAE**  | Integral of Absolute Error                 | `∫ e(t)dt`               | -      |
| **ITSE** | Time-weighted Squared Error                | `∫ t · e²(t) dt`         | -      |
| **ITAE** | Time-weighted Absolute Error               | `∫ t · e(t) dt`          | -      |
| **TCV**  | Total Control Variation                    | `∑ u(k+1) − u(k)`        | -      |


## 🧠 Future Improvements

- **Support for additional control strategies (e.g., LQR, MPC):**  
  Extend the controller to support advanced control algorithms that can provide better performance, especially under variable patient dynamics and clinical challenges.

## 🤝 Contributing

Contributions are welcome! Here are a few ways you can help:

- 🔧 Improve controller performance or add new control strategies (e.g., LQR, MPC)
- 🎛️ Tune gains for different patient profiles or clinical scenarios
- 📝 Help document the project and expand educational content

Feel free to fork the repository, open issues, or submit pull requests. Let's make anesthesia simulation more accessible, robust, and educational together!

---

Crafted with 🎯 control theory, 💉 simulation, and ❤️ for real-time systems.

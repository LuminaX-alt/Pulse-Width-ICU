# Pulse-Width-ICU
Pulse width is the duration of time that a digital or analog pulse signal remains in the "high" state (logic 1 or positive voltage).

It is typically measured in microseconds (µs) or milliseconds (ms).

Pulse width is a critical parameter in many biomedical signals, such as:

Pulse oximeter output pulses representing heartbeat.

ECG QRS complex duration.

Ventilator control pulses.

Neural stimulation pulses in ICU device

<img width="631" alt="image" src="https://github.com/user-attachments/assets/591885ed-07d7-4523-ac99-2c88b20f2de5" />


Equipment Setup
Use a digital oscilloscope with sufficient bandwidth (≥ signal frequency) and sampling rate.

Connect the oscilloscope probe to the signal source (e.g., pulse output from sensor or medical device).

Ensure proper grounding to avoid noise or signal distortion.

Measurement Procedure
Triggering the Oscilloscope

Set trigger mode to Edge trigger on the rising or falling edge of the pulse.

Adjust trigger level to cross the threshold voltage representing pulse start/end.

Display the Pulse Waveform

Use appropriate time base (horizontal scale) to clearly see the pulse.

Adjust vertical scale (voltage) for signal clarity.

Measure Pulse Width

Most modern oscilloscopes have a cursor measurement function:

Place Cursor 1 at pulse rising edge (start time).

Place Cursor 2 at pulse falling edge (end time).

The difference between cursors gives the pulse width (Δt).

Alternatively, use the oscilloscope’s automatic measurement feature to measure pulse width.

Interpreting Pulse Width

The measured pulse width corresponds to the duration the signal stays ‘high’.

In pulse oximeters, pulse width is related to pulse rate and oxygen saturation levels.

In neural stimulation, pulse width affects stimulation strength and safety.

Important Considerations
Threshold Voltage Level: Set threshold at a voltage level that reliably represents signal transitions (often 50% of pulse amplitude).

Noise and Jitter: Minimize noise for accurate edge detection.

Sampling Rate: Must be at least 10× the pulse frequency to avoid aliasing.

Pulse Shape: Rectangular pulses yield straightforward measurements; distorted pulses may require filtering or advanced signal processing.




<img width="745" alt="image" src="https://github.com/user-attachments/assets/d56de034-ec92-470b-b7dc-61fbc3107f0c" />


Results
Let’s look at some oscope measurements for different PWM configurations. We’ll start with the configuration given in the above code excerpts: clock source = 1 MHz, polarity = PWM_HIGH, alignment = PWM_ALIGN_LEFT, ul_period = 20, ul_duty = 5. Note that the relevant timing characteristics are displayed on the right side of the scope captures.

<img width="486" alt="image" src="https://github.com/user-attachments/assets/e32d9bcc-2c43-4dfa-9a77-3ea7660c40fa" />

If we keep everything the same but switch to polarity = PWM_LOW, we get this:

<img width="478" alt="image" src="https://github.com/user-attachments/assets/79bd8963-fc54-4818-a636-ce96c2bba69a" />

If we go back to PWM_HIGH then change to alignment = PWM_ALIGN_CENTER, we see the following:

 <img width="474" alt="image" src="https://github.com/user-attachments/assets/0036057f-ad96-49ce-82b5-4bf0498de1fd" />

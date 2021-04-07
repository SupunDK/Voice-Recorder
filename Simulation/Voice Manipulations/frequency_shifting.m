Fs = 1000;
Ts = 1/Fs;
t = 0:Ts:5;

f1 = 50;
f2 = 100;

f0 = input("Enter a frequency between 0-1000 Hz: ");

subplot(2, 1, 1);
signal = 1*sin(2*pi*f1*t) + 2*sin(2*pi*f2*t);

show_freq(signal, length(t), Fs, "Original Signal");

w0 = 2*pi*f0;

offset_const = exp(1i*w0*t);

signal2 = offset_const .* signal;

subplot(2, 1, 2);
show_freq(signal2, length(t), Fs, string(f0) + "Hz Frequency Shifted Signal");

sgtitle("Amplitude Spectrum");
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
function [signal_out] = frequency_shifting(signal, t, F_shift)
    offset = cos(2*pi*F_shift*t);
    
    signal_out = signal .* (offset');
end
=======
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
Fs = 1000;
Ts = 1/Fs;
t = 0:Ts:5-Ts;

f1 = 200;
f2 = 300;

f0 = input("Enter a frequency between 0-1000 Hz: ");

subplot(2, 1, 1);
signal = 1*sin(2*pi*f1*t) + 2*sin(2*pi*f2*t);

show_freq(signal, length(t), Fs, "Original Signal");

w0 = 2*pi*f0;

offset_const = exp(1i*w0*t);

signal2 = offset_const .* signal;

subplot(2, 1, 2);
show_freq(signal2, length(t), Fs, string(f0) + "Hz Frequency Shifted Signal");

<<<<<<< HEAD
<<<<<<< HEAD
sgtitle("Amplitude Spectrum");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
sgtitle("Amplitude Spectrum");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
sgtitle("Amplitude Spectrum");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6

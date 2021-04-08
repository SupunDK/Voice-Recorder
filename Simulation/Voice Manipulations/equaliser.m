file = "africa-toto.wav";

[y, Fs] = audioread(file, [20*22050, 30*22050]);

%High-Pass
figure;
subplot(4,1,1);
show_freq_equaliser(y, length(y), Fs, "Original signal");

y_high = highpass(y, 500, Fs);

subplot(4,1,2);
show_freq_equaliser(y_high, length(y_high), Fs, "High-Pass filtered signal");

sgtitle("Amplitude Spectrum");

%Low-Pass
y_low = lowpass(y, 500, Fs);

subplot(4,1,3);
show_freq_equaliser(y_low, length(y_high), Fs, "Low-Pass filtered signal");

%Band-Pass
y_band = bandpass(y,[100 500],Fs);

subplot(4,1,4);
show_freq_equaliser(y_band, length(y_band), Fs, "Band-Pass filtered signal");

%figure;
%bandpass(y,[100 500],Fs, 'Steepness', 1);

figure;
show_freq_equaliser( (y_low+y_band+y_high)./3, length(y), Fs, "Final Signal");
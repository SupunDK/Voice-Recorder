% file = "africa-toto.wav";
% 
% [y, Fs] = audioread(file, [20*22050, 30*22050]);
% 
% plot(y);
% 
% sound(y,Fs);

Fs = 1000;
Ts = 1/Fs;
t = 0:Ts:5;

f1 = 50;
f2 = 100;

figure;
signal = 1*sin(2*pi*f1*t) + 2*sin(2*pi*f2*t);

show_freq(signal, t, Fs);

w0 = 2*pi*50;

offset_const = exp(1i*w0*t);

s2 = offset_const .* signal;

figure;
show_freq(s2, t, Fs);
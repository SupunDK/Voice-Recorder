Fs = 1000;
Ts = 1/Fs;
t = -10:Ts:10;

l = length(t);

y = sin(2*pi*50*t);

x = sin(2*pi*10*t) ./ (pi*t);

figure;
hold on;
stem(t, x);

z = conv(y, x);

figure;
subplot(3,1,1);
show_freq_equaliser(y, l, Fs, "y");

subplot(3,1,2);
show_freq_equaliser(x, l, Fs, "x");

%subplot(3,1,3);
%show_freq(z(1:5001), l, Fs, "z");
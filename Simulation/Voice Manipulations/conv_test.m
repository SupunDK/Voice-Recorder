Fs = 1000;
Ts = 1/Fs;
t = 0:Ts:5;

l = length(t);

y = sin(2*pi*50*t);

x = sin(2*pi*10*t) ./ (pi*t);

%z = conv(y, x);

subplot(3,1,1);
show_freq(y, l, Fs, "y");

subplot(3,1,2);
show_freq(x, l, Fs, "x");

%subplot(3,1,3);
%show_freq(z(1:5001), l, Fs, "z");
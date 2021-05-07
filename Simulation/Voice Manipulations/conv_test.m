Fs = 1000;
Ts = 1/Fs;
t = -10:Ts:10;

l = length(t);

y = sin(2*pi*50*t);

x = sin(2*pi*10*t) ./ (pi*(t/Ts));

figure;
subplot(3, 1, 1);
stem(t, y);
xlim([-1, 1]);

subplot(3, 1, 2);
stem(t, x);
xlim([-1, 1]);

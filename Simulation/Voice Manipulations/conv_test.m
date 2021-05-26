Fs = 1000;
Ts = 1/Fs;
t = -10:Ts:10;

l = length(t);

y = sin(2*pi*50*t);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
x = sin(2*pi*10*t) ./ (pi*(t/Ts));

figure;
subplot(3, 1, 1);
stem(t, y);
xlim([-1, 1]);

subplot(3, 1, 2);
stem(t, x);
xlim([-1, 1]);
=======
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
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
<<<<<<< HEAD
<<<<<<< HEAD
%show_freq(z(1:5001), l, Fs, "z");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
%show_freq(z(1:5001), l, Fs, "z");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
%show_freq(z(1:5001), l, Fs, "z");
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6

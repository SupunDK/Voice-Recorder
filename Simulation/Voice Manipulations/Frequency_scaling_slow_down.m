[y,Fs] = audioread('africa-toto.wav');
y_seg = y(30*Fs:35*Fs);
L = length(y_seg);

t1 = (0:L-1)/Fs;    %time vector of sample signal
t2 = (0:2*L-1)/Fs;  %time vector of slowed signal

% create the slowed signal
y_slow = zeros(2*L,1);
for i = (1:2*L-1)
    if mod(i,2) == 1
        y_slow(i) = y_seg((i+1)/2);
    else
        y_slow(i) = (y_seg(i/2)+y_seg(i/2+1))/2;
    end
end

%plot normal signal sample
figure;
subplot(2,2,1);
plot(t1,y_seg);
title('y(t)');
xlabel('t');
ylabel('Amplitude');

%plot slowed signal
subplot(2,2,3);
plot(t2(1:L),y_slow(1:L));
title('y(t/2)');
xlabel('t');
ylabel('Amplitude');

%FFT of normal signal sample
Y1 = fft(y_seg);
Y1 = abs(Y1/L);
Y  = Y1(1:L/2+1);
Y(2:end-1) = 2*Y(2:end-1);
f = Fs/L*(0:(L/2)); %setting the frequency axis to scale
subplot(2,2,2)
plot(f,Y);
xlim([1,2000])
title('one-sided Amplitude Spectrum of y(t)');
xlabel('f(Hz)');
ylabel('|Y(f)|');

%FFT of slowed signal sample
Y2 = fft(y_slow);
L = 2*L;
Y2 = abs(Y2/L);
Ys  = Y2(1:L/2+1);
Ys(2:end-1) = 2*Ys(2:end-1);
f = Fs/L*(0:(L/2)); %setting the frequency axis to scale
subplot(2,2,4)
plot(f,Ys);
xlim([1,2000])
title('one-sided Amplitude Spectrum of y(t/2)');
xlabel('f(Hz)');
ylabel('|Y(2f)|');
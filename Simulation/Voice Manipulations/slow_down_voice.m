file = "my_voice_record.wav";

[y, Fs] = audioread(file);
Ts = 1/Fs;

t = 0:1:length(y)-1;
t = t * Ts;

sound(y, Fs);
pause(11);

clear sound;

figure;
show_freq_equaliser(y, length(y), Fs, "Original signal - Frequency domain");

% y_edit = zeros(2*length(y) - 1, 2);
% 
% for i = 1:length(y)
%     y_edit(2*i-1, 1) = y(i, 1);
% 
%     if i ~= length(y)
%         y_edit(2*i, 1) = ( y(i, 1) + y(i+1, 1) ) / 2;
%     end
% end
% 
% for i = 1:length(y)
%     y_edit(2*i-1, 2) = y(i, 2);
% 
%     if i ~= length(y)
%         y_edit(2*i, 2) = ( y(i, 2) + y(i+1, 2) ) / 2;
%     end
% end


sound(y, 0.8*Fs);
pause(11);
clear sound;

y_edit = frequency_shifting(y, t, 10000);

figure;
show_freq_equaliser(y_edit, length(y), Fs, "Edited signal - Frequency domain");

sound(y_edit, 0.8*Fs);
pause(11);
clear sound;

audiowrite("my_voice_record_shifted.wav", y, Fs);
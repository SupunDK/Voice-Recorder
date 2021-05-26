<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

w0 = 2*pi*Fs;

off_set = cos(w0 * t);

y_edit = y .* (off_set.');

sound(y_edit, 0.5*Fs);
pause(21);

clear sound;

figure;
show_freq_equaliser(y_edit, length(y), Fs, "Edited signal - Frequency domain");

audiowrite("my_voice_record_shifted.wav", y_edit, Fs);
=======
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
file = "africa-toto.wav";

[y, Fs] = audioread(file, [20*22050, 30*22050]);

figure;
<<<<<<< HEAD
<<<<<<< HEAD
show_freq_equaliser(y, length(y), Fs);
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
show_freq_equaliser(y, length(y), Fs);
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
show_freq_equaliser(y, length(y), Fs);
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
